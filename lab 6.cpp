#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long factorial(int n) {
    if (n <= 1) return 1; // Базовый случай
    return n * factorial(n - 1); // Шаг рекурсии
}
int fibonacci(int n) {
    if (n <= 1) return n; // Базовый случай
    return fibonacci(n - 1) + fibonacci(n - 2); // Шаг рекурсии
}
int gcd(int a, int b) {
    if (b == 0) return a; // Базовый случай
    return gcd(b, a % b); // Шаг рекурсии
}
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Переместить диск 1 с " << from << " на " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to); // Шаг 1
    cout << "Переместить диск " << n << " с " << from << " на " << to << endl; // Шаг 2
    hanoi(n - 1, aux, to, from); // Шаг 3
}
struct Stats {
    int comparisons;
    int swaps;
};
Stats bubbleSort(int arr[], int n) {
    Stats stats = {0, 0};
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            stats.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                stats.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
    return stats;
}
Stats insertionSort(int arr[], int n) {
    Stats stats = {0, 0};
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            stats.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats.swaps++; // Считаем сдвиг как операцию изменения
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        if (j + 1 != i) {
            stats.swaps++;
        }
    }
    return stats;
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "ru");
    cout << "=== ЧАСТЬ 1: РЕКУРСИЯ ===" << endl;
    int num = 5;
    cout << "1. Факториал " << num << "! = " << factorial(num) << endl;
    int fibN = 7;
    cout << "2. Число Фибоначчи (позиция " << fibN << ") = " << fibonacci(fibN) << endl;
    int a = 48, b = 18;
    cout << "3. НОД(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    cout << "4. Ханойские башни (3 диска):" << endl;
    hanoi(3, 'A', 'C', 'B'); 
    cout << endl;
    cout << "=== ЧАСТЬ 2: СОРТИРОВКИ ===" << endl;
    const int N = 8;
    int original[N] = {64, 34, 25, 12, 22, 11, 90, 5};
    int arrBubble[N], arrInsert[N];
    for (int i = 0; i < N; i++) {
        arrBubble[i] = original[i];
        arrInsert[i] = original[i];
    }
    cout << "Исходный массив: ";
    printArray(original, N);
    cout << endl;
    Stats statsBubble = bubbleSort(arrBubble, N);
    cout << "Пузырьковая сортировка:" << endl;
    cout << "  Отсортировано: "; printArray(arrBubble, N);
    cout << "  Сравнений: " << statsBubble.comparisons << ", Обменов: " << statsBubble.swaps << endl << endl;
    Stats statsInsert = insertionSort(arrInsert, N);
    cout << "Сортировка вставками:" << endl;
    cout << "  Отсортировано: "; printArray(arrInsert, N);
    cout << "  Сравнений: " << statsInsert.comparisons << ", Обменов (сдвигов): " << statsInsert.swaps << endl << endl;
    return 0;
}
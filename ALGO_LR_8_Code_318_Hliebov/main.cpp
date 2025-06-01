#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // Для функції SetConsoleOutputCP (зміна кодування)
#include <sys/stat.h> // Для перевірки існування файлу

#include "array_utils.h"   // Функції для роботи з масивами
#include "matrix_utils.h"  // Функції для роботи з матрицями

using namespace std;
// Функція перевірки існування файлу
bool file_exists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}
// Функція створення прикладового файлу з масивом
void create_example_array_file(const string& filename) {
    ofstream fout(filename);
    if (fout.is_open()) {
        fout << "5\n1.1 2.2 3.3 4.4 5.5\n";
        fout.close();
        cout << "Створено приклад файлу: " << filename << endl;
    } else {
        cout << "Не вдалося створити файл: " << filename << endl;
    }
}
//  Завдання 1: Зсув масиву вліво
void runTask1() {
    string inputFile, outputFile;
    cout << "Введіть ім'я вхідного файлу для масиву (наприклад, array_in_1.txt): ";
    cin >> inputFile;
    cout << "Введіть ім'я вихідного файлу для масиву (наприклад, array_out_1.txt): ";
    cin >> outputFile;
// Введення імен файлів
    if (!file_exists(inputFile)) {
        cout << "Файл не знайдено. Створюємо приклад..." << endl;
        create_example_array_file(inputFile);
    }
// Якщо файл не існує, створюється приклад.
    const int MAX = 20;
    double array[20];
    int size = 0; 
// Оголошення масиву
    get_array(inputFile, array, size);
    if (size <= 0 || size > MAX) {
        cout << "Помилка: не вдалося прочитати масив з файлу або некорректний розмір." << endl;
        return;
    } 
// Зчитування масиву з файлу, перевірка коректності
    shift_array_left(array, size);
    show_array(outputFile, array, size); 
//  Зсув вліво та запис у файл
    cout << "Завдання 1 виконано. Результат записано у " << outputFile << endl;
}
// Завдання 2: Пошук максимуму серед впорядкованих стовпців матриці
void runTask2() {
    string inputFile;
    cout << "\nВведіть ім'я вхідного файлу для матриці (наприклад, matr_in_1.txt): ";
    cin >> inputFile;
// Введення імені файлу з матрицею
    const int MAX = 20;
    double matrix[MAX][MAX];
    int rows, cols;

    get_matrix(inputFile, matrix, rows, cols); // Зчитування матриці з файлу

    double maxVal = max_ordered_columns(matrix, rows, cols); // Пошук максимуму серед впорядкованих стовпців

    ofstream fout(inputFile, ios::app); // дописуємо у той же файл
    if (fout.is_open()) {
        fout << "\nМаксимальний елемент серед впорядкованих стовпців: " << maxVal << endl;
        fout.close(); // Результат дописується в кінець того ж файлу
    }

    cout << "Завдання 2 виконано. Результат дописано у " << inputFile << endl;
}
// Завдання 3: Сортування масиву методом двійкових вставок
void runTask3() {
    string inputFile, outputFile;
    cout << "\nВведіть ім'я вхідного файлу для сортування (наприклад, sort_in.txt): ";
    cin >> inputFile;
    cout << "Введіть ім'я вихідного файлу після сортування (наприклад, sort_out.txt): ";
    cin >> outputFile; // Введення файлів

    const int MAX = 100;
    double array[MAX];
    int size;

    get_array(inputFile, array, size);
    binary_insertion_sort_desc(array, size);
    show_array(outputFile, array, size);

    cout << "Завдання 3 виконано. Відсортований масив записано у " << outputFile << endl; // запис результату
}
// Основна функція програми
int main() {
    SetConsoleOutputCP(65001); // Встановлюємо UTF-8 для правильної роботи з українською/російською мовою
// Меню для вибору задачі
    int choice;
    do {
        cout << "\n========== МЕНЮ ==========" << endl;
        cout << "1. Зсув елементів масиву вліво" << endl;
        cout << "2. Пошук максимуму в впорядкованих стовпцях матриці" << endl;
        cout << "3. Сортування методом двійкових вставок (за спаданням)" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: runTask1(); break;
        case 2: runTask2(); break;
        case 3: runTask3(); break;
        case 0: cout << "Завершення програми." << endl; break;
        default: cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }

    } while (choice != 0);

    return 0; // Завершення програми
}
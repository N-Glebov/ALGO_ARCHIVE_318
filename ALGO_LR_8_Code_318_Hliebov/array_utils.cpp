#include "array_utils.h"      // Підключення заголовочного файлу з прототипами функцій для роботи з масивами
#include <fstream>            // Підключення бібліотеки для роботи з файлами
using namespace std;

// Функція зчитує одновимірний масив із файлу
void get_array(const string& filename, double arr[], int& size) {
    ifstream fin(filename);     // Відкриваємо файл для читання
    const int MAX = 20;         // Максимальний допустимий розмір масиву
    size = 0;                   // Початкове значення розміру

    if (fin.is_open()) {
        // Зчитуємо розмір масиву з файлу
        if (!(fin >> size) || size < 1 || size > MAX) {
            size = 0;           // Якщо помилка у форматі або розмір не у дозволених межах — скидаємо
            return;
        }

        // Зчитуємо елементи масиву
        for (int i = 0; i < size; ++i) {
            if (!(fin >> arr[i])) {
                size = 0;       // Якщо помилка при зчитуванні — скидаємо
                return;
            }
        }
        fin.close();            // Закриваємо файл
    }
}

// Функція виводить масив у вказаний файл
void show_array(const string& filename, const double arr[], int size) {
    ofstream fout(filename);    // Відкриваємо файл для запису

    if (fout.is_open()) {
        for (int i = 0; i < size; ++i)
            fout << arr[i] << " ";   // Виводимо елементи масиву у файл через пробіл
        fout << endl;                // Новий рядок після виводу всіх елементів
        fout.close();                // Закриваємо файл
    }
}

// Функція зсуває всі елементи масиву вліво на 1 позицію і останній елемент встановлює як 0
void shift_array_left(double arr[], int size) {
    if (size < 1) return;       // Перевірка на нульовий/від’ємний розмір — нічого не робимо

    if (size >= 2) {
        for (int i = 0; i < size - 1; ++i)
            arr[i] = arr[i + 1];    // Зсуваємо елементи вліво
    }

    arr[size - 1] = 0;          // Останній елемент встановлюємо рівним 0
}

// Сортування масиву методом двійкових вставок за спаданням
void binary_insertion_sort_desc(double arr[], int size) {
    for (int i = 1; i < size; ++i) {
        double key = arr[i];         // Зберігаємо поточний елемент для вставки
        int left = 0, right = i - 1;

        // Бінарний пошук позиції для вставки
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] < key)      // Шукаємо позицію так, щоб результат був у порядку спадання
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Зсуваємо елементи вправо, щоб звільнити місце для вставки
        for (int j = i - 1; j >= left; --j)
            arr[j + 1] = arr[j];

        arr[left] = key;            // Вставляємо елемент на потрібну позицію
    }
}
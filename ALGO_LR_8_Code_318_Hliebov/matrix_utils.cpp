#include "matrix_utils.h" // Підключення заголовків
#include <fstream> // Підключення заголовків
// Функція get_matrix
void get_matrix(const string& filename, double matrix[][20], int& rows, int& cols) {
    ifstream fin(filename);
    if (fin.is_open()) {
        fin >> rows >> cols;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                fin >> matrix[i][j];
        fin.close();
    }
}
// Початок функції перевірки впорядкованості стовпця
bool is_column_ordered(double matrix[][20], int rows, int col) {
    bool ascending = true, descending = true;
    for (int i = 0; i < rows - 1; ++i) {
        if (matrix[i][col] > matrix[i + 1][col]) ascending = false;
        if (matrix[i][col] < matrix[i + 1][col]) descending = false;
    }
    return ascending || descending; // Якщо стовпець повністю зростає або спадає — він вважається впорядкованим.
}
// Функція знаходження максимуму серед впорядкованих стовпців
double max_ordered_columns(double matrix[][20], int rows, int cols) {
    double maxVal = -1e9; // Дуже мале значення для ініціалізації
    bool found = false; // Чи знайдено хоча б один впорядкований стовпець
    for (int j = 0; j < cols; ++j) { // Перевірка всіх сусідніх елементів у стовпці: //  Функція знаходження максимуму серед впорядкованих стовпців
        if (is_column_ordered(matrix, rows, j)) { // Перебираємо всі стовпці.
            for (int i = 0; i < rows; ++i)
                if (matrix[i][j] > maxVal) {
                    maxVal = matrix[i][j];
                    found = true; 
                }
        }
    }
    return found ? maxVal : 0; //  Якщо знайдено хоча б один впорядкований стовпець — повертаємо знайдений максимум. Якщо жоден стовпець не впорядкований — повертаємо 0

}
#pragma once // Директива #pragma once
#include <string> // Підключення бібліотеки <string> і директива using namespace std
using namespace std;

void get_matrix(const string& filename, double matrix[][20], int& rows, int& cols); // Оголошення функції get_matrix
double max_ordered_columns(double matrix[][20], int rows, int cols); // Оголошення функції max_ordered_columns
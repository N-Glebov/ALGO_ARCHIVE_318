#pragma once
#include <string>
using namespace std;

void get_array(const string& filename, double arr[], int& size); //  Оголошення функції зчитування одновимірного масиву з файлу
void show_array(const string& filename, const double arr[], int size); // Оголошення функції для запису масиву у файл
void shift_array_left(double arr[], int size); // Оголошення функції зсуву масиву вліво
void binary_insertion_sort_desc(double arr[], int size); // Оголошення функції сортування методом двійкових вставок за спаданням
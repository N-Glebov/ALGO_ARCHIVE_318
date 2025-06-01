#include "array_utils.h"      // ϳ��������� ������������� ����� � ����������� ������� ��� ������ � ��������
#include <fstream>            // ϳ��������� �������� ��� ������ � �������
using namespace std;

// ������� ����� ����������� ����� �� �����
void get_array(const string& filename, double arr[], int& size) {
    ifstream fin(filename);     // ³�������� ���� ��� �������
    const int MAX = 20;         // ������������ ���������� ����� ������
    size = 0;                   // ��������� �������� ������

    if (fin.is_open()) {
        // ������� ����� ������ � �����
        if (!(fin >> size) || size < 1 || size > MAX) {
            size = 0;           // ���� ������� � ������ ��� ����� �� � ���������� ����� � �������
            return;
        }

        // ������� �������� ������
        for (int i = 0; i < size; ++i) {
            if (!(fin >> arr[i])) {
                size = 0;       // ���� ������� ��� ��������� � �������
                return;
            }
        }
        fin.close();            // ��������� ����
    }
}

// ������� �������� ����� � �������� ����
void show_array(const string& filename, const double arr[], int size) {
    ofstream fout(filename);    // ³�������� ���� ��� ������

    if (fout.is_open()) {
        for (int i = 0; i < size; ++i)
            fout << arr[i] << " ";   // �������� �������� ������ � ���� ����� �����
        fout << endl;                // ����� ����� ���� ������ ��� ��������
        fout.close();                // ��������� ����
    }
}

// ������� ����� �� �������� ������ ���� �� 1 ������� � ������� ������� ���������� �� 0
void shift_array_left(double arr[], int size) {
    if (size < 1) return;       // �������� �� ��������/�䒺���� ����� � ����� �� ������

    if (size >= 2) {
        for (int i = 0; i < size - 1; ++i)
            arr[i] = arr[i + 1];    // ������� �������� ����
    }

    arr[size - 1] = 0;          // ������� ������� ������������ ����� 0
}

// ���������� ������ ������� �������� ������� �� ���������
void binary_insertion_sort_desc(double arr[], int size) {
    for (int i = 1; i < size; ++i) {
        double key = arr[i];         // �������� �������� ������� ��� �������
        int left = 0, right = i - 1;

        // �������� ����� ������� ��� �������
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] < key)      // ������ ������� ���, ��� ��������� ��� � ������� ��������
                right = mid - 1;
            else
                left = mid + 1;
        }

        // ������� �������� ������, ��� �������� ���� ��� �������
        for (int j = i - 1; j >= left; --j)
            arr[j + 1] = arr[j];

        arr[left] = key;            // ���������� ������� �� ������� �������
    }
}
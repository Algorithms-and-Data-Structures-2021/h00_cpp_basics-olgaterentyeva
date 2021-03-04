#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs != nullptr && rhs != nullptr) {
        int temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_cols > 0 && num_rows > 0) {
        int **arr = new int *[num_rows];
        for (int i = 0; i < num_rows; i++) {
            arr[i] = new int[num_cols];
        }
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                arr[i][j] = init_value;
            }
        }
        return arr;
    }
    return nullptr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (arr_2d_target != nullptr && arr_2d_source != nullptr) {
        if (num_rows > 0 && num_cols > 0) {
            for (int i = 0; i < num_rows; i++) {
                for (int j = 0; j < num_cols; j++) {
                    arr_2d_source[i][j] = arr_2d_target[i][j];
                }
            }
            return true;
        }
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int i = 0; i < arr.size() / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1 - i] = temp;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin != nullptr && arr_end != nullptr) {
        int temp;
        while (arr_begin <= arr_end) {
            temp = *arr_begin;
            *arr_begin = *arr_end;
            *arr_end = temp;
            ++arr_begin;
            --arr_end;
        }
    }
}


// Задание 6
int *find_max_element(int *arr, int size) {
    if (arr != nullptr && size > 0) {
        int *max = arr;
        arr++;
        for (int i = 1; i < size; i++, arr++) {
            if (*max < *arr) {
                max = arr;
            }
        }
        return max;
    }
    return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {

    vector<int> result;
    for (int el : arr) {
        if (el % 2 != 0) {
            result.push_back(el);
        }
    }
    if (arr.empty()) {
        return {};
    }
    return result;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> arr_c;
    sort(arr_a.begin(), arr_a.end());
    sort(arr_b.begin(), arr_b.end());
    for (int i : arr_a) {
        for (int j : arr_b) {
            if (i == j) {
                if (!arr_c.empty()) {
                    bool flag = true;
                    for (int x : arr_c) {
                        if (i == x) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) arr_c.push_back(i);
                }
                else arr_c.push_back(i);
            }
        }
    }
    return arr_c;
}

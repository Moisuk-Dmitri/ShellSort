#include "Sort.h"

void Sort::ShellSort(std::vector<int>& arr) {       // Алгоритм сортировки Шелла
    for (size_t interval = arr.size() / 2; interval > 0; interval /= 2) {
        for (size_t i = interval; i < arr.size(); i += 1) {
            int temp = arr[i];
            size_t j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}
#include "Sort.h"

void Sort::ShellSort(std::vector<int>& arr) {       // Shell sorting algorithm
    for (size_t interval = arr.size() / 2; interval > 0; interval /= 2) {
        for (size_t i = interval; i < arr.size(); ++i) {
            for (size_t j = i; j >= interval && arr[j - interval] > arr[j]; j -= interval) {
                std::swap(arr[j - interval], arr[j]);
            }
        }
    }
}
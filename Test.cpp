#include "InOutStream.h"
#include "Test.h"
#include "Sort.h"

void runTest()		// Tests with two prepared arrays from files test_orig_#.txt and test_sorted.txt
{
	std::vector<int> arr_orig;
	inputArrFile(arr_orig, "test_orig_1.txt");

	std::vector<int> arr_sorted;
	inputArrFile(arr_sorted, "test_sorted.txt");

	auto begin = std::chrono::steady_clock::now();
	Sort::ShellSort(arr_orig);
	auto end = std::chrono::steady_clock::now();

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	if (arr_orig == arr_sorted) {
		std::cout << "[TEST 1 SUCCESSFUL]\n Elapsed time: " << elapsed_ms.count() << " nanoseconds";
	}
	else {
		std::cout << "[TEST 1 FAILED]\n";
		return;
	}

	arr_orig.clear();
	inputArrFile(arr_orig, "test_orig_2.txt");

	begin = std::chrono::steady_clock::now();
	Sort::ShellSort(arr_orig);
	end = std::chrono::steady_clock::now();

	elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	if (arr_orig == arr_sorted) {
		std::cout << "[TEST 2 SUCCESSFUL]\n Elapsed time: " << elapsed_ms.count() << " nanoseconds";
	}
	else {
		std::cout << "[TEST 2 FAILED]\n";
		return;
	}

	arr_orig.clear();
	inputArrFile(arr_orig, "test_orig_3.txt");

	begin = std::chrono::steady_clock::now();
	Sort::ShellSort(arr_orig);
	end = std::chrono::steady_clock::now();

	elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	if (arr_orig == arr_sorted) {
		std::cout << "[TEST 3 SUCCESSFUL]\n Elapsed time: " << elapsed_ms.count() << " nanoseconds\n";
	}
	else {
		std::cout << "[TEST 3 FAILED]\n";
		return;
	}
}

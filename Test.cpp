#include "InOutStream.h"
#include "Test.h"
#include "Sort.h"

void runTest()		// Test with two prepared arrays from files
{
	std::vector<int> arr_orig;
	inputArrFile(arr_orig, "test_orig.txt");

	std::vector<int> arr_sorted;
	inputArrFile(arr_sorted, "test_sorted.txt");

	Sort::ShellSort(arr_orig);
	if (arr_orig == arr_sorted) {
		std::cout << "[TEST SUCCESSFUL]\n";
		return;
	}
	else {
		std::cout << "[TEST FAILED]\n";
		return;
	}
}

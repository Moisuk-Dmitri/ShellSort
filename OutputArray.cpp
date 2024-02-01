#include "InOutStream.h"

void outputArrConsole(std::vector<int> const& arr){
	if (arr.empty()) {
		throw std::invalid_argument("[EMPTY ARRAY]\n");
	}

	std::cout << "\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void outputArrConsole(std::vector<int> const& arr, std::vector<int> const& arr_orig) {		//
	if (arr_orig.empty()) {
		throw std::invalid_argument("[EMPTY ARRAY]\n");
	}
	if (arr.empty()) {
		throw std::invalid_argument("[EMPTY ARRAY]\n");
	}

	std::cout << "\n";
	std::cout << "Original array:\n";
	for (int i = 0; i < arr_orig.size(); i++) {
		std::cout << arr_orig[i] << " ";
	}
	std::cout << "\nSorted array:\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void outputArrFile(std::vector<int> const& arr) {
	if (arr.empty()) {
		throw std::invalid_argument("[EMPTY ARRAY]\n");
	}

	std::cout << "\n";
	std::ofstream file;
	std::string name;
	do {
		std::cout << "Enter file name:\n";
		std::cin >> name;
		if (std::filesystem::is_regular_file(name) &&
			name != "test_sorted.txt" &&
			name != "test_orig_1.txt" &&
			name != "test_orig_2.txt" &&
			name != "test_orig_3.txt") {
			file.open(name);
			if (!file.is_open()) {
				throw std::invalid_argument("[FILE CANT BE OPENED]\n");
			}
			break;
		}
		else {
			std::cerr << "\n[INVALID FILE NAME]\n";
		}
	} while (true);

	for (int i = 0; i < arr.size(); i++) {
		file << arr[i] << " ";
	}

	if (file.is_open()) {
		file.close();
	}

	std::cout << "[FILE OUTPUT SUCCESSFUL]\n";
}

void outputArrFile(std::vector<int> const& arr, std::vector<int> const& arr_orig) {
	if (arr.empty()) {
		throw std::invalid_argument("[EMPTY ARRAY]\n");
	}

	std::cout << "\n";
	std::ofstream file;
	std::string name;
	do {
		std::cout << "Enter file name:\n";
		std::cin >> name;
		if (std::filesystem::is_regular_file(name) &&
			name != "test_sorted.txt" &&
			name != "test_orig_1.txt" &&
			name != "test_orig_2.txt" &&
			name != "test_orig_3.txt") {
			file.open(name);
			if (!file.is_open()) {
				throw std::invalid_argument("[FILE CANT BE OPENED]\n");
			}
			break;
		}
		else {
			std::cerr << "\n[INVALID FILE NAME]\n";
		}
	} while (true);

	file << "Original array:\n";
	for (int i = 0; i < arr.size(); i++) {
		file << arr_orig[i] << " ";
	}
	file << "\nSorted array:\n";
	for (int i = 0; i < arr.size(); i++) {
		file << arr[i] << " ";
	}

	if (file.is_open()) {
		file.close();
	}

	std::cout << "[FILE OUTPUT SUCCESSFUL]\n";
}

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
			name != "test_orig.txt" &&
			name != "test_sorted.txt") {
			file.open(name);
		}
		else {
			std::cerr << "\n[INVALID FILE NAME]\n";
		}
	} while (!std::filesystem::is_regular_file(name) ||
		name == "test_orig.txt" ||
		name == "test_sorted.txt");

	for (int i = 0; i < arr.size(); i++) {
		file << arr[i] << " ";
	}

	if (file.is_open()) {
		file.close();
	}
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
			name != "test_orig.txt" &&
			name != "test_sorted.txt") {
			file.open(name);
		}
		else {
			std::cerr << "\n[INVALID FILE NAME]\n";
		}
	} while (!std::filesystem::is_regular_file(name) ||
		name == "test_orig.txt" ||
		name == "test_sorted.txt");

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
}

#include "InOutStream.h"

void outputArrConsole(std::vector<int> const& arr){
	if (arr.empty()) {
		throw std::invalid_argument("[������ ������]\n");
	}

	std::cout << "\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void outputArrConsole(std::vector<int> const& arr, std::vector<int> const& arr_orig) {		//
	if (arr_orig.empty()) {
		throw std::invalid_argument("[������ ������]\n");
	}
	if (arr.empty()) {
		throw std::invalid_argument("[������ ������]\n");
	}

	std::cout << "\n";
	std::cout << "����������� ������:\n";
	for (int i = 0; i < arr_orig.size(); i++) {
		std::cout << arr_orig[i] << " ";
	}
	std::cout << "\n��������������� ������:\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void outputArrFile(std::vector<int> const& arr) {
	if (arr.empty()) {
		throw std::invalid_argument("[������ ������]\n");
	}

	std::cout << "\n";
	std::ofstream file;
	std::string name;
	do {
		std::cout << "������� ��� �����:\n";
		std::cin >> name;
		if (std::filesystem::is_regular_file(name) &&
			name != "test_orig.txt" &&
			name != "test_sorted.txt") {
			file.open(name);
		}
		else {
			std::cerr << "\n[������������ ��� �����]\n";
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
		throw std::invalid_argument("[������ ������]\n");
	}

	std::cout << "\n";
	std::ofstream file;
	std::string name;
	do {
		std::cout << "������� ��� �����:\n";
		std::cin >> name;
		if (std::filesystem::is_regular_file(name) &&
			name != "test_orig.txt" &&
			name != "test_sorted.txt") {
			file.open(name);
		}
		else {
			std::cerr << "\n[������������ ��� �����]\n";
		}
	} while (!std::filesystem::is_regular_file(name) ||
		name == "test_orig.txt" ||
		name == "test_sorted.txt");

	file << "����������� ������:\n";
	for (int i = 0; i < arr.size(); i++) {
		file << arr_orig[i] << " ";
	}
	file << "\n��������������� ������:\n";
	for (int i = 0; i < arr.size(); i++) {
		file << arr[i] << " ";
	}

	if (file.is_open()) {
		file.close();
	}
}

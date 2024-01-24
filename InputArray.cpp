#include "InOutStream.h"

void inputArrManual(std::vector<int>& arr){
	std::cout << "\n";
	int size = 0;
	do {
		std::cout << "Enter array size:\n";
		input(size);
		if (size < 1) {
			std::cerr << "[INVALID ARRAY SIZE]\n";
		}
	} while (size < 1);

	int val;
	for (int i = 0; i < size; i++) {
		std::cout << "Array[" << i + 1 << "] = ";
		input(val);
		arr.push_back(val);
	}
	std::cout << "\n";
}

void inputArrFile(std::vector<int>& arr) {
	std::cout << "\n";
	std::ifstream file;

	std::string name;
	do {
		std::cout << "Enter file name:\n";
		std::cin >> name;
		if ((std::filesystem::is_regular_file(name))) {
			file.open(name);
			if (!file.is_open()) {
				throw std::invalid_argument("[FILE CANT BE OPENED]\n");
			}
			break;
		}
		else {
			throw std::invalid_argument("[INVALID FILE NAME]\n");
		}
	} while (true);

	int val = 0;
	while (file >> val) {
		arr.push_back(val);
	}

	if (file.is_open()) {
		file.close();
	}
}

void inputArrFile(std::vector<int>& arr, std::string name) {
	std::cout << "\n";
	std::ifstream file;

	if ((!std::filesystem::is_regular_file(name))) {
		throw std::invalid_argument("[INVALID FILE NAME]\n");
	}
	file.open(name);
	if (!file.is_open()) {
		throw std::invalid_argument("[FILE CANT BE OPENED]\n");
	}
	int val = 0;
	while (file >> val) {
		arr.push_back(val);
	}

	if (file.is_open()) {
		file.close();
	}
}

void inputArrRandom(std::vector<int>& arr){
	std::cout << "\n";
	int size = 0;
	do {
		std::cout << "Enter array size:\n";
		input(size);
		if (size < 1) {
			std::cerr << "[Invalid array size]\n";
		}
	} while (size < 1);

	srand(static_cast<int>(std::time(nullptr)));
	for (int i = 0; i < size; i++) {
		arr.push_back(std::rand() % 10000 - 5000);
	}
}

template <typename T>
void input(T& obj) {		// Value correctness check 
	while (!(std::cin >> obj) || (std::cin.peek() != '\n')) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Enter value once more: ";
	}
}
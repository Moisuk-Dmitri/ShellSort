#include "InOutStream.h"

void inputArrManual(std::vector<int>& arr){
	std::cout << "\n";
	int size = 0;
	do {
		std::cout << "������� ������ �������:\n";
		input(size);
		if (size < 1) {
			std::cerr << "[������������ ������ �������]\n";
		}
	} while (size < 1);

	int val;
	for (int i = 0; i < size; i++) {
		std::cout << "������[" << i + 1 << "] = ";
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
		std::cout << "������� ��� �����:\n";
		std::cin >> name;
		if ((std::filesystem::is_regular_file(name))) {
			file.open(name);
		}
	} while (!std::filesystem::is_regular_file(name));

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
		throw std::invalid_argument("[������������ ��� �����]\n");
	}
	file.open(name);
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
		std::cout << "������� ������ �������:\n";
		input(size);
		if (size < 1) {
			std::cerr << "[������������ ������ �������]\n";
		}
	} while (size < 1);

	srand(static_cast<int>(std::time(nullptr)));
	for (int i = 0; i < size; i++) {
		arr.push_back(std::rand() % 10000 - 5000);
	}
}

template <typename T>
void input(T& obj) {		// �������� ������������ �������� ��������
	while (!(std::cin >> obj) || (std::cin.peek() != '\n')) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "������� �������� ��������: ";
	}
}
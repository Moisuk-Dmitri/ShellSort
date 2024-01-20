#include "InOutStream.h"

void outputArrConsole(std::vector<int> const& arr){
	if (arr.empty()) {
		throw std::invalid_argument("[œ”—“Œ… Ã¿——»¬]\n");
	}

	std::cout << "\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void outputArrConsole(std::vector<int> const& arr, std::vector<int> const& arr_orig) {		//
	if (arr_orig.empty()) {
		throw std::invalid_argument("[œ”—“Œ… Ã¿——»¬]\n");
	}
	if (arr.empty()) {
		throw std::invalid_argument("[œ”—“Œ… Ã¿——»¬]\n");
	}

	std::cout << "\n";
	std::cout << "»ÁÌ‡˜‡Î¸Ì˚È Ï‡ÒÒË‚:\n";
	for (int i = 0; i < arr_orig.size(); i++) {
		std::cout << arr_orig[i] << " ";
	}
	std::cout << "\nŒÚÒÓÚËÓ‚‡ÌÌ˚È Ï‡ÒÒË‚:\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void outputArrFile(std::vector<int> const& arr) {
	if (arr.empty()) {
		throw std::invalid_argument("[œ”—“Œ… Ã¿——»¬]\n");
	}

	std::cout << "\n";
	std::ofstream file;
	std::string name;
	do {
		std::cout << "¬‚Â‰ËÚÂ ËÏˇ Ù‡ÈÎ‡:\n";
		std::cin >> name;
		if (std::filesystem::is_regular_file(name) &&
			name != "test_orig.txt" &&
			name != "test_sorted.txt") {
			file.open(name);
		}
		else {
			std::cerr << "\n[Õ≈ƒŒœ”—“»ÃŒ≈ »Ãﬂ ‘¿…À¿]\n";
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
		throw std::invalid_argument("[œ”—“Œ… Ã¿——»¬]\n");
	}

	std::cout << "\n";
	std::ofstream file;
	std::string name;
	do {
		std::cout << "¬‚Â‰ËÚÂ ËÏˇ Ù‡ÈÎ‡:\n";
		std::cin >> name;
		if (std::filesystem::is_regular_file(name) &&
			name != "test_orig.txt" &&
			name != "test_sorted.txt") {
			file.open(name);
		}
		else {
			std::cerr << "\n[Õ≈ƒŒœ”—“»ÃŒ≈ »Ãﬂ ‘¿…À¿]\n";
		}
	} while (!std::filesystem::is_regular_file(name) ||
		name == "test_orig.txt" ||
		name == "test_sorted.txt");

	file << "»ÁÌ‡˜‡Î¸Ì˚È Ï‡ÒÒË‚:\n";
	for (int i = 0; i < arr.size(); i++) {
		file << arr_orig[i] << " ";
	}
	file << "\nŒÚÒÓÚËÓ‚‡ÌÌ˚È Ï‡ÒÒË‚:\n";
	for (int i = 0; i < arr.size(); i++) {
		file << arr[i] << " ";
	}

	if (file.is_open()) {
		file.close();
	}
}

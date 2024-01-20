#include <iostream>
#include <vector>
#include <locale>
#include <typeinfo>
#include <exception>
#include "Sort.h"
#include "InOutStream.h"
#include "Test.h"

enum { EXIT, IN, OUT, RUN_TEST };
enum { IN_EXIT, IN_MANUAL, IN_FILE, IN_RANDOM };
enum { OUT_EXIT, OUT_MANUAL, OUT_FILE };

int main() {
	setlocale(LC_ALL, "rus");

	std::vector<int> arr_orig;		// Изначальный массив
	std::vector<int> arr;		// Отсортированный массив

	int choice = -1;
	do {
		std::cout << "\n1 - Ввод\n"
			<< "2 - Вывод\n"
			<< "3 - Тест\n"
			<< "0 - Выход\n";
		input(choice);

		switch (choice) {
		case IN: {		// Блок ввода массива
			int choice_in = -1;

			do {
				try {
					std::cout << "\n1 - Ввод с клавиатуры\n"
						<< "2 - Ввод с файла\n"
						<< "3 - Ввод рандомных чисел\n"
						<< "0 - Выход\n";
					input(choice_in);
					switch (choice_in) {
					case IN_MANUAL:		// Ввод с клавиатуры
						arr.clear();
						inputArrManual(arr);
						break;
					case IN_FILE:		// Ввод с файла
						arr.clear();
						inputArrFile(arr);
						break;
					case IN_RANDOM:		// Ввод рандомных чисел
						arr.clear();
						inputArrRandom(arr);
						break;
					case IN_EXIT:		// Выход с блока ввода
						break;
					default:
						std::cerr << "\n[НЕДОПУСТИМЫЙ ВЫБОР]\n";
						choice_in = -1;
					}
					if (choice_in != IN_EXIT && choice_in != -1) {		// Сортировка заполненного массива
						arr_orig = arr;
						if (arr.empty() || arr_orig.empty()) {
							throw std::invalid_argument("[ПУСТОЙ МАССИВ]\n");
						}
						std::cout << "Изначальный массив:";
						outputArrConsole(arr_orig);
						Sort::ShellSort(arr);
						std::cout << "Отсортированный массив:";
						outputArrConsole(arr);
					}
				}
				catch (std::invalid_argument e) {
					std::cerr << e.what();
					choice_in = -1;
				}
				catch (...) {
					std::cerr << "[ОШИБКА ВВОДА]\n";
					choice_in = -1;
				}
			} while (choice_in != IN_EXIT &&
				choice_in != IN_MANUAL &&
				choice_in != IN_FILE &&
				choice_in != IN_RANDOM);
		}
			   break;
		case OUT: {		// Блок вывода массива
			int choice_out = 0;

			do {
				std::cout << "\n1 - Вывод в консоль\n"
					<< "2 - Вывод в файл\n"
					<< "0 - Выход\n";
				input(choice_out);

				try {
					switch (choice_out) {
					case OUT_MANUAL:		// Вывод на консоль
						outputArrConsole(arr, arr_orig);
						break;
					case OUT_FILE:		// Вывод в файл
						outputArrFile(arr, arr_orig);
						break;
					case OUT_EXIT:		// Выход из блока вывода
						break;
					default:
						std::cerr << "\n[НЕДОПУСТИМЫЙ ВЫБОР]\n";
						choice_out = -1;
					}
				}
				catch (std::invalid_argument e) {
					std::cerr << e.what();
					choice_out = -1;
				}
				catch (...) {
					std::cerr << "[ОШИБКА ВЫВОДА]\n";
					choice_out = -1;
				}
			} while (choice_out != OUT_EXIT);
		}
				break;
		case RUN_TEST:		// Блок тестов
			try {
				runTest();
			}
			catch (std::invalid_argument e) {
				std::cerr << e.what();
			}
			catch (...) {
				std::cerr << "[ОШИБКА ТЕСТИРОВАНИЯ]\n";
			}
			break;
		case EXIT:		// Выход из программы
			break;
		default:
			std::cerr << "\n[НЕДОПУСТИМЫЙ ВЫБОР]\n";
			choice = -1;
			break;
		}
	} while (choice != EXIT);

	return 1;
}
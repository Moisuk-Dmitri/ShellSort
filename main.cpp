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

	std::vector<int> arr_orig;
	std::vector<int> arr;

	int choice = -1;
	do {
		std::cout << "\n1 - ����\n"
			<< "2 - �����\n"
			<< "3 - ����\n"
			<< "0 - �����\n";
		input(choice);

		switch (choice) {
		case IN: { //
			int choice_in = -1;

			do {
				try {
					std::cout << "\n1 - ���� � ����������\n"
						<< "2 - ���� � �����\n"
						<< "3 - ���� ��������� �����\n"
						<< "0 - �����\n";
					input(choice_in);
					switch (choice_in) {
					case IN_MANUAL: //
						arr.clear();
						inputArrManual(arr);
						break;
					case IN_FILE: //
						arr.clear();
						inputArrFile(arr);
						break;
					case IN_RANDOM: //
						arr.clear();
						inputArrRandom(arr);
						break;
					case IN_EXIT:
						break;
					default: //
						std::cerr << "\n[������������ �����]\n";
						choice_in = -1;
					}
					if (choice_in != IN_EXIT && choice_in != -1) {
						arr_orig = arr;
						if (arr.empty() || arr_orig.empty()) {
							throw std::invalid_argument("[������ ������]\n");
						}
						std::cout << "����������� ������:";
						outputArrConsole(arr_orig);
						Sort::ShellSort(arr);
						std::cout << "��������������� ������:";
						outputArrConsole(arr);
					}
				}
				catch (std::invalid_argument e) {
					std::cerr << e.what();
					choice_in = -1;
				}
				catch (...) {
					std::cerr << "[������ �����]\n";
					choice_in = -1;
				}
			} while (choice_in != IN_EXIT &&
				choice_in != IN_MANUAL &&
				choice_in != IN_FILE &&
				choice_in != IN_RANDOM);
		}
			   break;
		case OUT: {//
			int choice_out = 0;

			do {
				std::cout << "\n1 - ����� � �������\n"
					<< "2 - ����� � ����\n"
					<< "0 - �����\n";
				input(choice_out);

				try {
					switch (choice_out) {
					case OUT_MANUAL: //
						outputArrConsole(arr, arr_orig);
						break;
					case OUT_FILE: //
						outputArrFile(arr, arr_orig);
						break;
					case OUT_EXIT: //
						break;
					default: //
						std::cerr << "\n[������������ �����]\n";
						choice_out = -1;
					}
				}
				catch (std::invalid_argument e) {
					std::cerr << e.what();
					choice_out = -1;
				}
				catch (...) {
					std::cerr << "[������ ������]\n";
					choice_out = -1;
				}
			} while (choice_out != OUT_EXIT);
		}
				break;
		case RUN_TEST: //
			try {
				runTest();
			}
			catch (std::invalid_argument e) {
				std::cerr << e.what();
			}
			catch (...) {
				std::cerr << "[������ ������������]\n";
			}
			break;
		case EXIT: //
			break;
		default:
			std::cerr << "\n[������������ �����]\n";
			choice = -1;
			break;//
		}
	} while (choice != EXIT);

	return 1;
}
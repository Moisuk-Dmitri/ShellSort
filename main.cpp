#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include "Sort.h"
#include "InOutStream.h"
#include "Test.h"

enum { EXIT, IN, OUT, RUN_TEST };
enum { IN_EXIT, IN_MANUAL, IN_FILE, IN_RANDOM };
enum { OUT_EXIT, OUT_MANUAL, OUT_FILE };

int main() {
	std::vector<int> arr_orig;		// Original array
	std::vector<int> arr;		// sorted array

	int choice = -1;
	do {
		std::cout << "\n1 - Array input\n"
			<< "2 - Array output\n"
			<< "3 - Run test\n"
			<< "0 - Exit\n";
		input(choice);

		switch (choice) {
		case IN: {		// Input array module
			int choice_in = -1;

			do {
				try {
					std::cout << "\n1 - Enter manually\n"
						<< "2 - Enter from file\n"
						<< "3 - Enter random\n"
						<< "0 - Exit\n";
					input(choice_in);
					switch (choice_in) {
					case IN_MANUAL:		// Enter array using keyboard
						arr.clear();
						inputArrManual(arr);
						break;
					case IN_FILE:		// Enter array from file
						arr.clear();
						inputArrFile(arr);
						break;
					case IN_RANDOM:		// Enter random numbers into array
						arr.clear();
						inputArrRandom(arr);
						break;
					case IN_EXIT:		// Exit from input module
						break;
					default:
						std::cerr << "\n[INVALID CHOICE]\n";
						choice_in = -1;
					}
					if (choice_in != IN_EXIT && choice_in != -1) {		// Array sort module
						arr_orig = arr;
						if (arr.empty() || arr_orig.empty()) {
							throw std::invalid_argument("[EMPTY ARRAY]\n");
						}
						std::cout << "Original array:";
						outputArrConsole(arr_orig);
						Sort::ShellSort(arr);
						std::cout << "Sorted array:";
						outputArrConsole(arr);
					}
				}
				catch (std::invalid_argument e) {
					std::cerr << e.what();
					choice_in = -1;
				}
				catch (...) {
					std::cerr << "[ENTER ERROR]\n";
					choice_in = -1;
				}
			} while (choice_in != IN_EXIT &&
				choice_in != IN_MANUAL &&
				choice_in != IN_FILE &&
				choice_in != IN_RANDOM);
		}
			   break;
		case OUT: {		// Output array module
			int choice_out = 0;

			do {
				std::cout << "\n1 - Print into console\n"
					<< "2 - Print into file\n"
					<< "0 - Exit\n";
				input(choice_out);

				try {
					switch (choice_out) {
					case OUT_MANUAL:		// Console array output
						outputArrConsole(arr, arr_orig);
						break;
					case OUT_FILE:		// File array output
						outputArrFile(arr, arr_orig);
						break;
					case OUT_EXIT:		// Exit from output module
						break;
					default:
						std::cerr << "\n[INVALID CHOICE]\n";
						choice_out = -1;
					}
				}
				catch (std::invalid_argument e) {
					std::cerr << e.what();
					choice_out = -1;
				}
				catch (...) {
					std::cerr << "[OUTPUT ERROR]\n";
					choice_out = -1;
				}
			} while (choice_out != OUT_EXIT);
		}
				break;
		case RUN_TEST:		// Test module
			try {
				runTest();
			}
			catch (std::invalid_argument e) {
				std::cerr << e.what();
			}
			catch (...) {
				std::cerr << "[TEST ERROR]\n";
			}
			break;
		case EXIT:		// Exit from program
			break;
		default:
			std::cerr << "\n[INVALID CHOICE]\n";
			choice = -1;
			break;
		}
	} while (choice != EXIT);

	return 1;
}
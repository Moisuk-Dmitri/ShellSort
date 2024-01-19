#ifndef IN_OUT_STREAM //
#define IN_OUT_STREAM

#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <cstdlib>

template <typename T>
void input(T& obj);
void inputArrManual(std::vector<int>&); //
void inputArrFile(std::vector<int>&); //
void inputArrFile(std::vector<int>&, std::string); //
void inputArrRandom(std::vector<int>&); //
void outputArrConsole(std::vector<int> const&); //
void outputArrConsole(std::vector<int> const&, std::vector<int> const&); //
void outputArrFile(std::vector<int> const&); //
void outputArrFile(std::vector<int> const&, std::vector<int> const&); //

#endif
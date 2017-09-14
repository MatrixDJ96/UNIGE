#pragma once

#include <iostream>

int checkDim(const char* str1);
char* setStr(const char* str1);

char* insertStr(std::istream& is = std::cin, bool space = false);

char* intToStr(int integer);
int strToInt(const char* str);
double strToDouble(const char* str);

bool sameWord(const char* str1, const char* str2);

#pragma once

#include <string>
#include <cstring>
#include "Bit.h"

class Num
{
public:
	Num();
	~Num();
	Num(std::string first, std::string second);
	Num(std::string first, std::string second, int m);
	Bit *first_head;
	Bit *first_rear;
	Bit *second_head;
	Bit *second_rear;
	Bit *sum_head;
	Bit *sum_rear;
	int first_len;
	int second_len;
	bool change;		//第一第二个数是否交换了
	std::string Mul();
	std::string Add();
	std::string Sub();
	std::string Div();
	std::string Pow();
};


#pragma once
class Bit
{
public:
	Bit();
	~Bit();

	//r��ʵ����i���鲿
	double r, i;
	Bit *father;
	Bit *son;
};


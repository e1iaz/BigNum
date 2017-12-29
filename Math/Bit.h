#pragma once
class Bit
{
public:
	Bit();
	~Bit();

	//r是实部，i是虚部
	double r, i;
	Bit *father;
	Bit *son;
};


#include "stdafx.h"
#include "MathDll.h"
#include <stdexcept>
#include <iostream>

namespace MathDll {


	//c#的string和c++的char*一样，所以用char*来传递
	const char *MathDll::Mul(const char *first, const char *second)
	{
		std::string s1 = first;
		std::string s2 = second;
		Num *num = new Num(s1, s2);
		std::string s = num->Mul();
		char result[50000];
		memset(result, 0, sizeof(result));
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			result[i] = c;
		}
		const char *r = result;
		return r;
	}

	const char *MathDll::Add(const char *first, const char *second)
	{
		std::string s1 = first;
		std::string s2 = second;
		Num *num = new Num(s1, s2, 1);
		std::string s = num->Add();
		char result[50000];
		memset(result, 0, sizeof(result));
		for (int i = 0; i < s.size(); ++i) {
			result[i] = s[i];
		}
		const char *r = result;
		return r;
	}

	const char *MathDll::Sub(const char *first, const char *second)
	{
		std::string s1 = first;
		std::string s2 = second;
		Num *num = new Num(s1, s2, 1);
		std::string s = num->Sub();
		char result[50005];
		memset(result, 0, sizeof(result));
		for (int i = 0; i < s.size(); ++i) {
			result[i] = s[i];
		}
		const char *r = result;
		return r;
	}

	const char *MathDll::Div(const char *first, const char *second)
	{
		std::string s1 = first;
		std::string s2 = second;
		Num *num = new Num(s1, s2, 0);
		std::string s = num->Div();
		char result[50005];
		memset(result, 0, sizeof(result));
		for (int i = 0; i < s.size(); ++i) {
			result[i] = s[i];
		}
		const char *r = result;
		return r;
	}

	const char *MathDll::Pow(const char *first, const char *second)
	{
		std::string s1 = first;
		std::string s2 = second;
		Num *num = new Num(s1, s2, 0);
		std::string s = num->Pow();
		char result[50005];
		memset(result, 0, sizeof(result));
		for (int i = 0; i < s.size(); ++i) {
			result[i] = s[i];
		}
		const char *r = result;
		return r;
	}
}

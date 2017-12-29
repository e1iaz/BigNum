#pragma once

#include <string>
#include <cstring>
#include "Num.h"

#ifdef MATHDLL_EXPORTS
#define MATHDLL_API __declspec(dllexport) 
#else
#define MATHDLL_API __declspec(dllimport) 
#endif

namespace MathDll {
	class MathDll
	{
	public:

		//五个接口
		static MATHDLL_API const char *Mul(const char *first, const char *second);
		static MATHDLL_API const char *Add(const char *first, const char *second);
		static MATHDLL_API const char *Sub(const char *first, const char *second);
		static MATHDLL_API const char *Div(const char *first, const char *second);
		static MATHDLL_API const char *Pow(const char *first, const char *second);
	};
}
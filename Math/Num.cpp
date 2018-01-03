#include "stdafx.h"
#include "Num.h"
#include "Bit.h"
#include <iostream>

const double pi = acos(-1.0);
int len;
int res[500005];

Num::Num()
{
}

Num::~Num()
{
}

//乘法运算的构造函数
Num::Num(std::string first, std::string second)
{
	int n1 = first.size();
	int n2 = second.size();
	len = 1;
	while (len < 2 * n1 || len < 2 * n2) {
		len <<= 1;
	}

	int bit = 0;
	Bit *mark_a = new Bit();
	mark_a->r = first[n1 - 1] - '0';
	mark_a->i = 0;
	first_head = mark_a;
	mark_a->father = NULL;
	mark_a->son = NULL;
	for (int i = 1; i < n1; ++i) {
		Bit *temp = new Bit();
		temp->r = first[n1 - i - 1] - '0';
		temp->i = 0;
		temp->father = mark_a;
		temp->father->son = temp;
		temp->son = NULL;
		mark_a = temp;
	}
	bit = n1;
	while (bit < len) {
		Bit *temp = new Bit();
		temp->r = 0;
		temp->i = 0;
		temp->father = mark_a;
		temp->father->son = temp;
		temp->son = NULL;
		mark_a = temp;
		bit++;
	}

	Bit *mark_b = new Bit();
	mark_b->r = second[n2 - 1] - '0';
	mark_b->i = 0;
	second_head = mark_b;
	mark_b->father = NULL;
	mark_b->son = NULL;
	for (int i = 1; i < n2; ++i) {
		Bit *temp = new Bit();
		temp->r = second[n2 - i - 1] - '0';
		temp->i = 0;
		temp->father = mark_b;
		temp->father->son = temp;
		temp->son = NULL;
		mark_b = temp;
	}
	bit = n2;
	while (bit<len) {
		Bit *temp = new Bit();
		temp->r = 0;
		temp->i = 0;
		temp->father = mark_b;
		temp->father->son = temp;
		temp->son = NULL;
		mark_b = temp;
		bit++;
	}
}

//其他算法的构造函数
Num::Num(std::string first, std::string second, int m)
{
	first_len = first.size();
	second_len = second.size();

	//判断，加法减法可能要交换
	if (m) {
		change = false;
		if (first_len < second_len) {
			std::string s = first;
			first = second;
			second = s;
			change = true;
		}
	}
	Bit *Node = new Bit();
	Node->r = first[0] - '0';
	Node->father = NULL;
	Node->son = NULL;
	first_head = Node;
	for (int i = 1; i < first.size(); ++i) {
		Bit *temp = new Bit();
		temp->r = first[i] - '0';
		temp->father = Node;
		temp->father->son = temp;
		temp->son = NULL;
		Node = temp;
	}
	first_rear = Node;


	Node = new Bit();
	Node->r = second[0] - '0';
	Node->father = NULL;
	Node->son = NULL;
	second_head = Node;
	for (int i = 1; i < second.size(); ++i) {
		Bit *temp = new Bit();
		temp->r = second[i] - '0';
		temp->father = Node;
		temp->father->son = temp;
		temp->son = NULL;
		Node = temp;
	}
	second_rear = Node;
}

void Conv(Bit *a, Bit *b, int len);

//乘法运算  用的快速傅里叶变换
std::string Num::Mul()
{
	std::string result;
	Conv(this->first_head, this->second_head, len);
	Bit *a = first_head;
	memset(res, 0, sizeof(res));
	for (int i = 0; i < len; ++i) {
		res[i] = a->r + 0.5;
		a = a->son;
	}
	for (int i = 0; i < len; ++i) {
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	int high = 0;
	for (int i = len - 1; i >= 0; --i) {
		if (res[i]) {
			high = i;
			break;
		}
	}
	for (int i = high; i >= 0; --i) {
		result += (res[i] + '0');
	}
	return result;
}

//位相加
void add(Bit *first, Bit *second, Bit *result)
{
	result->r = first->r + second->r;
	result->i = first->i + second->i;
}

//位减法
void sub(Bit *first, Bit *second, Bit *result)
{
	result->r = first->r - second->r;
	result->i = first->i - second->i;
}

//位乘法
void mul(Bit *first, Bit *second, Bit *result)
{
	Bit *r = new Bit();
	r->r = first->r*second->r - first->i*second->i;
	r->i = first->i*second->r + first->r*second->i;
	result->r = r->r;
	result->i = r->i;
	delete r;
}

//交换
void swap(Bit *first, Bit *second)
{
	double i, r;
	i = first->i;
	r = first->r;
	first->r = second->r;
	first->i = second->i;
	second->r = r;
	second->i = i;
}

//雷德算法--倒位序
void rader(Bit *F, int len)
{
	int j = len >> 1;
	Bit *bit_j = F;
	for (int i = 0; i < j; ++i) {
		bit_j = bit_j->son;
	}
	Bit *bit_i = F;
	for (int i = 1; i < len - 1; ++i) {
		bit_i = bit_i->son;
		if (i < j) {
			swap(bit_i, bit_j);
		}
		int k = len >> 1;
		while (j >= k) {
			j -= k;
			for (int s = 0; s < k; ++s) {
				bit_j = bit_j->father;
			}
			k >>= 1;
		}
		if (j < k) {
			j += k;
			for (int s = 0; s < k; ++s) {
				bit_j = bit_j->son;
			}
		}
	}
}

//fft算法   还是不太懂实现方法，只是把string的代码改成了链表
void FFT(Bit *F, int, int t)
{
	rader(F, len);
	for (int h = 2; h <= len; h <<= 1) {		//分治后计算长度为h的DFT 
		Bit *wn = new Bit();		//单位复根e^(2*PI/m)用欧拉公式展开  
		wn->r = cos(-t * 2 * pi / h);
		wn->i = sin(-t * 2 * pi / h);
		for (int j = 0; j < len; j += h) {
			Bit *E = new Bit();			//旋转因子
			E->r = 1;
			E->i = 0;
			Bit *K = F;
			for (int k = 0; k < j; ++k) {
				K = K->son;
			}
			for (int k = j; k < j + h / 2; ++k) {
				Bit *u = new Bit();
				u->r = K->r;
				u->i = K->i;
				Bit *v = new Bit();
				v->r = K->r;
				v->i = K->i;
				Bit *H = K;
				for (int i = 0; i < h / 2; ++i) {
					H = H->son;
				}
				mul(E, H, v);
				add(u, v, K);		//蝴蝶合并操作 
				sub(u, v, H);
				mul(E, wn, E);		//更新旋转因子
				K = K->son;
				delete u;
				delete v;
			}
			delete E;
		}
		delete wn;
	}
	if (t == -1) {
		Bit *mark = F;
		for (int i = 0; i < len; ++i) {
			mark->r /= len;
			mark = mark->son;
		}
	}
}

//求卷积
void Conv(Bit *a, Bit *b, int len)
{
	FFT(a, len, 1);
	FFT(b, len, 1);
	Bit *temp_a = a;
	Bit *temp_b = b;
	for (int i = 0; i < len; ++i) {
		mul(temp_a, temp_b, temp_a);
		temp_a = temp_a->son;
		temp_b = temp_b->son;
	}
	temp_a = a;
	FFT(temp_a, len, -1);
}

//加法
std::string Num::Add()
{
	Bit *first_temp = first_rear;
	Bit *second_temp = second_rear;
	Bit *sum = new Bit();
	sum->r = 0;
	sum->son = NULL;
	sum->father = NULL;
	this->sum_head = sum;
	this->sum_rear = sum;

	//已经确定了第一个数比第二个数长度长
	while (first_temp != NULL) {
		if (second_temp != NULL) {
			sum->r += first_temp->r + second_temp->r;

			//先把上一位新建出来
			Bit *temp = new Bit();
			temp->father = NULL;
			temp->son = sum;
			sum->father = temp;

			//大于10进位
			if (sum->r >= 10) {
				temp->r += (int)sum->r / 10;
				sum->r = (int)sum->r % 10;;
			}
			sum = temp;
			second_temp = second_temp->father;
		}
		else {
			sum->r += first_temp->r;
			Bit *temp = new Bit();
			temp->father = NULL;
			temp->son = sum;
			sum->father = temp;
			if (sum->r >= 10) {
				temp->r += (int)sum->r / 10;
				sum->r = (int)sum->r % 10;
			}
			sum = temp;
		}
		first_temp = first_temp->father;
	}
	//如果加完后第一位小于10，就要把新建的略过去
	if (sum->r == 0) {
		this->sum_head = sum->son;
	}
	//大于10就不用了
	else {
		this->sum_head = sum;
	}
	std::string result;
	Bit *head = sum_head;
	while (head != NULL) {
		result += (head->r + '0');
		head = head->son;
	}
	return result;
}

//减法
std::string Num::Sub()
{
	Bit *first_temp = first_rear;
	Bit *second_temp = second_rear;
	Bit *sub = new Bit();
	sub->r = 0;
	sub->son = NULL;
	sub->father = NULL;
	this->sum_head = sub;
	this->sum_rear = sub;
	int mark = 0;		//mark    0是相等    1是第一个小于第二个    2是第一个大于第二个

	//先判断是否相等
	if (first_len == second_len) {
		Bit *fHead = first_head;
		Bit *sHead = second_head;
		while (fHead != NULL) {
			if (fHead->r < sHead->r) {
				mark = 1;
				first_temp = second_rear;
				second_temp = first_rear;
				break;
			}
			if (fHead->r > sHead->r) {
				mark = 2;
				break;
			}
			fHead = fHead->son;
			sHead = sHead->son;
		}
		if (!mark) {
			return "0";
		}
	}

	//按位相减
	while (first_temp != NULL) {
		if (second_temp != NULL) {
			sub->r += first_temp->r - second_temp->r;
			Bit *temp = new Bit();
			temp->father = NULL;
			temp->son = sub;
			temp->r = 0;
			sub->father = temp;
			if (sub->r < 0) {
				sub->r = 10 + sub->r;
				temp->r--;
			}
			sub = temp;
			second_temp = second_temp->father;
		}
		else {
			sub->r += first_temp->r;
			Bit *temp = new Bit();
			temp->father = NULL;
			temp->son = sub;
			temp->r = 0;
			sub->father = temp;
			if (sub->r < 0) {
				sub->r = 10 + sub->r;
				temp->r--;
			}
			sub = temp;
		}
		first_temp = first_temp->father;
	}
	if (sub->r <= 0) {
		this->sum_head = sub->son;
	}
	else {
		this->sum_head = sub;
	}
	std::string result;

	//交换了需要加个负号
	if (change) {
		result += '-';
	}
	Bit *head = sum_head;
	while (head->r == 0 && head != NULL) {
		head = head->son;
	}

	//第一个数小要加负号
	if (mark == 1) {
		result += "-";
	}
	while (head != NULL) {
		result += (head->r + '0');
		head = head->son;
	}
	return result;
}

//除法
//用string模拟了竖式
std::string Num::Div()
{
	if (first_len < second_len)
		return "0";
	Bit *fHead = first_head;
	Bit *sHead = second_head;
	int len = second_len;
	std::string s1 = "";
	std::string s2 = "";
	while (len--) {
		s1 += fHead->r + '0';
		s2 += sHead->r + '0';
		fHead = fHead->son;
		sHead = sHead->son;
	}
	std::string result = "";
	std::string mark = s1;
	int m;

	//从1开始计算商
	for (int i = 1; i <= 10; ++i) {
		m = i;
		mark = s1;		//mark记录原数据，然后s是相减的结果
		Num *num = new Num(s1, s2, 1);
		std::string s = num->Sub();
		s1 = s;

		//如果小于0表示减多了，商是i-1,如果等于0表示商正好是i
		if (s[0] == '-' || s[0] == '0') {
			if (s[0] == '-') {
				s1 = mark;
				result += (i - 1) + '0';
				int tmp = 0;

				//把被除数余下的位加到s1后面
				while (fHead != NULL && s1.size() < s2.size()) {
					//如果加了两位或者更多则需要商加0
					if (tmp != 0) {
						result += "0";
					}
					tmp++;
					s1 += fHead->r + '0';
					fHead = fHead->son;
				}
				//如果加了一位依旧s2比s1大 则需要再加一位
				Num *t = new Num(s1, s2, 1);
				if (t->Sub()[0] == '-') {
					if (tmp != 0) {
						result += "0";
					}
					s1 += fHead->r + '0';
					fHead = fHead->son;
				}
			}
			else if (s[0] == '0') {
				result += i + '0';
				int tmp = 0;
				while (fHead != NULL && s1.size() < s2.size()) {
					if (tmp) {
						result += "0";
					}
					tmp++;
					s1 += fHead->r + '0';
					fHead = fHead->son;
				}
				Num *t = new Num(s1, s2, 1);
				if (t->Sub()[0] == '-') {
					if (tmp != 0) {
						result += "0";
					}
					s1 += fHead->r + '0';
					fHead = fHead->son;
				}
			}

			//跳出循环
			if (fHead == NULL && s1.size() <= s2.size() + 1) {
				delete num;
				break;
			}
			i = 0;
		}
		delete num;
	}

	//进行最后一次计算
	for (int i = 1; i <= 10; ++i) {
		m = i;
		mark = s1;
		Num *num = new Num(s1, s2, 1);
		std::string s = num->Sub();
		if (s[0] == '-' || s[0] == '0') {
			if (s[0] == '-') {
				s1 = mark;
				result += (i - 1) + '0';
			}
			if (s[0] == '0') {
				result += i + '0';
			}
			break;
		}
		delete num;
		s1 = s;
	}

	//bit记录第一个不为0的数
	int bit = 0;
	for (int i = 0; i < result.size(); ++i) {
		if (result[i] != '0') {
			bit = i;
			break;
		}
	}
	std::string r = "";
	for (int i = bit; i < result.size(); ++i) {
		r += result[i];
	}
	return r;
}

//先将十进制转为二进制，这样会快一点
std::string Num::Pow()
{
	Bit *temp = second_head;
	int n = 0;
	while (temp != NULL) {
		n = n * 10 + temp->r;
		temp = temp->son;
	}
	std::string s;
	temp = first_head;
	while (temp != NULL) {
		s += temp->r + '0';
		temp = temp->son;
	}
	int time = 1;
	std::string result = "1";
	std::string pow = s;
	while (1) {
		if (n&time) {
			if (time == 1) {
				result = s;
			}
			else {
				Num *num = new Num(result, pow);
				result = num->Mul();
				delete num;
			}
		}
		Num *num = new Num(pow, pow);
		pow = num->Mul();
		delete num;
		time <<= 1;
		if (time > n)
			break;
	}
	return result;
}
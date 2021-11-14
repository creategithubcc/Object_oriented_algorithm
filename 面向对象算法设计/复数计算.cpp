#include<iostream>
#include <sstream>
#include <cstring>
using namespace std;

class Complex
{
	private:
		double real;//实部 
 		double imag;//虚部 
 		int ans;
	public:
		Complex(double a,double b)//为C1准备 
		{
			real=a;  //a+bi,a是实部 b是虚部 
	 		imag=b;
		}
		Complex()//为C2 C3准备 
		{
			real=0; 
	 		imag=0;
		}
		
		friend Complex operator + (Complex &a,Complex &b);//友元函数在外部实现运算+的重载 
		friend ostream &operator << (ostream &,Complex &);  // 一般情况下+无法实现复数 的计算，
		friend Complex operator += (Complex &c,Complex &d);  // 因此一定要用运算符号重载,<<也一样 
};                                                         

Complex operator + (Complex &a,Complex &b)//定义重载运算符+
{
 	return Complex(a.real+b.real,a.imag+b.imag);//这部分就是复数的计算，实部+实部，虚部+虚部 
}

Complex operator += (Complex &c,Complex &d)//定义重载运算符+=
{
	return Complex(c.real+=d.real,c.imag+=d.imag);//把两个复数相加在返回 
}

ostream &operator << (ostream &shuchu,Complex &c) //定义重载运算符<< 
{
	if(c.real==0&&c.imag==0)
	{
		shuchu<<"0";
		return shuchu;
	}
 	shuchu<<c.real<<"+"<<c.imag<<"i";
 	return shuchu;
}

int main()
{
	Complex C1(1, 2), C2;
	Complex C3 = C2;
	cout << " C3 = " << C3 << endl;
	C2 = C1 + C3;
	cout << " C2 = " << C2 << endl;
	C2 += C1;
	cout << " C2 = " << C2 << endl;	
}


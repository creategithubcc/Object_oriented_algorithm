#include<iostream>
#include <sstream>
#include <cstring>
using namespace std;

class Complex
{
	private:
		double real;//ʵ�� 
 		double imag;//�鲿 
 		int ans;
	public:
		Complex(double a,double b)//ΪC1׼�� 
		{
			real=a;  //a+bi,a��ʵ�� b���鲿 
	 		imag=b;
		}
		Complex()//ΪC2 C3׼�� 
		{
			real=0; 
	 		imag=0;
		}
		
		friend Complex operator + (Complex &a,Complex &b);//��Ԫ�������ⲿʵ������+������ 
		friend ostream &operator << (ostream &,Complex &);  // һ�������+�޷�ʵ�ָ��� �ļ��㣬
		friend Complex operator += (Complex &c,Complex &d);  // ���һ��Ҫ�������������,<<Ҳһ�� 
};                                                         

Complex operator + (Complex &a,Complex &b)//�������������+
{
 	return Complex(a.real+b.real,a.imag+b.imag);//�ⲿ�־��Ǹ����ļ��㣬ʵ��+ʵ�����鲿+�鲿 
}

Complex operator += (Complex &c,Complex &d)//�������������+=
{
	return Complex(c.real+=d.real,c.imag+=d.imag);//��������������ڷ��� 
}

ostream &operator << (ostream &shuchu,Complex &c) //�������������<< 
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


#include<iostream>
using namespace std;

class Shape
{
	public:
	    virtual double ans()=0;//���Ϊ�� 
	    
};
 double PrintArea(Shape &a)//�⺯�����������ش𰸵� 
{
	return a.ans();
}
class Circle:public Shape//Բ�� 
{
	private:
	    double r;
	    double yuan_area;
	public:
		Circle()
		{
			r=0;
		}
	    Circle(double a)
		{
			r=a;//��ֵ��r�뾶 
		}
	    
	 
	    double ans()//���㲢���� Բ��� 
		{ 
			 yuan_area=(r)*(r)*3.14; 
			return yuan_area;
		}
	    
 

};

 
class Triangle : public Shape
{
	private:
	    int kuan;//�����ߺ�������� 
	    int gao;
	    int sanjiao_area;
	public:
	    Triangle(int a, int b)
		{
			kuan=a;//������ ����ֵ 
			gao=b;
		}
	   
	 
	    double ans()//���㲢���� ��������� 
		{ 
			sanjiao_area=kuan*gao/2; 
			return sanjiao_area;
		}	
};

int main()
{
	Shape* p = new Circle(2);  
	cout << "The area of the circle is: " << PrintArea(*p) << endl; 
	Triangle triangle (3,4);
	cout << "The area of the triangle is: " << PrintArea(triangle) << endl;
	delete p;
}



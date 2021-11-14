#include<iostream>
using namespace std;

class Shape
{
	public:
	    virtual double ans()=0;//最初为零 
	    
};
 double PrintArea(Shape &a)//这函数是用来返回答案的 
{
	return a.ans();
}
class Circle:public Shape//圆类 
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
			r=a;//赋值给r半径 
		}
	    
	 
	    double ans()//计算并返回 圆面积 
		{ 
			 yuan_area=(r)*(r)*3.14; 
			return yuan_area;
		}
	    
 

};

 
class Triangle : public Shape
{
	private:
	    int kuan;//定义宽高和三角面积 
	    int gao;
	    int sanjiao_area;
	public:
	    Triangle(int a, int b)
		{
			kuan=a;//定义宽高 并赋值 
			gao=b;
		}
	   
	 
	    double ans()//计算并返回 三角形面积 
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



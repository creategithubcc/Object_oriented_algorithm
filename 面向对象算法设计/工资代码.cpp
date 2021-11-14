#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

const double jingli=7000; 
const double jishurenyuan=100;
const double xiaoshoujingli=4000; 
const double xiaoshouyuan=5.0/100; 

class Employee//基类 
{
	public:
			virtual void pay()//各自的月薪，这里的pay函数专指经理的月薪，因为经理的最简单所以就放到基类了 
			{
				cout<<"经理"<<name<<"的工资是"<<salary<<endl;
			}
			void input()
			{
				cout<<"姓名:";
				cin>>name;
			}
	protected:
			double salary;
			string name;
};

class Jishurenyuan:virtual public Employee//派生程序员，接下来所有函数都继承基类 
{
	public:
			void input()
			{
				cout<<"技术员的";
				Employee::input();
				cout<<"工作时间:";
				cin>>time;
			}
			
			virtual void pay()//pay程序员 
			{ 
				salary=time*jishurenyuan;
				cout<<"技术人员"<<name<<"的工资是"<<salary<<endl;	
			}
	protected:
			double time; //工作时间（小时）
};

class Jingli:virtual public Employee //经理类
{
	public:
			void input()
			{
				cout<<"经理的";
				Employee::input();
			}
			
			virtual void pay()
			{ 
				salary=jingli;
				Employee::pay();
			}
};
int ans=0;//创建一个全局函数，用来保存销售员全员的总销售额 
class Xiaoshouyuan:virtual public Employee //销售员类
{
	public:
		double xiaoshouliang=0;//销售量 
		void input()
		{
			cout<<"销售员的";
			Employee::input();
			cout<<"销售额:";
			cin>>xiaoshouliang;
			ans+=xiaoshouliang;
		}
		virtual void pay()//pay销售员 
		{ 
			salary=xiaoshouliang*xiaoshouyuan;
			cout<<"销售员"<<name<<"的工资是"<<salary<<endl;
		}
};

Xiaoshouyuan a[3]; //销售员，放在这里是为了让接下来的销售经理类能够使用该数组 

class Xiaoshoujingli:virtual public Employee//销售经理类
{
	public:
		void input()
		{
			cout<<"销售经理的";
			Employee::input();
		}
		virtual void pay()//pay销售经理 
		{ 
			salary=ans*xiaoshouyuan+xiaoshoujingli;
			cout<<name<<"的工资是"<<salary<<endl;
		}

};

Jishurenyuan b[3];//技术员，员工有复数以上位 ，经理就个一位 
Jingli c[1];//经理
Xiaoshoujingli d[1];//销售经理

int main()
{
	char n;
	int i;
	cout<<"输入您想要填写的职位"<<endl;
	for(int j=0;j<6;j++)
	{
		cout<<"1.经理数据输入  2.技术员数据输入  3.销售员数据输入  4.销售经理数据输入  0.返回上一级"<<endl;
		cin>>n;
		if(n!='0')
		{
			switch(n)
			{
				case'1':
				for(i=0;i<1;i++)
				c[i].input();
				cout<<"-------------------------------------------------------"<<endl;
				break;
				case'2':
				for(i=0;i<3;i++)
				b[i].input();
				cout<<"-------------------------------------------------------"<<endl;
				break;
				case'3':
				for(i=0;i<3;i++)
				a[i].input();
				cout<<"-------------------------------------------------------"<<endl;
				break;
				case'4':
				for(i=0;i<1;i++)
				d[i].input();
				cout<<"----------------------------------------------------"<<endl;
				break;
			}
		}
		else if(n=='0')
		{
			break;
		} 
	}
	cout<<"1.经理数据  2.技术员数据  3.销售员数据  4.销售经理数据  0.返回上一级"<<endl;
	for(int j=0;j<6;j++)
	{
		cin>>n;
		if(n!='0')
		{
			switch(n)
			{
				case'1':
						cout<<endl<<"经理"<<endl;//经理信息
						for(i=0;i<1;i++)
						c[i].pay();
						cout<<"-------------------------------------------------------------------------"<<endl;
						break;
				
				case'2':
						cout<<endl<<"技术员"<<endl;//程序员信息
						for(i=0;i<3;i++)
						b[i].pay();
						cout<<"-------------------------------------------------------------------------"<<endl;
						break;
				
				case'3':
						cout<<endl<<"销售员"<<endl;//销售员信息
						for(i=0;i<3;i++)
						a[i].pay();
						cout<<"-------------------------------------------------------------------------"<<endl;
						break;
				
				case'4':
						cout<<endl<<"销售经理"<<endl; //销售经理信息
						for(i=0;i<1;i++)
						d[i].pay();
						cout<<"-------------------------------------------------------------------------"<<endl;
						break; 
			}
		}
		else if(n=='0')
		{
			break;
		} 
	}
	Jishurenyuan a3;          //实验二在实验一的基础上修改了pay（）函数，原本有四个不同函数名paycxy，payxsy，payxsjl全改成一样的函数名pay了 
	Employee *aa=&a3;         // 在不加虚基类和虚函数的情况下优先Employee类里面的pay输出，因此全部变成了经理的工资 
	aa->pay();                //但是在修改了虚函数和虚基类后，答案就优先用各自的派生类里的pay函数了，因此答案是对的 
	Jingli b3;                //但是由于我给技术人员和销售员设立了附属以上的人数，因此他们显示出来的答案是各自派生类pay函数的首地址 
	Employee *bb=&b3;         // 虚函数是指一个类中你希望重载的成员函数 ，当你用一个 基类指针或引用 指向一个继承类对象的时候，
	bb->pay();                // 调用一个虚函数时, 实际调用的是继承类的版本
	Xiaoshouyuan c3;          //因此在不加虚函数的情况下输出来的往往都是基类的成员函数 
	Employee *cc=&c3;
	cc->pay();
	Xiaoshoujingli d3;
	Employee *dd=&d3;
	dd->pay();
	
}


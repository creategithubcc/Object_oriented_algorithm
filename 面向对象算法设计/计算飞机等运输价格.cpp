#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;//两个参数距离和重量 
int b=0;            //b是为了判断一个函数里面我们要的是飞机的计算方式还是轮船，汽车的 
class Vehicle
{
	public:
		double juli;
		double zhongliang;	
		double ans;
	    virtual double Fee()=0;
	    
};
class INPUT:virtual public Vehicle
{
	public:
		virtual void input()
		{
			cout<<"距离:";
			cin>>juli;
			cout<<"重量:";
			cin>>zhongliang;
		}
		virtual double Fee()
		{
			if(b==1)
			{
				ans=juli*1.15+zhongliang*1.05;
				return ans;
			}
			else if(b==2)
			{
				ans=juli*1.05+zhongliang*0.9;
				return ans;
			}
			else if(b==3)
			{
				ans=juli*1.2+zhongliang*1.1;
				return ans;
			}
		}		
};
int main()
{
	INPUT c;
	INPUT &a=c;
	int i,n;
	double ans;
	cout<<"请选择您要运输的交通工具种类"<<endl;
	cout<<"1.飞机 2.邮轮 3.汽车"<<endl;
	for(i=0;i<100;i++)
	{
		cin>>n;
		b=n;             //把n带入到b里，方便Fee函数判断 
			switch(n)
			{
				case 1:
					a.input();
					cout<<"----------正在计算中-------"<<endl;
					cout<<"----------拼命计算中-------"<<endl;
					cout<<"计算完毕！"<<endl;
					ans=a.Fee();
					cout<<"运输价格是"<<ans<<endl;
					cout<<"正在返回。。。。。。"<<endl;
					cout<<"1.飞机 2.邮轮 3.汽车 0.返回"<<endl;
					break; 
				case 2:
					a.input();
					cout<<"----------正在计算中-------"<<endl;
					cout<<"----------拼命计算中-------"<<endl;
					cout<<"计算完毕！"<<endl;
					ans=a.Fee();
					cout<<"运输价格是"<<ans<<endl;
					cout<<"正在返回。。。。。。"<<endl;
					cout<<"1.飞机 2.邮轮 3.汽车 0.返回"<<endl;
					break;
				case 3:
					a.input();
					cout<<"----------正在计算中-------"<<endl;
					cout<<"----------拼命计算中-------"<<endl;
					cout<<"计算完毕！"<<endl;
					ans=a.Fee();
					cout<<"运输价格是"<<ans<<endl;
					cout<<"正在返回。。。。。。"<<endl;
					cout<<"1.飞机 2.邮轮 3.汽车 0.返回"<<endl;
					break; 
				case 0:
					cout<<"----------程序结束---------"<<endl; 
					return 0;
			} 
	}
}



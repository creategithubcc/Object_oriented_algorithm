#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;//����������������� 
int b=0;            //b��Ϊ���ж�һ��������������Ҫ���Ƿɻ��ļ��㷽ʽ�����ִ��������� 
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
			cout<<"����:";
			cin>>juli;
			cout<<"����:";
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
	cout<<"��ѡ����Ҫ����Ľ�ͨ��������"<<endl;
	cout<<"1.�ɻ� 2.���� 3.����"<<endl;
	for(i=0;i<100;i++)
	{
		cin>>n;
		b=n;             //��n���뵽b�����Fee�����ж� 
			switch(n)
			{
				case 1:
					a.input();
					cout<<"----------���ڼ�����-------"<<endl;
					cout<<"----------ƴ��������-------"<<endl;
					cout<<"������ϣ�"<<endl;
					ans=a.Fee();
					cout<<"����۸���"<<ans<<endl;
					cout<<"���ڷ��ء�����������"<<endl;
					cout<<"1.�ɻ� 2.���� 3.���� 0.����"<<endl;
					break; 
				case 2:
					a.input();
					cout<<"----------���ڼ�����-------"<<endl;
					cout<<"----------ƴ��������-------"<<endl;
					cout<<"������ϣ�"<<endl;
					ans=a.Fee();
					cout<<"����۸���"<<ans<<endl;
					cout<<"���ڷ��ء�����������"<<endl;
					cout<<"1.�ɻ� 2.���� 3.���� 0.����"<<endl;
					break;
				case 3:
					a.input();
					cout<<"----------���ڼ�����-------"<<endl;
					cout<<"----------ƴ��������-------"<<endl;
					cout<<"������ϣ�"<<endl;
					ans=a.Fee();
					cout<<"����۸���"<<ans<<endl;
					cout<<"���ڷ��ء�����������"<<endl;
					cout<<"1.�ɻ� 2.���� 3.���� 0.����"<<endl;
					break; 
				case 0:
					cout<<"----------�������---------"<<endl; 
					return 0;
			} 
	}
}



#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

const double jingli=7000; 
const double jishurenyuan=100;
const double xiaoshoujingli=4000; 
const double xiaoshouyuan=5.0/100; 

class Employee//���� 
{
	public:
			virtual void pay()//���Ե���н�������pay����רָ�������н����Ϊ�����������Ծͷŵ������� 
			{
				cout<<"����"<<name<<"�Ĺ�����"<<salary<<endl;
			}
			void input()
			{
				cout<<"����:";
				cin>>name;
			}
	protected:
			double salary;
			string name;
};

class Jishurenyuan:virtual public Employee//��������Ա�����������к������̳л��� 
{
	public:
			void input()
			{
				cout<<"����Ա��";
				Employee::input();
				cout<<"����ʱ��:";
				cin>>time;
			}
			
			virtual void pay()//pay����Ա 
			{ 
				salary=time*jishurenyuan;
				cout<<"������Ա"<<name<<"�Ĺ�����"<<salary<<endl;	
			}
	protected:
			double time; //����ʱ�䣨Сʱ��
};

class Jingli:virtual public Employee //������
{
	public:
			void input()
			{
				cout<<"�����";
				Employee::input();
			}
			
			virtual void pay()
			{ 
				salary=jingli;
				Employee::pay();
			}
};
int ans=0;//����һ��ȫ�ֺ�����������������ԱȫԱ�������۶� 
class Xiaoshouyuan:virtual public Employee //����Ա��
{
	public:
		double xiaoshouliang=0;//������ 
		void input()
		{
			cout<<"����Ա��";
			Employee::input();
			cout<<"���۶�:";
			cin>>xiaoshouliang;
			ans+=xiaoshouliang;
		}
		virtual void pay()//pay����Ա 
		{ 
			salary=xiaoshouliang*xiaoshouyuan;
			cout<<"����Ա"<<name<<"�Ĺ�����"<<salary<<endl;
		}
};

Xiaoshouyuan a[3]; //����Ա������������Ϊ���ý����������۾������ܹ�ʹ�ø����� 

class Xiaoshoujingli:virtual public Employee//���۾�����
{
	public:
		void input()
		{
			cout<<"���۾����";
			Employee::input();
		}
		virtual void pay()//pay���۾��� 
		{ 
			salary=ans*xiaoshouyuan+xiaoshoujingli;
			cout<<name<<"�Ĺ�����"<<salary<<endl;
		}

};

Jishurenyuan b[3];//����Ա��Ա���и�������λ ������͸�һλ 
Jingli c[1];//����
Xiaoshoujingli d[1];//���۾���

int main()
{
	char n;
	int i;
	cout<<"��������Ҫ��д��ְλ"<<endl;
	for(int j=0;j<6;j++)
	{
		cout<<"1.������������  2.����Ա��������  3.����Ա��������  4.���۾�����������  0.������һ��"<<endl;
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
	cout<<"1.��������  2.����Ա����  3.����Ա����  4.���۾�������  0.������һ��"<<endl;
	for(int j=0;j<6;j++)
	{
		cin>>n;
		if(n!='0')
		{
			switch(n)
			{
				case'1':
						cout<<endl<<"����"<<endl;//������Ϣ
						for(i=0;i<1;i++)
						c[i].pay();
						cout<<"-------------------------------------------------------------------------"<<endl;
						break;
				
				case'2':
						cout<<endl<<"����Ա"<<endl;//����Ա��Ϣ
						for(i=0;i<3;i++)
						b[i].pay();
						cout<<"-------------------------------------------------------------------------"<<endl;
						break;
				
				case'3':
						cout<<endl<<"����Ա"<<endl;//����Ա��Ϣ
						for(i=0;i<3;i++)
						a[i].pay();
						cout<<"-------------------------------------------------------------------------"<<endl;
						break;
				
				case'4':
						cout<<endl<<"���۾���"<<endl; //���۾�����Ϣ
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
	Jishurenyuan a3;          //ʵ�����ʵ��һ�Ļ������޸���pay����������ԭ�����ĸ���ͬ������paycxy��payxsy��payxsjlȫ�ĳ�һ���ĺ�����pay�� 
	Employee *aa=&a3;         // �ڲ����������麯�������������Employee�������pay��������ȫ������˾���Ĺ��� 
	aa->pay();                //�������޸����麯���������󣬴𰸾������ø��Ե����������pay�����ˣ���˴��ǶԵ� 
	Jingli b3;                //���������Ҹ�������Ա������Ա�����˸������ϵ����������������ʾ�����Ĵ��Ǹ���������pay�������׵�ַ 
	Employee *bb=&b3;         // �麯����ָһ��������ϣ�����صĳ�Ա���� ��������һ�� ����ָ������� ָ��һ���̳�������ʱ��
	bb->pay();                // ����һ���麯��ʱ, ʵ�ʵ��õ��Ǽ̳���İ汾
	Xiaoshouyuan c3;          //����ڲ����麯�����������������������ǻ���ĳ�Ա���� 
	Employee *cc=&c3;
	cc->pay();
	Xiaoshoujingli d3;
	Employee *dd=&d3;
	dd->pay();
	
}


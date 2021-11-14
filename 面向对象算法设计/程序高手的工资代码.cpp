#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

//������e69da5e6ba907a6431333264663662�����޸��ã���

const int n1=2,n2=2,n3=4,n4=2; /*���幫˾����ְ�������������޸ģ�
(n1������Ա������n2:����������n3������Ա������n4:���۾������� ��*/
const double m_salary=8000; //����̶��¹���
const double hourpay=100; //����ԱСʱ����
const double basicpay=5000; //���۾���ĵ�н
const double s_proportion=4.0/100; //����Ա�Ĺ�����ɱ���
const double sm_proportion=0.5/100; //���۾������ɱ���

//�������֣�

void menu(); //���˵�
void menu2(); //������������˵�
void menu3(); //���ݴ�ӡ�����˵�
void data_input(); //�������뺯��
void data_print(); //���ݴ�ӡ
void charthead1(); //������ͷ1������ͳ�����۶�
void charthead2(); //������ͷ2���������ݴ�ӡ
void chartend(); //������β
void statistics(); //����ͳ��
double sm_salary(); //���۾����ʼ���
void sm_print(); //���۾����ӡ����
void data_find(); //���ݲ�ѯ
void data_save(); //���ݱ���

ofstream outfile; //�򿪴����ļ�������

string f_name; //ȫ�ֱ�������ѯ�ã�

//�����ࣺ

class Employee //��Ա�ࣨ���ࣩ
{
public:
void input() //�������뺯��
{
cout<<"���:";
cin>>num;
cout<<"������:";
cin>>name;
cout<<"�Ա�(m/w):";
cin>>sex;
cout<<"����:";
cin>>age;
}

void print() //��ӡ���ݺ���
{
cout<<"�������������੤���������੤���������੤���������੤����������"<<endl;
cout<<"��"<<setw(6)<<num<<" ��"<<setw(8)<<name<<" ��"<<setw(6)<<sex<<" ��"<<setw(6)
<<age<<" ��"<<setw(7)<<pay<<" ��"<<endl;
}

void find() //��ѯ����
{
if(f_name==name)
{
charthead2();
print();
chartend();
cout<<endl;
}
}

void save() //�������ݺ���
{

outfile<<"�������������੤���������੤���������੤���������੤����������"<<endl;
outfile<<"��"<<setw(6)<<num<<" ��"<<setw(8)<<name<<" ��"<<setw(6)<<sex<<" ��"<<setw(6)
<<age<<" ��"<<setw(7)<<pay<<" ��"<<endl;
}

protected:
int num; //ְ����
string name; //ְ������
char sex; //ְ���Ա�
int age; //ְ������
double pay; //ְ������
};

class Technician:public Employee //����Ա�ࣨ���м̳У�
{
public:
void input()
{
cout<<"����Ա��";
Employee::input();
cout<<"����ʱ��:";
cin>>worktime;
}

void print()
{ pay=worktime*hourpay;
Employee::print();
}
void find()
{
Employee::find();
}
void save()
{ pay=worktime*hourpay;
Employee::save();
}

protected:
double worktime; //����ʱ�䣨Сʱ��
};

class Manager:public Employee //������
{
public:
void input()
{
cout<<"�����";
Employee::input();
}

void print()
{ pay=m_salary;
Employee::print();
}

void find()
{
Employee::find();

}
void save()
{ pay=m_salary;
Employee::save();
}
};

class Sell_manager:public Employee //���۾�����
{
public:
void input()
{ cout<<"���۾����";
Employee::input();
}

int sm_number() //�������۾���ְ����
{
return num;
}

string sm_name() //�������۾�������
{
return name;
}

void print()
{
cout<<"�������������੤���������੤���������੤���������੤����������"<<endl;
cout<<"��"<<setw(6)<<num<<" ��"<<setw(8)<<name<<" ��"<<setw(6)<<sex<<" ��"<<setw(6)
<<age<<" ��";

}
void save()
{
outfile<<"�������������੤���������੤���������੤���������੤����������"<<endl;
outfile<<"��"<<setw(6)<<num<<" ��"<<setw(8)<<name<<" ��"<<setw(6)<<sex<<" ��"<<setw(6)
<<age<<" ��";
}

};

class Seller:public Employee //����Ա��
{
public:
Seller(){ sold_amount=0; } //���캯�������۶��ʼ��Ϊ0
void input()
{
cout<<"����Ա��";
Employee::input();
cout<<"���۶�:";
cin>>sold_amount;
cout<<"�������۾���ı��:";
cin>>nu;
}
void grade() //����Աҵ�����
{
cout<<"�������������੤���������੤����������"<<endl;
cout<<"��"<<setw(6)<<num<<" ��"<<setw(8)<<name<<" ��"<<setw(7)<<sold_amount<<" ��"<<endl;

}

void print()
{ pay=sold_amount*s_proportion;
cout<<"�������������੤���������੤���������੤���������੤���������੤����������������������"<<endl;
cout<<"��"<<setw(6)<<num<<" ��"<<setw(8)<<name<<" ��"<<setw(6)<<sex<<" ��"<<setw(6)
<<age<<" ��"<<setw(7)<<pay<<" ��"<<setw(13)<<nu<<" ��"<<endl;
}

int s_number() //��������Ա�������۾���ְ����
{
return nu;
}
double amount() //��������Ա���۶�
{
return sold_amount;
}

void find()
{ if(f_name==name)
{cout<<"�������������Щ����������Щ����������Щ����������Щ����������Щ�����������������������"<<endl;
cout<<"�� ְ �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �������ž����� ��"<<endl;
print();
cout<<"�������������ة����������ة����������ة����������ة����������ة�����������������������";
}
}
void save()
{ pay=sold_amount*s_proportion;
outfile<<"�������������੤���������੤���������੤���������੤���������੤����������������������"<<endl;
outfile<<"��"<<setw(6)<<num<<" ��"<<setw(8)<<name<<" ��"<<setw(6)<<sex<<" ��"<<setw(6)
<<age<<" ��"<<setw(7)<<pay<<" ��"<<setw(13)<<nu<<" ��"<<endl;
}

protected:
double sold_amount; //���۶�
int nu; //�������۾���ְ����
};

//����ȫ�ֶ�������

Technician t[n1]; //����Ա
Manager m[n2]; //����
Seller s[n3]; //����Ա
Sell_manager sm[n4]; //���۾���������������Ա��

//���������֣�
int main()
{
char n;
menu();
for(int i=0;i<1000;i++) //�趨ѭ�����������ڸ���������л��������ѯ��
{
cin>>n;
switch(n)
{
case'1': //��������
cout<<endl<<"����ѡ����Ϊ�������룬���������"<<endl<<endl;
data_input();
cout<<endl;
menu();
break;

case'2': //����ͳ��
cout<<endl<<"����ѡ����Ϊ����ͳ�ƣ����������"<<endl<<endl;
statistics();
cout<<endl<<"���۾�����������Ϊ:"<<'\n'<<endl;
sm_print();
cout<<endl;
menu();
break;

case'3': //���ݴ�ӡ
cout<<endl<<"����ѡ����Ϊ���ݴ�ӡ�����������"<<endl<<endl;
cout<<'\a'<<"���ݴ�ӡ�У���ȴ�����"<<'\n'<<'\n'<<endl;
cout<<"ְ���������һ�������£�"<<'\n'<<endl;;
data_print();
cout<<endl<<endl;
cout<<'\a'<<"�������ݴ�ӡ��ϡ���"<<'\n'<<'\n'<<endl;
menu();
break;

case'4': //���ݲ�ѯ
cout<<endl<<"����ѡ����Ϊ���ݲ�ѯ�����������"<<endl<<endl;
cout<<"��������Ҫ��ѯ��ְ�������� ";
cin>>f_name;
cout<<endl<<"�������ڲ�ѯ����ȴ�����"<<endl<<endl;
cout<<"����ѯ����Ϣ���£�"<<endl<<endl;
data_find();
cout<<endl<<endl;
menu();
break;

case'5': //���ݱ���
outfile.open("C++�������ʵϰ.txt",ios::out); //�򿪴����ļ�������
cout<<endl<<"����ѡ����Ϊ���ݱ��ݣ����������"<<endl<<endl;
outfile<<"ְ���������һ�������£�"<<'\n'<<endl;
data_save();
outfile.close();
cout<<endl<<endl;
cout<<'\a'<<"�������ݱ�����ɣ����������"<<endl<<endl;
menu();
break;

case'0': //�˳�ϵͳ
cout<<endl<<"����ѡ����Ϊ�˳�ϵͳ����ȷ�ϡ���"<<endl<<endl;
cout<<" ��( y )"<<" "<<"��( n ) ";
cin>>n;
if(n=='y')
{ cout<<'\n'<<"�����밴������˳�ϵͳ����"<<endl; exit(0); cout<<endl;}
else menu();
break;
default:
cout<<endl<<"��������������ѡ������� "<<'\n'<<endl;
menu();
break;
}

}
return 0;
}

//�Զ��庯�����֣�

void menu() //�˵�����
{
cout<<" ���С�͹�˾���ʹ���ϵͳ��� "<<endl;
cout<<"��������������������������������"<<endl;
cout<<"�� ��ѡ��������Ĳ��� ��"<<endl;
cout<<"�� �������룺1,�����س����� ��"<<endl;
cout<<"�� ����ͳ�ƣ�2,�����س����� ��"<<endl;
cout<<"�� ���ݴ�ӡ��3,�����س����� ��"<<endl;
cout<<"�� ���ݲ�ѯ��4,�����س����� ��"<<endl;
cout<<"�� ���ݱ��ݣ�5,�����س����� ��"<<endl;
cout<<"�� �˳�ϵͳ��0,�����س����� ��"<<endl;
cout<<"��������������������������������"<<endl;
cout<<" ��ѡ��һ������:";

}

void menu2() //������������˵�����
{
cout<<" ���С�͹�˾���ʹ���ϵͳ��� "<<endl;
cout<<"����������������������������������������"<<endl;
cout<<"�� ��ѡ��������Ĳ��� ��"<<endl;
cout<<"�� ������������ ��1,�����س����� ��"<<endl;
cout<<"�� ����Ա�������� ��2,�����س����� ��"<<endl;
cout<<"�� ����Ա�������� ��3,�����س����� ��"<<endl;
cout<<"�� ���۾����������룺4,�����س����� ��"<<endl;
cout<<"�� ������һ�� ��5,�����س����� ��"<<endl;
cout<<"����������������������������������������"<<endl;
cout<<" ��ѡ��һ������:";

}

void menu3() //���ݴ�ӡ�����˵�����
{
cout<<" ���С�͹�˾���ʹ���ϵͳ��� "<<endl;
cout<<"����������������������������������������"<<endl;
cout<<"�� ��ѡ��������Ĳ��� ��"<<endl;
cout<<"�� �������ݴ�ӡ ��1,�����س����� ��"<<endl;
cout<<"�� ����Ա���ݴ�ӡ ��2,�����س����� ��"<<endl;
cout<<"�� ����Ա���ݴ�ӡ ��3,�����س����� ��"<<endl;
cout<<"�� ���۾������ݴ�ӡ��4,�����س����� ��"<<endl;
cout<<"�� ������һ�� ��5,�����س����� ��"<<endl;
cout<<"����������������������������������������"<<endl;
cout<<" ��ѡ��һ������:";
}

void data_input() //�������뺯��
{
char p;int i;
menu2();
for(int j=0;j<100;j++)
{
cin>>p;
if(p=='5') break;
else
{
switch(p)
{
case'1':
for(i=0;i<n2;i++)
m[i].input();
cout<<endl<<"-----------------------------------------------------"<<endl;menu2();break;
case'2':
for(i=0;i<n1;i++)
t[i].input();
cout<<endl<<"-----------------------------------------------------"<<endl;menu2();break;
case'3':
for(i=0;i<n3;i++)
s[i].input();
cout<<endl<<"-----------------------------------------------------"<<endl;menu2();break;
case'4':
for(i=0;i<n4;i++)
sm[i].input();
cout<<endl<<"--------------------------------------------------"<<endl;menu2();break;
}

}
}
}

void charthead1() //�Ʊ�ͷ1������ͳ���ã�
{
cout<<"�������������Щ����������Щ�����������"<<endl;
cout<<"��ְ �� �š��� �� �� �� �� �� �� ��"<<endl;
}

void charthead2() //�Ʊ�ͷ2�����ݴ�ӡ�����۾�������ͳ���ã�
{
cout<<"�������������Щ����������Щ����������Щ����������Щ�����������"<<endl;
cout<<"�� ְ �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��"<<endl;
}

void chartend() //�Ʊ�β�����ݴ�ӡ�����۾�������ͳ���ã�
{
cout<<"�������������ة����������ة����������ة����������ة�����������";
}

void statistics() //����ͳ�ƺ���
{ int i,j;
for(i=0;i<n4;i++)
{ double sum=0;
cout<<endl<<"ְ����Ϊ "<<sm[i].sm_number()<<" ���۾��� "<<sm[i].sm_name()
<<" ��������Ա��ҵ��Ϊ:"<<endl<<endl;
charthead1();
for(j=0;j<n3;j++)
if(s[j].s_number()==sm[i].sm_number())
{
sum=sum+s[j].amount();
s[j].grade();
}
cout<<"�������������੤���������ة�����������"<<endl;
cout<<"�����۶��ܼƩ�"<<setw(12)<<sum<<" ��"<<endl;
cout<<"�������������ة�����������������������"<<endl;
}
}

double salary[n4];
double sm_salary() //���۾����ʼ��㼰����
{
int i,j;double a ;Sell_manager b;
for(int k=0;k<n4;k++)
salary[k]=0;
for(i=0;i<n4;i++)
{ double sum=0;
for(j=0;j<n3;j++)
if(s[j].s_number()==sm[i].sm_number())
{ sum=sum+s[j].amount();
salary[i]=sum*sm_proportion+basicpay;
}
}
for( j=0;j<n4-1;j++)
for( i=0;i<n4-1-j;i++)
if(salary[i]<salary[i+1])
{ a=salary[i+1];salary[i+1]=salary[i];salary[i]=a;
b=sm[i+1];sm[i+1]=sm[i];sm[i]=b;
}
return 0;
}

void sm_print()
{
sm_salary();
charthead2();
for(int i=0;i<n4;i++)
{ sm[i].print();
cout<<setw(7)<<salary[i]<<" ��"<<endl;
}

chartend();
cout<<endl;
}

void data_print() //���ݴ�ӡ
{
char p;int i,j;
menu2();
for(j=0;j<100;j++)
{
cin>>p;
if(p=='5') break;
else
{
switch(p)
{case'1':
cout<<endl<<"����"<<endl; //������Ϣ
charthead2();
for(i=0;i<n2;i++)
m[i].print();
chartend();
cout<<endl<<endl<<"-----------------------------------------------------------------------"<<endl;
menu3();break;

case'2':
cout<<endl<<"����Ա"<<endl; //����Ա��Ϣ
charthead2();
for(i=0;i<n1;i++)
t[i].print();
chartend();
cout<<endl<<endl<<"-----------------------------------------------------------------------"<<endl;
menu3();break;

case'3':
cout<<endl<<"����Ա"<<endl; //����Ա��Ϣ
cout<<"�������������Щ����������Щ����������Щ����������Щ����������Щ�����������������������"<<endl;
cout<<"�� ְ �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �������ž����� ��"<<endl;
for(i=0;i<n3;i++)
s[i].print();
cout<<"�������������ة����������ة����������ة����������ة����������ة�����������������������";
cout<<endl<<endl<<"------------------------------------------------------------------------"<<'\n'<<endl;
menu3();break;

case'4':
cout<<endl<<"���۾���"<<endl; //���۾�����Ϣ
sm_salary();
sm_print();
cout<<endl<<endl<<"-----------------------------------------------------------------------"<<endl<<endl;
menu3();break; }
}
}
}

void data_find() //���ݲ�ѯ����
{
for(int i=0;i<n1;i++)
t[i].find();
for(int i=0;i<n2;i++)
m[i].find();
for(int i=0;i<n3;i++)
s[i].find();
for(int i=0;i<n4;i++)
if(f_name==sm[i].sm_name())
{ charthead2();
sm[i].print();
cout<<setw(7)<<salary[i]<<" ��"<<endl;
chartend();
cout<<endl;
break;
}
}

void data_save() //���ݱ��ݺ���
{
outfile<<endl<<"����Ա"<<endl; //����Ա��Ϣ
outfile<<"�������������Щ����������Щ����������Щ����������Щ�����������"<<endl;
outfile<<"�� ְ �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��"<<endl;
for(int i=0;i<n1;i++)
t[i].save();
outfile<<"�������������ة����������ة����������ة����������ة�����������";
outfile<<endl<<endl<<"---------------------------------------------------------------------------"<<endl;

outfile<<endl<<"����"<<endl; //������Ϣ
outfile<<"�������������Щ����������Щ����������Щ����������Щ�����������"<<endl;
outfile<<"�� ְ �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��"<<endl;
for(int i=0;i<n2;i++)
m[i].save();
outfile<<"�������������ة����������ة����������ة����������ة�����������";
outfile<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;

outfile<<endl<<"���۾���"<<endl; //���۾�����Ϣ
sm_salary();
outfile<<"�������������Щ����������Щ����������Щ����������Щ�����������"<<endl;
outfile<<"�� ְ �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��"<<endl;
for(int i=0;i<n4;i++)
{ sm[i].save();
outfile<<setw(7)<<salary[i]<<" ��"<<endl;}
outfile<<"�������������ة����������ة����������ة����������ة�����������";
outfile<<endl<<endl<<"----------------------------------------------------------------------------"<<endl<<endl;

outfile<<endl<<"����Ա"<<endl; //����Ա��Ϣ
outfile<<"�������������Щ����������Щ����������Щ����������Щ����������Щ�����������������������"<<endl;
outfile<<"�� ְ �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �������ž����� ��"<<endl;
for(int i=0;i<n3;i++)
s[i].save();
outfile<<"�������������ة����������ة����������ة����������ة����������ة�����������������������";
outfile<<endl<<endl<<"-----------------------------------------------------------------------------"<<'\n'<<endl;
} 


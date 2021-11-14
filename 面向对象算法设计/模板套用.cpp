#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
void require(bool requirement,const std::string& msg = "Requirement failed")
{
    using namespace std;
    if (!requirement) 
	{
        fputs(msg.c_str(), stderr);//���ַ���д�룬���ƶ�ָ�� 
        fputs("\n", stderr);
        exit(1);
    }
}
template<typename T1,T1 n>//����ѧϰ�ص����ݣ�˵��ĵ�����main������ Array<int,5>��ʱ�� һʱ���û��Ӧ���� 
class Array               //����һ�������ϸ���ô��int���͵�5���������棬��Ϊ����Ϊֹ��������������<int,double>������ 
{                         //��������csdn�Ĳ��ͣ�������������ǲ���������Ļ�����ֱ�Ӵ����࣬������дtypename T2 
public:                   //��˾�д�������ʽ���󲿷ִ��붼���� IostreamOperatorOverloading.cpp ��Ϊԭ�͵� 
	T1 a[n];              
	Array() 
	{ 
		memset(a,0,sizeof(*a)); 
	}
	int& operator[](T1 x) 
	{
		require(x>=0&&x<5,"IntArray::operator[] out of range");
		return a[x];
	}
	friend ostream&operator<<(ostream& os,const Array<T1,n>& ia)//�����������Ԫ�����Ž������� 
	{                                                           //��Ԫģ�庯�������ں�����
		for(int j=0;j<5;j++)                                    // �Ͳ���Ҫ��д Array<T1,n>������ 
		{
			os<<ia.a[j];
			if(j!=4)
			os<<", ";
		}
		os<<endl;
		return os;
	} 
	friend istream&operator>>(istream& is,Array& ia)
	{
		for(int j=0;j<5;j++)
		is>>ia.a[j];
		return is;
	}
};


int main() 
{
    stringstream input("47 34 56 92 103");
    Array<int,5> a;
    input>>a;
    a[4]=-1;           // Use overloaded operator[]
    cout<<a;
}



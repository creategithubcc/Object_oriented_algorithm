#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
using namespace std;
class CSmart
{ 
    private:
    	string info;
		static int count;
	public:
		CSmart() 
		{ 
			count+=1;                         //ÿ����һ��+1��Ȼ����� 
		   	cout<<count<<" objects"<<endl;
		}   
		~CSmart()
		{
		    count--;                          //�ͷŵ�ʱ���-1 
			cout<<count<<" objects"<<endl; 
		}
		static int Getcount()
		{
			return count;
		}
};
int CSmart::count=0;
void DoSomething s12()
{ 
    CSmart s; 
	cout<<"��������ܹ�������"<<CSmart::Getcount()<<"�ζ��󣬷ֱ���s1,s2,s"<<endl;
}
CSmart  s1;
int main()	
{
    CSmart  s2;	
    DoSomething s12( );  
    CSmart  *s3 = new CSmart;
    delete s3;
    cout<<"��������ܹ�������"<<CSmart::Getcount()<<"�ζ���,����ͷ���s3"<<endl;
}


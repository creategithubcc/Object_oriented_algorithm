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
			count+=1;                         //每运行一次+1，然后输出 
		   	cout<<count<<" objects"<<endl;
		}   
		~CSmart()
		{
		    count--;                          //释放的时候就-1 
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
	cout<<"这个程序总共运行了"<<CSmart::Getcount()<<"次对象，分别是s1,s2,s"<<endl;
}
CSmart  s1;
int main()	
{
    CSmart  s2;	
    DoSomething s12( );  
    CSmart  *s3 = new CSmart;
    delete s3;
    cout<<"这个程序总共运行了"<<CSmart::Getcount()<<"次对象,最后释放了s3"<<endl;
}


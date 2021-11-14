#include <iostream>
#include<assert.h>
using namespace std;
char* strcpy(char* a,const char* b)//复制字符串 
{
char* c=a;
assert((a!=NULL)&&(b!=NULL));
while((*c++=*b++)!='\0');
return a;
}
class CString
{ 
    private:
    	char*str;
	public:
		CString(const char s[])
		{
			str=new char[50];	
			strcpy(str,s);	//把s复制到str当中，返回char类型 
		}
		char* GetString();
		~CString()
		{
			if(str!=NULL)
		    {
		     	delete[]str;
			}
		}
};
char* CString::GetString()
{
	char *q=new char[50];//把str复制到q当中,返回char类型 
	strcpy(q,str);
	return q;            //q回到主函数后赋给p 
}
int main()
{
	CString KS("Internal String"); 
	const char *p=KS.GetString(); 
	cout<<p<<endl;
}


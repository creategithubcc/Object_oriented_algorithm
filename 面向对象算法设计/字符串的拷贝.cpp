#include <iostream>
#include<assert.h>
using namespace std;
char* strcpy(char* a,const char* b)//�����ַ��� 
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
			strcpy(str,s);	//��s���Ƶ�str���У�����char���� 
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
	char *q=new char[50];//��str���Ƶ�q����,����char���� 
	strcpy(q,str);
	return q;            //q�ص��������󸳸�p 
}
int main()
{
	CString KS("Internal String"); 
	const char *p=KS.GetString(); 
	cout<<p<<endl;
}


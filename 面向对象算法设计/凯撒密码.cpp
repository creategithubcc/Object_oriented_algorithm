#include<iostream>
#include <string.h>
using namespace std; 
int main()
{	
	char str[10086]; 	
	int len=0,i,m;	
	gets(str);	
	len=strlen(str);	
	for(i=0;i<=25;i++)
	{	
		for(m=0;m<len;m++)
		{								
			if(str[m]==' ') //���ж����޿ո񣬲�Ȼ��ֱ�ӱ��/ 
			{
				continue;	
			}
			str[m]=str[m]+1;//��ʼ��λ 
			if(str[m]>'Z')//�жϴ���z����a ���������㷨Ҫ���ղ���д���������� 
			{
				str[m]='A';
			}	
		}	
		cout<<"������Ϣ����Ϊ��"<<"��"<<i+1<<"��"<<endl;	
		puts(str);	
	}
	return 0; 
}

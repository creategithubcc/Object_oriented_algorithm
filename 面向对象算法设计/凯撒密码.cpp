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
			if(str[m]==' ') //先判断有无空格，不然会直接变成/ 
			{
				continue;	
			}
			str[m]=str[m]+1;//开始移位 
			if(str[m]>'Z')//判断大于z返回a 以上三个算法要按照步骤写，否则会出错 
			{
				str[m]='A';
			}	
		}	
		cout<<"加密信息可能为："<<"第"<<i+1<<"种"<<endl;	
		puts(str);	
	}
	return 0; 
}

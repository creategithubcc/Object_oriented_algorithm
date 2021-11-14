#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int a[100];
void function(void *a,int b,int c)
{
	char *e=static_cast<char*>(a);//void*强制转换成char* 
	for(int i=0;i<b;i++)          //再用for循环赋值 
	{
		e[i]=c;
	}
}
int main()
{
	int c,d;
	void* b=static_cast<int*>(a);
	while(scanf("%d %d",&c,&d)!=EOF)
	{
		memset(a,0,sizeof(a));
		function(b,c,d);
		for(int i=0;i<(c+3)/4;i++)//由于int是四个字节的，因
		{                         // 此在输入超过四个字节时
			printf("%#x\n",a[i]);// 会重新加入0x 
		 } 
	}	
}

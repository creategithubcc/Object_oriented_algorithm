#include<iostream>
#include<stdio.h>
using namespace std; 

int n,n2,n3,n4;
int b=0,ans=0;
int arr[10001];
int main()
{
	cin>>n;//1
    for(int i=0;i<n;i++) 
    {
    	cin>>n2>>n3;//8  4
    }
    for(int i=0;i<n2;i++)
    {
    	cin>>n4;//1 2 -3 -4 -5 6 -7 -8
    	arr[i]=n4;
	}
	for(int i=n3;i<=n2;i++)//i从第四位开始一直到第n2位，表示每次加的数量，从最小连续的四开始 
	{
		for(int j=0;j<j+i;j++)//这个循环从arr【0】开始后的每i个数相加，一直到j=n2-i个数后 
		{
			for(int k=j;k<j+i;k++)//循环相加算出价值 
			{
				b+=arr[k];
			}
			if(ans<b)//如果当前的b比ans要大时则把b赋值给ans 
			{
				ans=b;	
			}
			b=0;//清空b 
			if(j==n2-i)//如果j=n2-i的话表示这次是最后一次相加，于是可以在这里break回到最开始的循环进行下一步的相加 
			{
				break;
			}
		}
	}
	cout<<ans<<endl;
}

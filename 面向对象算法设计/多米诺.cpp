#include<stdio.h>
#include<iostream>
using namespace std;
long int a[32]={0};

int main()
{
	int n=0;
	a[0]=1;
	a[2]=3;
    for(int i=4;i<32;i+=2)
	{
        a[i]=4*a[i-2]-a[i-4];
    }
    while(scanf("%d",&n)!=EOF&&n!=-1)
	{
		cout<<a[n]<<endl;
    }
} 


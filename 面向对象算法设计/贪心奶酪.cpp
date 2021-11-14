#include<stdio.h>
#include<iostream>
using namespace std;
int a[10086],b[10086];
int main()
{
    int n=0,m=0;
    int i=0;
    long long int ans=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
    	scanf("%d%d",a+i,b+i);
	}
    for(i=1;i<n;i++)
    {
    	a[i]=min(a[i-1]+m,a[i]);
	}
    for(i=0;i<n;i++)
    {
    	ans+=a[i]*b[i];
	}
    cout<<ans<<endl;
}

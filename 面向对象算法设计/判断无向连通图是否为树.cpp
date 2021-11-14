#include<stdio.h> 
#include<iostream> 
using namespace std;
int a[100][100]; 
int n,i,j,k,ans; 
int main() 
{ 
	cin>>n;
	for(i=0;i<n;++i) 
	{
		for(j=0;j<n;++j) 
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;++i) 
	{
		for(j=0;j<n;++j) 
		{
			ans+=a[i][i+j];
		}
	}
	if(ans==n-1)
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}
}

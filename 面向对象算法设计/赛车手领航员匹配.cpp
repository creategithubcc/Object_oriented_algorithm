#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std; 
int n,n1,n2,t,ans=0;
int arr[10001],arr2[10001];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>n1;
		arr[i]=n1;
	}
	for(int i=0;i<n;i++)
	{
		cin>>n2;
		arr2[i]=n2;
	}
	for(int i=0;i<n;i++)//将赛车手数组内的数字交换大小 排序 
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++)//将领航员数组内的数字交换大小 排序 
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr2[j]<arr2[j+1])
			{
				t=arr2[j];
				arr2[j]=arr2[j+1];
				arr2[j+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++)//查找数字完全一样的人，如果有则匹配到一起，删掉数组，其余数组个进一 
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i]==arr2[j])
			{
				for(int k=i;k<n;k++)
				{
					arr[k]=arr[k+1];
				}
				for(int k=j;k<n;k++)
				{
					arr2[k]=arr2[k+1];
				}
				break;
			}
		}
	}
	for(int i=0;i<n;i++)//俩俩对比求绝对值再相加 
	{
		ans+=abs(arr[i]-arr2[i]);	
	}
	cout<<ans<<endl;
} 

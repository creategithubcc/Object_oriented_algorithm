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
	for(int i=0;i<n;i++)//�������������ڵ����ֽ�����С ���� 
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
	for(int i=0;i<n;i++)//���캽Ա�����ڵ����ֽ�����С ���� 
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
	for(int i=0;i<n;i++)//����������ȫһ�����ˣ��������ƥ�䵽һ��ɾ�����飬�����������һ 
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
	for(int i=0;i<n;i++)//�����Ա������ֵ����� 
	{
		ans+=abs(arr[i]-arr2[i]);	
	}
	cout<<ans<<endl;
} 

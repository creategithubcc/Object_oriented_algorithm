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
	for(int i=n3;i<=n2;i++)//i�ӵ���λ��ʼһֱ����n2λ����ʾÿ�μӵ�����������С�������Ŀ�ʼ 
	{
		for(int j=0;j<j+i;j++)//���ѭ����arr��0����ʼ���ÿi������ӣ�һֱ��j=n2-i������ 
		{
			for(int k=j;k<j+i;k++)//ѭ����������ֵ 
			{
				b+=arr[k];
			}
			if(ans<b)//�����ǰ��b��ansҪ��ʱ���b��ֵ��ans 
			{
				ans=b;	
			}
			b=0;//���b 
			if(j==n2-i)//���j=n2-i�Ļ���ʾ��������һ����ӣ����ǿ���������break�ص��ʼ��ѭ��������һ������� 
			{
				break;
			}
		}
	}
	cout<<ans<<endl;
}

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int c;
int function(double b,int n,double a[])
{
    int sum;
    sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=int(a[i]/b);
    }
    return sum>=c;
}
int main()
{
    int lmax=-1,n;
	double a[100086],low=0.0,hig=100000.0,mid;
	scanf("%d %d",&n,&c);
    if((n+c!=0))
    {
    	int i;
        for(i=1;i<=n;i++)
        {
        	scanf("%lf",&a[i]);
		}
		i=1000;
        while(i--)
		{
			mid=(low+hig)/2;
			if(function(mid,n,a))
				low=mid;
			else
				hig=mid;
		}
    	//printf("%.2f\n",mid);
    	printf("%0.2f\n",floor(hig*100)/100);
	}
	else
	{
		
	}
    return 0;
}

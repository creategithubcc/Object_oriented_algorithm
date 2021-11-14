#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
int main()
{
	char d1[100086],d2[100086],op;
	int b1[100086],b2[100086],c1[100086];
	int i,j,k,p,q,jiahao,d;
	scanf("%s",&d1);
	scanf("%s",&d2);
	memset(b1,0,sizeof(b1));
	memset(b2,0,sizeof(b2));
	memset(c1,0,sizeof(c1));

	p=strlen(d1);
	q=strlen(d2);
	for(i=0;i<p;i++)
	{
		b1[i]=d1[p-i-1]-'0';
	}
	for(j=0;j<q;j++)
	{
		b2[j]=d2[q-j-1]-'0';
	}
			for(i=0;i<p;i++)
			{
				for(j=0;j<q;j++)
				{
					c1[i+j]+=b1[i]*b2[j];
				}
			}
			k=p+q;
			for(i=0;i<=k;i++)
			{
				if(c1[i]>=10)
				{
					c1[i+1]+=c1[i]/10;
					c1[i]%=10;
				}
			}
			d=k;
			while(c1[d]==0)d--;
			if(d<0)
			{
				printf("0");
			}
			else
			{
				for(;d>=0;d--)
				{
					printf("%d",c1[d]);
				}
			}
			printf("\n");
}

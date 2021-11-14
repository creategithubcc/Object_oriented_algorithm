#include<iostream>
#include<algorithm>
using namespace std;
struct jiedian
{
	long long int sj;
	int f;
}bb[2000001];
bool cmp(struct jiedian x, struct jiedian y)
{
	if(x.sj==y.sj)
	{
		return x.f>y.f;
	}
	else if(x.sj!=y.sj)
	{
		return x.sj<y.sj;
	}	
}
long long int aa,zz;
int n,cot=0,ans=0,i,j,tt=0;
int main()
{
	//cin>>n;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%lld %lld",&aa, &zz);
		//cin>>aa>>zz;
		bb[cot].sj=aa;
		bb[cot++].f=-1;
		bb[cot].sj=zz;
		bb[cot++].f=1;
	}
	sort(bb,bb+cot,cmp);
	for(i=0;i<cot;++i)
	{
		if(bb[i].f==1)
		{
			tt=tt-1;
		}	
		else if(bb[i].f==-1)
		{
			tt=tt+1;
		}
		if(ans<tt)
		{
			ans=tt;
		}		
	}
	cout<<ans<<endl;
	return 0;
}

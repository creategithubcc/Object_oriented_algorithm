#include<stdio.h> 
#include<map> 
#include<iostream> 
using namespace std; 
char aa[1086][1086]; 
int bb[1086][1086]; 
int hg=0,len=0,ans=0,num=0; 
int i,j,k,l,a,b;
char c;
map<char,int>p; 
map<char,int>q; 
typedef pair<char,int>r; 
int cmp(const r&x,const r&y) 
{ 
	return y.first<x.first; 
} 
int fuc(int z)
{
	z+=1;
	return z;
}
int main() 
{ 
	while(gets(aa[hg])!=NULL) 
	{ 
		for(i=0;aa[hg][i];++i) 
		{ 
			if(aa[hg][i]!=' ') 
			{ 
				c=aa[hg][i]; 
				if(p.count(c)==0) 
				{
					p.insert(pair<char,int>(c,0));
				} 
				if(q.count(c)==0) 
				{
					q.insert(pair<char, int>(c,0)); 
				}	
			} 
		} 
		if(p.size()>len)
		{
			len=p.size();
		 } 
		p.clear(); 
		l=fuc(hg);
		hg=l;
	} 
	map<char, int>::iterator it=q.begin();
	while(it!=q.end()) 
	{ 
		it->second=ans++; 
		it++; 
	} 
	for(i=0;i<hg;++i) 
	{ 
		a=q.find(aa[i][0])->second; 
		for(j=1;aa[i][j];++j) 
		{ 
			if(aa[i][j]!= ' ') 
			{ 
				b=q.find(aa[i][j])->second; 
				bb[a][b]+=1; 
			} 
		} 
	} 
	len=q.size(); 
	for(i=0;i<len;++i) 
	{ 
		for(j=0;j<len;++j) 
		{ 
		    if(j!=len-1) 
			{
				cout<<bb[i][j]<<" ";
			} 
			else if(j==len-1)
			{
				cout<<bb[i][j]<<endl;
			} 
		} 
	} 
}  

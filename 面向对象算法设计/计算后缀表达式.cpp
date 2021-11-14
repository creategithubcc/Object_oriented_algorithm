#include<cstdio> 
#include<stack> 
#include<map>
#include<iostream> 
using namespace std; 
stack<int>p;
int i,j,k,l,a,b,num;
int func(char c,int x,int y) 
{ 
	switch (c) 
	{ 
		case('+'):
			return x+y; 
		case('-'):
			return x-y; 
		case('*'):
			return x*y; 
		case('/'):
			return x/y; 
	} 
}  
void function(string aa) 
{ 
	for(i=0;aa[i];++i) 
	{ 
		if(aa[i]>'9'||aa[i]<'0')
		{ 
		    if(p.size()>=2)
			{ 
				a=p.top();
				p.pop(); 
				b=p.top();
				p.pop(); 
				if(a==0&&aa[i]=='/') 
				{ 
				  	cout<<"DIV0!"<<endl;
				 	return; 
				} 
				num=func(aa[i],b,a); 
				p.push(num); 
			} 
			else if(p.size()<2) 
			{ 
				cout<<"ERROR!"<<endl;
				return; 
			} 
		} 
		else if(aa[i]<='9'&&aa[i]>='0') 
		{ 
			num=aa[i]-'0'; 
			p.push(num); 
		} 
	} 
	if(p.size()>1) 
	{ 
		cout<<"ERROR!"<<endl;
		return; 
	} 
	cout<<p.top()<<endl;
} 
int main() 
{ 
	string aa; 
	getline(cin,aa); 
	function(aa); 
}  

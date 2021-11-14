#include<iostream> 
using namespace std; 
class CPointer 
{ 
	private: 
		int p,q; 
	public: 
		CPointer(int x,int y) 
		{ 
			p=x; 
			q=y; 
		} 
		//~CPointer();
		CPointer(const CPointer &p2) 
		{
			p=p2.p;
			q=p2.q; 
		} 
		int getX()            
		{  
			return p; 
		} 
		int getY()            
		{  
			return q; 
		} 
	
};  
int main() 
{ 
	CPointer p1(10,20); 
	CPointer p2=p1;  
	cout<<"p1.p="<<p1.getX()<<",p1.q="<<p1.getY(); 
	cout<<"\np2.p="<< p2.getX()<<",p2.q="<<p2.getY();
}

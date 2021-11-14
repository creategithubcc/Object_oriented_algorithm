#include <iostream>
using namespace std;
class  CArray
{
private:
     char*str;
     int length;  // elements number
     int size;     // storage number
     // Other variables are here.
public:
     CArray(char* a)
     {
     	str=new char[50];
	 }
	 void Copy(char*);
	 ~CArray()
     {
     	 if(str!=NULL)
	     {
	     	delete[]str;
		 }
	 }
    // Member functions are here.
};
void CArray::Copy(char*ch)
{
	int i=0;
	while(ch[i]!='\0')
	{
		str[i]=ch[i];
		i++;
	}
	str[i]=ch[i];
	cout<<str<<endl;
}
int main()
{
	
        CArray arr("Hello world!");
        // ¡°Hello world!¡± is stored in arr.
        arr.Copy("Hello world!");
}


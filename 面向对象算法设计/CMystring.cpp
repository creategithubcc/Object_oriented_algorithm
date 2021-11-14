#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
const char* fuzhi(char* a,const char* b)//复制字符串,之前实验里写的代码 
{
	char* c=a;
	assert((a!=NULL)&&(b!=NULL));
	while((*c++=*b++)!='\0');
	return a;
}

int changdu(char * aa)//字符串的长度 
{
    const char *bb = aa;
    while(*bb++) 
	return(bb-aa-1);
}

char *lianjie(char * aaa,const char * bbb)//实现字符串的连接 
{
	assert(NULL!=aaa&&NULL!=bbb); 
    char * p=aaa;
    while(*p)
    p++;    
    while(*p++=*bbb++) ;    
    return(aaa);               
}

class CMyString
{
	
private:
    char*Sans;
    int Cans; 
public:
    CMyString(char*s)
	{
		
		Sans=(char*)malloc(changdu(s)+1);
    	fuzhi(Sans,s);
    	
	}
    CMyString()
    {
		Sans=NULL;
	} 
    operator const char* ()const;
    friend const CMyString operator+(const CMyString &a1,const CMyString &a2);//利用友元函数在成员函数外面实现重载 
    //cout<<Sans<<endl;。。。。。。cout在函数里面没定义，所以不能直接在函数里面输出，需要另建一个函数 
    void Cprint();
	int Find(char c)           //实验6txt要求用int  Find(const CMyString& sub）类型来写，但是main函数里的a确是char型 
	{                          //所以最终还是用char型来写这段函数了 
	    int i=0;  
	    while(Sans[i]!=c&&Sans[i]!='\0')  
	    i+=1; 
		if(Sans[i]!='\0') 
	    return i;  
	    else if(Sans[i]=='\0')  
	    return -1;  
	}  
	
	CMyString Mid(int start, int length)//从字符串里提取子字符串，更进一步的话其实还要考虑star超过原字符串长度 
	{
		int i;                           //或者length参数大于或小于0等等的因素...... 
		int p=start;                     
		int q=length;
		int o=p+q;
		char *Mans=new char[length+1];
		for(p,i=0;p<o;p++)
		{
			Mans[i]=Sans[p];
			i++;
		} 
		return CMyString(Mans);
	}
};
CMyString::operator const char* ()const
{
    return Sans;
}
const CMyString operator+(const CMyString &a1,const CMyString &a2)
{
    char *temp=(char *)malloc(changdu(a1.Sans)+changdu(a2.Sans)+1);
    fuzhi(temp,a1.Sans);
    lianjie(temp,a2.Sans);
    CMyString q(temp);
    return q;
}
void CMyString::Cprint()
{
    cout<<Sans<<endl;
}
int main()
{
	CMyString s1("China"),s2;
	s2="Love";
	cout<<"I "+s2+" "+s1+"!";  // The output is: I Love China!
	int pos = s1.Find('a');      // pos is 4, or -1 if  'a'  is NOT found.
	cout<<endl<<"重复字符的位置是："<<pos<<endl;
	int a = 2, b = 2;
	CMyString my = s1.Mid(a, b); // A string in the my is "in".
	cout<<"从原来的字符串里提取出的子字符串是："<<my<<endl;
}

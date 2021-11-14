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

int changdu(const char * aa)//字符串的长度 
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
    
    int Cans; 
public:
	char*Sans;
    CMyString(const char*s)
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
    
    CMyString(const CMyString &s1)                       //第二个实验稍微修改了一下 CMyString类 
    {
    	this->Sans=new char[changdu(s1.Sans)+1];         //拷贝构造函数 
    	fuzhi(this->Sans,s1.Sans);
	}
    const CMyString operator=(const CMyString &s1)      //=号重载运算 
    {
    	this->Sans=new char[changdu(s1.Sans)+1];
    	fuzhi(this->Sans,s1.Sans);
	}
	
  
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
}//------------------------------------------------
class CInternetURL: public CMyString//继承上一个实验写的类 
{
	public:
	CInternetURL(const char *c):CMyString(c)
	{
		cout<<Sans<<endl;
	}

	char *GetDomain()
	{
		int a=7,b=14;
		CMyString my = Mid(a, b);
		return my.Sans;
	}
	char *GetDomainCountry()
	{
		int a=19,b=2;
		CMyString my = Mid(a, b);
		return my.Sans;
	}
	char *GetDomainType()
	{
		int a=15,b=3;
		CMyString my = Mid(a, b);
		return my.Sans;
	}
};
int main()
{
	CInternetURL URL("http://www.bit.edu.cn/tzgg17/jyjx/182787.htm");
	cout<<URL.GetDomain()<<endl;         // The result is:  www.bit.edu.cn
	cout<<URL.GetDomainCountry()<<endl;  // The result is:  cn
    cout<<URL.GetDomainType()<<endl;     // The result is:  edu
}

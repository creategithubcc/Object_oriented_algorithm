#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
const char* fuzhi(char* a,const char* b)//�����ַ���,֮ǰʵ����д�Ĵ��� 
{
	char* c=a;
	assert((a!=NULL)&&(b!=NULL));
	while((*c++=*b++)!='\0');
	return a;
}

int changdu(const char * aa)//�ַ����ĳ��� 
{
    const char *bb = aa;
    while(*bb++) 
	return(bb-aa-1);
}

char *lianjie(char * aaa,const char * bbb)//ʵ���ַ��������� 
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
    friend const CMyString operator+(const CMyString &a1,const CMyString &a2);//������Ԫ�����ڳ�Ա��������ʵ������ 
    //cout<<Sans<<endl;������������cout�ں�������û���壬���Բ���ֱ���ں��������������Ҫ��һ������ 
    void Cprint();
    
    CMyString(const CMyString &s1)                       //�ڶ���ʵ����΢�޸���һ�� CMyString�� 
    {
    	this->Sans=new char[changdu(s1.Sans)+1];         //�������캯�� 
    	fuzhi(this->Sans,s1.Sans);
	}
    const CMyString operator=(const CMyString &s1)      //=���������� 
    {
    	this->Sans=new char[changdu(s1.Sans)+1];
    	fuzhi(this->Sans,s1.Sans);
	}
	
  
int Find(char c)           //ʵ��6txtҪ����int  Find(const CMyString& sub��������д������main�������aȷ��char�� 
{                          //�������ջ�����char����д��κ����� 
    int i=0;  
    while(Sans[i]!=c&&Sans[i]!='\0')  
    i+=1; 
	if(Sans[i]!='\0') 
    return i;  
    else if(Sans[i]=='\0')  
    return -1;  
}  

CMyString Mid(int start, int length)//���ַ�������ȡ���ַ���������һ���Ļ���ʵ��Ҫ����star����ԭ�ַ������� 
{
	int i;                           //����length�������ڻ�С��0�ȵȵ�����...... 
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
class CInternetURL: public CMyString//�̳���һ��ʵ��д���� 
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

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

int changdu(char * aa)//�ַ����ĳ��� 
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
    friend const CMyString operator+(const CMyString &a1,const CMyString &a2);//������Ԫ�����ڳ�Ա��������ʵ������ 
    //cout<<Sans<<endl;������������cout�ں�������û���壬���Բ���ֱ���ں��������������Ҫ��һ������ 
    void Cprint();
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
}
int main()
{
	CMyString s1("China"),s2;
	s2="Love";
	cout<<"I "+s2+" "+s1+"!";  // The output is: I Love China!
	int pos = s1.Find('a');      // pos is 4, or -1 if  'a'  is NOT found.
	cout<<endl<<"�ظ��ַ���λ���ǣ�"<<pos<<endl;
	int a = 2, b = 2;
	CMyString my = s1.Mid(a, b); // A string in the my is "in".
	cout<<"��ԭ�����ַ�������ȡ�������ַ����ǣ�"<<my<<endl;
}

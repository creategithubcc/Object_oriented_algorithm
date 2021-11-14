#include <iostream>
using namespace std;
class C
{
	public:
    C():ans(6)
	{
		cout<<"A="<<ans<<endl;
	}

    C(int i):ans(i) 
	{ 
		cout<<"B="<<ans<<endl;
	}
    ~C() 
	{
		cout<<"C="<<ans<<endl;
	}
	private:
    int ans;
};

int main() 
{
    cout<<"X\n";
    C*c=new C;
    C stackC;
    cout<<"Y\n";
    delete c;
    cout<<"Z\n";
}

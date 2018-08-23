/*基本计算*/
#include<iostream>
using namespace std;
 
int main()
{
	int i,j;
	cout<<"input:";
	cin>>i>>j;
	cout<<i+j<<endl;
	cout<<i-j<<endl;
	cout<<i*j<<endl;
	cout<<i/j<<endl;
	/*测试溢出*/
	short n=32767,m;//short最大值
	cout<<"n="<<n<<endl;
	m=n+1;
	cout<<"m="<<m<<endl;
	return 0;
}
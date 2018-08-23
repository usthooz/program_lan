/*进制相关*/
#include<iostream>
using namespace std;
 
int main()
{
		int a=010,b=10,c=0x10;
 
		//十进制
		cout<<"DEC:"<<endl;
		cout<<"a="<<a<<endl;
		cout<<"b="<<b<<endl;
		cout<<"c="<<c<<endl;
		cout<<endl;
 
		//八进制
		cout<<"OCT:"<<endl;
		cout<<oct;
		cout<<"a="<<a<<endl;
		cout<<"b="<<b<<endl;
		cout<<"c="<<c<<endl;
		cout<<endl;
 
		//十六进制
		cout<<"HEX:"<<endl;
		cout<<hex;
		cout<<"a="<<a<<endl;
		cout<<"b="<<b<<endl;
		cout<<"c="<<c<<endl;
 
		//混合运算输出
		cout<<"a+b+c=";
		cout<<dec;
		cout<<a+b+c<<endl;
 
		return 0;
}
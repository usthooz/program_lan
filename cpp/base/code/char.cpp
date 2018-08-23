/*char*/
#include<iostream>
using namespace std;
 
int main()
{
	//字符变量声明
	char c1='A';
	char c2;
 
	//字符数据运算及输出
	c2=c1+32;
	cout<<"c="<<c1<<endl;
	cout<<"c2="<<c2<<endl;
 
	//字符及ASCII输出
	cout<<c1<<":"<<int(c1)<<endl;
	cout<<c2<<":"<<int(c2)<<endl;
	cout<<'&'<<int('&')<<endl;
 
	//输入字符
	cout<<"c1 c2"<<endl;
	cin>>c1>>c2;
	cout<<"c1="<<c1<<" c2="<<c2<<endl;
 
	return 0;
 
}
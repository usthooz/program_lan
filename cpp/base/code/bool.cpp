/*bool(0,1,false,true)*/
#include<iostream>
using namespace std;
 
int main()
{
	//声明bool变量并初始化
	bool xc1=false,xc2=true;
 
	//输出bool变量及常量
	cout<<"false:"<<false<<endl;
	cout<<"true:"<<true<<endl;
	cout<<"xc1:"<<xc1<<endl;
	cout<<"xc2:"<<xc2<<endl;
 
	//bool变量的赋值与输出
	int a=3;
	xc1=a>0;
	cout<<"xc1="<<xc1<<endl;
	xc2=xc1;
	cout<<"xc2:"<<xc2<<endl;
 
	//bool超界处理
	xc1=100;
	xc2=-200;
	cout<<"xc1:"<<xc1<<endl;
	cout<<"xc2:"<<xc2<<endl;
 
	return 0;
}

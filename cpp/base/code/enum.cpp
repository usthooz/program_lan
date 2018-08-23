/*enum*/
#include<iostream>
using namespace std;
 
int main()
{
	//定义枚举类型，并为枚举元素赋值
	enum num{
		one=1,
		two=2,
		three=3
	};
	//声明枚举变量并赋值
	enum num a=two;
	num b;//在C++中是允许的（struct也可以）
 
	//输出枚举常量
	cout<<"one:"<<one<<endl;
	cout<<"two:"<<two<<endl;
	cout<<"three:"<<three<<endl;
 
	//枚举变量的赋值和输出
	b=a;
	a=one;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
 
	//关系运算
	b=three;
	cout<<"a<b="<<(a<b)<<endl;
 
	return 0;
 
}

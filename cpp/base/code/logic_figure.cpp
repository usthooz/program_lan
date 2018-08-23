/*逻辑运算与关系运算*/
#include <iostream.h>
using namespace std;
main()     
{
    float a=3.5,b=2.1,c=0;
    cout<<"a="<<a<<"  b="<<b<<"  c="<<c<<endl;
 
    //与运算
    cout<<"a&&b="<<(a&&b)<<endl;//输出1
    cout<<"a&&c="<<(a&&c)<<endl;//输出0
 
    //或运算
    cout<<"a||b="<<(a||b)<<endl;//输出1
    cout<<"a||c="<<(a||c)<<endl;//输出1
 
    //非运算
    cout<<"!a="<<!a<<endl<<"!c="<<!c<<endl;//输出0  1
 
    //关系运算和逻辑运算
    bool flag=a>=0 && a<=5;  //变量a在[0,5]区间内
    cout<<"a=>0 && a<=5="<<flag<<endl;//输出1
 
    //算术运算、关系运算和逻辑运算
    cout<<"a+5>2*b+2||a<b+3="<<(a+5>2*b+2||a<b+3)<<endl;//输出1
}

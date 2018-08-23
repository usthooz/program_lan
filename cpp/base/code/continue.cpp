#include<iostream>
using namespace std;
main()
{
    //累加键盘输入的数据
    double x,sum=0.0;
    while(1) {
        cout<<"x=";
        cin>>x;
        if (x<=0) continue;
        sum+=x;
    }
    cout<<"sum="<<sum<<endl;
}

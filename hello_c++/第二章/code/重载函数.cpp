#include <iostream>
#include <fstream>
using namespace std;

// 定义第一个 Add()函数，使其可以计算两个 int 型数据的和
int Add( int a, int b )
{
 cout<<"int Add( int a, int b )被调用！"<<endl;
 return a + b;
}
// 重载 Add()函数，对其进行重新定义，
// 使其可以计算两个 double 型数据的和
double Add( double a, double b )
{
 cout<<" double Add( double a, double b )被调用！"<<endl;
 return a + b;
}
int main()
{
// 因为参数是整型数，其类型、个数
// 与 int Add( int a, int b )匹配
 // 所以 int Add( int a, int b )被调用
 int nSum = Add(2,3);
 cout<<" 2 + 3 = "<<nSum<<endl;
 
// 作为参数的小数会被表示成 double 类型，
// 其类型、个数与 double Add( double a, double b )匹配
 // 所以 double Add( double a, double b )被调用
 double fSum = Add(2.5,10.3);
cout<<" 2.5 + 10.3 = "<<fSum<<endl;
return 0;
}


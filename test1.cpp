#include<iostream>
using namespace std;
class complex
{
    public:
    complex(double r=0.0,double i=0.0){
        real=r;
        imag=i;
    }
    complex operator +(const complex &c);//函数重载
    complex operator -(const complex &c);//
    void display();
    private:
    double real;
    double imag;
};
complex complex::operator +(const complex &c){
    return complex(this->real+c.real,this->imag+c.imag);
}
complex complex::operator -(const complex &c){
    return complex(this->real-c.real,this->imag-c.imag);
}
void complex::display(){
    if(imag>0)
        cout<<real<<"+"<<imag<<'i'<<endl;
    else{
        cout<<real<<imag<<'i'<<endl;
    }
}
int main(){
    complex c1(5,4),c2(2,10),c3;  
	cout<<"c1=";   
	c1.display();
	cout<<"c2=";   
	c2.display();
	c3=c1-c2;	
	cout<<"c1-c2=";
	c3.display();
	c3=c1+c2;	
	cout<<"c1+c2=";
	c3.display();
	system("pause");
	return 0;
}
// 重载规则
/*（1）不能改变运算符的优先级；
（2）不能改变运算符的结合型；
（3）默认参数不能和重载的运算符一起使用；
（4）不能改变运算符的操作数的个数；
（5）不能创建新的运算符，只有已有运算符可以被重载；
（6）运算符作用于C++内部提供的数据类型时，原来含义保持不变。
 重载后运算符的含义应该符合原有用法习惯。例如重载+运算符，完成的功能就应该类似于做加法，在重载的+运算符中做减法是不合适的。此外，重载应尽量保留运算符原有的特性。
 C++ 规定，运算符重载不改变运算符的优先级。
 以下运算符不能被重载：.、.*、::、? :、sizeof。
 重载运算符()、[]、->、或者赋值运算符=时，只能将它们重载为成员函数，不能重载为全局函数。 */
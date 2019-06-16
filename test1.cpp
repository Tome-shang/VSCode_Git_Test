#include<iostream>
using namespace std;
class complex
{
    public:
    complex(double r=0.0,double i=0.0){
        real=r;
        imag=i;
    }
    complex operator +(const complex &c);
    complex operator -(const complex &c);
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
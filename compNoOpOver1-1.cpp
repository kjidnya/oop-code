#include<complex>
#include<iostream>
using namespace std;

class Complex
{
	private:
		double real;
		double imag;
		
	public:
		Complex():real(0.0),imag(0.0) {
		cout<<"Default Constructor Called"<<endl;}
		Complex(double r,double i):real(r),imag(i) {
		cout<<"Parameterised Constructor Called"<<endl;
		}
	
	void display()
	{
		cout<<real<<(imag>=0 ?"+":"-")<<abs(imag)<<"i"<<endl;
		
	} 
};

int main()
{
	cout<<"\Vaishnavi"<<endl;
	Complex defaultComplex;
	Complex customComplex(3.0,-2.5);
	
	cout<<"Default Complex Number:"<<endl;
	defaultComplex.display();
	
	cout<<"Custom Complex Number:"<<endl;
	customComplex.display();
	
	return 0;
}

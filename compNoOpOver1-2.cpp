#include<complex>
#include<iostream>
using namespace std;

int main()
{
	complex<double>a(4.0,2.0);
	complex<double>b(2.0,1.0);
	
	complex<double>sum = a+b;
	complex<double>subtract = a-b;
	complex<double>product = a*b;
	complex<double>division = a/b;
	complex<double>magnitude = abs(a);
	complex<double>conjugate = conj(a);
	
	
	cout<<"jidnyasa kale"<<endl;
	cout<<"A is:"<<a<<endl;
	cout<<"B is:"<<b<<endl;
	cout<<"Addition is:"<<sum<<endl;
	cout<<"Subtraction is:"<<subtract<<endl;
	cout<<"Multiplication is:"<<product<<endl;
	cout<<"Division is:"<<division<<endl;
	cout<<"Magnitude is:"<<magnitude<<endl;
	cout<<"Conjugate is:"<<conjugate<<endl;
	
	
	return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>
//f(x) = e^-x - x -> guess qualquer para newton e picard-peano
//f(x) = x^10 - 1 -> x0 = 0.5 - TPC fazer esta função com newton e picard-peano


using namespace std;

float fx(float x){
	return exp(-x)-x;
	//return x*x*x*x*x*x*x*x*x*x - 1;
}

float gx(float x){
	return exp(-x);
}

int main(){

	float x0=0,xn=0.0;
	do {
		x0=xn;
		xn = gx(x0);
		cout << "it(Xn-x0)= " << setprecision(15) << xn << endl;
	} while(abs(x0-xn)>1e-7);

	cout << "Xn :" << setprecision(15) << xn;
	cin.get();
	cin.ignore();

	return 0;
}
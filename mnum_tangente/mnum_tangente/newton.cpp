#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


float fx(float x){
	//return exp(-x) - x;
	return (x*x*x*x) - (2*x*x*x) - x  -1 ;
}

float dfx (float x){
	//return -exp(-x) -1 ;
	return 4*x*x*x - 6*x*x -1;
}

float newton(float x){
	cout << "newton: " << x - fx(x)/dfx(x) << endl;
	return x - fx(x)/dfx(x);
}

int main(){
	float xn=2,xna=0;
	int i=0;
	do {
		cout << "Iteration : " << i <<endl;
		i++;
		xna = xn;
		xn = newton(xn);
		cout << "xn : " << setprecision(10) << fixed << xn << endl;
		cout << "---- End Iteration -----" << endl;
	} while (abs(xn-xna)>1e-7);
	cout << "Root : " << setprecision(10) << fixed << xn;
	cin.get();
	cin.ignore();

	return 0;
}
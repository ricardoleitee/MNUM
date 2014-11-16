#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float f1 (float x, float y){
	return 2*x*x-x*y-5*x+1;
}

float f2 (float x, float y){
	return x+3*log10f(x)-y*y;
}

float g1(float x, float y){
	return sqrtf((x*(y+5)-1)/2);
}

float g2(float x, float y) {
	return sqrtf(x+log10f(x));
}


int main() {
	float xna=0,yna=0,xn=3.5,yn=2.3;
	int n=0;
	do {
		cout << " Iteration : " << n << endl;
		n++;
		yna = yn;
		xna = xn;
		xn = g1(xn,yn);
		yn = g2(xn,yn);
		cout << "Xn : " << setprecision(16) << fixed << xn << endl;
		//cout << "Xna : " << setprecision(16) << fixed << xna << endl;
		cout << "Yn : " << setprecision(16) << fixed << yn << endl;
		//cout << "Yna : " << setprecision(16) << fixed << yna << endl;

	} while (abs(xn-xna)>1e-7 && abs(yna-yn)>1e-7);

	cin.get();
	cin.ignore();
	return 0;
}
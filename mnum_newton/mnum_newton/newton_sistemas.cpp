#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


float f1(float x, float y){
	//return x-y*sin(x);
	return 2*x*x-x*y-5*x+1;
}

float f2(float x,float y){
	//return x-y*cos(x+y);
	return x+3*log10f(x)-y*y;
}

float df1x(float x, float y){
	//return 1-y*sin(x);
	return 4*x-y-5;
}

float df1y(float x, float y){
	//return x-sin(x)-y*cos(x);
	return 2*x*x-x-5*x;
}

float df2x(float x, float y){
	//return 1-y*cos(x+y);
	return 1+(1/(log10f(x)))-y*y;
}

float df2y(float x, float y) {
	//return x-cos(x+y)+y*sin(x+y);
	return x+3*log10f(x)-2*y;
}

float newton_x(float x, float y){
	return x-(f1(x,y)*df2y(x,y)-f2(x,y)*df1y(x,y))/(df1x(x,y)*df2y(x,y)-df2x(x,y)*df1y(x,y));
}

float newton_y(float x, float y){
	return y-(f2(x,y)*df1x(x,y)-f1(x,y)*df2x(x,y))/(df1x(x,y)*df2y(x,y)-df2x(x,y)*df1y(x,y));
}


int main(){
	float xn=1.46,xna=0,yn=-1.41,yna=0;
	float t1=0,t2=0;
	do {
		xna = xn;
		yna = yn;
		xn = newton_x(xn,yn);
		cout << "Xn : " << xn << endl;
		yn = newton_y(xn,yn);
		cout << "Yn : " << yn << endl;
		t1 = f1(xn,yn);
		t2 = f2(xn,yn);
		cout << "F(Xn) = " << t1 << endl;
		cout << "F(Yn) = " << t2 << endl;
	} while (abs(xna-xn)>1e-7 && abs(yna-yn)>1e-7) /*|| abs(t1-t2)> 1e-5)*/;

	cin.get();
	cin.ignore();

	return 0;
}
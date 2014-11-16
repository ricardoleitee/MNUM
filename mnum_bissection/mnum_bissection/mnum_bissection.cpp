#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

//Problema da pag. 128, falling parachutist problem
//Resolvido via método da bissecção

float fx(float x){
	//return 667.38/x * (1-exp(-0.146843*x))-40;
	return x*x*x*x + 2*x*x*x - x - 1;
}

float xu(float xl){
	do {
	float fxl = fx(xl);
	float fxu = fx(xl+1);
	if (fxl*fxu<0)
		return xl;
	else
		xl++;
	} while (true);
}

float bissection(float xl, float xu){
	return (xl+xu)/2;
}

/*A função stop contém o critério de paragem definido no livro, utilizando a função
|Ea| = | (xroot(new) - xroot(old)) / xroot(new) | * 100%
no entanto, nas aulas foi utilizado o método
dif(x) = | f(xroot(old)) - f(xroot(new)) | < 1e-7
cujo resultado da aproximação não é tão próximo do valor real da raiz como o da primeira função,
podendo até ser definido um erro aproximado (Ea) de 0, obtendo uma aproximação correcta da raiz a n casas decimais
*/


float stop(float xrn, float xro){
	return abs((xrn-xro)/xrn)*100;
}

int main(){
	float xl=0,xup=0,xr=0,xro=0;
	xl = 0;
	xup = 1;
	cout << "xl = " << xl << endl;
	unsigned int i=0;
	do {
		cout << "Iteration: " << i << endl;
		i++;
		xr = bissection(xl,xup);
		cout << "|Ea| = " << setprecision(4) << fixed << stop(xr,xro) << endl;
		float et = abs(((0.86674-xr)/0.86674)*100);
		cout << "Et = " << setprecision(4) << fixed << et << endl;
		if (stop(xr,xro)==0)
			break;
		xro = xr;
		cout << "xl = " << setprecision(4) << fixed << xl << endl;
		cout << "xu = " << setprecision(4) << fixed << xup << endl;
		cout << "xr = " << setprecision(4) << fixed << xr << endl;
		cout << "----- End Iteration -----" << endl;
		if (fx(xl)*fx(xr)<0)
			xup = xr;
		if (fx(xl)*fx(xr)>0)
			xl = xr;
	} while (/*abs(fx(xl)-fx(xr))<1e-7*/ true);

	cout << "Root: " << setprecision(4) << fixed << xr <<endl;
	int t = clock();
	cout << "Time Elapsed: " << t;
	cin.get();
	cin.ignore();
	return 0;
}
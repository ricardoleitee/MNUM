#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

//Problema da pag. 128, falling parachutist problem
//Resolvido via m�todo da corda (utilizando o modelo da bisse��o, mas mudando o passo 2 para false_position)
//foram tamb�m alteradas as condi��es de substitui��o do valor calculado para se enquadrarem no m�todo false_position

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

float false_position(float xl, float xu){
	return xu - (fx(xu)*(xl-xu))/(fx(xl)-fx(xu));
}

/*
A fun��o stop cont�m o crit�rio de paragem definido no livro, utilizando a fun��o
|Ea| = | (xroot(new) - xroot(old)) / xroot(new) | * 100%
no entanto, nas aulas foi utilizado o m�todo
dif(x) = | f(xroot(old)) - f(xroot(new)) | < 1e-7
cujo resultado da aproxima��o � t�o pr�ximo do valor real da raiz como o da primeira fun��o,
permitindo a defini��o de um erro relativo (Ea) de paragem 0-100, obtendo uma aproxima��o correcta da raiz a n casas decimais
*/


float stop(float xrn, float xro){
	return abs((xrn-xro)/xrn)*100;
}

int main(){
	float xl=0,xup=1,xr=1,xro=0; //xl - lower guess, xup - upper guess, xr - calculated root value, xro - previous calculated root value
	xl = 0;
	xup = 1;
	cout << "xl = " << xl << endl;
	unsigned int i=0;
	do {
		cout << "Iteration: " << i << endl;
		i++;
		xr = false_position(xl,xup);
		cout << "|Ea|, % = " << setprecision(15) << fixed << stop(xr,xro) << endl;  //erro relativo (referente � ra�z calculada na itera��o anterior)
		float et = abs((14.780208587646484-xr));
		cout << "|Et| = " << setprecision(15) << fixed << et << endl; //erro absoluto, comparando a ra�z calculada ao valor real da ra�z (hard-coded)
		if (stop(xr,xro)==0) //definir crit�rio de paragem ( e.g. erro < 0.5 ou erro == 0)
			break;
		xro = xr;
		cout << "xl = " << setprecision(15) << fixed << xl << endl;
		cout << "xu = " << setprecision(15) << fixed << xup << endl;
		cout << "xr = " << setprecision(15) << fixed << xr << endl;
		cout << "----- End Iteration -----" << endl;
		if (fx(xr)<0 && fx(xl)<0)
			xl = xr;
		if (fx(xr)>0 && fx(xl)>0)
			xl = xr;
		if (fx(xr)>0 && fx(xup)>0)
			xup = xr;
		if (fx(xr)<0 && fx(xup)<0)
			xup = xr;
	} while (/*abs(fx(xl)-fx(xr))<1e-7*/ true);

	cout << "Root: " << setprecision(15) << fixed << xr <<endl;
	int t = clock();
	cout << "Time Elapsed: " << CLOCKS_PER_SEC * t/1000; //o tempo decorrido � utilizado para poder inferir sobre o desempenho de cada algoritmo para a mesma fun��o
	cin.get();
	cin.ignore();
	return 0;
}
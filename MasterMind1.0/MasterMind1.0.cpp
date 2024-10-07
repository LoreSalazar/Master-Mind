#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

	const int cantidad_aleatorios = 4;
	char num_aleatorios[cantidad_aleatorios];
	int flag = 0, flag2 = 0, flag_resultado = 0;
	char trama_usuario[5];

	srand(time(NULL)); //Generación de números aleatorios

	for (int i = 0; i < cantidad_aleatorios; i++) {
		num_aleatorios[i] = 65 + rand() % (73 - 65);

		//if (i >= 1) {
		for (int j = 0; j < i; j++) {

			if (num_aleatorios[i] == num_aleatorios[j]) {
				num_aleatorios[i] = 65 + rand() % (73 - 65);
				j = -1;
			}
		}
		cout << num_aleatorios[i];
	}

	cout << "\nQue comience el juego, solo tienes 15 oportunidades para adivinar la trama \n";
	cout << "Pistas: solo hay letras de la A a la H y ninguna se repite\n";

	for (int i = 1; i <= 10; i++) {
		cout << "\nOportunidad " << i << " escribe una trama: ";
		cin >> trama_usuario;

		for (int k = 0; k <= 3; k++) {
			if (trama_usuario[k] == num_aleatorios[k]) {
				flag = flag + 1;
			}
		}

		cout << "Buenos: " << flag;
		if (flag == 4) {
			flag_resultado = 1;
		}
		flag = 0;

		for (int m = 0; m <= 3; m++) {
			for (int n = 0; n <= 3; n++) {
				if (trama_usuario[m] == num_aleatorios[n]) {
					if (m == n) {
						continue;
					}
					flag2 = flag2 + 1;
				}
			}
		}

		cout << "\nRegulares: " << flag2 << "\n";
		flag2 = 0;

		if (flag_resultado == 1) {
			cout << "\nFelicidades usted ha ganado";
			break;
		}
	}

	if (flag_resultado == 0) {
		cout << "\nUSTED ES UN PERDEDOR";
	}
}
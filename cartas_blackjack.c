/*
Departamento de programacion
7-1-2026
cartas_blackjack
*/
#include <stdio.h>

int main() {

    char valor='\0', palo='\0';
	int valorValido = 0;
	int paloValido = 0;
	int puntos = 0;

    printf("Introduce tu carta (valor palo): ");
    scanf(" %c %c", &valor, &palo);
	while (getchar()!='\n');

    /* Conversion manual a mayusculas (equivalente a toupper):
       si el caracter esta entre 'a' y 'z', restamos 32 para
       obtener su equivalente en mayuscula                     */
    if (valor >= 'a' && valor <= 'z') {
        //valor = valor - 32;
		valor = valor - ('a'-'A');
    }
    if (palo >= 'a' && palo <= 'z') {
        //palo = palo - 32;
		palo = palo -('a'-'A');
    }

    /* Comprobamos que el valor sea uno de los permitidos:
       A, 2-9, T, J, Q, K */
    valorValido = (valor == 'A' || valor == 'T' || valor == 'J' ||
                       valor == 'Q' || valor == 'K' ||
                       (valor >= '2' && valor <= '9'));

    /* Comprobamos que el palo sea uno de los permitidos:
       C (corazones), D (diamantes), P (picas), T (treboles) */
    paloValido = (palo == 'C' || palo == 'D' ||
                       palo == 'P' || palo == 'T');

    if (!valorValido || !paloValido) {
        printf("Carta inventada, \xa1trampa!.\n");
    }else{

		/* --- Carta valida: calculamos sus propiedades --- */

		/* 1. Color: corazones y diamantes son rojos; picas y treboles son negros */
		printf("Color: ");
		if (palo == 'C' || palo == 'D') {
			printf("rojo\n");
		} else {
			printf("negro\n");
		}

		/* 2. Es figura si es J, Q o K */
		printf("Figura: ");
		if (valor == 'J' || valor == 'Q' || valor == 'K') {
			printf("Si\n");
		} else {
			printf("No\n");
		}

		/* 3. Puntos de blackjack:
			 A vale 11
			 T, J, Q, K valen 10
			 2-9 valen su propio numero */
		puntos;
		if (valor == 'A') {
			puntos = 11;
		} else if (valor == 'T' || valor == 'J' || valor == 'Q' || valor == 'K') {
			puntos = 10;
		} else {
			puntos = valor - '0';
		}

		printf("Color: %s\n", color);
		printf("Figura: %s\n", esFigura);
		printf("Puntos de blackjack: %d.\n", puntos);
	}
    return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;

struct cartas
{
	string nome;
	int forca;
	int defesa;
	int magia;
};

int selecionar_carta()
{
	int numeros_repetidos = [];
	cartas cartasIniciais[100] = {
		{"Player1", 80, 60, 0},
        {"Player2", 80, 40, 50},
        {"Player3", 90, 70, 10},
        {"Player4", 90, 50, 0},
        {"Player5", 70, 70, 10},
        {"Player6", 50, 90, 20}
	};

	// Salvar qual numero foi escolhido e se na hora de escolher um numero, ele já tiver sido escolhido, gerar outro
	srand(time(NULL));
	cout << rand() % 6 - 1 <<endl;
	
	return 0;
}

int main(){
	selecionar_carta();
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct carta
{
	string nome;
	int forca;
	int defesa;
	int magia;
};
// Separar em duas funções, e retirar o for e o vetor
int main()
{
	carta Vet[2];
	
	for(int i = 0; i < 2; i++)
	{
		cout << "Nome carta " << i + 1 << endl;
		cin >> Vet[i].nome;
		
		cout << "Forca carta " << i + 1 << endl;
		cin >> Vet[i].forca;
		
		cout << "Defesa carta " << i + 1 << endl;
		cin >> Vet[i].defesa;
		
		cout << "Magia carta " << i + 1 << endl;
		cin >> Vet[i].magia;
	}
	
	ofstream arq1;
	arq1.open("cartas.txt", ofstream :: out);
	
	for(int i = 0; i < 2; i++)
	{
		arq1 << Vet[i].nome << endl;
		arq1 << Vet[i].forca << endl;
		arq1 << Vet[i].defesa << endl;
		// remover o segundo endl
		arq1 << Vet[i].magia << endl << endl;
		
	}
	
	
	return 0;
	
	}

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

void Ler_Carta(string nome, int forca, int defesa, int magia)
{
	ofstream arq1;
	arq1.open("cartas.txt", ofstream :: app);
	arq1 << nome << endl;
	arq1 << forca << endl;
	arq1 << defesa << endl;
	arq1 << magia << endl;
}

int main()
{
	carta carta1;
	
	cin >> carta1.nome >> carta1.forca >> carta1.defesa >> carta1.magia;
	
	Ler_Carta(carta1.nome, carta1.forca, carta1.defesa, carta1.magia);
	
	return 0;	
}

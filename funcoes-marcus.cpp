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
	arq1.close();
}

void Excluir_Carta(string carta2)
{
	ifstream arq;
	int y, i = 0, w = 0;
	string x;
	carta cartas[100];
	
	arq.open("cartas.txt", ifstream :: in);	
	while(arq >> x)
	{
		cartas[i].nome = x;
		
		arq >> y;
		cartas[i].forca = y;
		
		arq >> y;
		cartas[i].defesa = y;
		
		arq >> y;
		cartas[i].magia = y;
		
		i ++;
		
				
	}
	

	arq.close();
	
	ofstream arq2;
	arq2.open("cartas.txt", ofstream :: out);
	
	while(w < i)
	{
		if(cartas[w].nome != carta2)
		{
			arq2 << cartas[w].nome << endl;
			arq2 << cartas[w].forca << endl;
			arq2 << cartas[w].defesa << endl;
			arq2 << cartas[w].magia << endl;
			
		}
		
		w++;
	}
	
	arq2.close();
}

int main()
{
	int num;
	cout << "1 - Adicionar " << endl;
	cout << "2 - Excluir " << endl;
	cin >> num;
	
	if(num == 1)
	{
		carta carta1;
	
		cin >> carta1.nome >> carta1.forca >> carta1.defesa >> carta1.magia;
	
		Ler_Carta(carta1.nome, carta1.forca, carta1.defesa, carta1.magia);
	}
	
	else if(num == 2 )
	{
		string carta2;
		cin >> carta2;
		Excluir_Carta(carta2);
	}
	
	return 0;
}

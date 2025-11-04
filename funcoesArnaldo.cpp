#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct carta 
{
	string nome;
	int forca, defesa, magia;
};
carta ler_arquivos(carta[])
{
	
	string entrada_string;
	int entrada_forca, entrada_magia, entrada_defesa;
	int count = 0;
	ifstream leitura;
	arq.open("cartas.txt", ifstream::in);
	while(!arq.eof())
	{
	leitura >> 	entrada_string;
	leitura >> entrada_forca >> entrada_defesa >> entrada_magia;
	carta[count].nome = entrada_string;
	carta[count].forca = entrada_forca;
	carta[count].defesa = entrada_defesa;
	carta[count].magia = entrada_magia;
	}
	arq.close();
	return carta;
}





int main()
{
	
	carta[100] = [];
	ler_arquivos(carta);
	
	return 0;
}

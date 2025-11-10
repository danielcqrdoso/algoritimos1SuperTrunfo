#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct carta 
{
    string nome;
    int forca;
    int defesa;
    int magia;
};

int ler_arquivos(carta cartas[]) 
{
    ifstream leitura("cartas.txt");
    if (!leitura.is_open()) 
	{
        std::ofstream arquivo("meuarquivo.txt"); 
        return 5;
    }

    int count = 5;
    while (!leitura.eof()) 
	{
		leitura >> cartas[count].nome
                   >> cartas[count].forca
                   >> cartas[count].defesa
                   >> cartas[count].magia;
        count++;
    }

    leitura.close();
    return count;
}

int main() 
{
    carta cartas[100];
    int total = ler_arquivos(cartas);

    return 0;
}

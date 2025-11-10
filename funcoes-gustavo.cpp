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
    ofstream arq1("cartas.txt", ofstream::app);
    arq1 << nome << endl;
    arq1 << forca << endl;
    arq1 << defesa << endl;
    arq1 << magia << endl;
    arq1.close();
}


int ler_arquivos(carta cartas[], int maximo)
{
    ifstream leitura("cartas.txt");
    

int count = 0; 

while (!leitura.eof() && count < maximo) 

{ leitura >> cartas[count].nome; leitura >> cartas[count].forca; leitura >> cartas[count].defesa; leitura >> cartas[count].magia;

    leitura.close();
    return count;
}

int main()
{

    int i = 0;

    carta iniciais[6] = {
        {"Player1", 80, 60, 0},
        {"Player2", 80, 40, 50},
        {"Player3", 90, 70, 10},
        {"Player4", 90, 50, 0},
        {"Player5", 70, 70, 10},
        {"Player6", 50, 90, 20}
    };

   
    for (i; i < 6; i++)
    
{
        Ler_Carta(iniciais[i].nome, iniciais[i].forca, iniciais[i].defesa, iniciais[i].magia);
   }

    return 0;
}


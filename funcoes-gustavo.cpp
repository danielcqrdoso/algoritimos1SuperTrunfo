#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct cartas {
    string nome;
    int forca;
    int defesa;
    int magia;
};

int ler_arquivos(cartas cartas[]) 
{
    ifstream leitura("cartas.txt");
    if (!leitura.is_open()) 
    {
        ofstream arquivo("cartas.txt"); 
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

cartas selecionar_carta(int numeros_repetidos[], int &qtd, int total)
{
    srand(time(NULL));

    cartas cartasIniciais[6] = {
        {"Player1", 80, 60, 0},
        {"Player2", 80, 40, 50},
        {"Player3", 90, 70, 10},
        {"Player4", 90, 50, 0},
        {"Player5", 70, 70, 10},
        {"Player6", 50, 90, 20}
    };

    int id;

    do {
        id = rand() % (count + 1);
    } 
    while ([&]() {
        for (int i = 0; i < qtd; i++)
            if (numeros_repetidos[i] == id) return true;
        return false;
    }());

    numeros_repetidos[qtd] = id;
    qtd++;

    return cartasIniciais[id];
}

int main()
{
    int numeros_repetidos[100];
    int qtd = 0;

    cartas todas[100];
    int count = ler_arquivos(todas); 

    cartas escolhida = selecionar_carta(numeros_repetidos, qtd, count);

    cout << "Carta sorteada:\n";
    cout << escolhida.nome << " "
         << escolhida.forca << " "
         << escolhida.defesa << " "
         << escolhida.magia << endl;
}

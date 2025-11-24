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

int selecionar_index_carta(int numeros_repetidos[], int &quantidade_repetidos,
                           int total_cartas) {
  int id;
  bool repetido = false;

  do {
    // Gera um número entre 0 e total de cartas - 1
    id = rand() % (total_cartas);
    // validando se não houve repetição
    for (int i = 0; i < quantidade_repetidos; i++) {
      if (numeros_repetidos[i] == id) {
        repetido = true;
        break;
      }
      repetido = false;
    }
  } while (repetido);

  numeros_repetidos[quantidade_repetidos] = id;
  quantidade_repetidos++;

  return id;
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

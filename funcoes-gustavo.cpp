
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct cartas {
    string nome;
    int forca;
    int defesa;
    int magia;
};

cartas selecionar_carta(vector<int> &numeros_repetidos)
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
    
    // Sortear sem repetir
    do {
        id = rand() % 6;
    } while (find(numeros_repetidos.begin(), numeros_repetidos.end(), id) != numeros_repetidos.end());

    numeros_repetidos.push_back(id);

    return cartasIniciais[id];
}

int main()
{
    vector<int> numeros_repetidos;

    cartas escolhida = selecionar_carta(numeros_repetidos);

    cout << "Carta sorteada:\n";
    cout << escolhida.nome << " "
         << escolhida.forca << " "
         << escolhida.defesa << " "
         << escolhida.magia << endl;
}

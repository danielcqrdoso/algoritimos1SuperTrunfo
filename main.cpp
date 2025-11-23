#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// A estrutura (struct) da carta
struct cartas {
  string nome;
  int forca;
  int defesa;
  int magia;
};

int ler_arquivos(cartas cartas[]) {
  // O contador tem valor inicial de 6, pois criamos dentro do código 6 cartas
  int count = 6;
  ifstream leitura("cartas.txt");
  // se ele não abriu, é pq não existe, então ele é criado aqui
  if (!leitura.is_open()) {
    ofstream arquivo("cartas.txt");
    // finalizamos a função, pois não há cartas para ler nessa circunstancia
    return count;
  }

  // para evitar confusões essa variavel foi criada

  while (!leitura.eof()) {
    leitura >> cartas[count].nome >> cartas[count].forca >>
        cartas[count].defesa >> cartas[count].magia;
    count++;
  }

  leitura.close();
  return count; // <-- ESTE count será usado no sorteio
}

void exibir_carta(cartas carta) {
  cout << carta.nome << "\n"
       << carta.forca << "\n"
       << carta.defesa << "\n"
       << carta.magia << endl;
}

void Ler_Carta(string nome, int forca, int defesa, int magia) {
  ofstream arq1;
  arq1.open("cartas.txt", ofstream ::app);
  arq1 << nome << endl;
  arq1 << forca << endl;
  arq1 << defesa << endl;
  arq1 << magia << endl;
  arq1.close();
}

void Excluir_Carta(string carta2) {
  ifstream arq;
  int y, i = 0, w = 0;
  string x;
  cartas cartas[100];

  // Lê e guarda tudo que tá lá em um array
  arq.open("cartas.txt", ifstream ::in);
  while (arq >> x) {
    cartas[i].nome = x;

    arq >> y;
    cartas[i].forca = y;

    arq >> y;
    cartas[i].defesa = y;

    arq >> y;
    cartas[i].magia = y;

    i++;
  }

  arq.close();

  ofstream arq2;
  // Apaga tudo que está no arquivo
  arq2.open("cartas.txt", ofstream ::out);

  // reescreve sem a carta desejada
  while (w < i) {
    if (cartas[w].nome != carta2) {
      arq2 << cartas[w].nome << endl;
      arq2 << cartas[w].forca << endl;
      arq2 << cartas[w].defesa << endl;
      arq2 << cartas[w].magia << endl;
    }
    w++;
  }

  arq2.close();
}

int Menu1() {
  cartas todas_cartas[100] = {{"Player1", 75, 65, 20}, {"Player2", 70, 45, 60},
                              {"Player3", 85, 70, 25}, {"Player4", 85, 55, 15},
                              {"Player5", 65, 75, 30}, {"Player6", 50, 85, 35}};

  int count = ler_arquivos(todas_cartas);

  for (int i = 0; i < count - 1; i++) {
    if (i == 0) {
      cout << "Nao e possivel excluir essas cartas." << endl;
    } else if (i == 6) {
      cout << "----------------------------------" << endl;
      cout << "Essas abaixo podem ser excluidas." << endl;
      cout << "----------------------------------" << endl;
    }
    exibir_carta(todas_cartas[i]);
  }
  cout << endl;
  int num;
  cout << "1 - Adicionar " << endl;
  cout << "2 - Excluir " << endl;
  cout << "Outra tecla - sair" << endl;
  cin >> num;

  if (num == 1) {
    cartas carta1;
    cout << "Digite o nome, forca, defesa, magia. Separados por espaco ou "
            "virgula"
         << endl;
    cin >> carta1.nome >> carta1.forca >> carta1.defesa >> carta1.magia;
    Ler_Carta(carta1.nome, carta1.forca, carta1.defesa, carta1.magia);
  } else if (num == 2) {
    string carta2;
    cin >> carta2;
    Excluir_Carta(carta2);
  }

  return 0;
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

void jogo() {
  int numeros_repetidos[100];
  int quantidade_repetidos = 0;

  cartas todas_cartas[100] = {{"Player1", 75, 65, 20}, {"Player2", 70, 45, 60},
                              {"Player3", 85, 70, 25}, {"Player4", 85, 55, 15},
                              {"Player5", 65, 75, 30}, {"Player6", 50, 85, 35}};

  // como o contador vai ser usado em um array, tem que diminuir 1
  int count = ler_arquivos(todas_cartas) - 1;

  int num_entrada, quantidade_pontos_jogador = 0, quantidade_pontos_maquina = 0;
  for (int i = 0; i < 3; i++) {
    int escolhida_jogador =
        selecionar_index_carta(numeros_repetidos, quantidade_repetidos, count);
    int escolhida_maquina =
        selecionar_index_carta(numeros_repetidos, quantidade_repetidos, count);

    int valor_jogador, valor_maquina;

    cout << "Sua carta:\n";

    exibir_carta(todas_cartas[escolhida_jogador]);

    cout << "1 - forca\n2 - defesa\n3 - magia\n";

    cin >> num_entrada;

    switch (num_entrada) {
    case 1:
      valor_jogador = todas_cartas[escolhida_jogador].forca;
      valor_maquina = todas_cartas[escolhida_maquina].forca;
      break;

    case 2:
      valor_jogador = todas_cartas[escolhida_jogador].defesa;
      valor_maquina = todas_cartas[escolhida_maquina].defesa;
      break;

    case 3:
      valor_jogador = todas_cartas[escolhida_jogador].magia;
      valor_maquina = todas_cartas[escolhida_maquina].magia;
      break;

    default:
      valor_jogador = todas_cartas[escolhida_jogador].forca;
      valor_maquina = todas_cartas[escolhida_maquina].forca;
      cout << "erro de digitacao, escolhi forca\n";
      break;
    }
    // se a condição for verdadeira, retorna 1. Se for falsa retorna 0
    quantidade_pontos_jogador += (valor_jogador >= valor_maquina);
    quantidade_pontos_maquina += (valor_maquina >= valor_jogador);

    cout << "carta da maquina\n";
    exibir_carta(todas_cartas[escolhida_maquina]);
    cout << "jogador: " << quantidade_pontos_jogador
         << " maquina: " << quantidade_pontos_maquina << endl;
  }
  cout << "Fim de jogo!!!" << endl;
}

int main() {
  // criando uma semente para gerar número aleatorio
  // isso tem que ser feito aqui mesmo, para evitar que ela seja chamada
  // novamente (a extensão que deixa meu codigo bonito não deixa eu colocar tudo
  // na mesma linha)
  srand(time(NULL));

  int num_entrada;
  do {
    cout << "\nSelecione uma opcao: \n1- jogar\n2- ver cartas \n3- sair\n";
    cin >> num_entrada;
    if (num_entrada == 1) {
      jogo();
    }
    if (num_entrada == 2) {
      Menu1();
    }
  } while (num_entrada != 3);
}

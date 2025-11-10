#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct carta {
    string nome;
    int forca;
    int defesa;
    int magia;
};

void ler_arquivos(carta cartas[]) 
{
    ifstream leitura("cartas.txt");
    if (!leitura.is_open()) 
	{
        cout  << "Erro ao abrir o arquivo 'cartas.txt'!" << endl;
        return;
    }

    int count = 0;
    while (leitura.eof()) 
	{
    	leitura >> cartas[count].nome
                   >> cartas[count].forca
                   >> cartas[count].defesa
                   >> cartas[count].magia;
        count++;
    }

    leitura.close();
    return ;
}

int main() {
    carta cartas[100];
    ler_arquivos(cartas);

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct carta 
{
	string nome;
	int forca, defesa, magia;
};
void ler_arquivos(carta cartas[])
{
	
	string entrada_string;
	int entrada_forca, entrada_magia, entrada_defesa;
	int count = 5;
	ifstream leitura;
	leitura.open("cartas.txt", ifstream::in);
	while(!leitura.eof())
	{
	leitura >> 	entrada_string;
	leitura >> entrada_forca >> entrada_defesa >> entrada_magia;
	cartas[count].nome = entrada_string;
	cartas[count].forca = entrada_forca;
	cartas[count].defesa = entrada_defesa;
	cartas[count].magia = entrada_magia;
	count ++;
	cout << count;
	}
	leitura.close();
	return ;
}





int main()
{
	
	carta cartas[100] = {0};
	ler_arquivos ( cartas);
	cout << cartas;
	
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct carta 
{
	string nome;
	int forca, defesa, magia;
};
void ler_arquivos(carta cartas[])
{
	
	string entrada_string;
	int entrada_forca, entrada_magia, entrada_defesa;
	int count = 0;
	ifstream leitura;
	leitura.open("cartas.txt", ifstream::in);
	while(!leitura.eof())
	{
	leitura >> 	entrada_string;
	leitura >> entrada_forca >> entrada_defesa >> entrada_magia;
	carta[count].nome = entrada_string;
	carta[count].forca = entrada_forca;
	carta[count].defesa = entrada_defesa;
	carta[count].magia = entrada_magia;
	count ++;
	cout << count;
	}
	leitura.close();
	return ;
}





int main()
{
	
	carta cartas[100] = {0};
	ler_arquivos ( cartas);
	cout << cartas;
	
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct carta 
{
	string nome;
	int forca, defesa, magia;
};
void ler_arquivos(carta cartas[])
{
	
	string entrada_string;
	int entrada_forca, entrada_magia, entrada_defesa;
	int count = 0;
	ifstream leitura;
	leitura.open("cartas.txt", ifstream::in);
	while(!leitura.eof())
	{
	leitura >> 	entrada_string;
	leitura >> entrada_forca >> entrada_defesa >> entrada_magia;
	// carta[count].nome = entrada_string;
	// carta[count].forca = entrada_forca;
	// carta[count].defesa = entrada_defesa;
	// carta[count].magia = entrada_magia;
	count ++;
	cout << count;
	}
	leitura.close();
	return ;
}





int main()
{
	
	carta cartas[100] = {0};
	ler_arquivos ( cartas);
	cout << cartas;
	
	return 0;

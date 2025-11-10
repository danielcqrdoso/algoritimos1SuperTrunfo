

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


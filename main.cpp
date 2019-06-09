#include <iostream>
#include "velha.h"
using namespace std;

int main()
{
    JogoVelha V;
    int l, c;

    cout << endl << "         JOGO DA VELHA            " << endl;
    cout << endl << "Para sair digite linha 0 coluna 0 " << endl;
    cout << "Inicia-se com o jogador X " << endl;
    V.Imprimir();

    do
    {
        cout << endl << endl << "Digite Linha e Coluna: ";
        cin >> l >> c;
        
        if(l == 0 || c == 0)   // Encerrar o jogo
            return 0;

        V.Preenche(l-1,c-1);
        V.Imprimir();

        if(V.Vencedor() == 1) cout << endl << endl << "O Jogador X venceu!!!" << endl;
        else if(V.Vencedor() == 2) cout << endl << endl << "O Jogador O venceu!!!" << endl;
        else if(V.Vencedor() == 0) cout << endl << endl << "Deu Velha!!!" << endl;

    }while(V.Vencedor() == -1);

    return 0;
}

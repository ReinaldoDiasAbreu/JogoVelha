#ifndef VELHA_H
#define VELHA_H

class JogoVelha
{
    private:
        char tabuleiro[3][3];
        int cont_jog;
        char jogada;

    public:

        JogoVelha()
        {
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    tabuleiro[i][j] = ' ' ;
            cont_jog = 0;
            jogada = 'X';
        }

        void Imprimir()
        {
            std::cout << std::endl << "    " << "1   2   3" << std::endl;
            for(int i=1; i<=3; i++)
            {
                std::cout << "  " << "+---+---+---+" << std::endl;
                std::cout << i << " | ";
                for(int j=0; j<3; j++)
                    std::cout << tabuleiro[i-1][j] << " | ";
                std::cout << std::endl;
            }
            std::cout << "  " << "+---+---+---+";
        }

        void Preenche(int i, int j)
        {
            bool a= false, b = false;
            if(i >= 0 && i < 3) a = true;
            if(j >= 0 && j < 3) b = true;

            if ( a && b )
            {
                if(tabuleiro[i][j] == ' ')
                {
                    if(jogada == 'O')
                    {
                        tabuleiro[i][j] = 'O';
                        jogada = 'X';
                        cont_jog++;
                    }
                    else
                    {
                        tabuleiro[i][j] = 'X';
                        jogada = 'O';
                        cont_jog++;
                    }
                }

            }
            else
            {
                std::cout << std::endl << std::endl << "Jogada Inválida!!!" << std::endl << std::endl;
            }

        }

        bool Verifica_Colunas(char jog)
        {
            int cont=0;
            for(int i=0; i<3; i++)
            {
               for(int j=0; j<3; j++)
               {
                   if(tabuleiro[j][i] == jog)
                   {
                       cont++;
                   }
               }
               if(cont == 3)
                return true;
               else
                cont = 0;
            }
            return false;
        }

        bool Verifica_Linhas(char jog)
        {
            int cont=0;
            for(int i=0; i<3; i++)
            {
               for(int j=0; j<3; j++)
               {
                   if(tabuleiro[i][j] == jog)
                   {
                       cont++;
                   }
               }
               if(cont == 3)
                return true;
               else
                cont = 0;
            }
            return false;
        }

        bool Verifica_Diagonais(char jog)
        {
            int cont=0;
            for(int i=0; i<3; i++)
            {
               if(tabuleiro[i][i] == jog)
               {
                   cont++;
               }
            }
            if(cont == 3)
                return true;
               else
                cont = 0;

            for(int i=2, j=0; i>=0 && j<3; i--, j++)
            {
               if(tabuleiro[i][j] == jog)
               {
                   cont++;
               }
            }
            if(cont == 3)
                return true;
               else
                cont = 0;

            return false;
        }

        int Vencedor()
        {
            if(Verifica_Linhas('X') || Verifica_Colunas('X') || Verifica_Diagonais('X'))
                return 1;
            else if(Verifica_Linhas('O') || Verifica_Colunas('O') || Verifica_Diagonais('O'))
                return 2;
            else if(cont_jog == 9)
                return 0;
            else
                return -1;
        }
};

#endif // VELHA_H

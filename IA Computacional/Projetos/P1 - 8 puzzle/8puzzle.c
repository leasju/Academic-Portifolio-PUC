/* 
TRABALHO - 8 PUZZLE 
DISCIPLINA: IA COMPUTACIONAL
PROFESSOR: FERNANDO
INTEGRANTES:
- BÁRBARA LIMA 
- ISABEL BAUNGARTNER
- EMILY DELGADO
- JULIA LEANDRO 
*/

/* Usar vetores para representar um tabuleiro 8-puzzle
1. imprimir tabuleiro
2. ler movimento
3. aplicar movimento, se valido
4. repetir 1,2,3 infinitamente   */

#include <stdio.h>
#include <stdlib.h>
// Para usar a funcao srand e rand de aleatorizar
#include <time.h> //o time, garante que cada execução vai ser diferente em cada vez


void embaralhar(int tab[][3], int qtd_mov) //cria uma função sem retorno, que recebe como parâmetros uma matriz 3x3 (o tabuleiro) e a qtd de mov que será realizada para embaralhar
{
    int linha = 2, col = 2; // declara a posição inicial do 0 (X), pq pra embaralhar, ele vai se movimentar
    int opcoes[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // Cria uma matriz que guarda os movimentos possíveis do X; 4 opções, 1 linha
                       //0=cima, 1=baixo, 2=esquerda, 3=direita


    srand(time(NULL));

    for (int i = 0; i < qtd_mov; i++) //vai repetir movimentos aleatórios do x quantas vezes for determinado
    {
        int nLinha, nCol, mov, aux; //mov é um número aleatório entre 0 e 3, que vai dizer qual linha da matriz opcoes vamos usar.
        do {
            mov = rand()%4; // escolhe um movimento aleatório de 0 a 3 (qtd de linhas e col), e guarda na variavel movimento
            nLinha = linha + opcoes[mov][0]; //pega uma opção de movimento das linhas (ex: opção[3][1]={0,1} -- a linha n muda)
            nCol = col + opcoes[mov][1];// pega uma opção de mov das colunas (ex: opção[3][1] -- anda para direita)
        } while (nLinha < 0 || nLinha > 2 || nCol < 0 || nCol > 2); // verifica os limites (ex, ja está na col3 (indice 2) e quer ir para direita, n funciona)

        // troca 0 com o número da posição escolhida
        aux = tab[linha][col]; //pega o valor do x (0) e guarda em aux
        tab[linha][col] = tab[nLinha][nCol]; // nLinha e nCol é para onde o X vai se mover, pegamos o número q está nessa posição onde será a do x e colocamos onde o X estava.
        tab[nLinha][nCol] = aux; //coloca o X na nova posção

       //atualiza a posição atual do X para a próxima iteração do laço
        linha = nLinha;
        col = nCol;
    }
}

// IMPRIMIR O TABULEIRO (Matriz)
void mostrar_tab(int T[3][3]) { // percorre as linhas da matriz
    for (int i = 0; i < 3; i++) // percorre as colunas da matriz
    {
        printf("\t"); // Adiciona tabulação no início de cada linha
        for (int j = 0; j < 3; j++) {
            if (T[i][j] == 0){
                printf("| X |"); // se a posição for 0, imprime o X
            } else{
                printf("| %d |", T[i][j]);
            }
        }
        printf("\n");
    }
}

// LER MOVIMENTO
int ler(){
    int op;

    printf("\n\n\n MOVIMENTOS POSSIVEIS:");
    printf("\n\n\n| mover para CIMA = 8; \n| mover para BAIXO = 2;\n| mover para ESQUERDA = 4;\n| mover para DIREITA = 6;\n\n| fechar programa = 5.\n\nDigite o movimento que deseja realizar: ");
    scanf("%d", &op);

    return op;

}

// APLICAR O MOVIMENTO
void fs(int T[3][3], int opcao, int linha, int col)
{

    if (opcao==8 && linha>0) //se o comando for para mover para cima e se ele pode ir para cima
        {
            T[linha][col] = T[linha - 1][col]; // pega a o num que esta em cima do X e coloca ele embaixo, onde anteriormente estava o X
            T[linha - 1][col] = 0; // coloca o O (X), na posição nova
        }
        else if (opcao==2 && linha<2) //se o comando for para mover pra baixo e se ele puder mover para baixo
        {
            T[linha][col] = T[linha + 1][col]; // pega o num que esta embaixo do X e coloca em cima
            T[linha + 1][col] = 0; // coloca o X na nova posção
        }
        else if (opcao==4 && col>0) // se o comando for para mover para esquerda e se ele puder mover para esquerda
        {
            T[linha][col] = T[linha][col - 1]; // pega o num que está a esquerda e coloca no lugar que estava o X
            T[linha][col - 1] = 0; // coloca o X na nova posição a esquerda
        }
        else if (opcao==6 && col<2) // se o comando for para mover para a direita e se ele puder mover para direita
        {
            T[linha][col] = T[linha][col + 1]; // pega um num que esta a direita do X e move ele para onde estava o X
            T[linha][col + 1] = 0; // coloca o X na nova posição a direita
        }
        else
        {
            printf("Comando invalido!!!");
        }

}

// SOLUÇÃO
int resolvido(int tab[3][3])
{
    int solucao[3][3] = {{1,2,3},{4,5,6},{7,8,0}};

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (tab[i][j] != solucao[i][j])
            {
                return 0; // ainda não resolvido
            }
        }
    }
    return 1; // resolvido
}

// -------------------------- MAIN() --------------------------

int main ()
{
    int T[3][3] = {{1,2,3},{4,5,6},{7,8,0}}; // define a matriz do tabuleiro
    int opcao, linha, col;

    embaralhar(T, 50);

    printf("\tOBJETIVO FINAL:\n\n");
    printf("\t| 1 || 2 || 3 |\n");
    printf("\t| 4 || 5 || 6 |\n");
    printf("\t| 7 || 8 || X |\n");

    printf("\n\n\n\n");

    do
    {
        printf("\tESTADO ATUAL:\n\n");
        mostrar_tab(T); // chama a função para mostrar a matriz

        if (resolvido(T))
        {
           printf("\n\nParabens! Voce resolveu o 8-puzzle!\n\n");
           break;
        }

        opcao = ler(); // chama a função para ler o movimento

        // Opção 5 para sair do jogo
        if (opcao == 5)
        {
            printf("Jogo encerrado\n");
            break;
        };

        // Localiza o X (0) na matriz e guarda suas coordenadas em 'linha' e 'col'
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (T[i][j]==0)
                {
                    // NOMEIA 'i' E 'j' RESPECTIVAMENTE COMO 'linha' e 'col'
                    linha = i;
                    col = j;
                }
            }
        }

        fs(T, opcao, linha, col); // chama a função para aplicar os movimentos na matriz

        system("cls"); // limpa a tela a cada iteração do loop

    } while (1);

    return 0;
}

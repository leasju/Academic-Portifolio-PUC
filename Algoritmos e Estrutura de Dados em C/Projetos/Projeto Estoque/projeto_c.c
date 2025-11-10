#include <stdio.h>
#include <stdlib.h>

void estoque(int matriz[][15],int l,int c) {          
                 
    system("cls");

    int i,j,n,o;
    int repetidor = 0, opcao;
    while(repetidor == 0){

        system("cls");
        printf("\n1 - Preencher a Matriz \n2 - Sair");
        printf("\nDigite a opção desejada: ");
        scanf("%d",&opcao);

        if (opcao == 1) {
            
            for (n=0;n<l;n++) {

                for (o=0;o<c;o++){

                    printf("Digite a quantidade do produto: ");

                    if (scanf("%d",&matriz[n][o]) != 1) {

                        printf("Valor de quantidade inválida!\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    else {

                        printf("Quantidade cadastrada com sucesso!\n");
                    }
                }
            } 
            for (i=0;i<l;i++) {

                for (j=0;j<c;j++) {

                     printf("%d",matriz[i][j]);
                }
            }         
        }
        else if (opcao == 2) {

            repetidor = 1;
            break;
        }
        else {
            printf("Opção inválida!");
        }
    }
}

void atualizar (int matriz[][15], int l, int c)
{
    system("cls");

    int produto, setor, quanti, aux;
    printf("\n\tQual produto alterar?");
    scanf("%d",& produto);
    if( produto > 0 )
    {
        if(produto > l-1)
        {
            printf("\n\tProdto nao consta no sistema");
            return;
        }
    }
    else
    {
        printf("\n\tProduto precisa ter um valor positivo");
        return;
    }
    printf("\n\tQual setor: ");
    scanf("%d", & setor);
    if (setor> 0)
    {
        if(setor > c-1)
        {
            printf("\n\tSetor nao consta no sistema");
            return;
        }
    }
    else
    {
        printf("\n\tSetor precisa ter um valor positivo");
        return;
    }
    printf("\n\tQual sera a nova quantidade? ");
    scanf("%d", & quanti);
    if (quanti> 0)
    {
        aux=matriz[setor][produto];
        matriz[setor][produto]=quanti;
        printf("\n\tEstoque atualizado com sucesso!!");
        printf("\n\tValor antigo = %d \n Valor Atualizado = %d",aux, quanti);
    }
    else
    {
        printf("\n\tERRO"" Nao pode ser um valor negativo");
    }
}

void consultas(int matriz[][15], int l, int c)
{
    int opcao;

    do
    {
        printf("\n MENU DE CONSULTAS \n");
        printf("1 - Mostrar estoque total de um produto (em todas as filiais)\n");
        printf("2 - Mostrar estoque total de uma filial (todos os produtos)\n");
        printf("3 - Mostrar produto com maior e menor quantidade total\n");
        printf("4 - Mostrar filial com mais e menos estoque\n");
        printf("5 - Mostrar média de estoque de uma filial escolhida\n");
        printf("6 - Mostrar média de estoque de um produto escolhido\n");
        printf("0 - Voltar pro menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
            {
                int produto;
                printf("Digite o número do produto (0 a %d): ", c - 1);
                scanf("%d", &produto);

                if (produto < 0 || produto >= c)
                {
                    printf("Produto inválido!\n");
                    break;
                }

                int soma = 0;
                for (int i = 0; i < l; i++)
                {
                    soma += matriz[i][produto];
                }

                printf("\nEstoque total do produto %d (todas as filiais): %d unidades\n", produto, soma);
                break;
            }

            case 2:
            {
                int filial;
                printf("Digite o número da filial (0 a %d): ", l - 1);
                scanf("%d", &filial);

                if (filial < 0 || filial >= l)
                {
                    printf("Filial inválida!\n");
                    break;
                }

                int soma = 0;
                for (int j = 0; j < c; j++)
                {
                    soma += matriz[filial][j];
                }

                printf("\nEstoque total da filial %d: %d unidades\n", filial, soma);
                break;
            }

            case 3:
            {
                int maiorProduto = 0, menorProduto = 0;
                int maiorValor = -1, menorValor = 999999;

                for (int j = 0; j < c; j++)
                {
                    int soma = 0;
                    for (int i = 0; i < l; i++)
                    {
                        soma += matriz[i][j];
                    }

                    if (soma > maiorValor)
                    {
                        maiorValor = soma;
                        maiorProduto = j;
                    }
                    if (soma < menorValor)
                    {
                        menorValor = soma;
                        menorProduto = j;
                    }
                }

                printf("\nProduto com MAIS estoque total: %d (%d unidades)\n", maiorProduto, maiorValor);
                printf("Produto com MENOS estoque total: %d (%d unidades)\n", menorProduto, menorValor);
                break;
            }

            case 4:
            {
                int maiorFilial = 0, menorFilial = 0;
                int maiorValor = -1, menorValor = 999999;

                for (int i = 0; i < l; i++)
                {
                    int soma = 0;
                    for (int j = 0; j < c; j++)
                    {
                        soma += matriz[i][j];
                    }

                    if (soma > maiorValor)
                    {
                        maiorValor = soma;
                        maiorFilial = i;
                    }
                    if (soma < menorValor)
                    {
                        menorValor = soma;
                        menorFilial = i;
                    }
                }

                printf("\nFilial com MAIS estoque: %d (%d unidades)\n", maiorFilial, maiorValor);
                printf("Filial com MENOS estoque: %d (%d unidades)\n", menorFilial, menorValor);
                break;
            }

            case 5:
            {
                int filial;
                printf("Digite o número da filial (0 a %d): ", l - 1);
                scanf("%d", &filial);

                if (filial < 0 || filial >= l)
                {
                    printf("Filial inválida!\n");
                    break;
                }

                int soma = 0;
                for (int j = 0; j < c; j++)
                {
                    soma += matriz[filial][j];
                }

                float media = (float)soma / c;
                printf("Média de estoque da filial %d: %.2f unidades\n", filial, media);
                break;
            }

            case 6:
            {
                int produto;
                printf("Digite o número do produto (0 a %d): ", c - 1);
                scanf("%d", &produto);

                if (produto < 0 || produto >= c)
                {
                    printf("Produto inválido!\n");
                    break;
                }

                int soma = 0;
                for (int i = 0; i < l; i++)
                {
                    soma += matriz[i][produto];
                }

                float media = (float)soma / l;
                printf("Média de estoque do produto %d: %.2f unidades\n", produto, media);
                break;
            }

            case 0:
                printf("\nVoltando pro menu principal...\n");
                break;

            default:
                printf("\nOpção inválida, tenta de novo!\n");
                break;
        }

    } while (opcao != 0);
}


int main() {

    int l,c;
    int matriz[10][15]={0}; 
    int repetidor = 0,opcao;

    printf("____Parâmetros da Matriz____"); //Cadastrar o tamanho da matriz
    printf("\nDigite a quantidade de linhas (máx: 10): ");
    scanf("%d",&l);
    if (l < 0 || l > 10) {

        printf("\nQuantidade inválida!");
    }
    else {
        printf("Digite a quantidade de colunas (máx: 15): ");
        scanf("%d",&c);
        if (c < 0 || c > 15) {

            printf("\nQuantidade inválida!");
        }
        else {

            printf("Parâmetros cadastrados!");
        }
    }
    

    while (repetidor == 0){

        printf("\n1 - Cadastro \n2 - Edição \n3 - Consulta \n4 - Sair");
        printf("\nDigite a opção desejada: ");
        scanf("%d",&opcao);

        switch (opcao){

            case 1:
                estoque(matriz,l,c);
                break;
            case 2:
                atualizar(matriz,l,c);
                break;
            case 3:
                consultas(matriz,l,c);
            case 4:
                repetidor=1;
                break;
            default:
                printf("Opção não encontrada");
                break;
        
        }



    }

    return 0;

}


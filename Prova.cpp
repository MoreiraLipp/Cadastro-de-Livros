#include<stdio.h>
#include<stdlib.h>

const int MAX = 101;

char titulo[MAX][100];
char autor[MAX][100];

int paginas[MAX];
int qtd[MAX];
int livroscadastrados;
int maispaginas;
int mediapaginas;

int pos = 1;

void menu();
void editar();
void listar();
void cadastrar();
void relatorio();

void relatorio()
{
    system("CLS");
printf("Relatorio\n\n");
    printf("Quantidade de Livros Cadastrados: %d\n\n", livroscadastrados);
    printf("Livros com menos de 3 quantidades em nosso estoque:");
    for(int l = 1; l < pos; l++)
    {
        if(qtd[l] <= 3)
        {
            printf("\nTitulo: %s\n", titulo[l]);
            printf("Autor: %s\n", autor[l]);
        }
        else
        {
            printf("[NENHUM]");
        }
    }
    //("\nLivro com maior quantidade de paginas: %d\n", maispaginas);

    for(int m = 1; m < pos; m++)
    {
        if(paginas[m] > maispaginas)
        {
            maispaginas = paginas[m];

            if(maispaginas == paginas[m])
            {
                printf("\nLivro com mais paginas: %s (%d paginas)", titulo[m], paginas[m]);
            }
        }
    }


    printf("\nMedia de paginas: %d\n\n", mediapaginas / 2);


    system("PAUSE");
    menu();
}

void editar()
{
    int livroEditar;
    system("CLS");
    printf("Editar\n\n");

    printf("Qual desses livros voce deseja editar?\n\n");

    for(int e = 1; e < pos; e++)
    {
        printf("[%d]\n", e);
        printf("    Titulo: %s\n", titulo[e]);
        printf("    autor : %s\n", autor[e]);
        printf("    Quantidade Pags: %d\n", paginas[e]);
        printf("    Quantidade Disp: %d\n", qtd[e]);
        printf("--------------------------------------------------\n");
    }

    printf("Digite: ");
    scanf("%d", &livroEditar);

    if((livroEditar < 1) || (livroEditar >= pos))
    {
        printf("Opcao Invalida!\n\n");
        system("PAUSE");
        editar();
    }

    system("CLS");
    printf("Editando: [%d] %s\n\n", livroEditar, titulo[livroEditar]);

    printf("Titulo Atual: %s\n", titulo[livroEditar]);
    printf("Titulo Novo: ");
    scanf("%s", &titulo[livroEditar]);

    printf("\nAutor Atual: %s\n", autor[livroEditar]);
    printf("Autor Novo: ");
    scanf("%s", &autor[livroEditar]);

    printf("\nQuantidade de paginas Atual: %d\n", paginas[livroEditar]);
    printf("Quantidade de paginas Nova: ");
    scanf("%d", &paginas[livroEditar]);

        if(paginas[livroEditar] < 1)
    {
        printf("Numero de paginas invalido. Voltando ao menu.\n");
        system("PAUSE");
        menu();
    }

    printf("\nQuantidade disponiveis Atual: %d\n", qtd[livroEditar]);
    printf("Quantidade disponiveis Nova: ");
    scanf("%d", &qtd[livroEditar]);

        if(qtd[livroEditar] < 1)
    {
        printf("Numero de Quantidades negativo. Voltando ao menu.\n");
        system("PAUSE");
        menu();
    }

    menu();
}

void listar()
{
    system("CLS");
    printf("Listagem dos Livros\n\n");

    for(int l = 1; l < pos; l++)
    {
        printf("[%d]\n", l);
        printf("    Titulo: %s\n", titulo[l]);
        printf("    autor : %s\n", autor[l]);
        printf("    Quantidade Pags: %d\n", paginas[l]);
        printf("    Quantidade Disp: %d\n", qtd[l]);
        printf("--------------------------------------------------\n");
    }

    system("PAUSE");
    menu();
}

void cadastrar()
{
    system("CLS");
    printf("Novo Livro\n\n");

    printf("Titulo: ");
    scanf("%s", &titulo[pos]);
    printf("Autor: ");
    scanf("%s", &autor[pos]);
    printf("Quantidade de paginas: ");
    scanf("%d", &paginas[pos]);

    if(paginas[pos] < 1)
    {
        printf("Numero de paginas invalido. Voltando ao menu.\n");
        system("PAUSE");
        system("CLS");
        menu();
    }

    printf("Quantidade Disponivel: ");
    scanf("%d", &qtd[pos]);

            if(qtd[pos] < 1)
    {
        printf("Numero de Quantidades negativo. Voltando ao menu.\n");
        system("PAUSE");
        system("CLS");
        menu();
    }

    printf("-----------------\n\n");
    printf("Livro Registrado!\n\n");

    mediapaginas = mediapaginas + paginas[pos];
    livroscadastrados++;
    pos++;
    system("PAUSE");
    menu();
}

void menu()
{
    system("CLS");
    int escolha;

    printf("Biblioteca Virtual\n\n");
    printf("1 Novo Livro\n");
    printf("2 Listar Livros\n");
    printf("3 Editar Livros\n");
    printf("4 Relatorio\n");
    printf("0 Sair\n");
    printf("-----------------\n");
    printf("Digite a opcao: ");
    scanf("%d", &escolha);

    switch(escolha)
    {

    case 0:
        printf("Saindo...\n\n");
        system("PAUSE");
        break;
    case 1:
        cadastrar();
        break;

    case 2:
        listar();
        break;

    case 3:
        editar();
        break;

    case 4:
        relatorio();
        break;

    default:
        printf("Erro ao escolher. Tente Novamente!");
        menu();
        break;

    }
}

int main()
{
    menu();
}

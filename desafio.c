#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct dados {
    char nome[20];
    char estadoCivil[9];
    int diaNasc;
    int mesNasc;
    int anoNasc;
    int salario;
};

adicionarContato(struct dados *contato,int tam){

    FILE *p, *p1;
    int cont = 0;
    int i;


    p1 = fopen("contador.txt","r");
    fscanf(p1,"%d",&cont);
    fclose(p1);

    if((p = fopen("arquivo.txt","a")) == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    getchar();
    printf("Digite o nome:\n->");
    gets(contato->nome);
    printf("Digite o seu estado civil:\n->");
    gets(contato->estadoCivil);
    printf("Digite o dia do seu nascimento:\n->");
    scanf("%d",&contato->diaNasc);
    printf("Digite o mes do seu aniversario:\n->");
    scanf("%d",&contato->mesNasc);
    printf("Digite o ano do seu nascimento:\n->");
    scanf("%d",&contato->anoNasc);
    printf("Digite o valor do seu salario:\n->");
    scanf("%d",&contato->salario);

    fwrite(contato,tam,1,p);
    fclose(p);

    cont++;

    p1=fopen("contador.txt","w");
    fprintf(p1,"%d",cont);
    fclose(p1);


}

listarDados(struct dados *contato,int tam){

    FILE *p,*p1;
    int cont = 0;
    int comprimentoArq;

    p1 = fopen("contador.txt","r");
    fscanf(p1,"%d",&cont);
    fclose(p1);

    if((p = fopen("arquivo.txt","r"))== NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    for(int i = 0 ; i < cont ; i++){
        comprimentoArq = i*tam;       //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);            //le o registro
        if(contato -> nome[0] != '*'){         //verifica se esta apagado
            printf("------------------------------------------\n");
            printf("Nome: %s\n",contato->nome);
            printf("Estado civil: %s\n",contato->estadoCivil);
            printf("Data de nascimento: %d/%d/%d\n",contato->diaNasc,contato->mesNasc,contato->anoNasc);
            printf("Salario: %d\n",contato->salario);
        }
    }
        fclose(p);

}

pesquisarNome(struct dados *contato,int tam){

    char nomeP[20];
    getchar();
    printf("Digite o nome para pesquisa:\n->");
    gets(nomeP);


    FILE *p,*p1;
    int cont = 0;
    int comprimentoArq;

    p1 = fopen("contador.txt","r");
    fscanf(p1,"%d",&cont);
    fclose(p1);

    if((p = fopen("arquivo.txt","r"))== NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    for(int i = 0 ; i < cont ; i++){
        comprimentoArq = i*tam;       //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);            //le o registro
        if(contato -> nome[0] != '*'){         //verifica se esta apagado
            if(!strcmp(nomeP,contato->nome)){
                printf("------------------------------------------\n");
                printf("Nome: %s\n",contato->nome);
                printf("Estado civil: %s\n",contato->estadoCivil);
                printf("Data de nascimento: %d/%d/%d\n",contato->diaNasc,contato->mesNasc,contato->anoNasc);
                printf("Salario: %d\n",contato->salario);
            }
        }
    }
        fclose(p);

}

pesquisarEstadoCivil(struct dados *contato,int tam){

    char estadoCivilP[9];
    getchar();
    printf("Digite o estado civil para pesquisa:\n->");
    gets(estadoCivilP);


    FILE *p,*p1;
    int cont = 0;
    int comprimentoArq;

    p1 = fopen("contador.txt","r");
    fscanf(p1,"%d",&cont);
    fclose(p1);

    if((p = fopen("arquivo.txt","r"))== NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    for(int i = 0 ; i < cont ; i++){
        comprimentoArq = i*tam;       //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);            //le o registro
        if(contato -> nome[0] != '*'){         //verifica se esta apagado
            if(!strcmp(estadoCivilP,contato->estadoCivil)){
                printf("------------------------------------------\n");
                printf("Nome: %s\n",contato->nome);
                printf("Estado civil: %s\n",contato->estadoCivil);
                printf("Data de nascimento: %d/%d/%d\n",contato->diaNasc,contato->mesNasc,contato->anoNasc);
                printf("Salario: %d\n",contato->salario);
            }
        }
    }
        fclose(p);

}

pesquisarAniversariante(struct dados *contato,int tam){

    int mes;

    printf("Digite o mes para mostrar os aniversariantes:\n->");
    scanf("%d",&mes);

    FILE *p,*p1;
    int cont = 0;
    int comprimentoArq;

    p1 = fopen("contador.txt","r");
    fscanf(p1,"%d",&cont);
    fclose(p1);

    if((p = fopen("arquivo.txt","r"))== NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    for(int i = 0 ; i < cont ; i++){
        comprimentoArq = i*tam;       //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);            //le o registro
        if(contato -> nome[0] != '*'){         //verifica se esta apagado
            if(mes == contato->mesNasc){
                printf("------------------------------------------\n");
                printf("Nome: %s\n",contato->nome);
                printf("Estado civil: %s\n",contato->estadoCivil);
                printf("Data de nascimento: %d/%d/%d\n",contato->diaNasc,contato->mesNasc,contato->anoNasc);
                printf("Salario: %d\n",contato->salario);
            }
        }
    }
        fclose(p);

}

pesquisarFaixaSalarial(struct dados *contato,int tam){

    int valorMin, valorMax;

    printf("Digite o valor minimo:\n->");
    scanf("%d",&valorMin);
    printf("\n");
    printf("Digite o valor maximo:\n->");
    scanf("%d",&valorMax);

    FILE *p,*p1;
    int cont = 0;
    int comprimentoArq;

    p1 = fopen("contador.txt","r");
    fscanf(p1,"%d",&cont);
    fclose(p1);

    if((p = fopen("arquivo.txt","r"))== NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    for(int i = 0 ; i < cont ; i++){
        comprimentoArq = i*tam;       //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);            //le o registro
        if(contato -> nome[0] != '*'){         //verifica se esta apagado
            if(contato->salario >= valorMin && contato->salario <= valorMax){
                printf("------------------------------------------\n");
                printf("Nome: %s\n",contato->nome);
                printf("Estado civil: %s\n",contato->estadoCivil);
                printf("Data de nascimento: %d/%d/%d\n",contato->diaNasc,contato->mesNasc,contato->anoNasc);
                printf("Salario: %d\n",contato->salario);
            }
        }
    }
        fclose(p);

}

deletarContato(struct dados *contato,int tam){

    char nomeP[20];
    getchar();
    printf("Digite o nome do usuario que voce deseja deletar:\n->");
    gets(nomeP);

    FILE *p,*p1;
    int cont = 0;
    int comprimentoArq;

    p1 = fopen("contador.txt","r");
    fscanf(p1,"%d",&cont);
    fclose(p1);

    if((p = fopen("arquivo.txt","r"))== NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    for(int i = 0 ; i < cont ; i++){
        comprimentoArq = i*tam;       //calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);    //posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);            //le o registro
        if(contato -> nome[0] != '*'){         //verifica se esta apagado
            if(!strcmp(nomeP,contato->nome)){
                *contato->nome = '*';
                fseek(p,sizeof(struct dados) * i,0);
                fwrite(contato,sizeof(struct dados),1,p);
                printf("Usuario deletado com sucesso!\n");
            }
        }
    }
        fclose(p);

}
int main(){



    struct dados contato;
    int tam;               //numero de bytes da estrutura

    tam = sizeof(contato);

    int acao;


do{
    printf(" \n==MENU==\n");
    printf("1 - Adicionar dados\n");
    printf("2 - Lista de dados\n");
    printf("3 - Pesquisar registro por nome\n");
    printf("4 - Pesquisar por estado civil\n");
    printf("5 - Pesquisar os aniversariantes de um mes\n");
    printf("6 - Pesquisar por faixa salarial\n");
    printf("7 - Alterar o valor do salario\n");
    printf("8 - Alterar dados\n");
    printf("9 - Excluir dados\n");
    printf("0 - Sair\n");
    printf("-> ");
    scanf("%d",&acao);


    switch(acao){
        case 1:{
            adicionarContato(&contato,tam);
            break;
        }
        case 2:{
            listarDados(&contato,tam);
            break;
        }
        case 3:{
            pesquisarNome(&contato,tam);
            break;
        }
        case 4:{
            pesquisarEstadoCivil(&contato,tam);
            break;
        }
        case 5:{
            pesquisarAniversariante(&contato,tam);
            break;
        }
        case 6:{
            pesquisarFaixaSalarial(&contato,tam);
            break;
        }
        case 7:{
            break;
        }
        case 8:{
            break;
        }
        case 9:{
            deletarContato(&contato,tam);
            break;
        }
        case 0:{
            break;
        }
        default:{
            printf("Digite uma opcao valida!\n");
        }
    }
}while(acao);


}

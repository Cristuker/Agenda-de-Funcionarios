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

int pesquisa(struct dados *ps, int tam){
    FILE *p;
    FILE *p1;

    char nome1[20];
    int i=0,y, x;
    int cont;

    printf("Informe um nome para pesquisa: \n");
    gets(nome1);

    p1 = fopen("contador.txt", "r");
    fscanf(p1,"%d",&cont);
    fclose(p1);

    p = fopen("arquivo.txt", "r");

    for(y=0;y<cont;y++){
        fread(ps,tam,1,p);                      //Le o conteudo do arquivo.txt
        for(x = 0; nome1[x] != '\0';x++){
            if(nome1[x] != ps -> nome[x]){
                break;                          //Para se alguma letra do nome for diferente
            }
        }

        if(nome1[x] == '\0' && ps -> nome[x] == '\0'){
            return y;                            //Verifica se os dois nomes tem o finalizador na mesma casa do array,
                                                 //Só entra aqui se as letras forem iguais na mesma posição
        }
    }

    return -1;
}

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

    p1=fopen("contador.txt","w");  //Abre o arquivo do contador no modo escrita e sobreescreve o valor de lá adicona +1
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
        comprimentoArq = i*tam;                 //Calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);              //Posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);                 //Le o registro
        if(contato -> nome[0] != '*'){          //Verifica se esta apagado
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
    printf("Digite o nome para pesquisa:\n->");
    gets(nomeP);


    FILE *p,*p1;
    int cont = 0;
    int comprimentoArq;

    p1 = fopen("contador.txt","r");                 //Le quantos registros tem no contador.txt
    fscanf(p1,"%d",&cont);
    fclose(p1);

    if((p = fopen("arquivo.txt","r"))== NULL){      //Abre o arquivo no modo leitura
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    for(int i = 0 ; i < cont ; i++){
        comprimentoArq = i*tam;                     //Calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);                  //Posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);                     //Le o registro
        if(contato -> nome[0] != '*'){              //Verifica se esta apagado
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
        comprimentoArq = i*tam;                     //Calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);                  //Posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);                     //Le o registro
        if(contato -> nome[0] != '*'){              //Verifica se esta apagado
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
        comprimentoArq = i*tam;                     //Calcula o n. de bytes para posicionar o ponteiro do arquivo

        fseek(p,comprimentoArq,0);                  //Posiciona o ponteiro no inicio do registro dentro do arquivo
        fread(contato,tam,1,p);                     //Le o registro
        if(contato -> nome[0] != '*'){              //Verifica se esta apagado
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
        comprimentoArq = i*tam;

        fseek(p,comprimentoArq,0);
        fread(contato,tam,1,p);

        if(contato -> nome[0] != '*'){
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

    FILE *p;
    int n_reg;
    int n_bytes;

    n_reg = pesquisa(contato, tam);     //Pesquisa o registro no arquivo
    n_bytes = tam * n_reg;

    p = fopen("arquivo.txt", "r+");

    fseek(p,n_bytes,0);                 //Posioiona o ponteiro do arquivo no registro a ser alterado
    fread(contato, tam, 1, p );         //Le registro do arquivo

    contato->nome[0] = '*';

    fseek(p,n_bytes,0);                 //Posiciona o ponteiro do arquivo no inicio do regisro a ser alterado
    fwrite(contato, tam,1,p);           //Escreve o registro no arquivo

    fclose(p);

}

alterarFaixaSalarial(struct dados *contato,int tam){

    FILE *p;
    int n_reg;
    int n_bytes;
    int valor;

    n_reg = pesquisa(contato, tam);     //Pesquisa o registro no arquivo
    n_bytes = tam * n_reg;

    p = fopen("arquivo.txt", "r+");

    fseek(p,n_bytes,0);                //Posioiona o ponteiro do arquivo no registro a ser alterado
    fread(contato, tam, 1, p );        //Le registro do arquivo

    printf("Digite o valor que voce deseja alterar:\n->");
    scanf("%d",&valor);
    printf("\n");


    contato->salario = valor;

    fseek(p,n_bytes,0);                 //Posiciona o ponteiro do arquivo no inicio do regisro a ser alterado
    fwrite(contato, tam,1,p);           //Escreve o registro no arquivo

    fclose(p);

}

alterarDados(struct dados *contato,int tam){

    FILE *p;
    int n_reg;
    int n_bytes;



    n_reg = pesquisa(contato, tam);     //Pesquisa o registro no arquivo
    n_bytes = tam * n_reg;

    p = fopen("arquivo.txt", "r+");

    fseek(p,n_bytes,0);                 //Posioiona o ponteiro do arquivo no registro a ser alterado
    fread(contato, tam, 1, p );         //Le registro do arquivo

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

    fseek(p,n_bytes,0);             //Posiciona o ponteiro do arquivo no inicio do regisro a ser alterado
    fwrite(contato, tam,1,p);       //Escreve o registro no arquivo

    fclose(p);

}

int main(){



    struct dados contato;
    int tam;                        //Numero de bytes da estrutura

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
    getchar();

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
            alterarFaixaSalarial(&contato,tam);
            break;
        }
        case 8:{
            alterarDados(&contato,tam);
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

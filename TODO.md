   [x] � entra dados.
   [x] � lista dados na tela.
   [x] � pesquisar um registro por nome.
   [x] � pesquisa por estado civil
   [x] � pesquisar os aniversariantes de um determinado m�s.
   [x] � pesquisa por faixa salarial
   [ ] - altera valor do sal�rio
   [ ] � altera dados.
   [x] � exclui dados.
   [x] - sa�da

## Estrutura: nome, data de nascimento, estado civil,  sal�rio. 
## A estrutura de dados deve ser vari�vel local na fun��o main().
## O programa deve ser finalizado pelo usu�rio
    struct dados {
            char nome[20];
            char estadoCivil[9];
            int diaNasc;
            int mesNasc;
            int anoNasc;
            int salario;
    };
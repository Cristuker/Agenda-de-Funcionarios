   [x] – entra dados.
   [x] – lista dados na tela.
   [x] – pesquisar um registro por nome.
   [x] – pesquisa por estado civil
   [x] – pesquisar os aniversariantes de um determinado mês.
   [x] – pesquisa por faixa salarial
   [ ] - altera valor do salário
   [ ] – altera dados.
   [x] – exclui dados.
   [x] - saída

## Estrutura: nome, data de nascimento, estado civil,  salário. 
## A estrutura de dados deve ser variável local na função main().
## O programa deve ser finalizado pelo usuário
    struct dados {
            char nome[20];
            char estadoCivil[9];
            int diaNasc;
            int mesNasc;
            int anoNasc;
            int salario;
    };
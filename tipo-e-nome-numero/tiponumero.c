#include <stdio.h>
#include <string.h>

/*
    2) faça um programa que recebe um número no formato de string e 
    informa o tipo do número fornecido (natural, inteiros ou real). 
    Existe a possibilidade do número fornecidos não ser válido para 
    nenhum desses tipos, caso em que uma mensagem de erro deve ser 
    exibida para o usuário {{{{{{QUESTÃO OK}}}}}
    3) faça um programa que recebe um número (natural, inteiros ou 
    real) no formato de string e escreve por extenso o número lido. 
    Existe a possibilidade do número fornecidos não ser válido para 
    nenhum desses tipos, caso em que uma mensagem de erro deve ser 
    exibida para o usuário.
*/

int valida_numero(char numero[10], int i){
    //retorna 0 caso seja válido
    //retorna 1 caso seja inválido
    if(i == 10 || numero[i] == '\0') return 0;
    else{
        if(
            numero[0] != '1' && numero[0] != '2' && numero[0] != '3' &&
            numero[0] != '4' && numero[0] != '5' && numero[0] != '6' &&
            numero[0] != '7' && numero[0] != '8' && numero[0] != '9' &&
            numero[0] != '0' && numero[0] != '-' && numero[0] != '+'
        ) return 1;
        else if(i > 0 &&
            numero[i] != '1' && numero[i] != '2' && numero[i] != '3' &&
            numero[i] != '4' && numero[i] != '5' && numero[i] != '6' &&
            numero[i] != '7' && numero[i] != '8' && numero[i] != '9' &&
            numero[i] != '0' && numero[i] != ','
        ) return 1;
        return valida_numero(numero, i+1);
    }
}

int tem_virgula(char numero[10], int i, int virgula, int posicao){
//retorna 0 se não tiver vírgula
    if(i == 10 || numero[i] == '\0'){
        if(virgula == 1) return posicao;
        else if(virgula == 0) return 0;
        else return -1;
    }else{
        if(numero[i] == ','){
            virgula++;
            posicao = i;
        }
        return tem_virgula(numero, i+1, virgula, posicao);
    }
}

int pos_virgula(char numero[10], int i){
//retorna 1 se for real
//retorna 0 se não for
    int valida = 0;
    int posicao = tem_virgula(numero, 0, 0, 0);
    if(posicao == 1){
        posicao++;
        for(posicao; numero[posicao] != '\0'; posicao++){
            if(numero[posicao] != '0') valida = 1;
        }
        if(valida == 1) return 1;
        else return 0;
    }else if(posicao == -1) return -1;
}

void tipo_numero(char numero[10], int i){
    int posicao, eh_real;
    if(i == 10 || numero[i] == 'o') return;
    else{
        if(numero[0] == '-'){
            posicao = tem_virgula(numero, 0, 0, 0);
            if(posicao == 0) printf("inteiro e real");
            else if(posicao > 0){
                eh_real = pos_virgula(numero, 0);
                if(eh_real == 1) printf("real");
                else printf("inteiro e real");
            }else{
                printf("ERRO!");
            }
        }else{
            posicao = tem_virgula(numero, 0, 0, 0);
            if(posicao == 0) printf("natural, inteiro e real");
            else if(posicao > 0){
                eh_real = pos_virgula(numero, 0);
                if(eh_real == 1) printf("real");
                else printf("natural, inteiro e real");
            }else if(posicao == -1) printf("ERRO!");
        }
    }
}

int main()
{
    char numero[10];
    gets(numero);
    int valido = valida_numero(numero, 0);
    if(valido == 1) printf("ERRO!\n");
    else tipo_numero(numero, 0);
 
    return 0;
}
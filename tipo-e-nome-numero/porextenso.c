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

int unidade(char numero[10], int i){
    if(numero[i] == '1') printf("um");
    else if(numero[i] == '2') printf("dois");
    else if(numero[i] == '3') printf("tres");
    else if(numero[i] == '4') printf("quatro");
    else if(numero[i] == '5') printf("cinco");
    else if(numero[i] == '6') printf("seis");
    else if(numero[i] == '7') printf("sete");
    else if(numero[i] == '8') printf("oito");
    else if(numero[i] == '9') printf("nove");
    else if(numero[i] == '0') printf("zero");
}

void dezena(char numero[10], int i){
    if(numero[i] == '1'){
        if(numero[i+1] == '0') printf("dez");
        else if(numero[i+1] == '1') printf("onze");
        else if(numero[i+1] == '2') printf("doze");
        else if(numero[i+1] == '3') printf("treze");
        else if(numero[i+1] == '4') printf("quatorze");
        else if(numero[i+1] == '5') printf("quinze");
        else if(numero[i+1] == '6') printf("dezesseis");
        else if(numero[i+1] == '7') printf("dezessete");
        else if(numero[i+1] == '8') printf("dezoito");
        else if(numero[i+1] == '9') printf("dezenove");
    }else if(numero[i] == '2'){
        if(numero[i+1] == '0') printf("vinte");
        else{
            printf("vinte e ");
            unidade(numero, i+1);
        }
    }else if(numero[i] == '3'){
        if(numero[i+1] == '0') printf("trinta");
        else{
            printf("trinta e ");
            unidade(numero, i+1);
        }
    }else if(numero[i] == '4'){
        if(numero[i+1] == '0') printf("quarenta");
        else{
            printf("quarenta e ");
            unidade(numero, i+1);
        }
    }else if(numero[i] == '5'){
        if(numero[i+1] == '0') printf("cinquenta");
        else{
            printf("cinquenta e ");
            unidade(numero, i+1);
        }
    }else if(numero[i] == '6'){
        if(numero[i+1] == '0') printf("sessenta");
        else{
            printf("sessenta e ");
            unidade(numero, i+1);
        }
    }else if(numero[i] == '7'){
        if(numero[i+1] == '0') printf("setenta");
        else{
            printf("setenta e ");
            unidade(numero, i+1);
        }
    }else if(numero[i] == '8'){
        if(numero[i+1] == '0') printf("oitenta");
        else{
            printf("oitenta e ");
            unidade(numero, i+1);
        }
    }else if(numero[i] == '9'){
        if(numero[i+1] == '0') printf("noventa");
        else{
            printf("noventa e ");
            unidade(numero, i+1);
        }
    }else if(numero[i] == '0'){
        if(numero[i+1] != '0') unidade(numero, i+1);
    }
}

void centena(char numero[10], int i){
    if(numero[i] == '1'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("cem");
            else{
                printf("cento e ");
                unidade(numero, i+2);
            }
        }else{
            printf("cento e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '2'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("duzentos");
            else{
                printf("duzentos e ");
                unidade(numero, i+2);
            }
        }else{
            printf("duzentos e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '3'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("trezentos");
            else{
                printf("trezentos e ");
                unidade(numero, i+2);
            }
        }else{
            printf("trezentos e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '4'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("quatrocentos");
            else{
                printf("quatrocentos e ");
                unidade(numero, i+2);
            }
        }else{
            printf("quatrocentos e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '5'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("quinhentos");
            else{
                printf("quinhentos e ");
                unidade(numero, i+2);
            }
        }else{
            printf("quinhentos e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '6'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("seiscentos");
            else{
                printf("seiscentos e ");
                unidade(numero, i+2);
            }
        }else{
            printf("seiscentos e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '7'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("setecentos");
            else{
                printf("setecentos e ");
                unidade(numero, i+2);
            }
        }else{
            printf("setecentos e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '8'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("oitocentos");
            else{
                printf("oitocentos e ");
                unidade(numero, i+2);
            }
        }else{
            printf("oitocentos e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '9'){
        if(numero[i+1] == '0'){
            if(numero[i+2] == '0') printf("novecentos");
            else{
                printf("novecentos e ");
                unidade(numero, i+2);
            }
        }else{
            printf("novecentos e ");
            dezena(numero, i+1);
        }
    }else if(numero[i] == '0'){
        if(numero[i+1] == '0'){
            if(numero[i+2] != '0'){
                unidade(numero, i+2);
            }
        }else dezena(numero, i+1);
    }
}

int tamanho_num(char numero[10], int posicao){
    if(numero[posicao] == '\0' || posicao == 9) return posicao;
    else{
        posicao++;
        return tamanho_num(numero, posicao);
    }
}

int verifica_zero(char numero[10], int tam, int i){
    if(i == tam) return 0;
    else{
        if(numero[i] != '0') return 1;
        return verifica_zero(numero, tam, i+1);
    }

}

int qtd_zero(char numero[10], int i, int tam, int qtd){
    if(i == tam) return qtd;
    else{
        if(numero[i] == '0') qtd++;
        return qtd_zero(numero, i+1, tam, qtd);
    }
}

void mil(char numero[10], int i, int tam){
    int zeros = qtd_zero(numero, 0, tam, 0);
    if(tam == 4){
        if(zeros == 4) printf("zero");
        else if(numero[0] == '0') centena(numero, i+1);
        else if(numero[0] == '1'){
            if(verifica_zero(numero, tam, 1) == 0) printf("mil");
            else{
                if(verifica_zero(numero, tam, 2) == 0){
                    printf("mil e ");
                    centena(numero, 1);
                }else if(numero[1] == '0'){
                    printf("mil e ");
                    dezena(numero, 2);
                }else{
                    printf("mil ");
                    centena(numero, 1);
                }
            }
        }else{
            if(verifica_zero(numero, tam, 1) == 0){
                unidade(numero, 0);
                printf(" mil");
            }else if(numero[i+1] != '0'){
                if(verifica_zero(numero, tam, 2) == 0){
                    unidade(numero, 0),
                    printf(" mil e ");
                    centena(numero, i+1);
                }else{
                    unidade(numero, 0),
                    printf(" mil ");
                    centena(numero, i+1);
                }
            }else{
                unidade(numero, 0);
                printf(" mil e ");
                dezena(numero, 2);
            }
        }
    }else if(tam == 5){
        if(zeros == 5) printf("zero");
        else if(numero[0] == '0'){
            if(numero[1] == '0') centena(numero, 2);
        }
        else if(verifica_zero(numero, tam, 2) == 0){
            dezena(numero, 0);
            printf(" mil");
        }else if(verifica_zero(numero, tam, 3) == 0 || numero[2] == '0'){
            dezena(numero, 0);
            printf(" mil e ");
            centena(numero, 2);
        }else{
            dezena(numero, 0);
            printf(" mil ");
            centena(numero, 2);
        }
    }else if(tam == 6){
        if(zeros == 6) printf("zero");
        else if(numero[0] == '0'){
            if(numero[1] == '0' && numero[2] == '0') centena(numero, 3);
        }
        else if(verifica_zero(numero, tam, 3) == 0){
            centena(numero, 0);
            printf(" mil");
        }else if(verifica_zero(numero, tam, 4) == 0 || numero[3] == '0'){
            centena(numero, 0);
            printf(" mil e ");
            centena(numero, 3);
        }else{
            centena(numero, 0);
            printf(" mil ");
            centena(numero, 3);
        }
    }
}

char pegar_mil(char numero[10], int i, int tam, char new[6]){
    if(i == 6){
        mil(new, 0, 6);
    }else{
        if(tam == 7) new[i] = numero[i+1];
        else if(tam == 8) new[i] = numero[i+2];
        else if(tam == 9) new[i] = numero[i+3];
        return pegar_mil(numero, i+1, tam, new);
    }
}

void milhao(char numero[10], int i, int tam){
    char new[6];
    int zeros = qtd_zero(numero, 0, tam, 0);
    if(tam == 7){
        if(zeros == 7) printf("zero");
        else if(numero[0] == '0') pegar_mil(numero, 0, 7, new);
        else if(numero[0] == '1'){
            if(zeros == 5){
                if(verifica_zero(numero, 7, 4) == 0){
                    printf("um milhao e ");
                    pegar_mil(numero, 0, 7, new);
                }else if(numero[4] != '0' || numero[5] != '0' || numero[6] != '0'){
                    printf("um milhao e ");
                    centena(numero, 4);
                }
            }else{
                printf("um milhao ");
                pegar_mil(numero, 0, 7, new);
            }
        }else{
            if(zeros == 6){
                unidade(numero, 0);
                printf(" milhoes");
            }else if(zeros == 5){
                if(verifica_zero(numero, 7, 4) == 0){
                    unidade(numero, 0);
                    printf(" milhoes e ");
                    pegar_mil(numero, 0, 7, new);
                }else if(numero[4] != '0' || numero[5] != '0' || numero[6] != '0'){
                    unidade(numero, 0);
                    printf(" milhoes e ");
                    centena(numero, 4);
                }
            }else{
                unidade(numero, 0);
                printf(" milhoes ");
                pegar_mil(numero, 0, 7, new);
            }
        }
    }else if(tam == 8){
        if(zeros == 8) printf("zero");
        else if(numero[0] == '0' && numero[1] == '0') pegar_mil(numero, 0, 8, new);
        else if(zeros == 7 || verifica_zero(numero, tam, 2) == 0){
            dezena(numero, 0);
            printf(" milhoes");
        }else if(zeros >= 5){
            if(verifica_zero(numero, 8, 5) == 0){
                dezena(numero, 0);
                printf(" milhoes e ");
                pegar_mil(numero, 0, tam, new);
            }else if(numero[5] != '0' || numero[6] != '0' || numero[7] != '0'){
                dezena(numero, 0);
                printf(" milhoes e ");
                centena(numero, 5);
            }
        }else{
            dezena(numero, 0);
            printf(" milhoes ");
            pegar_mil(numero, 0, tam, new);
        }
    }else if(tam == 9){
        if(zeros == 9) printf("zero");
        else if(numero[0] == '0' && numero[1] == '0' && numero[2] == '0') pegar_mil(numero, 0, 9, new);
        else if(zeros == 8){
            centena(numero, 0);
            printf(" milhoes");
        }else if(zeros >= 5){
            if(verifica_zero(numero, 9, 6) == 0){
                centena(numero, 0);
                printf(" milhoes e ");
                pegar_mil(numero, 0, 9, new);
            }else if(numero[6] != '0' || numero[7] != '0' || numero[8] != '0'){
                centena(numero, 0);
                printf(" milhoes e ");
                centena(numero, 6);
            }
        }else{
            centena(numero, 0);
            printf(" milhoes ");
            pegar_mil(numero, 0, 9, new);
        }
    }
}

void escreve_nome(char numero[10]){
    int tam;
    tam = tamanho_num(numero, 0);
    if(tam == 1) unidade(numero, 0);
    else if(tam == 2) dezena(numero, 0);
    else if(tam == 3) centena(numero, 0);
    else if(tam > 3 && tam < 7) mil(numero, 0, tam);
    else if(tam > 6 && tam < 10) milhao(numero, 0, tam);
}

int main()
{
    char numero[10];
    gets(numero);
    int valido = valida_numero(numero, 0);
    if(valido == 1) printf("ERRO!\n");
    else escreve_nome(numero);
    return 0;
}
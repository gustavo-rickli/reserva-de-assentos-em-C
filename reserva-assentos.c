// PROGRAMA PARA RESERVA DE ASSENTOS EM UM AVIÃO

#include <stdio.h>
#include <stdlib.h>

#define ASSENTOS_MAXIMOS 10
#define MENSAGEM_DE_ERRO "O assento já está reservado!\n"

#define INICIO_ASSENTOS_CLASSE_ECONOMICA 0
#define INICIO_ASSENTOS_PRIMEIRA_CLASSE 6

int assentos[ASSENTOS_MAXIMOS] = {0};

// controla a reserva de assentos do avião
void reserva_assentos(void);

// imprime um bilhete com os assentos reservados do passageiro
char *imprimir_bilhete(void);

// verifica o indice do assento
int verificar_assento(int indice_do_assento);

// imprime os assentos
void imprimir_assentos(void);

// efetua a reserva do assento
void efetuar_reserva(int indice_do_assento);

// verifica se todos os assentos já estão reservados
int verificar_lotacao(void);

// verificar se a classe está cheia
int classe_cheia(void);

int main() {
    /*
    int y = 5;
    int *yPrt;

    printf("%d", *yPtr);
*/
reserva_assentos();

    return 0;
}

void reserva_assentos(void) {

    int encerrarReservas = 0;
    int assentoEscolhido;

    do {

        printf("Escolha seu assento:\n0-4 Primeira Classe e 5-9 Classe economica\n");

        for (int i = 0; i < ASSENTOS_MAXIMOS; i = i + 1) {
            printf("%d\t", i);
        }

        printf("\n");

        imprimir_assentos();

        printf("Escolha o assento: ");
        scanf("%d", &assentoEscolhido);

        if (verificar_assento(assentoEscolhido)) {
            efetuar_reserva(assentoEscolhido);
        } else {
            printf("%s", MENSAGEM_DE_ERRO);
        }

        puts("Deseja encerrar a reserva dos assentos?");
        puts("Digite 1 para sair");
        puts("Digite 0 para continuar");
        scanf("%d", &encerrarReservas);

        system("clear");

    } while (encerrarReservas != 1 || verificar_lotacao());

    printf("\n\n%s\n\n", imprimir_bilhete());
}

void efetuar_reserva(int indice_do_assento) {
    assentos[indice_do_assento] = 1;
}

int verificar_lotacao(void) {
    int totalDeAssentosReservados = 0;

    for (int counter = 0; counter < ASSENTOS_MAXIMOS; counter = counter + 1) {
        if (assentos[counter] == 1) {
            totalDeAssentosReservados = totalDeAssentosReservados + 1;
        }
    }

    if (totalDeAssentosReservados == ASSENTOS_MAXIMOS) {
        return 1; // caso todos os assentos estejam reservados
    } else {
        return 0; // caso tenha assentos livres ainda
    }
}

void imprimir_assentos(void) {
    for (int counter = 0; counter < ASSENTOS_MAXIMOS; counter = counter + 1) {
        printf("%d\t", assentos[counter]);
    }

    printf("\n");
}

int verificar_assento(int indice_do_assento) {

    /*Quan-
do a primeira classe estiver cheia, seu programa deverá
perguntar à pessoa se ela aceita ser colocada na classe
econômica (e vice-versa). Se a resposta for sim, faça a
designação de assentos apropriada. Se a resposta for não,
imprima a mensagem “O próximo voo sairá em 3
horas.”
*/

    // verficação em caso da classe estiver cheia
    if (!classe_cheia()) {
        if (assentos[indice_do_assento] == 0) {
            return 1; // está livre
        } else {
            return 0; // está reservado
        }
    }
}

int classe_cheia(void) {

    // Primeira Classe

    int totalDeAssentosReservados = 0;

    for (int counter = INICIO_ASSENTOS_CLASSE_ECONOMICA; counter < INICIO_ASSENTOS_PRIMEIRA_CLASSE; counter = counter + 1) {
        if (assentos[counter] == 1) {
            totalDeAssentosReservados = totalDeAssentosReservados + 1;
        }
    }

    int maximoAssentosPrimeiraClasse = INICIO_ASSENTOS_PRIMEIRA_CLASSE - 1;

    if (totalDeAssentosReservados == maximoAssentosPrimeiraClasse) {
        puts("A classe econômica está lotada, aceita ser colocado na primeira classe?");
        puts("1 - Sim         0 - Não");

        int resposta;

        scanf("%d", &resposta);

        if (resposta == 1) {
            for (int counter = INICIO_ASSENTOS_PRIMEIRA_CLASSE; counter < ASSENTOS_MAXIMOS; counter = counter + 1) {
                if (assentos[counter] == 0) {
                    assentos[counter] = 1;
                    printf("\nReservamos o assento %d para o senhor.\n", counter);
                    return 1;
                }
            }
        }
    }

    // Classe Economica

    totalDeAssentosReservados = 0;

    for (int counter = INICIO_ASSENTOS_PRIMEIRA_CLASSE; counter < ASSENTOS_MAXIMOS; counter = counter + 1) {
        if (assentos[counter] == 1) {
            totalDeAssentosReservados = totalDeAssentosReservados + 1;
        }
    }

    int maximoAssentosClasseEconomica = ASSENTOS_MAXIMOS - 1;

    if (totalDeAssentosReservados == maximoAssentosClasseEconomica) {
        puts("A primeira classe está lotada, aceita ser colocado na classe econômica?");
        puts("1 - Sim         0 - Não");

        int resposta;

        scanf("%d", &resposta);

        if (resposta == 1) {

            // verificação
            for (int counter = INICIO_ASSENTOS_PRIMEIRA_CLASSE; counter < ASSENTOS_MAXIMOS; counter = counter + 1) {
                if (assentos[counter] == 0) {
                    assentos[counter] = 1;
                    printf("\nReservamos o assento %d para o senhor.\n", counter);
                    return 1;
                }
            }
        }
    }

    // retorno padrão
    return 0;
}

// a fazer
char *imprimir_bilhete(void) {
    
}

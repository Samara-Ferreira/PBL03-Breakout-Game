/**
 *  Função de utilização dos dados dos botões.
 */


#include "prototype.h"

/**
 * Alteração do estado atual do jogo.
 * 
 * Utiliza o estado atual do jogo e as alterações dos sinais dos botões para indicar qual será o próximo estado.
 * 
 * @param pointer_state   Ponteiro indicando o endereço que armazena o estado atual do jogo.
 * @param pointer_buttons Ponteiro indicando o endereço que armazena o sinais lidos dos botões.
 * @return void
 */
void change_state(int *pointer_state, int *pointer_buttons) {

    /*
        state = 0; tela inicial
        state = 1; jogo rodando
        state = 2; em pausa com opção de play
        state = 3; em pausa com opção de exit
    */

    switch (*pointer_state) {

    case 0:

        if (*pointer_buttons == 1) {

            *pointer_state = 1;
        }

        break;

    case 1:

        if (*pointer_buttons == 1) {

            *pointer_state = 2;
        }

        break;

    case 2:

        if (*pointer_buttons == 1) {

            *pointer_state = 3;
        }
        else if (*pointer_buttons == 2) {

            *pointer_state = 1;
        }

        break;

    case 3:

        if (*pointer_buttons == 1) {

            *pointer_state = 2;
        }

        else if (*pointer_buttons == 2) {
	
            *pointer_state = 0;
        }

        break;
    }
}
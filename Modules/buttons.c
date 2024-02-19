#include "prototype.h"

void change_state(int *pointer_state, int *pointer_buttons) {

    /*
        state = 0; tela inicial
        state = 1; jogo rodando
        state = 2; em pausa play
        state = 3; em pausa exit
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
#include "prototype.h"


/**
 * Desenha uma frase na tela.
 *
 * Esta função desenha uma frase na tela do dispositivo de vídeo VGA, onde cada caractere
 * é desenhado em escala 10x10.
 * A frase deve esta em uma lista com esse formato:
 * char letras[] = {'H', 'e', 'l', 'l', 'o'};
 *
 * @param coordX A coordenada X do canto superior esquerdo da região onde a frase será desenhada.
 * @param coordY A coordenada Y do canto superior esquerdo da região onde a frase será desenhada.
 * @param lista Um ponteiro para a string contendo a frase a ser desenhada.
 * @param tamanhoLista O tamanho da lista contendo a frase.
 * @param cor A cor dos caracteres da frase.
 * @return void
 */
void phrase(int coordX, int coordY, char *list, int lenList, short cor) {

    int X;

    for (int i = 0; i < lenList; ++i) {

        if (list[i] != ' ') {

            X = coordX + i * 13;
            alphanumeric(X, coordY, list[i], cor);

        }
    }
}

void write_score( int coordX, int coordY, int score) {

    char number_str[10];

    sprintf(number_str, "%d", score);

    int len = strlen(number_str);
    int i;

    for (i = 0; i < len; i++) {

        alphanumeric(coordX + (13 * i), coordY, number_str[i], 0xFFE0);
    }
}

void screen_defeat (int score) {

    char defeat_message[9] = "game over";
    char score_message[6] = "score:";

    phrase(100, 110, defeat_message, 9, 0xf800);
    phrase(105, 145, score_message, 6, 0xffe0);
    write_score(183,  145, score);

}

void screen_victory () {

    char victory_message[9] = "you win";

    phrase(115, 110, victory_message, 7, 0x07e0);

}

void create_menu () {

    char start_game[] = "start game";

    phrase(96, 160, start_game, 10, 0xdd82);
}

void game_field(Block blocksList[], int score, int state_game) {

    char text_score[6] = "score:";

    phrase(0, 0, text_score, 6, 0xFFE0);
    write_score(78, 0, score);

    if (state_game == 1) {

        char text_pause[11] = "";
        phrase(177, 0, text_pause, 11, 0xFFFF);
        
    }
    else if (state_game == 2) {

        char text_pause[11] = "pause<play>";
        phrase(177, 0, text_pause, 11, 0xFFFF);
        
    }
    else if (state_game == 3) {

        char text_pause[11] = "pause<exit>";
        phrase(177, 0, text_pause, 11, 0xFFFF);
        
    }

    video_box(0, 15, 2, 239, 0xC618);
    video_box(3, 15, 319, 17, 0xC618);
    video_box(317, 18, 319, 239, 0xC618);

    int i;

    for (i = 0; i < 48; i++) {

        if (blocksList[i].flagVisible == 1) {

            video_box(blocksList[i].coordX, blocksList[i].coordY, blocksList[i].coordX + 36, blocksList[i].coordY + 11, blocksList[i].color);
        }
    }
}

void title (coordX, coordY) {

    short cor1 = 0x3f9e; //ciano
    short cor2 = 0xf81f; //magenta

    // Letra B

    video_box(coordX     , coordY     , coordX +  9, coordY + 33, cor1);
    video_box(coordX + 10, coordY     , coordX + 23, coordY +  5, cor1);
    video_box(coordX + 10, coordY +  6, coordX + 11, coordY + 13, cor2);
    video_box(coordX + 10, coordY + 20, coordX + 11, coordY + 27, cor2);
    video_box(coordX + 10, coordY + 14, coordX + 23, coordY + 19, cor1);
    video_box(coordX + 10, coordY + 28, coordX + 23, coordY + 33, cor1);
    video_box(coordX + 20, coordY +  6, coordX + 27, coordY + 13, cor1);
    video_box(coordX + 20, coordY + 20, coordX + 27, coordY + 27, cor1);
    video_box(coordX + 24, coordY     , coordX + 25, coordY +  5, cor2);
    video_box(coordX + 28, coordY +  6, coordX + 29, coordY + 13, cor2);
    video_box(coordX + 24, coordY + 14, coordX + 25, coordY + 19, cor2);
    video_box(coordX + 28, coordY + 20, coordX + 29, coordY + 27, cor2);
    video_box(coordX + 24, coordY + 28, coordX + 25, coordY + 33, cor2);

    coordX += 33;

    // Letra r

    video_box(coordX     , coordY +  8, coordX +  9, coordY + 33, cor1);
    video_box(coordX + 10, coordY +  8, coordX + 11, coordY + 13, cor2);
    video_box(coordX + 12, coordY +  8, coordX + 23, coordY + 13, cor1);
    video_box(coordX + 24, coordY +  8, coordX + 25, coordY + 13, cor2);
    video_box(coordX + 10, coordY + 14, coordX + 13, coordY + 19, cor1);
    video_box(coordX + 14, coordY + 14, coordX + 15, coordY + 19, cor2);
    video_box(coordX + 10, coordY + 20, coordX + 11, coordY + 33, cor2);

    coordX += 29;

    // Letra e

    video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, cor1);
    video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, cor2);
    video_box(coordX     , coordY + 14, coordX +  9, coordY + 27, cor1);
    video_box(coordX + 10, coordY + 14, coordX + 11, coordY + 17, cor2);
    video_box(coordX + 10, coordY + 24, coordX + 11, coordY + 27, cor2);
    video_box(coordX + 10, coordY + 18, coordX + 25, coordY + 23, cor1);
    video_box(coordX + 20, coordY + 14, coordX + 25, coordY + 17, cor1);
    video_box(coordX + 26, coordY + 14, coordX + 27, coordY + 23, cor2);
    video_box(coordX +  4, coordY + 28, coordX + 21, coordY + 33, cor1);
    video_box(coordX + 22, coordY + 28, coordX + 23, coordY + 33, cor2);

    coordX += 30;

    // Letra a

    video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, cor1);
    video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, cor2);
    video_box(coordX + 18, coordY + 14, coordX + 26, coordY + 17, cor1);
    video_box(coordX +  4, coordY + 18, coordX + 25, coordY + 23, cor1);
    video_box(coordX     , coordY + 24, coordX +  9, coordY + 27, cor1);
    video_box(coordX + 10, coordY + 24, coordX + 12, coordY + 27, cor2);
    video_box(coordX + 18, coordY + 24, coordX + 25, coordY + 27, cor1);
    video_box(coordX +  4, coordY + 28, coordX + 25, coordY + 33, cor1);
    video_box(coordX +  26, coordY +  14, coordX + 27, coordY + 33, cor2);

    coordX += 30;

    // Letra k

    video_box(coordX     , coordY     , coordX +  9, coordY + 33, cor1);
    video_box(coordX + 10, coordY     , coordX + 11, coordY + 17, cor2);
    video_box(coordX + 10, coordY + 22, coordX + 11, coordY + 33, cor2);
    video_box(coordX + 10, coordY + 18, coordX + 18, coordY + 21, cor1);
    video_box(coordX + 18, coordY + 18, coordX + 19, coordY + 21, cor2);
    video_box(coordX + 18, coordY +  6, coordX + 25, coordY + 11, cor1);
    video_box(coordX + 26, coordY +  6, coordX + 27, coordY + 11, cor2);
    video_box(coordX + 14, coordY + 12, coordX + 21, coordY + 17, cor1);
    video_box(coordX + 22, coordY + 12, coordX + 23, coordY + 17, cor2);
    video_box(coordX + 14, coordY + 22, coordX + 21, coordY + 27, cor1);
    video_box(coordX + 22, coordY + 22, coordX + 23, coordY + 27, cor2);
    video_box(coordX + 18, coordY + 28, coordX + 25, coordY + 33, cor1);
    video_box(coordX + 26, coordY + 28, coordX + 27, coordY + 33, cor2);

    coordX += 30;

    //Letra o

    video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, cor1);
    video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, cor2);
    video_box(coordX     , coordY + 14, coordX +  9, coordY + 27, cor1);
    video_box(coordX + 10, coordY + 14, coordX + 11, coordY + 27, cor2);
    video_box(coordX + 20, coordY + 14, coordX + 25, coordY + 27, cor1);
    video_box(coordX + 26, coordY + 14, coordX + 27, coordY + 27, cor2);
    video_box(coordX +  4, coordY + 28, coordX + 21, coordY + 33, cor1);
    video_box(coordX + 22, coordY + 28, coordX + 23, coordY + 33, cor2);

    coordX += 30;

    // Letra u

    video_box(coordX     , coordY +  8, coordX +  9, coordY + 27, cor1);
    video_box(coordX + 10, coordY +  8, coordX + 11, coordY + 27, cor2);
    video_box(coordX + 20, coordY +  8, coordX + 25, coordY + 33, cor1);
    video_box(coordX + 26, coordY +  8, coordX + 27, coordY + 33, cor2);
    video_box(coordX + 4, coordY +  28, coordX + 19, coordY + 33, cor1);

    coordX += 31;

    // Letra t

    video_box(coordX +  8, coordY     , coordX + 17, coordY +  7, cor1);
    video_box(coordX + 18, coordY     , coordX + 19, coordY +  7, cor2);
    video_box(coordX     , coordY +  8, coordX + 25, coordY + 13, cor1);
    video_box(coordX + 26, coordY +  8, coordX + 27, coordY + 13, cor2);
    video_box(coordX +  8, coordY + 14, coordX + 17, coordY + 33, cor1);
    video_box(coordX + 18, coordY + 14, coordX + 19, coordY + 33, cor2);

}

void alphanumeric(int coordX, int coordY, char caracter, short cor) {

    switch (caracter) {

    case '^':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY + 1, coordX + 3, coordY + 8, cor);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, cor);
        video_box(coordX + 6, coordY + 3, coordX + 7, coordY + 6, cor);
        video_box(coordX + 8, coordY + 4, coordX + 9, coordY + 5, cor);

    case '<':

        video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, cor);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, cor);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, cor);
        video_box(coordX + 6, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 6, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '>':

        video_box(coordX + 2, coordY, coordX + 3, coordY + 1, cor);
        video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, cor);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, cor);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, cor);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, cor);

        break;

    case ':':

        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, cor);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, cor);

        break;

    case ';':

        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, cor);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 9, cor);

        break;

    case '0':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, cor);

        break;

    case '1':


        video_box(coordX + 2, coordY, coordX + 3, coordY + 1, cor);
        video_box(coordX + 4, coordY, coordX + 5, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '2':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, cor);
        video_box(coordX, coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    case '3':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX, coordY + 6, coordX + 1, coordY + 7, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '4':

        video_box(coordX, coordY, coordX + 1, coordY + 5, cor);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, cor);

        break;

    case '5':

        video_box(coordX, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '6':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '7':

        video_box(coordX, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, cor);

        break;

    case '8':

        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX, coordY + 6, coordX + 1, coordY + 7, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '9':

        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX, coordY + 8, coordX + 7, coordY + 9, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, cor);

        break;

    case 'a':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 9, cor);

        break;

    case 'b':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);

        break;

    case 'c':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    case 'd':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, cor);

        break;

    case 'e':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    case 'f':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);

        break;

    case 'g':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 4, coordY + 4, coordX + 9, coordY + 5, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    case 'h':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, cor);

        break;

    case 'i':

        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case 'j':

        video_box(coordX, coordY + 4, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, cor);

        break;

    case 'k':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY + 4, coordX + 5, coordY + 5, cor);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, cor);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    case 'l':

        video_box(coordX, coordY, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    case 'm':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, cor);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, cor);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, cor);

        break;

    case 'n':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, cor);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, cor);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, cor);

        break;

    case 'o':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, cor);

        break;

    case 'p':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, cor);

        break;

    case 'q':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, cor);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, cor);
        video_box(coordX + 2, coordY + 8, coordX + 5, coordY + 9, cor);

        break;

    case 'r':

        video_box(coordX, coordY, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, cor);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, cor);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    case 's':

        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case 't':

        video_box(coordX, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 9, cor);

        break;

    case 'u':

        video_box(coordX, coordY, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, cor);

        break;

    case 'v':

        video_box(coordX, coordY, coordX + 1, coordY + 5, cor);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, cor);
        video_box(coordX + 4, coordY + 8, coordX + 5, coordY + 9, cor);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 5, cor);

        break;

    case 'w':

        video_box(coordX, coordY, coordX + 1, coordY + 7, cor);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case 'x':

        video_box(coordX, coordY, coordX + 1, coordY + 3, cor);
        video_box(coordX, coordY + 6, coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 3, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 9, cor);

        break;

    case 'y':

        video_box(coordX, coordY, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, cor);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 9, cor);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 3, cor);

        break;

    case 'z':

        video_box(coordX, coordY, coordX + 9, coordY + 1, cor);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, cor);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, cor);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, cor);
        video_box(coordX, coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    default:

        break;
    }
}


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

/**
 * Converte o valor do score do tipo inteiro para um vetor do tipo char. Cada caractere do vetor
 * é percorrido e enviado para a função que irá exibir cada um dos valores através do cabo VGA.
 * 
 * @param coordX A coordenada X do canto superior esquerdo da região onde o valor será exibido.
 * @param coordY A coordenada Y do canto superior esquerdo da região onde o valor será exibido.
 * @param score Valor do score que deve ser exibido.
 * @return void
 */
void write_score( int coordX, int coordY, int score) {

    char number_str[10];

    sprintf(number_str, "%d", score);

    int len = strlen(number_str);
    int i;

    for (i = 0; i < len; i++) {

        alphanumeric(coordX + (13 * i), coordY, number_str[i], 0xFFE0);
    }
}

/**
 * Exibe a tela de derrota. São exibidas as frases "game over" e o valor do score alcançado, utilizando
 * as funções de escrita de frase e exibição do valor do score.
 * 
 * @param score Valor do score alcançado na rodada.
 * @return void
 */
void screen_defeat (int score) {

    char defeat_message[9] = "game over";
    char score_message[6] = "score:";
    int sub_coordX = 0;

    if (score > 100) {

        sub_coordX = 10; 
    }
    else if (score > 10) {

        sub_coordX = 5;
    }

    phrase(100, 110, defeat_message, 9, 0xf800);
    phrase(110 - sub_coordX, 145, score_message, 6, 0xffe0);
    write_score(188 - sub_coordX,  145, score);

}

/**
 * Exibe a tela inicial do jogo. É exibido o título do jogo e a frase "start game", utilizando a função de 
 * exibição do título e de exibição da frase.
 * 
 * @return void
 */
void create_menu () {

    char start_game[] = "start game";

    phrase(96, 160, start_game, 10, 0xdd82);

    title(40, 30);
}

/**
 * Exibe o campo de jogo. É exibido o título do jogo e a frase "start game".
 * 
 * @return void
 */
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

void title ( int coordX, int coordY) {

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

void rocket (int coordX, int coordY, int cor1, int cor2) {

    // cor1 = preto
    // cor2 = vermelho

    int orange = 0xFC00;
    int yellow = 0xFFE0;

    video_box ( coordX + 10, coordY + 1, coordX + 12, coordY + 1, cor1);
    video_box ( coordX + 9, coordY + 2, coordX + 13, coordY + 2, cor1);
    video_box ( coordX + 8, coordY + 3, coordX + 14, coordY + 4, cor1);

    video_box ( coordX + 7, coordY + 5, coordX + 15, coordY + 6, cor2);
    video_box ( coordX + 7, coordY + 7, coordX + 15, coordY + 8, cor1);
    video_box ( coordX + 7, coordY + 9, coordX + 15, coordY + 10, cor2);
    video_box ( coordX + 7, coordY + 11, coordX + 15, coordY + 12, cor1);
    video_box ( coordX + 7, coordY + 13, coordX + 15, coordY + 14, cor2);
    video_box ( coordX + 7, coordY + 15, coordX + 15, coordY + 16, cor1);
    video_box ( coordX + 7, coordY + 17, coordX + 15, coordY + 18, cor2);

    video_box ( coordX + 8, coordY + 19, coordX + 9, coordY + 20, orange);
    video_box ( coordX + 10, coordY + 19, coordX + 12, coordY + 20, yellow);
    video_box ( coordX + 13, coordY + 19, coordX + 14, coordY + 20, orange);

    video_box ( coordX + 9, coordY + 21, coordX + 13, coordY + 22, orange);
    video_box ( coordX + 11, coordY + 21, coordX + 11, coordY + 21, yellow);
    video_box ( coordX + 10, coordY + 23, coordX + 12, coordY + 23, orange);
    video_box ( coordX + 11, coordY + 14, coordX + 11, coordY + 14, orange);
    
}

void explosion (int coordX, int coordY, int cor1, int cor2) {

    // cor1 = vermelho
    // cor2 = amarelo

    video_line ( coordX + 12, coordY + 10, coordX + 37, coordY + 34, cor1);
    video_line ( coordX + 49, coordY + 2, coordX + 49, coordY + 34, cor1);
    video_line ( coordX + 87, coordY + 10, coordX + 63, coordY + 35, cor1);

    video_line ( coordX + 63, coordY + 50, coordX + 89, coordY + 50, cor1);
    video_line ( coordX + 64, coordY + 64, coordX + 91, coordY + 91, cor1);
    video_line ( coordX + 49, coordY + 65, coordX + 49, coordY + 98, cor1);

    video_line ( coordX + 37, coordY + 64, coordX + 14, coordY + 89, cor1);
    video_line ( coordX + 37, coordY + 49, coordX + 13, coordY + 49, cor1);


    video_line ( coordX + 33, coordY + 10, coordX + 33, coordY + 15, cor2);
    video_line ( coordX + 33, coordY + 16, coordX + 33, coordY + 20, cor1);

    video_line ( coordX + 65, coordY + 9, coordX + 65, coordY + 14, cor2);
    video_line ( coordX + 65, coordY + 15, coordX + 65, coordY + 19, cor1);

    video_line ( coordX + 81, coordY + 31, coordX + 87, coordY + 31, cor2);
    video_line ( coordX + 77, coordY + 31, coordX + 80, coordY + 31, cor1);

    video_line ( coordX + 97, coordY + 50, coordX + 100, coordY + 50, cor2);
    video_line ( coordX + 93, coordY + 50, coordX + 96, coordY + 50, cor1);

    video_line ( coordX + 81, coordY + 66, coordX + 87, coordY + 66, cor2);
    video_line ( coordX + 77, coordY + 66, coordX + 80, coordY + 66, cor1);

    video_line ( coordX + 65, coordY + 84, coordX + 65, coordY + 90, cor2);
    video_line ( coordX + 65, coordY + 78, coordX + 65, coordY + 83, cor1);

    video_line ( coordX + 37, coordY + 83, coordX + 37, coordY + 90, cor2);
    video_line ( coordX + 37, coordY + 77, coordX + 37, coordY + 82, cor1);

    video_line ( coordX + 11, coordY + 65, coordX + 18, coordY + 65, cor2);
    video_line ( coordX + 19, coordY + 65, coordX + 24, coordY + 65, cor1);

    video_line ( coordX + 1, coordY + 49, coordX + 4, coordY + 49, cor2);
    video_line ( coordX + 5, coordY + 49, coordX + 8, coordY + 49, cor1);

    video_line ( coordX + 12, coordY + 32, coordX + 18, coordY + 32, cor2);
    video_line ( coordX + 19, coordY + 32, coordX + 24, coordY + 32, cor1);

}

typedef struct Explosion {

    int coordX;         /* x do canto superior esquerdo */ 
    int coordY;
	int color;
    struct Explosion *prox;
    
} Explosion;

typedef struct {

    int len;
    Explosion *begin;

} List;

void screen_victory () {

    char victory_message[7] = "you win";

    int red = 0xF800;
    int blue = 0x041F;
    int yellow = 0xFFE0;
    int white = 0xFFFF;
    int green = 0x07E0;
    int pink = 0xFC18;
    int orange = 0xFC00;
    int listColors[] = {yellow, green, pink, orange, red, blue};
    int i, j, indexColor = 0;

    for ( i = 214; i > 37; i--) {

        video_clear();

        rocket( 38, i, white, red);
        rocket( 258, i, white, blue);
        phrase(115, 110, victory_message, 7, 0x07e0);

        video_show();

    }

    video_clear();

    explosion (0, 0, red, yellow );
    explosion (218, 0, blue, yellow );
    phrase(115, 110, victory_message, 7, 0x07e0);

    video_show();

    Explosion ex1;
    Explosion ex2;

    ex1.coordX = 0;
    ex1.coordY = 0;
    ex1.color = red;
    ex1.prox = &ex2;

    ex2.coordX = 218;
    ex2.coordY = 0;
    ex2.color = blue;
    ex2.prox = NULL;

    List list;

    list.begin = &ex1;
    list.len = 2;

    int buttons;

    KEY_read(&buttons);

    Explosion *aux, *new;
    int coordX = 60, coordY_limit = 129;
    j = 214;
    
    while (buttons != 1) {

        video_clear();

        aux = list.begin;

        for ( i = 0; i < list.len; i++) {

            explosion ( aux->coordX, aux->coordY, aux->color, yellow);
            aux = aux->prox;

        }

        if ( (j - 37) == coordY_limit) {

            new = malloc( sizeof(Explosion));
            new->color = listColors[indexColor];
            new->coordX = coordX - 38;
            new->coordY = coordY_limit;
            new->prox = list.begin;
            list.begin = new;
            list.len += 1;
            
            j = 214;
            coordX = (coordX + 80) % 259;
            coordY_limit = (coordY_limit + 60) % 139;
            indexColor++;

            if ( coordX < 38) coordX += 38;
            if ( indexColor > 5) indexColor = 0;
            
        } 
        else {

            rocket( coordX, j, white, listColors[indexColor]);
            j -= 1;

        }

        phrase(115, 110, victory_message, 7, 0x07e0);
        video_show();

        KEY_read(&buttons);

    }

    for (i = 0; i < (list.len - 2); i++) {
        aux = list.begin;
        list.begin = list.begin->prox;
        free(aux);

    }

    return;

}
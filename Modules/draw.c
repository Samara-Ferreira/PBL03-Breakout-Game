/**
 *  Chamadas das funções de conexão do driver da VGA. Exibição de caracteres e imagens.
 */


#include "prototype.h"

/**
 * Exibição do título da tela inicial. O título exibe a palavra "breakout".
 * 
 * @param coordX Coordenada X do canto superior esquerdo da região onde o título será exibido.
 * @param coordY Coordenada Y do canto superior esquerdo da região onde o título será exibido.
 * @return void
 */
void title ( int coordX, int coordY) {

    short color1 = 0x3f9e; 
    short color2 = 0xf81f; 

    // Letra B

    video_box(coordX     , coordY     , coordX +  9, coordY + 33, color1);
    video_box(coordX + 10, coordY     , coordX + 23, coordY +  5, color1);
    video_box(coordX + 10, coordY +  6, coordX + 11, coordY + 13, color2);
    video_box(coordX + 10, coordY + 20, coordX + 11, coordY + 27, color2);
    video_box(coordX + 10, coordY + 14, coordX + 23, coordY + 19, color1);
    video_box(coordX + 10, coordY + 28, coordX + 23, coordY + 33, color1);
    video_box(coordX + 20, coordY +  6, coordX + 27, coordY + 13, color1);
    video_box(coordX + 20, coordY + 20, coordX + 27, coordY + 27, color1);
    video_box(coordX + 24, coordY     , coordX + 25, coordY +  5, color2);
    video_box(coordX + 28, coordY +  6, coordX + 29, coordY + 13, color2);
    video_box(coordX + 24, coordY + 14, coordX + 25, coordY + 19, color2);
    video_box(coordX + 28, coordY + 20, coordX + 29, coordY + 27, color2);
    video_box(coordX + 24, coordY + 28, coordX + 25, coordY + 33, color2);

    coordX += 33;

    // Letra r

    video_box(coordX     , coordY +  8, coordX +  9, coordY + 33, color1);
    video_box(coordX + 10, coordY +  8, coordX + 11, coordY + 13, color2);
    video_box(coordX + 12, coordY +  8, coordX + 23, coordY + 13, color1);
    video_box(coordX + 24, coordY +  8, coordX + 25, coordY + 13, color2);
    video_box(coordX + 10, coordY + 14, coordX + 13, coordY + 19, color1);
    video_box(coordX + 14, coordY + 14, coordX + 15, coordY + 19, color2);
    video_box(coordX + 10, coordY + 20, coordX + 11, coordY + 33, color2);

    coordX += 29;

    // Letra e

    video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, color1);
    video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, color2);
    video_box(coordX     , coordY + 14, coordX +  9, coordY + 27, color1);
    video_box(coordX + 10, coordY + 14, coordX + 11, coordY + 17, color2);
    video_box(coordX + 10, coordY + 24, coordX + 11, coordY + 27, color2);
    video_box(coordX + 10, coordY + 18, coordX + 25, coordY + 23, color1);
    video_box(coordX + 20, coordY + 14, coordX + 25, coordY + 17, color1);
    video_box(coordX + 26, coordY + 14, coordX + 27, coordY + 23, color2);
    video_box(coordX +  4, coordY + 28, coordX + 21, coordY + 33, color1);
    video_box(coordX + 22, coordY + 28, coordX + 23, coordY + 33, color2);

    coordX += 30;

    // Letra a

    video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, color1);
    video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, color2);
    video_box(coordX + 18, coordY + 14, coordX + 26, coordY + 17, color1);
    video_box(coordX +  4, coordY + 18, coordX + 25, coordY + 23, color1);
    video_box(coordX     , coordY + 24, coordX +  9, coordY + 27, color1);
    video_box(coordX + 10, coordY + 24, coordX + 12, coordY + 27, color2);
    video_box(coordX + 18, coordY + 24, coordX + 25, coordY + 27, color1);
    video_box(coordX +  4, coordY + 28, coordX + 25, coordY + 33, color1);
    video_box(coordX +  26, coordY +  14, coordX + 27, coordY + 33, color2);

    coordX += 30;

    // Letra k

    video_box(coordX     , coordY     , coordX +  9, coordY + 33, color1);
    video_box(coordX + 10, coordY     , coordX + 11, coordY + 17, color2);
    video_box(coordX + 10, coordY + 22, coordX + 11, coordY + 33, color2);
    video_box(coordX + 10, coordY + 18, coordX + 18, coordY + 21, color1);
    video_box(coordX + 18, coordY + 18, coordX + 19, coordY + 21, color2);
    video_box(coordX + 18, coordY +  6, coordX + 25, coordY + 11, color1);
    video_box(coordX + 26, coordY +  6, coordX + 27, coordY + 11, color2);
    video_box(coordX + 14, coordY + 12, coordX + 21, coordY + 17, color1);
    video_box(coordX + 22, coordY + 12, coordX + 23, coordY + 17, color2);
    video_box(coordX + 14, coordY + 22, coordX + 21, coordY + 27, color1);
    video_box(coordX + 22, coordY + 22, coordX + 23, coordY + 27, color2);
    video_box(coordX + 18, coordY + 28, coordX + 25, coordY + 33, color1);
    video_box(coordX + 26, coordY + 28, coordX + 27, coordY + 33, color2);

    coordX += 30;

    //Letra o

    video_box(coordX +  4, coordY +  8, coordX + 21, coordY + 13, color1);
    video_box(coordX + 22, coordY +  8, coordX + 23, coordY + 13, color2);
    video_box(coordX     , coordY + 14, coordX +  9, coordY + 27, color1);
    video_box(coordX + 10, coordY + 14, coordX + 11, coordY + 27, color2);
    video_box(coordX + 20, coordY + 14, coordX + 25, coordY + 27, color1);
    video_box(coordX + 26, coordY + 14, coordX + 27, coordY + 27, color2);
    video_box(coordX +  4, coordY + 28, coordX + 21, coordY + 33, color1);
    video_box(coordX + 22, coordY + 28, coordX + 23, coordY + 33, color2);

    coordX += 30;

    // Letra u

    video_box(coordX     , coordY +  8, coordX +  9, coordY + 27, color1);
    video_box(coordX + 10, coordY +  8, coordX + 11, coordY + 27, color2);
    video_box(coordX + 20, coordY +  8, coordX + 25, coordY + 33, color1);
    video_box(coordX + 26, coordY +  8, coordX + 27, coordY + 33, color2);
    video_box(coordX + 4, coordY +  28, coordX + 19, coordY + 33, color1);

    coordX += 31;

    // Letra t

    video_box(coordX +  8, coordY     , coordX + 17, coordY +  7, color1);
    video_box(coordX + 18, coordY     , coordX + 19, coordY +  7, color2);
    video_box(coordX     , coordY +  8, coordX + 25, coordY + 13, color1);
    video_box(coordX + 26, coordY +  8, coordX + 27, coordY + 13, color2);
    video_box(coordX +  8, coordY + 14, coordX + 17, coordY + 33, color1);
    video_box(coordX + 18, coordY + 14, coordX + 19, coordY + 33, color2);

}

/**
 * Exibição de caracteres.
 * 
 * @param coordX   Coordenada X do canto superior esquerdo da região onde o caractere será exibido.
 * @param coordY   Coordenada Y do canto superior esquerdo da região onde o caractere será exibido.
 * @param caracter Caractere que deve ser exibido.
 * @param color    Cor do caractere. 
 * @return void
 */
void alphanumeric(int coordX, int coordY, char caracter, short color) {

    switch (caracter) {

    case '^':

        video_box(coordX    , coordY    , coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 1, coordX + 3, coordY + 8, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
        video_box(coordX + 6, coordY + 3, coordX + 7, coordY + 6, color);
        video_box(coordX + 8, coordY + 4, coordX + 9, coordY + 5, color);

    case '<':

        video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, color);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
        video_box(coordX + 6, coordY    , coordX + 7, coordY + 1, color);
        video_box(coordX + 6, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '>':

        video_box(coordX + 2, coordY    , coordX + 3, coordY + 1, color);
        video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, color);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);

        break;

    case ':':

        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);

        break;

    case ';':

        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 9, color);

        break;

    case '0':

        video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

        break;

    case '1':


        video_box(coordX + 2, coordY    , coordX + 3, coordY + 1, color);
        video_box(coordX + 4, coordY    , coordX + 5, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '2':

        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
        video_box(coordX    , coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case '3':

        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX    , coordY + 6, coordX + 1, coordY + 7, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '4':

        video_box(coordX    , coordY    , coordX + 1, coordY + 5, color);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY    , coordX + 9, coordY + 9, color);

        break;

    case '5':

        video_box(coordX    , coordY    , coordX + 9, coordY + 1, color);
        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX    , coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '6':

        video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY    , coordX + 9, coordY + 1, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '7':

        video_box(coordX    , coordY    , coordX + 9, coordY + 1, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, color);

        break;

    case '8':

        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX    , coordY + 6, coordX + 1, coordY + 7, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case '9':

        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, color);
        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX    , coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

        break;

    case 'a':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 9, color);

        break;

    case 'b':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);

        break;

    case 'c':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'd':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

        break;

    case 'e':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'f':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);

        break;

    case 'g':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 4, coordY + 4, coordX + 9, coordY + 5, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'h':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

        break;

    case 'i':

        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case 'j':

        video_box(coordX, coordY + 4, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);

        break;

    case 'k':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'l':

        video_box(coordX, coordY, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 'm':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

        break;

    case 'n':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 9, color);

        break;

    case 'o':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, color);

        break;

    case 'p':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);

        break;

    case 'q':

        video_box(coordX, coordY + 2, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);
        video_box(coordX + 2, coordY + 8, coordX + 5, coordY + 9, color);

        break;

    case 'r':

        video_box(coordX, coordY, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY, coordX + 7, coordY + 1, color);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, color);
        video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    case 's':

        video_box(coordX + 2, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX, coordY + 2, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, color);
        video_box(coordX, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case 't':

        video_box(coordX, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 9, color);

        break;

    case 'u':

        video_box(coordX, coordY, coordX + 1, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);

        break;

    case 'v':

        video_box(coordX, coordY, coordX + 1, coordY + 5, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
        video_box(coordX + 4, coordY + 8, coordX + 5, coordY + 9, color);
        video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 5, color);

        break;

    case 'w':

        video_box(coordX, coordY, coordX + 1, coordY + 7, color);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 7, color);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, color);

        break;

    case 'x':

        video_box(coordX, coordY, coordX + 1, coordY + 3, color);
        video_box(coordX, coordY + 6, coordX + 1, coordY + 9, color);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 3, color);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 9, color);

        break;

    case 'y':

        video_box(coordX, coordY, coordX + 1, coordY + 3, color);
        video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, color);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 9, color);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, color);
        video_box(coordX + 8, coordY, coordX + 9, coordY + 3, color);

        break;

    case 'z':

        video_box(coordX, coordY, coordX + 9, coordY + 1, color);
        video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, color);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, color);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, color);
        video_box(coordX, coordY + 8, coordX + 9, coordY + 9, color);

        break;

    default:

        break;
    }
}

/**
 * Exibição de um foguete.
 * 
 * @param coordX   Coordenada X do canto superior esquerdo da região onde o foguete será exibido.
 * @param coordY   Coordenada Y do canto superior esquerdo da região onde o foguete será exibido.
 * @param color1   Primeira cor do foguete. 
 * @param color2   Segunda cor do foguete. 
 * @return void
 */
void rocket (int coordX, int coordY, int color1, int color2) {

    video_box ( coordX + 10, coordY + 1, coordX + 12, coordY + 1, color1);
    video_box ( coordX + 9, coordY + 2, coordX + 13, coordY + 2, color1);
    video_box ( coordX + 8, coordY + 3, coordX + 14, coordY + 4, color1);

    video_box ( coordX + 7, coordY + 5, coordX + 15, coordY + 6, color2);
    video_box ( coordX + 7, coordY + 7, coordX + 15, coordY + 8, color1);
    video_box ( coordX + 7, coordY + 9, coordX + 15, coordY + 10, color2);
    video_box ( coordX + 7, coordY + 11, coordX + 15, coordY + 12, color1);
    video_box ( coordX + 7, coordY + 13, coordX + 15, coordY + 14, color2);
    video_box ( coordX + 7, coordY + 15, coordX + 15, coordY + 16, color1);
    video_box ( coordX + 7, coordY + 17, coordX + 15, coordY + 18, color2);

    video_box ( coordX + 8, coordY + 19, coordX + 9, coordY + 20, COLOR_ORANGE);
    video_box ( coordX + 10, coordY + 19, coordX + 12, coordY + 20, COLOR_YELLOW);
    video_box ( coordX + 13, coordY + 19, coordX + 14, coordY + 20, COLOR_ORANGE);

    video_box ( coordX + 9, coordY + 21, coordX + 13, coordY + 22, COLOR_ORANGE);
    video_box ( coordX + 11, coordY + 21, coordX + 11, coordY + 21, COLOR_YELLOW);
    video_box ( coordX + 10, coordY + 23, coordX + 12, coordY + 23, COLOR_ORANGE);
    video_box ( coordX + 11, coordY + 14, coordX + 11, coordY + 14, COLOR_ORANGE);
    
}

/**
 * Exibição de uma explosão.
 * 
 * @param coordX   Coordenada X do canto superior esquerdo da região onde a explosão será exibida.
 * @param coordY   Coordenada Y do canto superior esquerdo da região onde a explosão será exibida.
 * @param color1   Primeira cor da explosão. 
 * @param color2   Segunda cor da explosão. 
 * @return void
 */
void explosion (int coordX, int coordY, int color1, int color2) {

    video_line ( coordX + 12, coordY + 10, coordX + 37, coordY + 34, color1);
    video_line ( coordX + 49, coordY + 2, coordX + 49, coordY + 34, color1);
    video_line ( coordX + 87, coordY + 10, coordX + 63, coordY + 35, color1);

    video_line ( coordX + 63, coordY + 50, coordX + 89, coordY + 50, color1);
    video_line ( coordX + 64, coordY + 64, coordX + 91, coordY + 91, color1);
    video_line ( coordX + 49, coordY + 65, coordX + 49, coordY + 98, color1);

    video_line ( coordX + 37, coordY + 64, coordX + 14, coordY + 89, color1);
    video_line ( coordX + 37, coordY + 49, coordX + 13, coordY + 49, color1);


    video_line ( coordX + 33, coordY + 10, coordX + 33, coordY + 15, color2);
    video_line ( coordX + 33, coordY + 16, coordX + 33, coordY + 20, color1);

    video_line ( coordX + 65, coordY + 9, coordX + 65, coordY + 14, color2);
    video_line ( coordX + 65, coordY + 15, coordX + 65, coordY + 19, color1);

    video_line ( coordX + 81, coordY + 31, coordX + 87, coordY + 31, color2);
    video_line ( coordX + 77, coordY + 31, coordX + 80, coordY + 31, color1);

    video_line ( coordX + 97, coordY + 50, coordX + 100, coordY + 50, color2);
    video_line ( coordX + 93, coordY + 50, coordX + 96, coordY + 50, color1);

    video_line ( coordX + 81, coordY + 66, coordX + 87, coordY + 66, color2);
    video_line ( coordX + 77, coordY + 66, coordX + 80, coordY + 66, color1);

    video_line ( coordX + 65, coordY + 84, coordX + 65, coordY + 90, color2);
    video_line ( coordX + 65, coordY + 78, coordX + 65, coordY + 83, color1);

    video_line ( coordX + 37, coordY + 83, coordX + 37, coordY + 90, color2);
    video_line ( coordX + 37, coordY + 77, coordX + 37, coordY + 82, color1);

    video_line ( coordX + 11, coordY + 65, coordX + 18, coordY + 65, color2);
    video_line ( coordX + 19, coordY + 65, coordX + 24, coordY + 65, color1);

    video_line ( coordX + 1, coordY + 49, coordX + 4, coordY + 49, color2);
    video_line ( coordX + 5, coordY + 49, coordX + 8, coordY + 49, color1);

    video_line ( coordX + 12, coordY + 32, coordX + 18, coordY + 32, color2);
    video_line ( coordX + 19, coordY + 32, coordX + 24, coordY + 32, color1);

}
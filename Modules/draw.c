#include "prototype.h"

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

        video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
        video_box(coordX + 2, coordY + 1, coordX + 3, coordY + 8, cor);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, cor);
        video_box(coordX + 6, coordY + 3, coordX + 7, coordY + 6, cor);
        video_box(coordX + 8, coordY + 4, coordX + 9, coordY + 5, cor);

    case '<':

        video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, cor);
        video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 3, cor);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, cor);
        video_box(coordX + 6, coordY    , coordX + 7, coordY + 1, cor);
        video_box(coordX + 6, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '>':

        video_box(coordX + 2, coordY    , coordX + 3, coordY + 1, cor);
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

        video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
        video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, cor);

        break;

    case '1':


        video_box(coordX + 2, coordY    , coordX + 3, coordY + 1, cor);
        video_box(coordX + 4, coordY    , coordX + 5, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '2':

        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, cor);
        video_box(coordX    , coordY + 8, coordX + 9, coordY + 9, cor);

        break;

    case '3':

        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 4, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX    , coordY + 6, coordX + 1, coordY + 7, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '4':

        video_box(coordX    , coordY    , coordX + 1, coordY + 5, cor);
        video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, cor);
        video_box(coordX + 8, coordY    , coordX + 9, coordY + 9, cor);

        break;

    case '5':

        video_box(coordX    , coordY    , coordX + 9, coordY + 1, cor);
        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX    , coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '6':

        video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, cor);
        video_box(coordX + 2, coordY    , coordX + 9, coordY + 1, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '7':

        video_box(coordX    , coordY    , coordX + 9, coordY + 1, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 3, coordY + 9, cor);

        break;

    case '8':

        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX    , coordY + 6, coordX + 1, coordY + 7, cor);
        video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
        video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

        break;

    case '9':

        video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
        video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, cor);
        video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
        video_box(coordX    , coordY + 8, coordX + 7, coordY + 9, cor);
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
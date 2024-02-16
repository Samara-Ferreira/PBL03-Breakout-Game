#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <intelfpgaup/accel.h>
#include <intelfpgaup/video.h>
#include "alfa.h"

/**
 * Descrição da função
 * 
 * Esta função desenha um caractere em escala 10x10 no dispositivo de vídeo VGA.
 * 
 * 
 * @param coordX A coordenada X do canto superior esquerdo da caixa.
 * @param coordY A coordenada Y do canto superior esquerdo da caixa.
 * @param caracter O caractere a ser desenhado.
 * @param cor A cor do pixel.
 * @return void
 */
void alfanumerico (int coordX, int coordY, char caracter, short cor){
	switch (caracter)
	{

	case'^':

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
		video_box(coordX + 8, coordY    , coordX + 7, coordY + 9, cor);

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

		video_box( coordX + 2, coordY    , coordX + 3, coordY + 1, cor);
		video_box( coordX + 4, coordY    , coordX + 5, coordY + 7, cor);
		video_box( coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);

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

break;
	case 'a':
		video_box(coordX    , coordY + 2, coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
		video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, cor);
		video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 9, cor);

		break;
	
	case 'b':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
		video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
		video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
		video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 3, cor);
		video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
		
		break;

	case 'c':
		video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, cor);
		video_box(coordX + 2, coordY    , coordX + 9, coordY + 1, cor);
		video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, cor);
		
		break;

	case 'd':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
		video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
		video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, cor);
		
		break;

	case 'e':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY    , coordX + 9, coordY + 1, cor);
		video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
		video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, cor);
		
		break;

		case 'f':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY    , coordX + 9, coordY + 1, cor);
		video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
		
		break;

	case 'g':
		video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, cor);
		video_box(coordX + 2, coordY    , coordX + 9, coordY + 1, cor);
		video_box(coordX + 4, coordY + 4, coordX + 9, coordY + 5, cor);
		video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
		video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, cor);
		
		break;

	case 'h':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 9, cor);
		
		break;

	case 'i':
		video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
		video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, cor);
		video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
		
		break;

	case 'j':
		video_box(coordX    , coordY + 4, coordX + 1, coordY + 7, cor);
		video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 7, cor);
		
		break;

	case 'k':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY + 4, coordX + 5, coordY + 5, cor);
		video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, cor);
		video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 1, cor);
		video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, cor);
		
		break;

	case 'l':
		video_box(coordX    , coordY    , coordX + 1, coordY + 7, cor);
		video_box(coordX + 2, coordY + 8, coordX + 9, coordY + 9, cor);
		
		break;
	
	case 'm':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, cor);
		video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, cor);
		video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 9, cor);
		
		break;
	
	case 'n':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY + 2, coordX + 3, coordY + 3, cor);
		video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, cor);
		video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 9, cor);
		
		break;

	case 'o':
		video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, cor);
		video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
		video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
		video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 7, cor);
		
		break;
	
	case 'p':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
		video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, cor);
		video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, cor);
		
		break;
	
	case 'q':
		video_box(coordX    , coordY + 2, coordX + 1, coordY + 7, cor);
		video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
		video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, cor);
		video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, cor);
		video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, cor);
		video_box(coordX + 2, coordY + 8, coordX + 5, coordY + 9, cor);
		
		break;

	case 'r':
		video_box(coordX    , coordY    , coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY    , coordX + 7, coordY + 1, cor);
		video_box(coordX + 2, coordY + 6, coordX + 7, coordY + 7, cor);
		video_box(coordX + 8, coordY + 2, coordX + 9, coordY + 5, cor);
		video_box(coordX + 8, coordY + 8, coordX + 9, coordY + 9, cor);
		
		break;
	
	case 's':
		video_box(coordX + 2, coordY    , coordX + 9, coordY + 1, cor);
		video_box(coordX    , coordY + 2, coordX + 1, coordY + 3, cor);
		video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
		video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 7, cor);
		video_box(coordX    , coordY + 8, coordX + 7, coordY + 9, cor);
		
		break;
	
	case 't':
		video_box(coordX    , coordY    , coordX + 9, coordY + 1, cor);
		video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 9, cor);
		
		break;

	case 'u':
		video_box(coordX    , coordY    , coordX + 1, coordY + 7, cor);
		video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 7, cor);
		
		break;
	
	case 'v':
		video_box(coordX    , coordY    , coordX + 1, coordY + 5, cor);
		video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, cor);
		video_box(coordX + 4, coordY + 8, coordX + 5, coordY + 9, cor);
		video_box(coordX + 6, coordY + 6, coordX + 7, coordY + 7, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 5, cor);
		
		break;

	case 'w':
		video_box(coordX    , coordY    , coordX + 1, coordY + 7, cor);
		video_box(coordX + 4, coordY + 2, coordX + 5, coordY + 7, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 7, cor);
		video_box(coordX + 2, coordY + 8, coordX + 7, coordY + 9, cor);
		
		break;

	case 'x':
		video_box(coordX    , coordY    , coordX + 1, coordY + 3, cor);
		video_box(coordX    , coordY + 6, coordX + 1, coordY + 9, cor);
		video_box(coordX + 2, coordY + 4, coordX + 7, coordY + 5, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 3, cor);
		video_box(coordX + 8, coordY + 6, coordX + 9, coordY + 9, cor);
		
		break;
	
	case 'y':
		video_box(coordX    , coordY    , coordX + 1, coordY + 3, cor);
		video_box(coordX + 2, coordY + 4, coordX + 3, coordY + 5, cor);
		video_box(coordX + 4, coordY + 6, coordX + 5, coordY + 9, cor);
		video_box(coordX + 6, coordY + 4, coordX + 7, coordY + 5, cor);
		video_box(coordX + 8, coordY    , coordX + 9, coordY + 3, cor);
		
		break;
	
	case 'z':
		video_box(coordX    , coordY    , coordX + 9, coordY + 1, cor);
		video_box(coordX + 6, coordY + 2, coordX + 7, coordY + 3, cor);
		video_box(coordX + 4, coordY + 4, coordX + 5, coordY + 5, cor);
		video_box(coordX + 2, coordY + 6, coordX + 3, coordY + 7, cor);
		video_box(coordX    , coordY + 8, coordX + 9, coordY + 9, cor);
		
		break;

	default:
		break;
	}

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
	void frase(int coordX, int coordY, char *lista, int tamanhoLista, short cor) {
    for (int i = 0; i < tamanhoLista; ++i) {
        int X = coordX + i * 13;
        alfanumerico(X, coordY, lista[i], cor);
    	}
	}
}


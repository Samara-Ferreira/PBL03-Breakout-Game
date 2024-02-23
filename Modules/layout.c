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


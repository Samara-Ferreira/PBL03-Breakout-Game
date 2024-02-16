#include "alfa.h"

void create_menu() {
    char start[] = {'s', 't', 'a', 'r', 't'};
    char game[] = {'g', 'a', 'm', 'e'};
    char tutorial[] = {'t', 'u', 't', 'o', 'r', "i", 'a', 'l'};
    char exit[] = {'e', 'x', 'i', 't'};


    frase(125, 125, start   , sizeof(start)    / sizeof(char), 0xdd82);
    frase(192, 125, game    , sizeof(game)     / sizeof(char), 0xdd82);
    frase(110, 145, tutorial, sizeof(tutorial) / sizeof(char), 0xdd82);
    frase(136, 165, exit    , sizeof(exit)     / sizeof(char), 0xdd82);

}

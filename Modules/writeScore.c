void write_score (int score) {

char number_str[3];

sprintf(number_str, "%d", score);

int len = strlen(number_str);
int i;

for (i = 0; i < len; i++) {
    alfanumerico( 78 + (13 * i), 0, number_str[i], 0xFFE0);
    }
}


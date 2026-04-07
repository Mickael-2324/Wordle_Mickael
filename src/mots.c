#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mots.h"

int load_words(char words[MAX_WORDS][WORD_LEN]) {
    FILE *f = fopen("ressource/bdd_wordle.txt", "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return 0;
    }

    int count = 0;
    char buffer[100];
    while (fscanf(f, "%99s", buffer) == 1) {
        if (strlen(buffer) == 5) {
            int valid = 1;
            for (int i = 0; i < 5; i++) {
                if (!isalpha(buffer[i])) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                strcpy(words[count], buffer);
                count++;
            }
        }
    }
    fclose(f);
    return count;
}

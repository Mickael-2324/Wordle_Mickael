#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mots.h"
#include "jeu.h"

void play_game(char words[MAX_WORDS][WORD_LEN], int count) {
    srand(time(NULL));
    char secret[WORD_LEN];
    strcpy(secret, words[rand() % count]);

    int essais = 0;
    char guess[WORD_LEN];

    while (essais < 6) {
        printf("Proposez un mot de 5 lettres: ");
        scanf("%5s", guess);

        // Vérifier validité
        int valid = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(guess, words[i]) == 0) {
                valid = 1;
                break;
            }
        }
        if (!valid) {
            printf("Mot invalide, réessayez.\n");
            continue;
        }

        // Vérifier victoire
        if (strcmp(guess, secret) == 0) {
            printf("Bravo, vous avez gagné!\n");
            return;
        }

        // Comparaison lettre par lettre
        for (int i = 0; i < 5; i++) {
            if (guess[i] == secret[i]) printf("V");
            else if (strchr(secret, guess[i])) printf("O");
            else printf("X");
        }
        printf("\n");

        essais++;
    }

    printf("Perdu! Le mot était %s\n", secret);
}

int main() {
    char words[MAX_WORDS][WORD_LEN];
    int count = load_words(words);

    char choix;
    do {
        play_game(words, count);
        printf("Voulez-vous rejouer ? (o/n): ");
        scanf(" %c", &choix);
    } while (choix == 'o' || choix == 'O');

    printf("Merci d'avoir joué!\n");
    return 0;
}

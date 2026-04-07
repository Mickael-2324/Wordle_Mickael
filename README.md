# Wordle_Mickael
# Wordle en C

## Présentation
Ce projet est une implémentation du jeu **Wordle** en langage C.  
Le joueur doit deviner un mot de 5 lettres en maximum 6 essais, avec des indications :
- `V` : lettre bien placée
- `O` : lettre présente mais mal placée
- `X` : lettre absente

## Structure du projet
- `src/mots.c` : lecture et filtrage des mots depuis `ressource/bdd_wordle.txt`
- `include/mots.h` : prototypes pour la gestion des mots
- `src/jeu.c` : logique du jeu Wordle (partie principale)
- `include/jeu.h` : prototypes pour la logique du jeu
- `ressource/bdd_wordle.txt` : base de données (brute) des mots
- `bin/wordle` : exécutable compilé

## Compilation
Depuis la racine du projet :
```bash
gcc -o bin/wordle src/*.c -Iinclude


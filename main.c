#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int nombremystere();
int suitemystere();
int mastermind();

int bestscoreSuitemystere, bestscoreNombremystere, bestscoreMastermind,
    bestscoreTotal = 0; // Variables meilleur score

int main() {
  int choix;

  bestscoreTotal =
      bestscoreSuitemystere + bestscoreNombremystere + bestscoreMastermind;

  // Menu pricipal
  printf("╔═══════════════════════════════════════════════╗\n");
  printf("║                 JEU SAE 1.01                  ║\n");
  printf("╚═══════════════════════════════════════════════╝\n");
  printf("╔═══════════════════════════════════════════════╗\n");
  printf("║    Jeu                         Meilleur Score ║\n");
  printf("║═══════════════════════════════════════════════║\n");
  printf("║    1. La Suite Mystere               %4d     ║\n",
         bestscoreSuitemystere);
  printf("║    2. Nombre Mystere                 %4d     ║\n",
         bestscoreNombremystere);
  printf("║    3. Mastermind                     %4d     ║\n",
         bestscoreMastermind);
  printf("║    4. Quitter                                 ║\n");
  printf("║═══════════════════════════════════════════════║\n");
  printf("║    Score Total:                      %4d     ║\n", bestscoreTotal);
  printf("║═══════════════════════════════════════════════║\n");
  printf("     Votre choix : ");
  scanf("%d", &choix); // Recuperation du choix du jeu par l'utilisateur

  switch (choix) {
  case 1:
    suitemystere();
    break;
  case 2:
    nombremystere();
    break;
  case 3:
    mastermind();
    break;
  case 4:
    return 0;
    break;
  default: // Cas ou l'utilisateur rentre un nombre hors de la liste
    printf("\033[1;31m╔═══════════════════════════════════════════════╗\n");
    printf("║               Choix invalide.                 ║\n");
    printf("║    Veuillez choisir un nombre entre 1 et 4.   ║\n");
    printf("╚═══════════════════════════════════════════════╝\n\033[0m");

    return main();
    break;
  }

  return 0;
}

// jeu 1. Suite mystere
int suitemystere() {
  int scoreSuitemystere = 31;
  int a, b, c;
  int reponse;
  srand(time(0));
  a = rand() % 10 + 1;
  b = rand() % 10 + 1;
  c = rand() % 10 + 1;

  // suite
  int Un0 = c;
  int Un1 = a * Un0 + b;
  int Un2 = a * Un1 + b;
  printf("╔═══════════════════════════════════════════════╗\n");
  printf("║       Le but du jeu est de retrouver le       ║\n");
  printf("║    4e terme de la suite a partir des trois    ║\n");
  printf("║    permier termes suivant : %3d; %3d; %3d.    ║\n", Un0, Un1, Un2);
  printf("║═══════════════════════════════════════════════║\n");
  printf("  Proposez la valeur du 4e terme : ");
  scanf("%d", &reponse);

  clock_t debut, fin;
  debut = clock();
  fin = clock();

  double temps = (double)(fin - debut) / CLOCKS_PER_SEC;

  if (reponse == a * Un2 + b && temps <= 30) {
    scoreSuitemystere = scoreSuitemystere - temps;
    printf("╔═══════════════════════════════════════════════╗\n");
    printf("║          Bravo, votre score est : %d          ║ \n",
           scoreSuitemystere);
    printf("╚═══════════════════════════════════════════════╝\n");
    // On regarde si le score est meilleur que le meilleur score
    if (bestscoreSuitemystere == 0) {
      printf("\033[1;32m╔═══════════════════════════════════════════════╗\n");
      printf("║                MEILLEUR SCORE                 ║\n");
      printf("╚═══════════════════════════════════════════════╝\033[0m\n");
      bestscoreSuitemystere =
          scoreSuitemystere; // On met le meilleur score a jour

    } else if (scoreSuitemystere < bestscoreSuitemystere) {
      printf("\033[1;32m╔═══════════════════════════════════════════════╗\n");
      printf("║                MEILLEUR SCORE                 ║\n");
      printf("╚═══════════════════════════════════════════════╝\033[0m\n");
      bestscoreSuitemystere = scoreSuitemystere;
    }
  } else { // Cas ou l'utilisateur n'a pas trouvé la bonne reponse
    printf("╔═══════════════════════════════════════════════╗\n");
    printf("║          Désolé, votre score est : %d         ║ \n",
           scoreSuitemystere);
    printf("╚═══════════════════════════════════════════════╝\n");

    if (bestscoreSuitemystere == 0) {
      printf("\033[1;32m╔═══════════════════════════════════════════════╗\n");
      printf("║                MEILLEUR SCORE                 ║\n");
      printf("╚═══════════════════════════════════════════════╝\033[0m\n");
      bestscoreSuitemystere = scoreSuitemystere;
    } else if (scoreSuitemystere < bestscoreSuitemystere) {
      printf("\033[1;32m╔═══════════════════════════════════════════════╗\n");
      printf("║                MEILLEUR SCORE                 ║\n");
      printf("╚═══════════════════════════════════════════════╝\033[0m\n");
      bestscoreSuitemystere = scoreSuitemystere;
    }
  }

  return main();
}

// jeu 2. Nombre mystere
int nombremystere() {
  int nombreMystere, proposition, essais = 0;
  int valeurMaximale = 1000;
  int scoreNombremystere = 11;
  int maxEssaisNombremystere = 10;
  time_t t;

  srand(
      (unsigned)time(&t)); // Initialisation du générateur de nombres aléatoires

  nombreMystere = rand() % valeurMaximale + 1; // génération du nombre mystere

  printf("╔═══════════════════════════════════════════════╗\n");
  printf("║  Le principe du jeu est de trouver un nombre  ║\n");
  printf("║  caché dans un intervalle compris entre 1 et  ║\n");
  printf("║           une valeur maximale 1000.           ║\n");
  printf("╚═══════════════════════════════════════════════╝\n");

  // boucle de jeu
  while (essais < maxEssaisNombremystere) {
    printf("Entrez votre proposition : ");
    scanf("%d", &proposition);

    essais++;             // incrémentation du nombre d'essais
    scoreNombremystere--; // décrémentation du scoreNombremystere

    if (proposition == nombreMystere) {
      printf("\033[1;32mFélicitations ! Vous avez trouvé le nombre mystère "
             "!\n\033[0m"); // \033[1;32m : code pour changer la couleur du
                            // texte en vert, \033[0m : code pour revenir à la
                            // couleur par défaut
      printf("Score : %d\n", scoreNombremystere);
      if (scoreNombremystere >
          bestscoreNombremystere) { // Si le score est meilleur que le meilleur

        printf("\033[1;32m╔═══════════════════════════════════════════════╗\n");
        printf("║                MEILLEUR SCORE                 ║\n");
        printf("╚═══════════════════════════════════════════════╝\033[0m\n");

        bestscoreNombremystere = scoreNombremystere;
      }
      return main();
    } else if (proposition < nombreMystere) { // Si la proposition est
                                              // inférieure au nombre mystere
      printf("Le nombre mystère est plus grand\n");
    } else { // Si la proposition est supérieure au nombre mystere
      printf("Le nombre mystère est plus petit\n");
    }

    printf("Essai %d / %d\n", essais, maxEssaisNombremystere);
  }

  printf("\033[1;31mGame over ! Le nombre mystére était: %d\n\033[0m",
         nombreMystere);
  printf("Score : %d\n", scoreNombremystere);

  if (scoreNombremystere > bestscoreNombremystere) {
    printf("\033[1;32m╔═══════════════════════════════════════════════╗\n");
    printf("║                MEILLEUR SCORE                 ║\n");
    printf("╚═══════════════════════════════════════════════╝\033[0m\n");
    bestscoreNombremystere = scoreNombremystere;
  }

  return main();
}

// jeu 3. Mastermind
int mastermind() {
  char combinaison[5];        // tableau pour stocker la combinaison
  char combinaisonSecrete[5]; // tableau pour stocker la combinaison secrete
  int bienPlaces, malPlaces, essais = 0;
  int scoreMastermind = 0;
  int maxEssaisMastermind = 10;

  int i, j;
  time_t debut, fin; // Variables permetant le calcule du temps de jeu
  srand((unsigned)time(NULL));

  // Génère la combinaison secrete
  for (i = 0; i < 4; i++) {
    char voyelle; 
    while (1) { // boucle infini
      voyelle = 'A' + rand() % 26;
      if (voyelle == 'A' || voyelle == 'E' || voyelle == 'I' ||
          voyelle == 'O' || voyelle == 'U') {
        int exists = 0;
        for (j = 0; j < i; j++) {
          if (combinaisonSecrete[j] == voyelle) {
            exists = 1;
            break;
          }
        }
        if (!exists) {
          break;
        }
      }
    }
    combinaisonSecrete[i] = voyelle;
  }
  combinaisonSecrete[4] = '\0';

  printf("╔═══════════════════════════════════════════════╗\n");
  printf("║      Trouvez la combinaison secrète de 4      ║\n");
  printf("║        voyelles majuscules distinctes         ║\n");
  printf("╚═══════════════════════════════════════════════╝\n");

  // printf("Combinaison secrete : %s\n", combinaisonSecrete);

  debut = time(NULL); // Début du temps de jeu

  while (essais < maxEssaisMastermind) {
    bienPlaces = 0;
    malPlaces = 0;
    essais++;

    printf("Essai %d / %d\n", essais, maxEssaisMastermind);
    printf("Saisissez une combinaison de 4 voyelles majuscules (Ex: "
           "A,E,I,O,U,Y): ");
    scanf("%s", combinaison);

    // Vérification de la validité de la combinaison
    if (strlen(combinaison) != 4) {
      printf("\033[1;31mLa combinaison doit comporter 4 voyelles !\n\033[0m");
      continue;
    }

    int isDistinct = 1;
    for (i = 0; i < 4; i++) {
      for (j = i + 1; j < 4; j++) {
        if (combinaison[i] == combinaison[j]) {
          isDistinct = 0;
          break;
        }
      }
    }
    if (!isDistinct) {
      printf("\033[1;31mLa combinaison doit comporter des voyelles distinctes "
             "!\n\033[0m");
      continue;
    }

    // Vérification des placements
    for (i = 0; i < 4; i++) { // Parcours de la combinaison
      if (combinaison[i] == combinaisonSecrete[i]) { // Voyelle bien placée
        bienPlaces++;
      } else {
        for (j = 0; j < 4; j++) {
          if (combinaison[i] == combinaisonSecrete[j]) { // Voyelle mal placée
            malPlaces++;
            break;
          }
        }
      }
    }

    scoreMastermind += 10;

    printf("Résultat : %d bien placé(s), %d mal placé(s)\n", bienPlaces,
           malPlaces);
    if (bienPlaces == 4) {
      fin = time(NULL); // Fin du temps de jeu
      scoreMastermind += (int)(fin - debut) * 10;
      printf(
          "\033[1;32mFélicitations ! Vous avez trouvé la combinaison secrète ! "
          "!\n\033[0m");
      printf("Score final : %d\n", scoreMastermind);
      if (bestscoreMastermind == 0) {
        bestscoreMastermind = scoreMastermind;
      } else if (scoreMastermind < bestscoreMastermind) {
        printf("\033[1;32m╔═══════════════════════════════════════════════╗\n");
        printf("║                MEILLEUR SCORE                 ║\n");
        printf("╚═══════════════════════════════════════════════╝\033[0m\n");
        bestscoreMastermind = scoreMastermind;
      }
      return main();
    }
  }

  printf("\033[1;31mGame Over ! Plus d'essais, la combinaison secrète était : "
         "%s\n\033[0m",
         combinaisonSecrete);
  fin = time(NULL); // Fin du temps de jeu
  scoreMastermind += (int)(fin - debut) * 10;
  printf("Score final : %d\n", scoreMastermind);

  if (bestscoreMastermind == 0) {
    bestscoreMastermind = scoreMastermind;
  } else if (scoreMastermind <
             bestscoreMastermind) { // Vérification du meilleur score
    printf("\033[1;32m╔═══════════════════════════════════════════════╗\n");
    printf("║                MEILLEUR SCORE                 ║\n");
    printf("╚═══════════════════════════════════════════════╝\033[0m\n");
    bestscoreMastermind = scoreMastermind; // Mettre à jour le meilleur score
  }

  return main();
}

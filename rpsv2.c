#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char userInput[16];
char compRps[16];
int fini;
int randNum;

char *compinput(randNum) {
  // checks to see which num randNum picked, then copies respective string to
  // compRps and setting finalDisplay
  if (!randNum) {
    strcpy(compRps, "rock\n");
    fini = 2;
  } else if (randNum == 1) {
    strcpy(compRps, "paper\n");
    fini = 0;
  } else {
    strcpy(compRps, "scissors\n");
    fini = 1;
  }
  return compRps;
}

int main() {
  int plScore = 0, compScore = 0;

  static char *finalDisplay[] = {"rock\n", "paper\n", "scissors\n", "\0"};

  printf("Rock paper scissors!\n");
  int valid = 0;

  // bo 5, if not bo5, dont exit loop lol
  while (plScore < 3 && compScore < 3) {
    // random number
    srand(time(0));
    randNum = rand() % 3;

    while (!valid) {
      printf("rock, paper, or scissors: ");
      fgets(userInput, 16, stdin); // user input
      // checking if userinput is valid
      for (int i = 0; i < 4; ++i) {
        if (!strcmp(userInput, finalDisplay[i])) {
          valid = 1;
          break;
        } else if (i == 3)
          printf("Not a valid answer\n");
      }
    }

    // checks userinput against randNum, == is win
    if (!strcmp(userInput, compinput(randNum))) {
      printf("You win! Your opponent picked %s", finalDisplay[fini]);
      ++plScore;
      // != does another check against finalDisplay, == is tie
    } else if (!strcmp(userInput, finalDisplay[fini]))
      printf("You tied! Your opponent picked %s", finalDisplay[fini]);
    else {
      printf("You lost! Your opponent picked %s", finalDisplay[fini]);
      compScore++;
    }
    printf("Score is %d:%d\n", plScore, compScore);
    valid = !valid; // resets valid check
  }
  if (plScore > 2)
    printf("You Win!");
  else
    printf("You Lost!");
}

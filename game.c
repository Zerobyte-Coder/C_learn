#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void black()
{
    printf("\033[0;37m");
}
void printBanner() {
    black();
    printf(
        "8888888888P                  .d8888b.          888               888                  .d8888b.                888                  \n"
        "      d88P                  d88P  Y88b         888               888                 d88P  Y88b               888                  \n"
        "     d88P                   888    888         888               888                 888    888               888                  \n"
        "    d88P    .d88b.  888d888 888    888         88888b.  888  888 888888 .d88b.       888         .d88b.   .d88888  .d88b.  888d888 \n"
        "   d88P    d8P  Y8b 888P\"   888    888         888 \"88b 888  888 888   d8P  Y8b      888        d88\"\"88b d88\" 888 d8P  Y8b 888P\"   \n"
        "  d88P     88888888 888     888    888         888  888 888  888 888   88888888      888    888 888  888 888  888 88888888 888      \n"
        " d88P      Y8b.     888     Y88b  d88P         888 d88P Y88b 888 Y88b. Y8b.          Y88b  d88P Y88..88P Y88b 888 Y8b.     888      \n"
        "d8888888888 \"Y8888  888      \"Y8888P\" 88888888 88888P\"   \"Y88888  \"Y888 \"Y8888        \"Y8888P\"   \"Y88P\"   \"Y88888  \"Y8888  888      \n"
        "                                                             888                                                                     \n"
        "                                                        Y8b d88P                                                                     \n"
        "                                                         \"Y88P\"                                                                      \n"
    );
}

int main(void) {
    int counter = 0;
    int usr_win = 0;
    double avr_win;
    printBanner();

    
    do {
        char choice, level, control, computer;

        counter++;
        avr_win = ((double)usr_win / counter) * 100; // Corrected the formula

        printf("Please input stone, paper, scissor, quit (s, p, z, q): ");
        scanf(" %c", &choice);

        if (choice != 's' && choice != 'p' && choice != 'z' && choice != 'q') {
            printf("Error, please input (s, p, z, q) only!!\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if(choice == 'q') {

            
            printf("############################################################################################\n");
            printf("You have played %d times.\n", counter);
            printf("You have won %d out of %d games.\n", usr_win, counter);
            printf("Average win rate percent is %.2lf%% \n", avr_win); // Corrected the format specifier
            printf("Thank you for playing. See you soon!\n");
            break;
        }

        printf("Please input Computer level (hard = h, medium = m): ");
        scanf(" %c", &level);

        while (level != 'h' && level != 'm') {
            printf("Oppos, input invalid; please input 'h' and 'm' only!!\n");
            while (getchar() != '\n'); // Clear input buffer
            printf("Please input Computer level (hard = h, medium = m): ");
            scanf(" %c", &level);
        }

        control = tolower(level);
        int n;
        srand(time(NULL));
        n = rand() % 10; 

        if (n < 4) {
            computer = 's';//stone
        } else if (n >= 4 && n < 7) {
            computer = 'z';//scissor
        } else {
            computer = 'p';//paper
        }

        switch (control) {
            case 'm':
                if (computer == 's' && choice == 'z') {
                    printf("Computer chose Scissor, User chose Paper. Computer Win!!\n");
                } else if (computer == 's' && choice == 'p') {
                    printf("Computer chose Scissor, User chose Paper. User Win!!\n");
                    usr_win++;
                } else if (computer == 's' && choice == 's') {
                    printf("Computer chose Scissor, User chose Scissor. Draw!!\n");
                } else if (computer == 'p' && choice == 's') {
                    printf("Computer chose Paper, User chose Scissor. User Win!!\n");
                    usr_win++;
                } else if (computer == 'p' && choice == 'p') {
                    printf("Computer chose Paper, User chose Paper. Draw!!\n");
                } else if (computer == 'p' && choice == 'z') {
                    printf("Computer chose Paper, User chose Stone. Computer Win!!\n");
                } else if (computer == 'z' && choice == 's') {
                    printf("Computer chose Stone, User chose Scissor. Computer Win!!\n");
                } else if (computer == 'z' && choice == 'p') {
                    printf("Computer chose Stone, User chose Paper. User Win!!\n");
                    usr_win++;
                } else if (computer == 'z' && choice == 'z') {
                    printf("Computer chose Stone, User chose Stone. Draw!!\n");
                } else {
                    printf("Invalid input!!\n");
                }
                break;
            case 'h':
                if (choice == 's') {
                    computer = 'p';
                    printf("Computer chose Paper, User chose Scissor. Computer Win !! \n");
                } else if (choice == 'p') {
                    computer = 'z';
                    printf("Computer chose Stone, User chose Paper. Computer Win !! \n");
                } else if (choice == 'z') {
                    computer = 's';
                    printf("Computer chose Scissor, User chose Stone. Computer Win !! \n");
                } else {
                    printf("Invalid input!!\n");
                }
                break;
        }
    } while (1);

    return 0;
}

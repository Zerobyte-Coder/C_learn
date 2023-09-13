#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int num_sub;
    char sub_names[10][20];
    int sub_scores[10];
    char choice;

    do
    {
        printf("How many subjects do you have? (1-10): ");
        if (scanf("%d", &num_sub) != 1)
        {
            printf("Oops, only integer values are allowed.\n");
            while (getchar() != '\n');
            continue;
        }
        else if (num_sub <= 0 || num_sub > 10)
        {
            printf("Invalid input. Please enter a number between 1 and 10.\n");
            continue; 
        }

        for (int i = 0; i < num_sub; i++)
        {
            printf("Enter the name of subject %d:  ", i + 1);

            // Read input as a string
            char input[20];
            scanf("%19s", input);

            // Check if the input is a valid string (contains only letters)
            int valid = 1;
            for (int j = 0; input[j] != '\0'; j++)
            {
                if (!isalpha(input[j]))
                {
                    valid = 0;
                    break;
                }
            }

            if (!valid)
            {
                printf("Invalid input. Please enter a valid subject name.\n");
                i--; 
                continue;
            }

            strcpy(sub_names[i], input);

            printf("Enter the score for subject %d: ", i + 1);
            scanf("%d", &sub_scores[i]);
        }

        int total = 0;
        for (int i = 0; i < num_sub; i++)
        {
            total += sub_scores[i];
        }

        printf("\nSubject Details:\n");
        for (int i = 0; i < num_sub; i++)
        {
            printf("Subject %d: %s, Score: %d\n", i + 1, sub_names[i], sub_scores[i]);
        }

        printf("The total score for %d subjects is : %d \n", num_sub, total);
        int avg_mark = total / num_sub; 
        printf("The average mark for %d subjects is : %d %\n", num_sub, avg_mark);

        printf("Do you want to perform for your friends? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');


    printf("Goodbye!!\n");

    return 0;
}

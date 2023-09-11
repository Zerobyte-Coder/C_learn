#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    enum shop { APPLE = 100, BANANA = 110, ORANGE = 111, MILK = 100, TOMATO = 110, PINEAPPLE = 60, WATERMELON = 100, TISSUE = 50, Eggs = 25, Bread = 20,Coffee = 30,Tea = 20,Soda = 10, WATER = 5,Chocolate = 40,Ice_cream = 55};
    
    
    printf("What would you like to order: ");
    char want[100];
    scanf("%99[A-Za-z ]", want); 
    
    int price = 0;
    int price1 = 0;

    for(int a = 0; want[a];a++){
        want[a] = tolower(want[a]);
    }
    char firstChar = want[0];

    switch (firstChar) 
    {
        case 'a':
            price = APPLE;
            printf("The price of %s is: %d\n", want, price);
            break;
        case 'b':
            price = BANANA;
            printf("The price of %s is: %d\n", want, price);
            break;
        case 't':
            if(tolower(want[1]) == 'o')
            {
                price = TOMATO;
                printf("The price of %s is: %d\n", want, price);
                break;
            }else if(tolower(want[1]) == 'i')
            {
                price = TISSUE;
                printf("The price of %s is: %d\n", want, price);
                break;

            }
        case 'w':
             if(strcmp(want,"watermelon") == 0)
             {
                price = WATERMELON;
                printf("The price of %s is: %d\n", want, price);
                break;

             }else if(strcmp(want,"water") == 0){
                price = WATER;
                printf("The price of %s is: %d\n", want, price);
                break;
             }



        default:
            printf("Item not found.\n");
            break;
    }

    return 0;
}

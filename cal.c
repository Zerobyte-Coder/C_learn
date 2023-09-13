#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char Choose;
    do
    {
        double fir_num,sec_num,result;
        char operator;
        printf("Enter the first number : ");
        if(scanf("%lf",&fir_num) != 1)
        {
            printf("Oppos, Incorrect data type, Try again !!\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Choose an operator ( + , - , / , *) : ");
        scanf(" %c", &operator);

        printf("Enter the second number : ");
        if(scanf("%lf",&sec_num) != 1)
        {
            printf("Oppos, Incorrect data type, Try again !!\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch(operator)
        {
            case '+':
                result = fir_num + sec_num;
                printf("The result is : %.4lf\n",result);
                break;
            case '-':
                result = fir_num - sec_num;
                printf("The result is : %.4lf\n",result);
                break;
            case '/':
                if(sec_num == 0)
                {
                    printf("Error Division by zero is not allowed\n");
                    
                }else
                {
                    result = fir_num / sec_num;
                    printf("The result is : %.4lf\n",result);
                    break;
                } 
            case '*':
                result = fir_num * sec_num;
                printf("The result is : %.4lf\n",result);
                break;
            default:
                printf("Oppos Only allow (+ , - , / , * )\n");
                break;
        }
        printf("Would you like to calculate more ? answer y/n ");
        scanf(" %c",&Choose);

    }while(Choose == 'Y' || Choose == 'y');
    printf("GOOD BYE !!");
    return 0;
}
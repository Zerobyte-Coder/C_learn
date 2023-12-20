#include <stdio.h>

int int_filter(double * input)
{
    if(scanf("%lf",input) != 1)
    {
        printf("Error: Only double-precision numbers are allowed!\n");
        while(getchar() != '\n');
        return 0;
    }
    return 1;
}
int main()
{
    double input1,input2,result;
    char operator;
    
    printf("input first num : ");
    if(!int_filter(&input1)){
        printf("Invaild input,Quitting...");
        return 1;
    }
    printf("input second num : ");
    if(!int_filter(&input2)){
        printf("Invaild input,Quitting...");
        return 1;
    }
    printf("enter operator [+,-,*,/] : ");
 
    while (getchar() != '\n');  // Clear input buffer
    scanf("%c", &operator);

    switch (operator) {
        case '+':
            result = input1 + input2;
            break;
        case '-':
            result = input1 - input2;
            break;
        case '*':
            result = input1 * input2;
            break;
        case '/':
            if (input2 == 0) {
                printf("Error: Division by zero is not allowed\n");
                return 1;
            } else {
                result = input1 / input2;
                break;
            }
        default:
            printf("Error: Only allow (+ , - , / , * )\n");
            return 1;
    }

    printf("The result is : %.4lf\n", result);

    return 0;
}    

    


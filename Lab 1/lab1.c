#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
        int count = 0;
        int denom;
        int quot;
        int dividend;
        srand ((int) time(NULL));
        int i;
        for (i = 0; i < 10; i++)
        {
                denom = rand()%12+1;
                quot = rand()%13;
                dividend = denom * quot;
                printf("The denominator is %d and the dividend is %d\n", denom, dividend);
                int input;
                printf("Quotient?\n");
                scanf("%d", &input);


                if (input == quot)
                {
                        printf("Correct!\n");
                        count++;
                }
                else
                {
                        printf("Wrong! The correct answer is: %d\n", quot);
                }
        }
        printf("Your score was: %d out of 10\n", count);
        return 0;
}

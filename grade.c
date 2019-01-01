#include <stdint.h>
intMain(){
char letter;
double dwant;
double dhave;
double dweight;

printf("Enter the letter grade that you want: ");
scanf(" %c", &letter);

printf("Enter the percent that you need to get to get that grade: ");
scanf("%lf", &dwant);

printf("Enter the percent that you currently have: ");
scanf("%d", &dhave);

printf("Enter the weight of the final: ");
scanf("%d", &dweight);

printf("You need at least a %d on the final to get a %c in the class",(((100 * dwant) - ((100 - dweight) * dhave)) / dweight), letter);

return 0;
}

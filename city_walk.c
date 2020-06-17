#include<stdio.h>
#include<string.h>
#include <stdbool.h>

int dir_point (char d) 
{
    switch (d) {
        case 'n':
          return 1;
        case 'e':
           return 2;
        case 'w':
          return -2;
        case 's':
           return -1;
        default:
           return 0; 
    }

}
int isValidWalk(const char *walk) {
     int i = 0, sum = 0;
     if (strlen(walk) != 10) {
        return 0;
     }
     while (i != strlen(walk)) {
         sum += dir_point(walk[i]); 
         i++;
     }
     return sum;
}
int main() {
     const char *str = "sewnnsewns";
     printf("<%d>..\n", isValidWalk(str));

}

#include<stdio.h>
#include<stdlib.h>

/*
Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000
*/

int values[7] = {1000, 500, 100, 50, 10, 5, 1};
char symbols[7]  = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

char * roman (unsigned int a) {
    int index = 0, j = 0;
    char *str = malloc(64);
    while (a > 0) {
        if ((a > values[index]) && (a / values[index])) {
            str[j++] = symbols[index];
            a = a - values[index];
        }
        index++;
    }
    return str;
}
int main() {
    printf("roman : <%s>..\n", roman(2000));
}

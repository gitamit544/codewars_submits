#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *alphabet_position(char *str) {
    int i = 0, a, nbytes = 0;
    char *newstr = malloc(2 * strlen(str));
    memset(newstr, 0, 2*strlen(str));
    while (i != strlen(str)) {
        if (!isalpha(str[i])) {
            i++;
            continue;
        }
        a = toupper(str[i]) - 64;
        nbytes += sprintf(newstr + nbytes ,"%d " , a);
        i++;
    }
    newstr[nbytes - 1] = 0;
    return newstr;

}

int main() {
    printf("<%s>..\n", alphabet_position("The sunset sets at twelve o' clock."));
}

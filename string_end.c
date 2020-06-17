#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int solution(const char *string, const char *ending)
{
    int len1 = strlen(string);
    int len2 = strlen(ending);
    if (!len2) {
       return true;
    }
    if (!len1 || (len2 > len1)) {
       return false;
    }
     
    int diff = len1-len2; 

    char *start;
    int i = diff, j = 0;
    while (j != len2) {
         if (string[i] != ending[j]) 
             return false;
         i++;
         j++;
    }

    return true;
}


int main() {
    printf("<%d>..\n", solution("abc", "bc"));
    printf("<%d>..\n", solution("abc", "d"));
    printf("<%d>..\n", solution("abc", ""));
    printf("<%d>..\n", solution("", "b"));
    printf("<%d>..\n", solution("baabababa", "ba"));
    printf("<%d>..\n", solution("abcabc", "bc"));
}

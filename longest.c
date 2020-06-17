#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* longest(char* s1, char* s2) {
     int symbols[26] = {0};
     int i, len, len2, nbytes = 0;
     
     len = strlen(s1);
     len2 = strlen(s2);  
     
     i = 0;
     while (i != len) {
        symbols[s1[i] - 'a'] = 1;
        i++;
     }// your code

     i = 0;
     while (i != len2) {
        symbols[s2[i] - 'a'] = 1;
        i++;
     }// your code

     char *buffer = malloc(26);
     memset(buffer, 0, 26);
     i = 0;
     while (i != 26) {
         if (symbols[i])
             nbytes += snprintf(buffer + nbytes, 26-nbytes, "%c", 'a'+ i);
         i++;
     }

     return buffer;
}

int main() {
printf("buffer : <%s>..\n", longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"));
printf("buffer : <%s>..\n", longest("aretheyhere", "yestheyarehere"));
printf("buffer : <%s>..\n", longest("loopingisfunbutdangerous", "lessdangerousthancoding"));
printf("buffer : <%s>..\n", longest("lordsofthefallen", "gamekult"));
printf("buffer : <%s>..\n", longest("codewars", "codewars"));

}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int
panagram(char *str) {
   int symbols[26] = {0};
   int i = 0;
   
   while(i != strlen(str)) {
      if (!isalpha(str[i])) {
         i++;
         continue;
      }
      symbols[toupper(str[i]) - 65] = 1;
      i++; 
   }
   for (i = 0; i<26; i++) {
      if (symbols[i] != 1) {
         return 0;
      }
   }
   
   return 1;
}

int
isogram(char *str) {
   int symbols[26] = {0};
   int i = 0, upper;
   while(i != strlen(str)) {
      if (!isalpha(str[i])) {
         i++;
         continue;
      }
      upper = toupper(str[i]) - 65;
      if (symbols[upper] == 1) {
         return 0;
      }
      symbols[toupper(str[i]) - 65] = 1;
      i++; 
   }

   return 1;
}


int main(){
   int i = 0;
   printf ("panagram : <%d>..\n", panagram("Th quick brown fox jumps ovr th lazy dog"));

   printf ("isogram : <%d>..\n", isogram("abcdef"));
   printf ("isogram : <%d>..\n", isogram("moOse"));
   printf ("isogram : <%d>..\n", isogram("Dermatoglyphics"));

   return;
}

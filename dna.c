#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char 
complement (char a) {
    switch (a) {
       case 'A':
          return 'T';
       case 'T':
          return 'A';
       case 'C':
          return 'G';
       case 'G':
          return 'C';
       default:
           return 0;
     }


}

char * dna_strand(const char *str) {
   int i = 0;
   char *newstr = malloc(strlen(str) + 1);
   while (i != strlen(str)) {
      newstr[i] = complement(str[i]);
      i++; 
   }
   newstr[strlen(newstr)] = '\0';
   return newstr;
}
int main() {

printf("<%s>...\n", dna_strand("AAAA"));  /* return "CATA"  */
printf("<%s>...\n", dna_strand(""));  /* return "CATA"  */


}

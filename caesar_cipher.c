#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *rot(char *src, int k) {
     int len, i = 0;
     len = strlen(src);
     char *cipher = malloc(len + 1);
     memset(cipher, 0, len);
     while (i != len) {
        if (!isalpha(src[i])) {
           cipher[i] = src[i];
           k++;
        } else if (src[i] >= 'a' && src[i] <= 'z') {
           cipher[i] = 'a' + (char) ((src[i] - 'a' + (k++)) % 26);
        } else {
           cipher[i] = 'A' + (char) ((src[i] - 'A' + (k++)) % 26);
        }
        i++;
     }
     cipher[i] = '\0';
     return cipher;
}

char *multiple[5];

char *reverse_rot(char *src, int k) {
     int len, i = 0;
     char diff;
     len = strlen(src);
     char *cipher = malloc(len + 1);
     memset(cipher, 0, len);
     while (i != len) {
        if (!isalpha(src[i])) {
           cipher[i] = src[i];
           k++;
        } else if (src[i] >= 'a' && src[i] <= 'z') {
           diff = (src[i] - (k++) % 26);
           if (diff < 'a') {
               cipher[i] = diff + 'z' - 'a' + 1;
               printf("<%c %c>...\n", diff, cipher[i]); 
           } else {
               cipher[i] = diff;
           }       
 
        } else {
           diff = (src[i] - (k++) % 26);
           if (diff < 'A') {
               cipher[i] = diff + 'Z' - 'A' + 1;
           } else {
               cipher[i] = diff;
           } 
        }
        i++;
     }
     cipher[i] = '\0';
     printf("demove : <%s>...\n", cipher);
     return cipher;
}
void multiple_arrays(char *temp, int i) {
    
     printf("orig src : <%s>...\n", temp); 
     char *src = rot(temp, i);
     
     printf("src : <%s>...\n", src); 
     int len = strlen(src);
      
     int div, mod, part_len;

     div  = len / 5;
     mod  = len % 5;
  
     if (mod == 0) {
         part_len = div;
     } else {
         part_len = div+1;
     }

     int index = 0;
     i = 0;
     while (i != 5) {
          if (len > part_len) {
              multiple[i] = malloc(part_len+1);
              strncpy(multiple[i], src+index, part_len);
              printf("<%s>...\n", multiple[i]);
              index += part_len;
          } else {
              multiple[i] = malloc(len+1);
              printf("<%s>...\n", multiple[i]);
              strncpy(multiple[i], src+index, len);
          }
          i++;
     }

}

char *demoving(int shift) {
     int i, curr_len, index = 0;
     char *buffer;
     
     buffer = malloc(5000);
     for (i = 0; i<5; i++) {
         printf("array  : <%s>..\n", multiple[i]);
         curr_len = strlen(multiple[i]);
         sprintf(buffer+(index), "%s", reverse_rot(multiple[i], shift+index));
         index += curr_len;            
         printf("<curr_buffer : %s>...\n", buffer);
     }

     buffer[index] = '\0';
     return buffer;
}


int main() {
    multiple_arrays("-uoxIirmoveNreefckgieaoiEcooqo", 2);
    int i = 0;
    for (i = 0 ; i<5 ; i++) {
        printf("part : <%s>...\n", multiple[i]);
    }

    printf("full buffer : <%s>..\n", demoving(2));
}

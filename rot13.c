#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *rot13(const char *src) {
     int len, i = 0;
     len = strlen(src);
     char *cipher = malloc(len + 1);
     memset(cipher, 0, len);
     while (i != len) {
        if (!isalpha(src[i])) {
           cipher[i] = src[i];
        } else if (src[i] >= 'a' && src[i] <= 'z') {
           cipher[i] = 'a' + (char) ((src[i] - 'a' + 13) % 26);
        } else {
           cipher[i] = 'A' + (char) ((src[i] - 'A' + 13) % 26);
        }
        i++;
     }
     cipher[i] = '\0';
     return cipher;
}

int main() {
	rot13("abcd");
    rot13("test123");

}

#include<stdio.h>
int main() {
int num = 144;
int last_digit, new_num, second_last_digit, new_num2, rearranged_num;

last_digit = num%10;
new_num = num/10;
second_last_digit = new_num%10;
new_num2 = new_num/10;

rearranged_num = new_num2 * 10 + last_digit;
rearranged_num = rearranged_num * 10 + second_last_digit;


printf("<%d>...\n", rearranged_num);


}

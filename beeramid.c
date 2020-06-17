#include<stdio.h>
#include<stdlib.h>

int beeramid(double bonus, double price) {
    double total_cans = bonus/price;
    int level = 1;
    while(total_cans > 0) {
         total_cans -= (level * level);
         level++;
    }
    if (total_cans == 0)
    return level-1;
    else 
    return level-2;
}

int main() {
    printf("<%d>...\n", beeramid(10,3));
    printf("<%d>...\n", beeramid(10,2));
    printf("<%d>...\n", beeramid(1500,2));
    printf("<%d>...\n", beeramid(5000,3));

}

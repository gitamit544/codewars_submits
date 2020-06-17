#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t days_represented(size_t n, size_t trips[n][2]) {
    size_t i= 0, total_days = 0, start_date, end_date, diff;
    bool days[365] = {false};
    for (i = 0 ; i < n; i++) {
         start_date = trips[i][0];
         end_date = trips[i][1];
         while(start_date <= end_date) {
              if (days[start_date] == false) {
                  total_days++;
                  days[start_date] = true;
              }
              start_date++;
         }
         printf("total  : <%ld>..\n", total_days); 
    }
   printf("total  : <%ld>..\n", total_days); 
   return total_days;
}

int main() {
size_t trips[13][2] = {{176, 203},
{59, 60},
{142, 183},
{51, 64},
{244, 257},
{239, 285},
{129,154},
{20, 29},
{110, 112},
{240, 287},
{51, 100},
{207, 208},
{170, 230}};
   
size_t n = 13, days = 24;

   days_represented(n, trips);
}

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>




bool king_is_in_check(const char chessboard[8][8])
{
  int king_i = 0, king_j =0, i, j, diff_i, diff_j, temp_i, temp_j;
  
  for (i = 0 ; i < 8; i++) {
      for (j = 0; j < 8; j++) {
          if (chessboard[i][j] == 'K') {
              king_i = i;
              king_j = j;
              goto found_king;
          }
      }  
  }
  found_king:
  
  for (i = 0 ; i < 8; i++) {
      for (j = 0; j < 8; j++) {
          if (chessboard[i][j] == 'R') {
              if (i == king_i) {
                  temp_j = j;
                  if (temp_j > king_j) {
                      while(temp_j != king_j) {
                         temp_j--;
                         if (chessboard[i][temp_j] != ' ') {
                            break;
                         }
                      }
                  } else {
                      while(temp_j != king_j) {
                         temp_j++;
                         if (chessboard[i][temp_j] != ' ') {
                            break;
                         }
                      }   
                  }
                  if (temp_j == king_j) {
                      return true;
                  }
              } 
              if (j == king_j) {
                  temp_i = i;
                  if (temp_i > king_i) {
                      while(temp_i != king_i) {
                         temp_i--;
                         if (chessboard[temp_i][j] != ' ') {
                            break;
                         }
                      }
                  } else {
                      while(temp_i != king_i) {
                         temp_i++;
                         if (chessboard[temp_i][j] != ' ') {
                            break;
                         }
                      }   
                  }
                  if (temp_i == king_i) {
                      return true;
                  }
              }
          } else if (chessboard[i][j] == 'P') {
              if (king_i == i+1 && (king_j == j+1 || king_j == j-1)) {
                  return true;
              }
          } else if ((chessboard[i][j] == 'B') && (abs(king_i - i) == abs(king_j - j))) {
              if (king_i > i && king_j > j) {
                  temp_i = i+1;
                  temp_j = j+1;
                  while (temp_i != king_i) {
                      if (chessboard[temp_i][temp_j] != ' ') {
                          break;
                      }
                      temp_i++;
                      temp_j++;
                  }
              } else if (king_i < i && king_j < j) {
                  temp_i = i-1;
                  temp_j = j-1;
                  while (temp_i != king_i) {
                      if (chessboard[temp_i][temp_j] != ' ') {
                          break;
                      }
                      temp_i--;
                      temp_j--;
                  }
              } else if (king_i < i && king_j > j) {
                  temp_i = i-1;
                  temp_j = j+1;
                  while (temp_i != king_i) {
                      if (chessboard[temp_i][temp_j] != ' ') {
                          break;
                      }
                      temp_i--;
                      temp_j++;
                  }
              } else {
                  temp_i = i+1;
                  temp_j = j-1;
                  while (temp_i != king_i) {
                      if (chessboard[temp_i][temp_j] != ' ') {
                          break;
                      }
                      temp_i++;
                      temp_j--;
                  }            
              }
              printf("<%d %d>..\n\n", temp_i, king_i);
              if (temp_i == king_i) {
                      return true;
              } 
          } else if (chessboard[i][j] == 'N') {
              diff_i = abs(king_i - i);
              diff_j = abs(king_j -j);
              if ((diff_i == 2 && diff_j == 1) || (diff_j ==2 && diff_i ==1)) {
                  return true;
              }
          } else if (chessboard[i][j] == 'Q') {
              if (i == king_i) {
                  temp_j = j;
                  if (temp_j > king_j) {
                      while(temp_j != king_j) {
                         temp_j--;
                         if (chessboard[i][temp_j] != ' ') {
                            break;
                         }
                      }
                  } else {
                      while(temp_j != king_j) {
                         temp_j++;
                         if (chessboard[i][temp_j] != ' ') {
                            break;
                         }
                      }   
                  }
                  if (temp_j == king_j) {
                      return true;
                  }
              } 
              
               if (j == king_j) {
                  temp_i = i;
                  if (temp_i > king_i) {
                      while(temp_i != king_i) {
                         temp_i--;
                         if (chessboard[temp_i][j] != ' ') {
                            break;
                         }
                      }
                  } else {
                      while(temp_i != king_i) {
                         temp_i++;
                         if (chessboard[temp_i][j] != ' ') {
                            break;
                         }
                      }   
                  }
                  if (temp_i == king_i) {
                      return true;
                  }
              }
              
              if (abs(king_i - i) == abs(king_j - j)) {
              if (king_i > i && king_j > j) {
                  temp_i = i+1;
                  temp_j = j+1;
                  while (temp_i != king_i) {
                      if (chessboard[temp_i][temp_j] != ' ') {
                          break;
                      }
                      temp_i++;
                      temp_j++;
                  }
              } else if (king_i < i && king_j < j) {
                  temp_i = i-1;
                  temp_j = j-1;
                  while (temp_i != king_i) {
                      if (chessboard[temp_i][temp_j] != ' ') {
                          break;
                      }
                      temp_i--;
                      temp_j--;
                  }
              } else if (king_i < i && king_j > j) {
                  temp_i = i-1;
                  temp_j = j+1;
                  while (temp_i != king_i) {
                      if (chessboard[temp_i][temp_j] != ' ') {
                          break;
                      }
                      temp_i--;
                      temp_j++;
                  }
              } else {
                  temp_i = i+1;
                  temp_j = j-1;
                  while (temp_i != king_i) {
                      if (chessboard[temp_i][temp_j] != ' ') {
                          break;
                      }
                      temp_i++;
                      temp_j--;
                  }            
              }
              if (temp_i == king_i) {
                      return true;
              } 
          }
          }
  
      }
  }
  
  return false;  // good luck :)
}


int main() {
    const char chessboard[8][8]= { 
		"        ",
		"        ",
		"        ",
		"        ",
		"  K  P Q",
		"        ",
		"B RN    ",
		"        "};

    printf("<%d>", king_is_in_check(chessboard));
}

// implement combined transpopsition method using c or python or verilog considering blocksize as 5

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
char plaintext[30] = "enemyattackstonight";
int key = 31452;
int blocksize = 5;

// make the plaintext length divisible by blocksize
int len_plaintext = strlen(plaintext);
int padding = blocksize - len_plaintext % blocksize;

for (int i = len_plaintext; i < len_plaintext + padding; i++) {
  plaintext[i] = 'z';
}
plaintext[len_plaintext + padding] = '\0';

int size = len_plaintext + padding;

char ciphermatrix [size/blocksize][blocksize];
for (int i = 0; i < blocksize; i++) {
  for (int j = 0; j < size/blocksize; j++) {
    ciphermatrix[i][j] = plaintext[(j * blocksize) + i];
  }
  ciphermatrix[i][blocksize - 1] = '\0';
}

char ciphertext[size + 1];
int index = 0;
int divisor = 10000; // Assuming key is a 5-digit number

while (divisor > 0) {
  int row = key / divisor - 1; // Adjust key to 0-based index
  
  for (int i = 0; i < size / blocksize; i++)
    ciphertext[index++] = ciphermatrix[row][i];
  
  key %= divisor;
  divisor /= 10;
}
ciphertext[size] = '\0';

printf("Cipher Text: %s\n", ciphertext);
return 0;
}
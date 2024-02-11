// implement combined transpopsition method using c or python or verilog considering blocksize as 5
#include<stdio.h>
#include<string.h>

void encrypt_transposition(char*, int, int, char*);

void encrypt_transposition(char* plaintext, int key, int blocksize, char* ciphertext) {
// make the plaintext length divisible by blocksize
int len_plaintext = strlen(plaintext);
int padding = blocksize - len_plaintext % blocksize;

for (int i = len_plaintext; i < len_plaintext + padding; i++)
  plaintext[i] = 'z';
plaintext[len_plaintext + padding] = '\0';

int size = len_plaintext + padding;

char ciphermatrix [size/blocksize][blocksize];
for (int i = 0; i < blocksize; i++) {
  for (int j = 0; j < size/blocksize; j++) {
    ciphermatrix[i][j] = plaintext[(j * blocksize) + i];
  }
  ciphermatrix[i][blocksize - 1] = '\0';
}

int index = 0;
int divisor = 1;

for(int i = 1; i < blocksize; i++)
  divisor *= 10;

while (divisor > 0) {
  int row = key / divisor - 1; // Adjust key to 0-based index
  
  for (int i = 0; i < size / blocksize; i++)
    ciphertext[index++] = ciphermatrix[row][i];
  
  key %= divisor;
  divisor /= 10;
}
ciphertext[size] = '\0';
}

int main() {
char plaintext[30] = "enemyattackstonight";
int key = 31452;
int blocksize = 5;
char ciphertext[30];
encrypt_transposition(plaintext, key, blocksize, ciphertext);
printf("%s\n", ciphertext);
return 0;
}
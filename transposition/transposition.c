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

char ciphermatrix [blocksize + 1][size/blocksize];
for (int i = 0; i < size; i = i + blocksize) {
  for (int j = 0; j < blocksize; j++)
    ciphermatrix[i][j] = plaintext[i+j];
  ciphermatrix[i][j]
  printf("%s\t",ciphermatrix[i]);
}
// # build a matrix to hold the plaintext
// cip = [plaintext[i:i+blocksize] for i in range(0,len(plaintext),blocksize)]

// print(cip)

// ciphertext = ''
// # rearrange the rows and transpose
// for i in str(key):
//   for j in range(len(plaintext)//blocksize):
//     ciphertext += (cip[j][int(i) - 1])

// print(ciphertext)
return 0;
}

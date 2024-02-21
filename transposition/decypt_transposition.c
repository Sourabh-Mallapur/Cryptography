#include<stdio.h>
#include<string.h>
#include<math.h>

void decrypt_transposition(char* ciphertext, int key, int blocksize, char* decrypted_plaintext) {
    int dekey = 0;
    int temp = 1;
    int digit, divisor_copy;
    int divisor = 1;
    int temp_key = key;

    for(int i = 1; i < blocksize; i++)
        divisor *= 10;
    
    divisor_copy = divisor;

    for(int i = 1; i < blocksize + 1; i++) {
        digit = key / divisor;
        for(int j = digit; j < blocksize; j++)
            temp *= 10;
        dekey += (i * temp);
        temp = 1;
        key %= divisor;
        divisor /= 10;
    }

    // printf("%d", dekey);

    int size = strlen(ciphertext);
    
    char ciphermatrix [size/blocksize][blocksize];
    for (int i = 0; i < blocksize; i++) {
        for (int j = 0; j < size/blocksize; j++) {
            ciphermatrix[i][j] = ciphertext[(i * (size/blocksize)) + j];
        } 
        ciphermatrix[i][blocksize - 1] = '\0';
    }

    int index = 0;
    divisor = divisor_copy;
    key = temp_key;
    while (divisor > 0) {
        int row = key / divisor - 1; // Adjust key to 0-based index
        for (int i = 0; i < size / blocksize; i++) {
            decrypted_plaintext[index++] = ciphermatrix[row][i];
            // printf("%c",ciphermatrix[row][i] );
        }
        key %= divisor;
        divisor /= 10;
    }
    decrypted_plaintext[size] = '\0';

}

int main() {
    char ciphertext[30] = "ettheakimaotycnzntsg";
    int key = 31452;
    int blocksize = 5;
    char decrypted_plaintext[30];
    decrypt_transposition(ciphertext, key, blocksize, decrypted_plaintext);
    printf("%s",decrypted_plaintext);
    return 0;
}
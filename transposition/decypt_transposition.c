#include<stdio.h>
#include<string.h>
#include<math.h>

void decrypt_transposition(char* ciphertext, int key, int blocksize, char* decrypted_plaintext) {
    int dekey = 0;
    int temp = 1;
    int temp2 = 0;

    for(int i = 1; i < blocksize; i++)
        temp *= 10;
    
    for(int i = 0; i < blocksize; i++){
        temp2 += ((i + 1) * (temp));
        temp /= 10; }
    
    
    char decryptmatrix[rows][cols];

    // Decrypt using the key
    index = 0;
    for (int i = 0; i < cols; i++) {
        int col = dekey % 10;
        for (int j = 0; j < rows; j++) {
            decrypted_plaintext[index++] = matrix[j][col - 1];
        }
        key /= 10;
    }
    decrypted_plaintext[length] = '\0'; // Null-terminate the string
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
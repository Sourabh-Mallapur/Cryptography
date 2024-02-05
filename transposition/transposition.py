# implement combined transpopsition method using python considering blocksize as 5
def encrypt_transposition(plaintext, key, blocksize):
  # make the plaintext length divisible by blocksize
  padding = blocksize - len(plaintext) % blocksize
  plaintext += (padding*'z')

  # build a matrix to hold the plaintext
  cip = [plaintext[i:i+blocksize] for i in range(0,len(plaintext),blocksize)]

  ciphertext = ''
  # rearrange the rows and transpose
  for i in key:
    for j in range(len(plaintext)//blocksize):
      ciphertext += (cip[j][int(i) - 1])

  return(ciphertext)



def decrypt_transposition(ciphertext, key, blocksize):
  # Decryption
  temp = ''.join([str(i) for i in range(1,blocksize + 1,1)])
  dekey = ['0'] * blocksize
  
  for i in key:
    dekey[int(i) - 1] = temp[key.index(i)]

  decrypted_plaintext = ''
  cip = [ciphertext[i::blocksize-1] for i in range(0,len(ciphertext)//blocksize)]

  for j in range(len(ciphertext)//blocksize):
    for i in dekey:
      decrypted_plaintext += (cip[j][int(i) - 1])

  return decrypted_plaintext
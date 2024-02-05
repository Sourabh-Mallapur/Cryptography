from transposition.transposition import *
from gcd.gcd import *

plaintext = "enemyattackstonight"
key = "31452"
blocksize = 5

cipher = encrypt_transposition(plaintext,key,blocksize)
print(cipher)
result = decrypt_transposition(cipher,key,blocksize)
print(result)

g,s,t = gcd(348,846)

print("gcd = ",g)
print("s = ",s)
print("t = ",t)
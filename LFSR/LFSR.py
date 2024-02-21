# Code to implement a Linear Feedback Shift Register

seed = int(input("Initial state of the register (in binary): "))
cell = len(str(seed))
n = int(input("Enter no of coeff: "))
coeff = []
print("Bits to XOR (start at 1 from the left)")
for i in range(n): 
    coeff.append(int(input()))

def lfsr(seed, cell, coeff):
    bits = ''
    lfsrList = [0] + [int(i) for i in str(seed)] + [0]
    iterations = 1
    while(iterations < (2 ** cell)):
        lfsrList = [0] + lfsrList[:-1]
        temp = lfsrList[coeff[0]]
        for i in coeff[1:]:
            temp = temp ^ lfsrList[i]
        lfsrList[0] = temp
        bits += str(lfsrList[-1])
        iterations += 1
    return bits

bits = lfsr(seed, cell, coeff)
print(bits)
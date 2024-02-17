# Code to implement a Linear Feedback Shift Register

seed = 10001
cell = 5
coeff = [1,5]

def lfsr(seed, cell, coeff):
    lfsrList = [0] + [int(i) for i in str(seed)] + [0]
    iterations, temp = 1, 0
    # print('0', lfsrList)
    while(iterations < (2 ** cell)):
        lfsrList = [0] + lfsrList[:-1]
        for i in coeff:
            temp = temp ^ lfsrList[i]
        lfsrList[0] = temp
        # print(iterations, lfsrList)
        print(lfsrList[-1], end='')
        iterations += 1
        
lfsr(seed, cell, coeff)
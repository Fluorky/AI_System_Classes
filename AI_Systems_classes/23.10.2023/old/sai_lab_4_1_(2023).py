# -*- coding: utf-8 -*-
"""SAI_lab_4_1 (2023).ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1-bRHnCfp1TjvgO2vcxM5VyT7O_46qdE4

ZAD 1
"""

#WIELKOSC_TAB = 7
#WIELKOSC_TAB2 = 2

def y_(sum):
    if sum > 0:
        return 1
    else:
        return -1

def suma(xi, xi2, w1, w2, x0, Theta):
    sum = xi * w1 + xi2 * w2 + Theta * x0
    return sum

x1 = [2, 2, 0, -2, -2, 0, 4]
x2 = [1, 2, 6, 10, 0, 0, -20]
d = [1, 1, 1, -1, -1, -1, -1]
w = [0, 0, 0]
#Theta = 0
iterator = 0
x0 = 1

while True:
    z = True
    for i in range(7):
        y = y_(suma(x1[i], x2[i], w[0], w[1], x0, w[2]))
        if y != d[i]:
            w[0] = w[0] + d[i] * x1[i]
            w[1] = w[1] + d[i] * x2[i]
            w[2] = w[2] + d[i] * x0
            z = False
        print(y , d[i])
    iterator += 1
    print()
    print(iterator)
    print()
    if z:
        break

print("w 0 =", w[2] , "w 1 =", w[0] , "w 2 =", w[1])

"""ZAD 2

"""
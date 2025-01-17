# -*- coding: utf-8 -*-
"""SAI_lab_4_1 (2023).ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1-bRHnCfp1TjvgO2vcxM5VyT7O_46qdE4

ZAD 1
"""

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

import math

WIELKOSC_TAB = 2
WIELKOSC_TAB2 = 13
beta = 0.5
ni = 0.35

def f(suma):
    y = (1 - math.exp(-1*suma*beta))/(1+math.exp(-1*suma*beta))
    return y

jeden = [-1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, 1]
cztery = [1, -1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1]
d = [-1, 1]
w = [0]*WIELKOSC_TAB2
w2 = [0]*WIELKOSC_TAB2
iterator = 0
d1=-1
d4=1

while True:
    E = 0
    for i in range(12):
        s = jeden[i] * w[i] + w[12] * jeden[12]
        y = f(s)
        w[i] += d[0] * jeden[i] * ni
        w[12] += d[0] * jeden[12] * ni
        print(y,d[0])
    print(y,"<-- y koncowy dla 1",d[0],"<--d oczekiwana")
    E += 0.5*(d1 - y)*(d1 - y)
    for i in range(12):
        s2 = cztery[i] * w2[i] + w2[12] * cztery[12]
        y2 = f(s2)
        w2[i] += d[1] * cztery[i] * ni
        w2[12] += d[1] * cztery[12] * ni
        print(y2,d[1])
    print(y2,"<-- y koncowy dla 4",d[1],"<--d oczekiwana")
    iterator += 1
    print("\n",iterator,"<-- przebieg funkcji\n")
    E += 0.5*(d4 - y2)*(d4 - y2)
    print(E,"blad sumaryczny")
    if E <= 0.0000000005:
        break

"""Zadanie 3"""

import math

WIELKOSC_TAB = 2
WIELKOSC_TAB2 = 13
beta = 1
ni = 1

def f(suma):
    return 1 / (1 + math.exp(-beta * suma))

def fprim(x):
    y = beta * f(x)* (1-f(x))
    return y

w = [0]*13
jeden = [1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1]
cztery = [1,1,1,1,1,1,1,-1,-1,1,-1,-1,1]
cosjeden = [1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1]
cosdwa = [1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1]
d = [-1, 1]
iterator = 0
d4 = 0
d2 = 0
d1 = 1
s2=0

while True:
    E=0
    s=0
    for i in range(13):
      s = s + jeden[i] * w[i]
    y = f(s)
    for i in range(13):
        w[i] = w[i] + ni * beta*(1-y)*y*(d1-y)*jeden[i]
    E = 0.5*(d1 - y)*(d1 - y)
    s=0
    for i in range(13):
     s = s + cztery[i] * w[i]
    y2 = f(s)
    for i in range(13):
        w[i] = w[i] + ni * beta*(1-y2)*y2*(d4-y2)*cztery[i]
    iterator += 1
    E += 0.5*(d4 - y2)*(d4 - y2)
    print(E,"blad sumaryczny")
    if E <= 0.0005:
        break

s = sum([jeden[i] * w[i] for i in range(13)])
print("wyjscie dla 1",f(s))
s = sum([cztery[i] * w[i] for i in range(13)])
print("wyjscie dla  4",f(s))
s = sum([cosjeden[i] * w[i] for i in range(13)])
print("wyjscie dla niby 1",f(s))
s = sum([cosdwa[i] * w[i] for i in range(13)])
print("wyjscie dla niby 4",f(s))
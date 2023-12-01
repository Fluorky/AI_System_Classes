# -*- coding: utf-8 -*-
"""SAI_lab_4_1 (2023).ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1-bRHnCfp1TjvgO2vcxM5VyT7O_46qdE4
"""

# Commented out IPython magic to ensure Python compatibility.
# %matplotlib inline
import matplotlib
import matplotlib.pyplot as plt
import pandas as pd

"""ZAD 1


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
#x2 = [1, 2, -16, 10, 0, 0, -20]
d = [1, 1, 1, -1, -1, -1, -1]
w = [0, 0, 0]
Theta = 1 # x0 bias
iterator = 0

plt.scatter(x1,x2)
while True:
    z = True
    for i in range(7):
        y = y_(suma(x1[i], x2[i], w[0], w[1], Theta, w[2]))
        if y != d[i]:
            w[0] = w[0] + d[i] * x1[i]
            w[1] = w[1] + d[i] * x2[i]
            w[2] = w[2] + d[i] * Theta
            z = False
        print(y , d[i])
    if w[1] != 0:
      a= -w[0]/w[1]
      b = -w[2]/w[1]
    print(f"a: {a}, b: {b}")
    fx = [a*x+b for x in x1]
    _ = plt.plot(x1[:3],x2[:3],'o', color = "green")
    _ = plt.plot(x1[3:],x2[3:],'o')
    _ = plt.plot(x1,fx,'r')
    iterator += 1
    print()
    print(iterator)
    print()
    if z:
        break

print("w 0 =", w[2] , "w 1 =", w[0] , "w 2 =", w[1])

#a= -w[0]/w[1]
#b = -w[2]/w[1]
#print(f"a: {a}, b: {b}")

#y = [a*x+b for x in x1]

#y

_ = plt.plot(x1[:3],x2[:3],'o', color = "green")
_ = plt.plot(x1[3:],x2[3:],'o')
_ = plt.plot(x1,fx,'r')

"""ZAD 2

"""

import math

SIZE_TAB = 13
beta = 0.5
ni = 0.35

def f(suma):
    y = (1 - math.exp(-1*suma*beta))/(1+math.exp(-1*suma*beta))
    return y

one = [-1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, 1]
four = [1, -1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1]
d = [-1, 1]
w = [0]*SIZE_TAB
w2 = [0]*SIZE_TAB
iterator = 0
e_tab = []
while True:
    E = 0
    for i in range(12):
        s = one[i] * w[i] + w[12] * one[12]
        y = f(s)
        w[i] += d[0] * one[i] * ni
        w[12] += d[0] * one[12] * ni
        print(y,d[0])
        s2 = four[i] * w2[i] + w2[12] * four[12]
        y2 = f(s2)
        w2[i] += d[1] * four[i] * ni
        w2[12] += d[1] * four[12] * ni
        print(y2,d[1])
    E += 0.5*(d[0] - y)*(d[0] - y)+0.5*(d[1] - y2)*(d[1] - y2)
    print(y,"<-- y koncowy dla 1",d[0],"<--d oczekiwana")
    print(y2,"<-- y koncowy dla 4",d[1],"<--d oczekiwana")
    iterator += 1
    print("\n",iterator,"<-- przebieg funkcji\n")
    print(E,"blad sumaryczny")
    e_tab.append(E)
    if E <= 0.0000000005:
        break

plt.plot(e_tab)

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
one = [1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1]
four = [1,1,1,1,1,1,1,-1,-1,1,-1,-1,1]
like_one = [1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1]
like_four = [1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1]
d = [-1, 1]
iterator = 0
d4 = 0
d2 = 0
d1 = 1
s2=0
e_tab = []
while True:
    E=0
    s=0
    s2=0
    for i in range(13):
      s = s + one[i] * w[i]
      s2 = s2 + four[i] * w[i]
    y2 = f(s2)
    y = f(s)
    for i in range(13):
        w[i] = w[i] + ni * beta*(1-y)*y*(d1-y)*one[i]
        w[i] = w[i] + ni * beta*(1-y2)*y2*(d4-y2)*four[i]

    iterator += 1
    E +=  0.5*(d1 - y)*(d1 - y) +0.5*(d4 - y2)*(d4 - y2)
    print(E,"blad sumaryczny")
    e_tab.append(E)
    if E <= 0.0005:
        break


s1,s2,s3,s4= 0,0,0,0
for i in range(13):
  s1+=one[i] * w[i]
  s2+=four[i] * w[i]
  s3+=like_one[i] * w[i]
  s4+=like_four[i] * w[i]


print("wyjscie dla 1",f(s1),"\nwyjscie dla  4",f(s2),"\n wyjscie dla niby 1",f(s3),"\nwyjscie dla niby 4",f(s4))

print(e_tab)
plt.plot(e_tab)
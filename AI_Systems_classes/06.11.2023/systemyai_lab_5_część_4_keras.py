# -*- coding: utf-8 -*-
"""SystemyAI_lab_5_część_4_Keras.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1ETdhHx7Cz557-iF2W-7t7JOQV-LgnXN6

Import biblioteki **TensorFlow** ([https://www.tensorflow.org/](https://www.tensorflow.org/)) z której będziemy korzystali w **uczeniu maszynowym**:
"""

import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

number_of_points = 1000
x_point = []
y_point = []

a = 0.22
b = 0.78

for i in range(number_of_points):
    x = np.random.normal(0.0,0.5)
    y = (a*x+b)+np.random.normal(0.0,0.1)
    x_point.append(x)
    y_point.append(y)

plt.scatter(x_point,y_point,c='b')
plt.show()

real_x = np.array(x_point)
real_y = np.array(y_point)

import keras
from keras.models import Sequential
from keras.layers import Dense

"""Definiujemy model:"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=1, activation = "linear"))

"""Definiujemy **optymalizator** i **błąd** (średni błąd kwadratowy - MSE). **Współczynnik uczenia = 0.1**"""

opt = tf.keras.optimizers.SGD(learning_rate=0.1)

model.compile(loss='MSE',optimizer=opt)

model.summary()

"""Proces **uczenia**:"""

epochs = 1000
h = model.fit(real_x,real_y, verbose=0, epochs=epochs, batch_size=100)

Loss = h.history['loss']
Loss

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()

print(weights[0][0][0])
print(weights[1][0])    #bias

plt.scatter(np.arange(epochs),Loss)
plt.show()
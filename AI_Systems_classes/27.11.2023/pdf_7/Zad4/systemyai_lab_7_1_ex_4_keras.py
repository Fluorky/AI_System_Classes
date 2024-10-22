# -*- coding: utf-8 -*-
"""SystemyAI_lab_7_1_ex_4_Keras.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1XGYpOSFU3Ab_Rt-xaCpT_wVvjTA_x-fb

Import biblioteki **TensorFlow** ([https://www.tensorflow.org/](https://www.tensorflow.org/)) z której będziemy korzystali w **uczeniu maszynowym**:
"""

import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

import keras
from keras.models import Sequential
from keras.layers import Dense
from sklearn.metrics import confusion_matrix
import seaborn as sns
import matplotlib.pyplot as plt

"""**Dwa gangi**

Przetesuj poniższe instrukcje:
"""

[2]*12

[-3]*10+[4]*5

np.append([1,2,3],[4,5])

"""Przygotowujemy zbiór danych:"""

x_label1 = np.random.normal(3, 1, 1000)
y_label1 = np.random.normal(2, 1, 1000)
x_label2 = np.random.normal(7, 1, 1000)
y_label2 = np.random.normal(6, 1, 1000)

xs = np.append(x_label1, x_label2) #tablica wsp. x dla 2000 punktów
ys = np.append(y_label1, y_label2) #tablica wsp. y dla 2000 punktów
labels = np.asarray([0.]*len(x_label1)+[1.]*len(x_label2))

plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.show()



"""Przygotowanie danych:"""

xs[0:10].reshape(-1,1)

xs=xs.reshape(-1,1)
ys=ys.reshape(-1,1)
data_points=np.concatenate([xs,ys],axis=1)
data_points

def subset_dataset(data_points, label,subset_size):
    arr = np.arange(len(data_points))
    l=len(data_points)
    s=int(subset_size*l)
    np.random.shuffle(arr)
    data_points_val = data_points[arr[0:s]]
    label_val = label[arr[0:s]]
    #print(type(label_train))
    data_points_train = data_points[arr[s:int(l*(1-subset_size))]]
    label_train = label[arr[s:int(l*(1-subset_size))]]
    data_points_test = data_points[arr[int(l*(1-subset_size)):]]
    label_test = label[arr[int(l*(1-subset_size)):]]
    return data_points_train,label_train,data_points_val,label_val,data_points_test,label_test

data_points_train,label_train,data_points_val,label_val,data_points_test,label_test = subset_dataset(data_points, labels,0.1)

print(data_points_train.size,label_train.size,data_points_val.size,label_val.size,data_points_test.size,label_test.size)

"""##Wersja podstawowa

Definiujemy model:
"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=2, activation = "sigmoid"))

"""Definiujemy **optymalizator** i **błąd** (entropia krzyżowa). **Współczynnik uczenia = 0.1**"""

#opt = tf.keras.optimizers.Adam(learning_rate=0.1)
opt = tf.keras.optimizers.SGD(learning_rate=0.1)

model.compile(loss='binary_crossentropy',optimizer=opt,metrics=['accuracy'])

"""Informacja o modelu:"""

model.summary()

"""Proces **uczenia**:"""

epochs = 100
h = model.fit(data_points_train,label_train, verbose=1 ,epochs=epochs,validation_data=(data_points_val,label_val))

Loss = h.history['loss']
Loss

val_loss = h.history['val_loss']
val_loss

val_accuracy = h.history['val_accuracy']
accuracy = h.history['accuracy']

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()


print(weights[0])
print(weights[1])    #bias

plt.plot(Loss)
plt.plot(val_loss)

plt.show()

plt.plot(accuracy)
plt.plot(val_accuracy)
plt.show()

"""Model.evaluate for test data"""

results = model.evaluate(data_points_test,label_test)
print("test loss, test acc:", results)

"""Model.predict for test dataset"""

predictions = model.predict(data_points_test)

predictions

y_true = np.array(label_test, dtype=int)
y_pred = np.array(predictions, dtype=int)

# Convert continuous predictions to class labels (binary classification example)
y_pred = (y_pred > 0.5).astype(int)

# Generate confusion matrix
cm = confusion_matrix(label_test, y_pred)

# Display the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Class 0", "Class 1"], yticklabels=["Class 0", "Class 1"])
plt.xlabel("Predicted")
plt.ylabel("True")
plt.title("Confusion Matrix")
plt.show()

"""Sprawdzamy działanie modelu dla punktu o współrzędnych **x** i **y**:"""

x=3.0
y=2.0
plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.scatter(x,y,c='b', marker='s')
plt.show()
model.predict([[x,y]])

"""Liczba epok 50"""



"""Definiujemy model:"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=2, activation = "sigmoid"))

"""Definiujemy **optymalizator** i **błąd** (entropia krzyżowa). **Współczynnik uczenia = 0.1**"""

#opt = tf.keras.optimizers.Adam(learning_rate=0.1)
opt = tf.keras.optimizers.SGD(learning_rate=0.1)

model.compile(loss='binary_crossentropy',optimizer=opt,metrics=['accuracy'])

"""Informacja o modelu:"""

model.summary()

"""Proces **uczenia**:"""

epochs = 50
h = model.fit(data_points_train,label_train, verbose=1 ,epochs=epochs,validation_data=(data_points_val,label_val))

Loss = h.history['loss']
Loss

val_loss = h.history['val_loss']
val_loss

val_accuracy = h.history['val_accuracy']
accuracy = h.history['accuracy']

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()


print(weights[0])
print(weights[1])    #bias

plt.plot(Loss)
plt.plot(val_loss)

plt.show()

plt.plot(accuracy)
plt.plot(val_accuracy)
plt.show()

"""Model.evaluate for test data"""

results = model.evaluate(data_points_test,label_test)
print("test loss, test acc:", results)

"""Model.predict for test dataset"""

predictions = model.predict(data_points_test)

predictions

y_true = np.array(label_test, dtype=int)
y_pred = np.array(predictions, dtype=int)

# Convert continuous predictions to class labels (binary classification example)
y_pred = (y_pred > 0.5).astype(int)

# Generate confusion matrix
cm = confusion_matrix(label_test, y_pred)

# Display the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Class 0", "Class 1"], yticklabels=["Class 0", "Class 1"])
plt.xlabel("Predicted")
plt.ylabel("True")
plt.title("Confusion Matrix")
plt.show()

"""Sprawdzamy działanie modelu dla punktu o współrzędnych **x** i **y**:"""

x=3.0
y=2.0
plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.scatter(x,y,c='b', marker='s')
plt.show()
model.predict([[x,y]])

"""##Liczba epok 150"""



"""Definiujemy model:"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=2, activation = "sigmoid"))

"""Definiujemy **optymalizator** i **błąd** (entropia krzyżowa). **Współczynnik uczenia = 0.1**"""

#opt = tf.keras.optimizers.Adam(learning_rate=0.1)
opt = tf.keras.optimizers.SGD(learning_rate=0.1)

model.compile(loss='binary_crossentropy',optimizer=opt,metrics=['accuracy'])

"""Informacja o modelu:"""

model.summary()

"""Proces **uczenia**:"""

epochs = 150
h = model.fit(data_points_train,label_train, verbose=1 ,epochs=epochs,validation_data=(data_points_val,label_val))

Loss = h.history['loss']
Loss

val_loss = h.history['val_loss']
val_loss

val_accuracy = h.history['val_accuracy']
accuracy = h.history['accuracy']

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()


print(weights[0])
print(weights[1])    #bias

plt.plot(Loss)
plt.plot(val_loss)

plt.show()

plt.plot(accuracy)
plt.plot(val_accuracy)
plt.show()

"""Model.evaluate for test data"""

results = model.evaluate(data_points_test,label_test)
print("test loss, test acc:", results)

"""Model.predict for test dataset"""

predictions = model.predict(data_points_test)

predictions

y_true = np.array(label_test, dtype=int)
y_pred = np.array(predictions, dtype=int)

# Convert continuous predictions to class labels (binary classification example)
y_pred = (y_pred > 0.5).astype(int)

# Generate confusion matrix
cm = confusion_matrix(label_test, y_pred)

# Display the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Class 0", "Class 1"], yticklabels=["Class 0", "Class 1"])
plt.xlabel("Predicted")
plt.ylabel("True")
plt.title("Confusion Matrix")
plt.show()

"""Sprawdzamy działanie modelu dla punktu o współrzędnych **x** i **y**:"""

x=3.0
y=2.0
plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.scatter(x,y,c='b', marker='s')
plt.show()
model.predict([[x,y]])

"""##współczynnik uczenia 0.01 (SGD)

"""



"""Definiujemy model:"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=2, activation = "sigmoid"))

"""Definiujemy **optymalizator** i **błąd** (entropia krzyżowa). **Współczynnik uczenia = 0.1**"""

#opt = tf.keras.optimizers.Adam(learning_rate=0.1)
opt = tf.keras.optimizers.SGD(learning_rate=0.01)

model.compile(loss='binary_crossentropy',optimizer=opt,metrics=['accuracy'])

"""Informacja o modelu:"""

model.summary()

"""Proces **uczenia**:"""

epochs = 100
h = model.fit(data_points_train,label_train, verbose=1 ,epochs=epochs,validation_data=(data_points_val,label_val))

Loss = h.history['loss']
Loss

val_loss = h.history['val_loss']
val_loss

val_accuracy = h.history['val_accuracy']
accuracy = h.history['accuracy']

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()


print(weights[0])
print(weights[1])    #bias

plt.plot(Loss)
plt.plot(val_loss)

plt.show()

plt.plot(accuracy)
plt.plot(val_accuracy)
plt.show()

"""Model.evaluate for test data"""

results = model.evaluate(data_points_test,label_test)
print("test loss, test acc:", results)

"""Model.predict for test dataset"""

predictions = model.predict(data_points_test)

predictions

y_true = np.array(label_test, dtype=int)
y_pred = np.array(predictions, dtype=int)

# Convert continuous predictions to class labels (binary classification example)
y_pred = (y_pred > 0.5).astype(int)

# Generate confusion matrix
cm = confusion_matrix(label_test, y_pred)

# Display the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Class 0", "Class 1"], yticklabels=["Class 0", "Class 1"])
plt.xlabel("Predicted")
plt.ylabel("True")
plt.title("Confusion Matrix")
plt.show()

"""Sprawdzamy działanie modelu dla punktu o współrzędnych **x** i **y**:"""

x=3.0
y=2.0
plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.scatter(x,y,c='b', marker='s')
plt.show()
model.predict([[x,y]])

"""##współczynnik uczenia 0.01 (Adam)"""



"""Definiujemy model:"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=2, activation = "sigmoid"))

"""Definiujemy **optymalizator** i **błąd** (entropia krzyżowa). **Współczynnik uczenia = 0.01**"""

opt = tf.keras.optimizers.Adam(learning_rate=0.01)
#opt = tf.keras.optimizers.SGD(learning_rate=0.1)

model.compile(loss='binary_crossentropy',optimizer=opt,metrics=['accuracy'])

"""Informacja o modelu:"""

model.summary()

"""Proces **uczenia**:"""

epochs = 100
h = model.fit(data_points_train,label_train, verbose=1 ,epochs=epochs,validation_data=(data_points_val,label_val))

Loss = h.history['loss']
Loss

val_loss = h.history['val_loss']
val_loss

val_accuracy = h.history['val_accuracy']
accuracy = h.history['accuracy']

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()


print(weights[0])
print(weights[1])    #bias

plt.plot(Loss)
plt.plot(val_loss)

plt.show()

plt.plot(accuracy)
plt.plot(val_accuracy)
plt.show()

"""Model.evaluate for test data"""

results = model.evaluate(data_points_test,label_test)
print("test loss, test acc:", results)

"""Model.predict for test dataset"""

predictions = model.predict(data_points_test)

predictions

y_true = np.array(label_test, dtype=int)
y_pred = np.array(predictions, dtype=int)

# Convert continuous predictions to class labels (binary classification example)
y_pred = (y_pred > 0.5).astype(int)

# Generate confusion matrix
cm = confusion_matrix(label_test, y_pred)

# Display the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Class 0", "Class 1"], yticklabels=["Class 0", "Class 1"])
plt.xlabel("Predicted")
plt.ylabel("True")
plt.title("Confusion Matrix")
plt.show()

"""Sprawdzamy działanie modelu dla punktu o współrzędnych **x** i **y**:"""

x=3.0
y=2.0
plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.scatter(x,y,c='b', marker='s')
plt.show()
model.predict([[x,y]])

"""##Batch 100"""



"""Definiujemy model:"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=2, activation = "sigmoid"))

"""Definiujemy **optymalizator** i **błąd** (entropia krzyżowa). **Współczynnik uczenia = 0.1**"""

#opt = tf.keras.optimizers.Adam(learning_rate=0.1)
opt = tf.keras.optimizers.SGD(learning_rate=0.1)

model.compile(loss='binary_crossentropy',optimizer=opt,metrics=['accuracy'])

"""Informacja o modelu:"""

model.summary()

"""Proces **uczenia**:"""

epochs = 100
h = model.fit(data_points_train,label_train, verbose=1 ,epochs=epochs,validation_data=(data_points_val,label_val),batch_size=100)

Loss = h.history['loss']
Loss

val_loss = h.history['val_loss']
val_loss

val_accuracy = h.history['val_accuracy']
accuracy = h.history['accuracy']

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()


print(weights[0])
print(weights[1])    #bias

plt.plot(Loss)
plt.plot(val_loss)

plt.show()

plt.plot(accuracy)
plt.plot(val_accuracy)
plt.show()

"""Model.evaluate for test data"""

results = model.evaluate(data_points_test,label_test)
print("test loss, test acc:", results)

"""Model.predict for test dataset"""

predictions = model.predict(data_points_test)

predictions

y_true = np.array(label_test, dtype=int)
y_pred = np.array(predictions, dtype=int)

# Convert continuous predictions to class labels (binary classification example)
y_pred = (y_pred > 0.5).astype(int)

# Generate confusion matrix
cm = confusion_matrix(label_test, y_pred)

# Display the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Class 0", "Class 1"], yticklabels=["Class 0", "Class 1"])
plt.xlabel("Predicted")
plt.ylabel("True")
plt.title("Confusion Matrix")
plt.show()

"""Sprawdzamy działanie modelu dla punktu o współrzędnych **x** i **y**:"""

x=3.0
y=2.0
plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.scatter(x,y,c='b', marker='s')
plt.show()
model.predict([[x,y]])

"""##Batch 200"""



"""Definiujemy model:"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=2, activation = "sigmoid"))

"""Definiujemy **optymalizator** i **błąd** (entropia krzyżowa). **Współczynnik uczenia = 0.1**"""

#opt = tf.keras.optimizers.Adam(learning_rate=0.1)
opt = tf.keras.optimizers.SGD(learning_rate=0.1)

model.compile(loss='binary_crossentropy',optimizer=opt,metrics=['accuracy'])

"""Informacja o modelu:"""

model.summary()

"""Proces **uczenia**:"""

epochs = 100
h = model.fit(data_points_train,label_train, verbose=1 ,epochs=epochs,validation_data=(data_points_val,label_val),batch_size=200)

Loss = h.history['loss']
Loss

val_loss = h.history['val_loss']
val_loss

val_accuracy = h.history['val_accuracy']
accuracy = h.history['accuracy']

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()


print(weights[0])
print(weights[1])    #bias

plt.plot(Loss)
plt.plot(val_loss)

plt.show()

plt.plot(accuracy)
plt.plot(val_accuracy)
plt.show()

"""Model.evaluate for test data"""

results = model.evaluate(data_points_test,label_test)
print("test loss, test acc:", results)

"""Model.predict for test dataset"""

predictions = model.predict(data_points_test)

predictions

y_true = np.array(label_test, dtype=int)
y_pred = np.array(predictions, dtype=int)

# Convert continuous predictions to class labels (binary classification example)
y_pred = (y_pred > 0.5).astype(int)

# Generate confusion matrix
cm = confusion_matrix(label_test, y_pred)

# Display the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Class 0", "Class 1"], yticklabels=["Class 0", "Class 1"])
plt.xlabel("Predicted")
plt.ylabel("True")
plt.title("Confusion Matrix")
plt.show()

"""Sprawdzamy działanie modelu dla punktu o współrzędnych **x** i **y**:"""

x=3.0
y=2.0
plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.scatter(x,y,c='b', marker='s')
plt.show()
model.predict([[x,y]])

"""##Batch 400"""



"""Definiujemy model:"""

model = Sequential()

"""Dodajemy **jedną warstwę** (Dense) z **jednym neuronem** (units=1) z **biasem** (use_bias=True) i **liniową funkcją aktywacji** (activation="linear"):"""

model.add(Dense(units = 1, use_bias=True, input_dim=2, activation = "sigmoid"))

"""Definiujemy **optymalizator** i **błąd** (entropia krzyżowa). **Współczynnik uczenia = 0.1**"""

#opt = tf.keras.optimizers.Adam(learning_rate=0.1)
opt = tf.keras.optimizers.SGD(learning_rate=0.1)

model.compile(loss='binary_crossentropy',optimizer=opt,metrics=['accuracy'])

"""Informacja o modelu:"""

model.summary()

"""Proces **uczenia**:"""

epochs = 100
h = model.fit(data_points_train,label_train, verbose=1 ,epochs=epochs,validation_data=(data_points_val,label_val),batch_size=400)

Loss = h.history['loss']
Loss

val_loss = h.history['val_loss']
val_loss

val_accuracy = h.history['val_accuracy']
accuracy = h.history['accuracy']

"""Sprawdźmy jakie są **wartości wag**:"""

weights = model.get_weights()


print(weights[0])
print(weights[1])    #bias

plt.plot(Loss)
plt.plot(val_loss)

plt.show()

plt.plot(accuracy)
plt.plot(val_accuracy)
plt.show()

"""Model.evaluate for test data"""

results = model.evaluate(data_points_test,label_test)
print("test loss, test acc:", results)

"""Model.predict for test dataset"""

predictions = model.predict(data_points_test)

predictions

y_true = np.array(label_test, dtype=int)
y_pred = np.array(predictions, dtype=int)

# Convert continuous predictions to class labels (binary classification example)
y_pred = (y_pred > 0.5).astype(int)

# Generate confusion matrix
cm = confusion_matrix(label_test, y_pred)

# Display the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Class 0", "Class 1"], yticklabels=["Class 0", "Class 1"])
plt.xlabel("Predicted")
plt.ylabel("True")
plt.title("Confusion Matrix")
plt.show()

"""Sprawdzamy działanie modelu dla punktu o współrzędnych **x** i **y**:"""

x=3.0
y=2.0
plt.scatter(x_label1, y_label1, c='r', marker='x', s=20)
plt.scatter(x_label2, y_label2, c='g', marker='1', s=20)
plt.scatter(x,y,c='b', marker='s')
plt.show()
model.predict([[x,y]])

"""##Najlepszy model

Na uczenie modelu ma najwiekszy wpływ użycie batcha (bez batcha jest podawany cały zbiór uczący), dzięki temu wprowadza, że pewną losowość w procesie uczenia, pomoga to uniknąć utknięcia w minimach lokalnych. Model uczony z minibatchem osiąga lepsze rezultaty jeżeli chodzi o wyniki uczenia(szybszy spadek funkcji błędu oraz mniejszy błąd). Model lepiej i szybciej się uczy gdy mini-batch jest większy niż gdy jest on mniejszy.

Ponadto na proces uczenia modelu ma wpływ ilość epok.
Za mała ilość epok skutkuje niedouczeniem modelu (model nie nauczył się wystarczająco dobrze dostosowywać się do danych treningowych).
Ostatnim sprawdzonym przeze mnie parametrem jest współczynnik uczenia. Po przestawieniu na współczynnik Adam model uczy się lepiej
Jego zbyt duża wartość rowadzi do skakania wokół minimum globalnego przy czym model go nie osiągnie. W przypadku zastosowania zbyt małej wartości współczynnika uczenia proces uczenia jest bardzo wolny na przełomie epok.
"""


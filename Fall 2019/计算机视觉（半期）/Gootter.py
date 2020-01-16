

# 2. 导入库和模块
from keras.models import Sequential
from keras.layers import Conv2D, MaxPool2D
from keras.layers import Dense, Flatten
from keras.utils import to_categorical

import cv2
import numpy as np


# 3. 加载数据
from keras.datasets import mnist
(x_train, y_train), (x_test, y_test) = mnist.load_data()
print("打印训练集的示例：")
cv2.imshow("x_test[0]", x_train[0])



# 4. 数据预处理
img_x, img_y = 28, 28
x_train = x_train.reshape(x_train.shape[0], img_x, img_y, 1)
x_test = x_test.reshape(x_test.shape[0], img_x, img_y, 1)

print(x_test[4])

x_train = x_train.astype('float32')
x_test = x_test.astype('float32')
x_train /= 255
x_test /= 255

print(y_train[1])
y_train = to_categorical(y_train, 10)
y_test = to_categorical(y_test, 10)
print(y_train[1])


# 5. 定义模型结构
model = Sequential()
model.add(Conv2D(32, kernel_size=(5,5), activation='relu', input_shape=(img_x, img_y, 1)))
model.add(MaxPool2D(pool_size=(2,2), strides=(2,2)))
model.add(Conv2D(64, kernel_size=(5,5), activation='relu'))
model.add(MaxPool2D(pool_size=(2,2), strides=(2,2)))
model.add(Flatten())
model.add(Dense(1000, activation='relu'))
model.add(Dense(10, activation='softmax'))

# 6. 编译
model.compile(optimizer='adam',
              loss='categorical_crossentropy',
              metrics=['accuracy'])

# 7. 训练
model.fit(x_train, y_train, batch_size=128, epochs=10)

# 8. 评估模型
score = model.evaluate(x_test, y_test)
print('acc', score[1])

import numpy as np
import h5py
import matplotlib.pyplot as plt

"""
初始化各神经网络参数
Arguments:
    laryer_dims -- (list) 各层的维度
Returns:
    parameters -- (dict) 各初始化参数
        W1,W2,...WL
        b1,b2,...bL
"""
def initialize_parameters_deep(layer_dims):
    parameters = {}
    L = len(layer_dims)

    for l in range(1, L):
        parameters["W" + str(l)] = np.random.randn(layer_dims[l], layer_dims[l - 1]) * 0.01
        parameters["b" + str(l)] = np.zeros((layer_dims[l], 1))
    
    return parameters

"""
线性前向传播，单层
Arguments:
    A -- 上一层的激活函数
    W -- 当层的参数W
    b -- 当层的参数b
return:
    Z -- 当层的激活函数输入参数
    cache -- (tuple) 保存 A, W, b参数
"""
def linear_forward(A, W, b):
    Z = np.dot(W, A) + b
    cache = (A, W, b)
    return Z, cache

"""
Sigmoid激活函数
Arguments:
    Z -- 激活函数的输入
Return:
    A -- 激活函数的输出
    cache -- Z
"""
def sigmoid(Z):
    A = 1 / (1 + np.exp(-Z))
    cache = Z
    return A, cache

"""
ReLU激活函数
Arguments:
    Z -- 激活函数的输入
Return:
    A -- 激活函数的输出
    cache -- Z
"""
def relu(Z):
    A = np.maximun(0, Z)
    cache = Z
    return A, cache

"""
线性+激活前向传播，单层
Arguments:
    A_prev -- 上一层的激活函数
    W -- 当层的参数W
    b -- 当层的参数b
    activation -- 激活方式
Return:
    A -- 当层的激活函数
    cache -- 当层的参数
"""
def linear_activation_forward(A_prev, W, b, activation):
    # 线性传播
    Z, linear_cache = linear_forward(A_prev, W, b)
    # 非线性传播
    if activation == "sigmoid":
        A, activation_cache = sigmoid(Z)
    if activation == "relu":
        A, activation_cache = relu(Z)
    cache = (linear_cache, activation_cache)
    return A, cache
"""
L层的前向传播函数
Arguments:
    X -- 输入层
    parameters -- 各层参数
Returns:
    AL -- 最后一层的激活函数
    caches -- 各层参数
"""
def L_model_forward(X, parameters):
    caches = []
    A = X
    L = len(parameters) / 2
    # 第一层到L-1层使用ReLU激活函数
    for l in range(1, L):
        A_prev = A
        A, cache = linear_activation_forward(A_prev, parameters["W" + str(l)], parameters["b" + str(l)], "relu")
        caches.append(cache)
    # 第L层使用Sigmoid激活函数
    AL, cache = linear_activation_forward(A, parameters["W" + str(L)], parameters["b" + str(L)], "sigmoid")
    caches.append(cache)
    return AL, caches

"""
计算损失函数
Arguments: 
    AL -- 第L层输出的激活函数
    Y -- 训练标签
Returns:
    cost -- 损失函数
"""
def compute_cost(AL, Y):
    m = Y.shape[1]
    cost = (-1 / m) * (np.sum(np.multiply(Y, np.log(AL))) + np.sum(np.multiply(1 - Y, np.log(1 - AL))))
    cost = np.squeeze(cost)
    return cost

"""
线性反向传播
Arguments:
    dZ -- 损失函数对z的梯度
    cache -- 前向传播过程中的参数
Return:
    dA_prev -- 上一层激活函数的梯度
    dW -- 当层W参数的梯度
    db -- 当层b参数的梯度
"""
def linear_backward(dZ, cache):
    A_prev, W, b = cache
    m = A_prev.shape[1]
    dW = np.dot(dZ, A_prev.T) / m
    db = np.sum(dZ, axis = 1, keepdims = True) / m
    dA_prev = np.dot(W.T, dZ)
    return dA_prev, dW, db

"""
Implement the backward propagation for a single RELU unit.

Arguments:
    dA -- post-activation gradient, of any shape
    cache -- 'Z' where we store for computing backward propagation efficiently
Returns:
    dZ -- Gradient of the cost with respect to Z
"""
def relu_backward(dA, cache):
    Z = cache
    dZ = np.array(dA, copy=True) # just converting dz to a correct object.
    # When z <= 0, you should set dz to 0 as well. 
    dZ[Z <= 0] = 0
    return dZ

"""
Implement the backward propagation for a single SIGMOID unit.

Arguments:
    dA -- post-activation gradient, of any shape
    cache -- 'Z' where we store for computing backward propagation efficiently
Returns:
    dZ -- Gradient of the cost with respect to Z
"""
def sigmoid_backward(dA, cache):
    Z = cache
    s = 1/(1+np.exp(-Z))
    dZ = dA * s * (1-s)
    return dZ

"""
线性+激活反向传播
Arguments:
    dA -- 当层激活函数的梯度
    cache -- 前向传播过程中的参数
    activation -- 当层的激活函数种类
Returns:
    dA_prev -- 上一层激活函数的梯度
    dW -- 当层W参数的梯度
    db -- 当层b参数的梯度
"""
def linear_activation_backward(dA, cache, activation):
    linear_cache, activation_cache = cache
    if activation == "relu":
        dz = relu_backward(dA, activation_cache)
        dA_prev, dW, db = linear_backward(dZ, linear_cache)
    elif activation == "sigmoid":
        dZ = sigmoid_backward(dA, activation_cache)
        dA_prev, dW, db = linear_backward(dZ, linear_cache)
    return dA_prev, dW, db

"""
L层反向传播
"""
def L_model_backward(AL, Y, caches):
    grads = {}
    L = len(caches) # the number of layers
    m = AL.shape[1]
    Y = Y.reshape(AL.shape)
    dAL = -(np.divide(Y, AL) - np.divide(1 - Y, 1 - AL))
    grads["dA" + str(L)] = dAL
    grads["dA" + str(L - 1)], grads["dW" + str(L)], grads["db" + str(L)] = linear_activation_backward(dAL, caches[L - 1], "sigmoid")

    for l in reversed(range(L - 1)):
        grads["dA" + str(l)], grads["dW" + str(l + 1)], grads["db" + str(l + 1)] = linear_activation_backward(grads["dA" + str(l + 1)], caches[l], "relu")

    return grads

"""
更新参数
"""
def update_parameters(parameters, grads, learning_rate):    
    L = len(parameters) // 2 # number of layers in the neural network
    for l in range(L):
        parameters["W" + str(l + 1)] = parameters["W" + str(l + 1)] - learning_rate * grads["dW" + str(l + 1)]
        parameters["b" + str(l + 1)] = parameters["b" + str(l + 1)] - learning_rate * grads["db" + str(l + 1)]
    return parameters
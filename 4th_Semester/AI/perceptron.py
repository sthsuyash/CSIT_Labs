'''
Program to implement NAND Logic Function using Perceptron Model
'''

import numpy as np

# define Unit Step Function
def unitStep(v):
    if v >= 0:
        return 1
    else:
        return 0

# design Perceptron Model
def perceptronModel(x, w, b):
    v = np.dot(w, x) + b
    y = unitStep(v)
    return y

# NOT Logic Function
# wNOT = -1, bNOT = 0.5
def NOT_logicFunction(x):
    wNOT = -1
    bNOT = 0.5
    return perceptronModel(x, wNOT, bNOT)

# AND Logic Function
# w1 = 1, w2 = 1, bAND = -1.5
def AND_logicFunction(x):
    w = np.array([1, 1])
    bAND = -1.5
    return perceptronModel(x, w, bAND)

# NAND Logic Function with AND and NOT function calls in sequence
def NAND_logicFunction(x):
    output_AND = AND_logicFunction(x)
    output_NOT = NOT_logicFunction(output_AND)
    return output_NOT

if __name__ == '__main__':
    x, y = input("Enter the input x, y: ").split(' ')
    x = int(x)
    y = int(y)
    print(f"NAND({x}, {y}) = {NAND_logicFunction(np.array([x, y]))}")

# # testing the Perceptron Model
# test1 = np.array([0, 1])
# test2 = np.array([1, 1])
# test3 = np.array([0, 0])
# test4 = np.array([1, 0])

# print("NAND({}, {}) = {}".format(0, 1, NAND_logicFunction(test1)))
# print("NAND({}, {}) = {}".format(1, 1, NAND_logicFunction(test2)))
# print("NAND({}, {}) = {}".format(0, 0, NAND_logicFunction(test3)))
# print("NAND({}, {}) = {}".format(1, 0, NAND_logicFunction(test4)))

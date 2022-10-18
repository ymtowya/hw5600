import os
import matplotlib.pyplot as plt
import numpy as np

pageNum = 5000

i = 1
loopArr = []
resArr = []

while i < pageNum:
    commandStr = './tlb ' + str(i) + ' ' + str(5000) + '\n'
    res = os.system(commandStr)
    loopArr.append(i)
    resArr.append(res)
    i = i * 2

print("\nPageNum:")
print(loopArr)

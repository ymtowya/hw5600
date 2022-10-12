#! /usr/bin/env python3

import random

import matplotlib.pyplot as plt
import numpy as np

loops = 200
asize = 1024
psize = 2 * 1024
resList = [0.0] * asize

random.seed(1)

for limit_value in range(0, asize):
    count = 0
    for i in range(loops):
        tmpAddr = int(psize * random.random())
        if tmpAddr < limit_value:
            count += 1
    resList[limit_value] = count * 100 / loops

fig = plt.figure()
x = np.linspace(1, asize, asize)
plt.plot(x, [u for u in resList], color='blue')
plt.ylim(0, 100)
# plt.margins(0)
plt.xlabel('Limit')
plt.ylabel('Valid fraction (Average)')
plt.savefig('valid_fraction.png', dpi=227)
plt.show()
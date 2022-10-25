
import random

nums = 15
hots = [1, 2, 3]
colds = [10, 11, 12, 13, 14, 15, 16]
hotProb = 0.7

res = []

for i in range(0, nums):
    if (random.random() <= hotProb):
        res.append(str(random.choice(hots)))
    else:
        res.append(str(random.choice(colds)))

print(','.join(res))
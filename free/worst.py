
import random

class Node:
    def __init__(self, start, length, next):
        self.start = start
        self.length = length
        self.next = next

def getListStr(freeHead):
    res = 'START   -   LENGTH\n\n'
    curr = freeHead.next
    while not curr == None:
        res += '{start} - {length}\n'.format(start = curr.start, length = curr.length)
        curr = curr.next
    return res


def free(start, freeHead, memoRecord):
    size = memoRecord[start]
    curNext = freeHead.next
    newFree = Node(start, size, curNext)
    freeHead.next = newFree
    memoRecord.pop(start)


def worstFit(freeHead, memoRecord, size):
    maxSize = -1
    maxNode = None
    curr = freeHead
    loop = 1
    while not curr == None:
        if curr.length >= size and curr.length > maxSize:
            maxSize = curr.length
            maxNode = curr
        curr = curr.next
        loop += 1

    if not maxNode == None and maxSize >= size:
        oldLength = maxNode.length
        oldStart = maxNode.start
        maxNode.length = maxNode.length - size
        maxNode.start = maxNode.start + size

        memoRecord[oldStart] = size

        return [True, oldStart, size, loop]

    return [False, -1, -1, loop]

memoRecord = {}
freeHead = Node(-1, -1, Node(0, 2048, None))
starts = []
process = [200, 100, 30, 40, 170, 500, 60, 90, 10, 80, 150, 60, 70, 50]
random.shuffle(process)
prob_alloc = 50

for i in range(12):
    if random.randint(0, 99) < prob_alloc or len(memoRecord) == 0:
        # alloc
        size = random.choice(process)
        [res, start, length, loop] = worstFit(freeHead, memoRecord, size)
        print('- Allocate for {size} :\n{res} - Start {start} - Length {size} - Loop {loop}\n'
                .format(res = res, start = start, size = length, loop = loop))
    else:
        # free
        start = random.choice(list(memoRecord))
        size = memoRecord[start]
        free(start, freeHead, memoRecord)
        print('- Free Space:\nStart from {start} with Size of {size}\n'.format(
            start = start, size = size
        ))

print('\n\nFree Space List are like :\n')
print(getListStr(freeHead))


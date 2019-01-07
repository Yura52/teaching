#!/usr/bin/env python3
import time


start = time.time()
v = []
for x in range(10000000):
    v.append(x)
result = v[0]
for i in range(1, len(v)):
    if v[i] > result:
        result = v[i]
end = time.time()
print(f'result: {result}\nduration: {end - start}')

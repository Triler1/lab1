import time
import random

def contains(arr, target):
    for x in arr:
        if x == target:
            return True
    return False

def measure_time(func, data, target):
    start = time.perf_counter()
    func(data, target)
    end = time.perf_counter()
    return end - start

def generate_array(n):
    arr = []
    for i in range(n):
        arr.append(random.randint(0, 10000))
    return arr

if __name__ == '__main__':
    sizes = [100, 1000, 5000, 10000]
    for n in sizes:
        arr = generate_array(n)
        target = random.randint(0, 10000)
        t = measure_time(contains, arr, target)
        print(n, t)

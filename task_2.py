import time
import random

def second_max(arr):
    max1 = arr[0]
    max2 = arr[0]

    for x in arr:
        if x > max1:
            max2 = max1
            max1 = x
        elif x > max2 and x != max1:
            max2 = x

    return max2

def measure_time(func, data):
    start = time.perf_counter()
    func(data)
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
        t = measure_time(second_max, arr)
        print(n, t)

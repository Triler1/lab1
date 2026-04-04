import time
import random

def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return True
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

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
    arr.sort()
    return arr

if __name__ == '__main__':
    sizes = [100, 1000, 5000, 10000]

    for n in sizes:
        arr = generate_array(n)
        target = random.randint(0, 10000)
        t = measure_time(binary_search, arr, target)
        print(n, t)

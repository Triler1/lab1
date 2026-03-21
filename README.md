Задание 1: Проверка наличия элемента в массиве

Необходимо реализовать алгоритм проверки наличия элемента в массиве.  
Алгоритм последовательно проходит по массиву и сравнивает каждый элемент с искомым значением.

- Если элемент найден — возвращается `True`
- Если массив закончился — возвращается `False`

---

1. Реализация
```python
def contains(arr, target):
    for x in arr:
        if x == target:
            return True
    return False
```
2. Функция измерения времени.
```python
import time

def measure_time(func, data, target):
    start = time.perf_counter()
    func(data, target)
    end = time.perf_counter()
    return end - start
```
3. Функция генерации данных.
```python
import random

def generate_array(n):
    arr = []
    for i in range(n):
        arr.append(random.randint(0, 10000))
    return arr
```
4. Эксперимент.
```python
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
```
| n | t, c |
|---|------|
| 100 | 3.29999 |
| 1000 | 1.66999 |
| 5000 | 7.94999 |
| 10000 | 0.00014 |


Задание 2. Поиск второго максимального элемента
Алгоритм должен найти второе по величине число в массиве.

Идея алгоритма:

1. хранить два значения — максимальное и второе максимальное (т.е. на первой итерации max1 = arr[0] , max2 = arr[0])
2. пройти по массиву
3. обновлять значения при необходимости

1. Реализация
```python
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
```
2. Функция измерения времени
```python
import time

def measure_time(func, data):
    start = time.perf_counter()
    func(data)
    end = time.perf_counter()
    return end - start
```
3. Функция генерации данных
```python
import random

def generate_array(n):
    arr = []
    for i in range(n):
        arr.append(random.randint(0, 10000))
    return arr
```
4. Эксперимент
```python
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

    print("| n | t, c |")
    print("|---|------|")

    for n in sizes:
        arr = generate_array(n)
        t = measure_time(second_max, arr)
        print(f"| {n} | {t:.5f} |")
```
| n | t, c |
|---|------|
| 100 | 4.99999 |
| 1000 | 2.44000 |
| 5000 | 0.00011 |
| 10000 | 0.00022 |


| 10000 | 4.55999997939216e-05 |

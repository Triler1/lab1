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
```
import time

def measure_time(func, data, target):
    start = time.perf_counter()
    func(data, target)
    end = time.perf_counter()
    return end - start
```
3. Функция генерации данных.
```
import random

def generate_array(n):
    arr = []
    for i in range(n):
        arr.append(random.randint(0, 10000))
    return arr
```
4. Эксперимент.
```
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
| 100 | 3.2999996619764715e-06 |
| 1000 | 1.6699999832781032e-05 |
| 5000 | 7.949999962875154e-05 |
| 10000 | 4.55999997939216e-05 |

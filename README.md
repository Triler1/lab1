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

    for n in sizes:
        arr = generate_array(n)
        t = measure_time(second_max, arr)
        print(n, t)
```
| n | t, c |
|---|------|
| 100 | 4.99999 |
| 1000 | 2.44000 |
| 5000 | 0.00011 |
| 10000 | 0.00022 |

# Задание 3: Бинарный поиск

## Описание

Бинарный поиск используется для поиска элемента в **отсортированном массиве**.

---

## Идея алгоритма

1. Выбирается середина массива  
2. Если элемент найден — поиск завершён  
3. Если элемент меньше — поиск продолжается в левой части  
4. Если больше — в правой части  

---


1. Реализация
```python
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
```
2. Функция измерения времени
```python
import time

def measure_time(func, data, target):
    start = time.perf_counter()
    func(data, target)
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
    arr.sort()
    return arr
```
4. Эксперимент
```python
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
```
| n | t, c |
|---|------|
| 100 | 3.30000 |
| 1000 | 1.79999 |
| 5000 | 1.10000 |
| 10000 | 2.50000 |

---

# Задание 4: Построение таблицы умножения

1. Реализация
```cpp
void table(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << i * j << " ";
        }
        cout << endl;
    }
}
```
2. Функция измерения времени
```cpp
#include <chrono>

float measure_time(void (*func)(int), int n) {
    auto start = chrono::high_resolution_clock::now();
    func(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> diff = end - start;
    return diff.count();
}
```
3. Эксперимент
```cpp
#include <iostream>
#include <chrono>

using namespace std;

void table(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int x = i * j;
        }
    }
}

float measure_time(void (*func)(int), int n) {
    auto start = chrono::high_resolution_clock::now();
    func(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> diff = end - start;
    return diff.count();
}

int main() {
    int sizes[] = {100, 1000, 5000, 10000};
    for (int n : sizes) {
        float t = measure_time(table, n);
        cout << n << " " << t << endl;
    }
}
```
| n | t, c |
|---|------|
| 100 | 0.00001 |
| 1000 | 0.00117 |
| 5000 | 0.02922 |
| 10000 | 0.11636 |

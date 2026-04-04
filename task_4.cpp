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

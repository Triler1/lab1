#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

struct ComplexityResult {
    float time_sec;
    size_t memory_bytes;
};

void quicksort(vector<int>& arr, int left, int right, int depth, int& max_depth) {
    if (depth > max_depth) {
        max_depth = depth;
    }

    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j, depth + 1, max_depth);

    if (i < right)
        quicksort(arr, i, right, depth + 1, max_depth);
}

vector<int> generate_array(int n) {
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 10000);
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
    return arr;
}

ComplexityResult measure_complexities(vector<int> arr) {
    int max_depth = 0;

    auto start = chrono::high_resolution_clock::now();

    if (!arr.empty()) {
        quicksort(arr, 0, (int)arr.size() - 1, 1, max_depth);
    }

    auto end = chrono::high_resolution_clock::now();

    float time_sec = chrono::duration<float>(end - start).count();

    size_t memory_per_call = sizeof(int) * 6 + 32;
    size_t memory_bytes = max_depth * memory_per_call;

    return {time_sec, memory_bytes};
}

int main() {
    vector<int> sizes = {100, 1000, 5000, 10000};
    for (int n : sizes) {
        vector<int> arr = generate_array(n);
        ComplexityResult result = measure_complexities(arr);
        cout << n << " " << result.time_sec << " " << result.memory_bytes << "\n";
    }
    return 0;
}

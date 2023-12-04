// run with C++20

#include <iostream>
#include <vector>
#include <numeric>

void beadSort(std::vector<int>& arr) {
    const int n = arr.size();
    std::vector<std::vector<int>> grid(2, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < arr[i]; ++j)
            grid[j % 2][i] = 1;

    for (auto& row : grid) {
        int sum = std::accumulate(row.begin(), row.end(), 0);
        row = std::vector<int>(n - sum, 0);
        row.insert(row.end(), sum, 1);
    }

    arr.assign(grid[1].begin(), grid[1].end());
}

int main() {
    std::vector<int> arr = {5, 3, 1, 7, 4, 1, 1, 20};

    std::cout << "Original array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < 10; ++i) {
        beadSort(arr);
    }

    std::cout << "Sorted array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}

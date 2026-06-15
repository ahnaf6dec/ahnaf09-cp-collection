#include <iostream>
#include <vector>

// Generic iterative binary search
template <typename T>
int binarySearch(const std::vector<T>& arr, const T& target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        // Safe midpoint calculation preventing (low + high) overflow
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found, return index
        }
        else if (arr[mid] < target) {
            low = mid + 1; // Discard left half
        }
        else {
            high = mid - 1; // Discard right half
        }
    }

    return -1; // Target not found
}

#include <iostream>
#include <vector>
#include <algorithm> // Required for binary search functions

int main() {
    std::vector<int> data = {10, 20, 30, 30, 40, 50};
    int target = 30;

    // 1. Quick check for existence
    bool exists = std::binary_search(data.begin(), data.end(), target);

    // 2. Get the first matching index using std::lower_bound
    auto it = std::lower_bound(data.begin(), data.end(), target);
    
    if (it != data.end() && *it == target) {
        std::cout << "Found " << target << " at index: " << std::distance(data.begin(), it) << "\n";
    } else {
        std::cout << "Element not found.\n";
    }
}

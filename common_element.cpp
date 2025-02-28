#include <iostream>
#include <vector>

class CommonElementsFinder {
public:
    // Function to find common elements without duplicates
    std::vector<int> findCommonElements(const std::vector<int>& arr1, const std::vector<int>& arr2) {
        std::vector<int> result;
        int i = 0, j = 0;

        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                i++; // Move the pointer in the first array
            } else if (arr1[i] > arr2[j]) {
                j++; // Move the pointer in the second array
            } else { // Common element found
                if (result.empty() || result.back() != arr1[i]) {
                    result.push_back(arr1[i]); // Add only unique values
                }
                i++; j++; // Move both pointers to avoid duplicates
            }
        }
        return result;
    }
    
    // Function to display a vector
    void printVector(const std::vector<int>& vec) {
        std::cout << "[ ";
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    CommonElementsFinder finder;
    
    std::vector<int> arr1 = {1, 2, 4, 4, 5, 6, 7, 8, 9};
    std::vector<int> arr2 = {2, 4, 4, 6, 8, 10};

    std::vector<int> commonElements = finder.findCommonElements(arr1, arr2);

    std::cout << "Common elements without duplicates: ";
    finder.printVector(commonElements);

    return 0;
}

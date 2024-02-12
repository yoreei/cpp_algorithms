#include <iostream>
#include <vector>
#include <cassert>

// Function prototype for binary search
int binsearchImpl(const std::vector<int>& arr, int target) {
    if (arr.empty() || target < arr.front() || target > arr.back()) {
        return -1;
    }

    int lower = 0;
    int upper = arr.size() - 1;

    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;

        if (arr[mid] < target) {
            lower = mid + 1;
        }
        else if (arr[mid] > target) {
            upper = mid - 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}


// Function to run a test case
void testBinsearch(const std::vector<int>& arr, int target, int expected, int testNo) {
    int result = binsearchImpl(arr, target);
    std::cout << "Running Test " << testNo << " expected = " << expected << "; result = " << result << std::endl;
    assert(result == expected);
    std::cout << "Test " << testNo << " Passed. Found " << target << " at index " << result << std::endl;
}

void binsearch() {
    // Test cases
    std::vector<int> testArray1 = { 1, 3, 5, 7, 9, 11 };
    std::vector<int> testArray2 = { 2, 4, 6, 8, 10, 12, 14 };
    std::vector<int> testArray3 = { -5, -3, -1, 1, 3, 5 };

    std::vector<int> testArray4 = { 1, 3, 5, 7, 9, 11, 13, 15 };
    std::vector<int> testArray5 = { 2, 4, 6, 8, 10, 12, 14, 16 };
    std::vector<int> testArray6 = { -10, -8, -6, -4, -2, 0, 2, 4, 6 };

    // Running test cases
    testBinsearch(testArray1, 7, 3, 1);   // Test 1: 7 is at index 3 in testArray1
    testBinsearch(testArray2, 10, 4, 2);  // Test 2: 10 is at index 4 in testArray2
    testBinsearch(testArray3, -3, 1, 3);  // Test 3: -3 is at index 1 in testArray3
    testBinsearch(testArray1, 4, -1, 4);  // Test 4: 4 is not in testArray1, expecting -1
    testBinsearch(testArray2, 13, -1, 5); // Test 5: 13 is not in testArray2, expecting -1

    testBinsearch(testArray4, 9, 4, 6);   // Test 6: 9 is at index 4 in testArray4
    testBinsearch(testArray5, 8, 3, 7);   // Test 7: 8 is at index 3 in testArray5
    testBinsearch(testArray6, 0, 5, 8);   // Test 8: 0 is at index 5 in testArray6
    testBinsearch(testArray4, 14, -1, 9); // Test 9: 14 is not in testArray4, expecting -1
    testBinsearch(testArray5, 1, -1, 10); // Test 10: 1 is not in testArray5, expecting -1

}

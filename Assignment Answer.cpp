#include <iostream>
#include <cassert>

using namespace std;

/*
    You need to refactor the following function using clean code guidelines
        - Meaningful names
        - Functions
        - Comments
        - Formatting
        - Error Handling
    After finishing, you are requested to write unite tests below in the main code for the function.
*/

/**
 * This function calculates the sum of elements of an array from index `start_index` to `end_index` - 1.
 * @throw invalid_argument If `start_index` or `end_index` is out of range.
 */
int calculateSum(const int arr[], int start_index, int end_index, int arr_size) {
    // Validate indices
    if(start_index < 0 || end_index > arr_size || start_index >= end_index) {
        throw invalid_argument("Invalid index range for summation.");
    }
    
    int sum = 0;  
    for (int i = start_index; i < end_index; i++) {  
        sum += arr[i];
    }
    return sum;  
}

int main () {
    // Example array to test the function
    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);


    // Happy Scenarios
    // Test 1: Normal case
    assert(calculateSum(arr, 0, 3, arr_size) == 6); // 1 + 2 + 3 = 6

    // Test 2: Entire array
    assert(calculateSum(arr, 0, arr_size, arr_size) == 21); // 1 + 2 + 3 + 4 + 5 + 6 = 21

    // Test 3: Single element
    assert(calculateSum(arr, 2, 3, arr_size) == 3); // 3

    // Sad Scenarios
    // Test 1: Invalid range (start_index >= end_index)
    try {
        calculateSum(arr, 3, 3, arr_size);
        assert(false); // Should not reach here
    } catch (const invalid_argument&) {
        assert(true); // Expected to catch exception
    }

    // Test 2: Out of range
    try {
        calculateSum(arr, -1, 4, arr_size);
        assert(false); // Should not reach here
    } catch (const invalid_argument&) {
        assert(true); // Expected to catch exception
    }

    // If we reached here, so all tests passed
    cout << "All tests has passed!\n";
    return 0;
}

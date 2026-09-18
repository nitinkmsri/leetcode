// Include input and output stream functionality.
#include <iostream>
// Include the unordered_map container.
#include <unordered_map>
// Include the vector container.
#include <vector>

// Use the standard library namespace.
using namespace std;

// Define the Solution class.
class Solution {
public:
    // Find two indices whose values add up to the target using brute force.
    vector<int> twoSum(vector<int>& nums, int target) {
        // Store the number of values in the input vector.
        int n = nums.size();
        // Iterate over each possible first index.
        for (int i = 0; i < n - 1; i++) {
            // Iterate over every index after the first index.
            for (int j = i + 1; j < n; j++) {
                // Check whether the selected values add up to the target.
                if (nums[i] + nums[j] == target) {
                    // Return the two matching indices.
                    return {i, j};
                }
            }
        }
        // Return an empty vector when no solution is found.
        return {}; // No solution found
    }

    // Find two indices whose values add up to the target using a hash map.
    vector<int> twoSum_hashmap(vector<int>& nums, int target) {
        // Map each previously seen value to its index.
        unordered_map<int, int> seen;

        // Visit each value in the input vector.
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            // Calculate the value required to reach the target.
            int complement = target - nums[i];
            // Check whether the required value was seen previously.
            if (seen.count(complement)) {
                // Return the previous index and the current index.
                return {seen[complement], i};
            }
            // Store the current value and its index.
            seen[nums[i]] = i;
        }

        // Return an empty vector when no solution is found.
        return {};
    }
};

// Define the program entry point.
int main() {
    // Store the number of input values.
    int n;
    // Prompt the user for the list length.
    cout << "Enter list length: ";
    // Read the list length.
    cin >> n;

    // Create an empty vector for the input values.
    vector<int> nums;
    // Reserve space for the expected number of values.
    nums.reserve(n);
    // Read each value from the user.
    for (int i = 0; i < n; i++) {
        // Prompt the user for the current value.
        cout << "Enter number " << i << " of " << n - 1 << ": ";
        // Store the current input value.
        int number;
        // Read the current value.
        cin >> number;
        // Add the value to the input vector.
        nums.push_back(number);
    }

    // Store the requested target sum.
    int target;
    // Prompt the user for the target.
    cout << "Enter target: ";
    // Read the target value.
    cin >> target;

    // Create an instance of the Solution class.

    // Instantiate the solution implementation.
    Solution solution;
    // Find a pair using the brute-force implementation.
    vector<int> result = solution.twoSum(nums, target);
    // Find a pair using the hash-map implementation.
    vector<int> hashmap_result = solution.twoSum_hashmap(nums, target);

    // Print the result from the brute-force implementation.
    cout << "twoSum: [";
    // Print the indices if a pair was found.
    if (!result.empty()) {
        // Print both matching indices.
        cout << result[0] << ", " << result[1];
    }
    // Close the brute-force result.
    cout << "]\n";

    // Print the result from the hash-map implementation.
    cout << "twoSum_hashmap: [";
    // Print the indices if a pair was found.
    if (!hashmap_result.empty()) {
        // Print both matching indices.
        cout << hashmap_result[0] << ", " << hashmap_result[1];
    }
    // Close the hash-map result.
    cout << "]\n";

    // Indicate that the program completed successfully.
    return 0;
}


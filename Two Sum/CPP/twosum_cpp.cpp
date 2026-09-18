#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }

    vector<int> twoSum_hashmap(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    int n;
    cout << "Enter list length: ";
    cin >> n;

    vector<int> nums;
    nums.reserve(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i << " of " << n - 1 << ": ";
        int number;
        cin >> number;
        nums.push_back(number);
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    vector<int> hashmap_result = solution.twoSum_hashmap(nums, target);

    cout << "twoSum: [";
    if (!result.empty()) {
        cout << result[0] << ", " << result[1];
    }
    cout << "]\n";

    cout << "twoSum_hashmap: [";
    if (!hashmap_result.empty()) {
        cout << hashmap_result[0] << ", " << hashmap_result[1];
    }
    cout << "]\n";

    return 0;
}


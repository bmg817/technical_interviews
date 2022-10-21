class Solution
{
public:
    // 1. Two Sum: https://leetcode.com/problems/two-sum/
    // Space complexity: O(n)
    // Time complexity: O(n)
    vector<int> twoSum(const vector<int> &nums, int target)
    {
        // Space complexity: O(n)
        unordered_map<int, int> indexOfValues;

        // Time Complexity of loop: O(n)
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int diff = target - num;
            // check if complementary value already exists in the dictionary, if so, return the indices

            // this next step MUST be before storing current num in dictionary.
            // Otherwise, false positives could occur for non-unique combinations (e.g. 3+3 = 6, case: [1,3,4])

            // Average time complexity: O(n) (worst case O(n))
            if (indexOfValues.find(diff) != indexOfValues.end())
                return {i, indexOfValues[diff]};

            // If it does not exist, store the given index and number in the dictionary
            // Average time complexity: O(n)
            indexOfValues[num] = i;
        }
        return {};
    }
};
class Solution
{
public:
    // 217. Contains Duplicate: https://leetcode.com/problems/contains-duplicate/
    // Time complexity: O(n)
    // Space complexity: O(n)

    bool containsDuplicate(const vector<int> &nums)
    {
        // Space complexity: O(n)
        unordered_set<int> seenNums;

        // Loop through each value to check if number is unique
        // Time complexity: O(n)
        for (const auto &num : nums)
        {
            // Average case: O(1). Worst case: O(logn)
            const auto [_, uniqueVal] = seenNums.insert(num);
            if (!uniqueVal)
                return true;
        }

        return false;
    }
};
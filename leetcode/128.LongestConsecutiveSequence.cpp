class Solution
{
public:
    // 128. Longest Consecutive Sequence: https://leetcode.com/problems/longest-consecutive-sequence/
    // Time complexity: O(n)
    // Space complexity: O(n)

    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        // Time complexity: O(n) on average
        // Space complexity: O(n)
        unordered_set<int> seenNums(nums.begin(), nums.end());

        int maxCount = 1;

        // Time complexity: O(n)
        for (auto const &num : nums)
        {
            // This `if` checks if the current number we're investigating
            // is a left-most value. Which would imply it is the beginning of a sequence
            // If it is, count all sequential values that exist in set

            // Time complexity: O(1) on average (O(n) worst case)
            if (seenNums.find(num - 1) == seenNums.end())
            {
                int count = 1;
                // Time complexity: O(1) on average (O(n) worst case)
                while (seenNums.find(num + count) != seenNums.end())
                    count++;

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};
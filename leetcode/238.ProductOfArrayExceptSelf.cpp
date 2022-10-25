class Solution
{
public:
    // 238. Product of Array Except Self: https://leetcode.com/problems/product-of-array-except-self/
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    vector<int> productExceptSelf(const vector<int> &nums)
    {
        // First, calculate the prefix products for each index of the array
        // by multiplying the current prefix by the previous value

        // Then, calculate the post products for each index of the array
        // while multiplying by the prefix product that was previously
        // stored in the `res` array

        // An example to illustrate method: input nums = [1, 2, 3, 4]
        // prefix array: [1, 1*1, 1*2, 1*2*3] = [1, 1, 2, 6]
        // Postfix is calculated and then multiplied by res[i]
        // But I've added postfix array for illustrative purposes: [2*3*4, 3*4, 4, 1] = [24, 12, 4, 1]
        // Postfix now must be multiplied by prefix which is our result: [2*3*4, 3*4, 4*2, 6] = [24,12,8,6]
        vector<int> result(nums.size(), 1);
        int prefix = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            result[i] = nums[i - 1] * prefix;
            prefix = result[i];
        }

        int postfix = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            result[i] = nums[i + 1] * postfix * result[i];
            postfix = nums[i + 1] * postfix;
        }

        return result;
    }
};
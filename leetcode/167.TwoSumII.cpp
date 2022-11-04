class Solution
{
public:
    // 347. Two Sum II - Input Array Is Sorted: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    vector<int> twoSum(const vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;

        // Use two pointers to determine if target has been achieved
        // Because the array is sorted already, we can assume that if
        // the candidate target is too large, we should move i 
        // to the right to be greater. Same for j if candidate target 
        // is less than the actual target. We only investigate each index once
        // so time complexity is O(n).
        while (i < j)
        {
            int candidateTarget = numbers[i] + numbers[j];
            if (candidateTarget > target)
                j--;
            else if (candidateTarget < target)
                i++;
            else if (candidateTarget == target)
                break;
        }

        return {i + 1, j + 1};
    }
};
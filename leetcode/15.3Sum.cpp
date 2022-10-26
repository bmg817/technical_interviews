inline constexpr int kTarget = 0;

class Solution
{
public:
    // 15. 3 Sum: https://leetcode.com/problems/3sum/
    // Time complexity: O(n)
    // Space complexity: O(1)

    vector<vector<int>> threeSum(const vector<int> &nums)
    {
        // Time Complexity: O(nlogn)
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        // Check feasible combinations of triplets
        // We can reduce the number of "feasible" triplets to check by
        // taking advantage of the sorted array. Using a similar implementation
        // as the Two Sum II problem, we check a possible candidate target triplet sum
        // if the candidate target is less than the expected target (0 in this case),
        // move the j pointer to the right to a greater a value
        // if candidate target is greater than the expected target,
        // move k pointer to the left to a lesser value.
        // This way j and k inspect each value only once. Giving us a time complexity
        // of the inner while loop of n. The outer while loop for i is also `n`
        // total time complexity being O(n^2)

        int i = 0;
        while (i < nums.size() - 2)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int candidateValue = nums[i] + nums[j] + nums[k];
                if (candidateValue == kTarget)
                    // if a candidate value = target, push back values,
                    // but don't break from the current while loop
                    // there may be more combinations of j and k that
                    // reach the target with i
                    result.push_back({nums[i], nums[j], nums[k]});

                if (candidateValue < kTarget || candidateValue == kTarget)
                {
                    // skip duplicates to prevent duplicate triplets
                    while (j + 1 < k && nums[j] == nums[j + 1])
                        j++;
                    j++;
                }

                if (candidateValue > kTarget || candidateValue == kTarget)
                {
                    // skip duplicates to prevent duplicate triplets
                    while (k - 1 > j && nums[k] == nums[k - 1])
                        k--;
                    k--;
                }
            }

            // skip duplicates to prevent duplicate triplets
            while (i + 2 < nums.size() && nums[i] == nums[i + 1])
                i++;
            i++;
        }

        return result;
    }
};
class Solution
{
public:
    /* SOLUTION 1 */
    /*
    992. Subarrays with K Different Integers: https://leetcode.com/problems/subarrays-with-k-different-integers/
    Time Complexity: O(n)
    Space Complexity: O(n)

    Methodology:
    To find `k` distinct integers, first find all possible combinations of
    at MOST `k` distinct integers. Then, find all possible combinations of
    at MOST `k - 1` distinct integers. "At most `k`" will share the same space
    of solutions for ALL of "at most `k - 1`". This means, to find JUST
    the solution space of exactly `k` integers, we just need to subtract
    the total number of solutions of at most `k - 1` from at most `k`.

    Example below:
    inputs: [1,2,1,2,3], k = 2

    All possible solutions of "at most `k`":
    start = 0; [1], [1,2], [1,2,1], [1,2,1,2]
    start = 1; [2], [2,1], [2,1,2]
    start = 2; [1], [1,2]
    start = 3; [2], [2,3]
    start = 4; [3]
    If we sum the above, there are 12 possible unique solutions with at most `k` unique integers

    All possible solutions of "at most `k - 1`":
    start = 0; [1]
    start = 1; [2]
    start = 2; [1]
    start = 3; [2]
    start = 4; [3]
    There are 5 possible unique solutions with at most `k` unique integers

    If you look at all the possible combinations between `k` and `k-1` you can see that
    all possible solutions of `k - 1` are also within `k`. By removing those combinations,
    we're left with the following:

    All possible solutions of "at most `k` - `k - 1`":
    start = 0; [1,2], [1,2,1], [1,2,1,2]
    start = 1; [2,1], [2,1,2]
    start = 2; [1,2]
    start = 3; [2,3]
    start = 4; None
    Visually, there are exactly 7 solutions as expected if we subtract 5 solutions from
    the 12 of "at most `k`"
    */

    int subarraysWithKDistinct(const vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(const vector<int> &nums, int k)
    {
        int start = 0, result = 0, uniqueInts = 0;

        unordered_map<int, int> countsOfInts(nums.size());
        for (int end = 0; end < nums.size(); end++)
        {
            countsOfInts[nums[end]]++;
            // if the count = 1, this integer is a new unique value
            if (countsOfInts[nums[end]] == 1)
                uniqueInts++;

            // increase start to eliminate previous integers 
            // until uniqueInts is within constraints
            while (uniqueInts > k)
            {
                countsOfInts[nums[start]]--;
                if (countsOfInts[nums[start]] == 0)
                    uniqueInts--;
                start++;
            }

            // sum up ALL new possible combinations < k, which includes
            // when size = 1, 2, ... k
            // for example in the case of [1,2,1,2,3]
            // [1] -> end - start + 1 = 1; valid non-dup combinations: [1]
            // [1,2] -> end - start + 1 = 2; valid non-dup combinations: [1,2] & [2]
            // [1, 2, 3] -> end - start + 1 = 3; valid non-dup combinations: [1,2,3] & [2,3] & [3] 
            result += end - start + 1;
        }
        return result;
    }
};
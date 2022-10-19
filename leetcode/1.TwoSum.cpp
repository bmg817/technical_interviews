class Solution
{
public:
    // Space complexity: O(n)
    // Time complexity: O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indexOfValues; // Space complexity: O(n)
        for (int i = 0; i < nums.size(); i++)
        {                      // Time Complexity of loop: O(n)
            int num = nums[i]; // loop through each of the nums
            int diff = target - num;
            // see if the complementary value already exists in the dictionary, if it does return the indices
            // this next step MUST come before storing current num into the dictionary. Otherwise, if there are non-unique combinations (e.g. 3+3 = 6)
            // we might get a false positive for the wrong index
            if (indexOfValues.find(diff) != indexOfValues.end())
                return {i, indexOfValues[diff]}; // Average time complexity: O(n) (worst case O(logn))
            // if it does not exist, store the given index and number in the dictionary
            indexOfValues[num] = i; // Average time complexity: O(n) (worst case O(logn))
        }
        return {};
    }
};
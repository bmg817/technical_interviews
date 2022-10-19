class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Step 1: Initialize set (Space complexity: O(n))
        unordered_set<int> seenNums;
        
        // Step 2: Loop through each value (Time complexity: O(n))
        // and check if the number is unique
        for (const auto& num: nums) {
            const auto [_, uniqueVal] = seenNums.insert(num); // average case: O(1), although can be O(logn) in worst case
            if (!uniqueVal) return true;
        }
        
        return false;
    }
};
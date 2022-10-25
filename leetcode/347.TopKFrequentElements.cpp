class Solution
{
public:
    // 347. Top K Frequent Elements: https://leetcode.com/problems/top-k-frequent-elements/
    // Time Complexity: O(n) if k is sufficiently small. If k approaches n, time complexity is O(nlogn).
    // Space Complexity: O(n)

    vector<int> topKFrequent(const vector<int> &nums, int k)
    {
        // Space Complexity: O(n)
        unordered_map<int, int> data;

        // Store all numbers in the dictionary and count how many
        // Time Complexity: O(n)
        for (const auto &num : nums)
            data[num]++;

        // Space Complexity: O(n)
        vector<pair<int, int>> totals(data.size());

        // Store the counts as the first value in the pair for sorting in priority_queue
        // Time Complexity: O(n)
        int i = 0;
        for (const auto &[key, value] : data)
        {
            totals[i] = {value, key};
            i++;
        }

        // Time Complexity: O(n)
        priority_queue<pair<int, int>> pq(totals.begin(), totals.end());

        int j = 0;
        vector<int> result(k, 0);
        while (j < k)
        {
            // pop off max values from heap k times and store in `res` vector
            // Time Complexity: O(klogn)
            result[j] = pq.top().second;
            pq.pop();
            j++;
        }

        return result;
    }
};
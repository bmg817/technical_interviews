class Solution
{
public:
    // 3. Longest Substring Without Repeating Character: https://leetcode.com/problems/longest-substring-without-repeating-characters/

    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int lengthOfLongestSubstring(string_view s)
    {
        // This problem uses only ASCII characters
        // Index is used to store indices
        // of 256 of ASCII characters
        // Instantiate with -1 as placeholder
        // Space Complexity: O(1) because it is O(256), which is constant
        vector<int> indexOfChars(256, -1);
        // Instantiate start at initial index
        int start = 0;
        int maxWindow = 0;

        // Loop through each of the indices in the array
        // If the given character index is greater than start
        // that means there's a duplicate and start must be replaced with
        // the index after the first instance of the repeated character
        // Then update the current character index to have the current index
        // then update maximum window size

        // Time Complexity: O(n)
        for (int end = 0; end < s.size(); end++)
        {
            if (indexOfChars[s[end]] >= start)
                start = indexOfChars[s[end]] + 1;

            indexOfChars[s[end]] = end;
            maxWindow = max(end - start + 1, maxWindow);
        }

        return maxWindow;
    }
};
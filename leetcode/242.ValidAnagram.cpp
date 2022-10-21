class Solution
{
public:
    // 242. Valid Anagram: https://leetcode.com/problems/valid-anagram/
    // Space Complexity: O(n)
    // Time Complexity: O(n)

    // First case using a dictionary
    bool isAnagram1(string_view s, string_view t)
    {
        // Must have the same amount of chars to be anagram
        if (s.size() != t.size())
            return false;

        // Space Complexity: O(n) where n is the number of unique letters.
        // Only 26 characters in the alphabet, so just O(26) which is just O(1).
        unordered_map<char, int> countOfChars;

        // Count up total number of characters in first word
        // Time Complexity: O(n)
        for (const auto &c : s)
            countOfChars[c]++;

        // Subtract total number of characters in second word from first word
        // Time Complexity: O(n)
        for (const auto &c : t)
        {
            countOfChars[c]--;

            // If < 0, means there's an extra char in `t` that wasn't in `s`
            if (countOfChars[c] < 0)
                return false;
        }

        // Time Complexity: O(1) (b/c 26 chars)
        for (const auto &[c, cnt] : countOfChars)
            if (cnt != 0)
                return false;

        return true;
    }

    // Second case use vector which can reduce space complexity a little bit
    // No comments on this function b/c same content as the function above
    bool isAnagram2(string_view s, string_view t)
    {
        if (s.size() != t.size())
            return false;

        vector<int> countOfChars(26, 0);

        for (const auto &c : s)
            countOfChars[c - 'a']++;

        for (const auto &c : t)
        {
            countOfChars[c - 'a']--;
            if (countOfChars[c - 'a'] < 0)
                return false;
        }

        for (const auto &cnt : countOfChars)
            if (cnt != 0)
                return false;

        return true;
    }
};
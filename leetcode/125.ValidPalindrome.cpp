class Solution
{
public:
    // 125. Longest Consecutive Sequence: https://leetcode.com/problems/valid-palindrome/
    // Time complexity: O(n)
    // Space complexity: O(1)

    bool isPalindrome(string_view s)
    {
        int i = 0;
        int j = s.size() - 1;
        // Use two pointers that start on opposite ends to check each letter
        // Time complexity: O(n)
        while (i < j)
        {
            while (i < j && !isalnum(s[i]))
                i++;
            while (i < j && !isalnum(s[j]))
                j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};
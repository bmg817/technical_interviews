class Solution
{
public:
    string minWindow(string_view s, string_view t)
    {
        // 76. Minimum Window Substring: https://leetcode.com/problems/minimum-window-substring/
        // Time Complexity: O(n) where n is the length of s
        // Space Complexity: O(1)

        // unable to achieve all characters that exist in `t` because less chars in `s`
        if (t.size() > s.size())
            return "";

        // inspectChars will store counts of chars in target string `t`
        // countsOfChars will store counts of chars in a given window size
        // we initialize the window size at: start = 0; end = t.size() - 1
        vector<int> inspectChars(128, 0);
        int countUniqueChars = 0;
        for (const auto &c : t)
        {
            if (inspectChars[c] == 0)
                countUniqueChars++;
            inspectChars[c]++;
        }

        vector<int> countsOfChars(128, 0);
        for (int i = 0; i < t.size(); i++)
            if (inspectChars[s[i]] > 0)
                countsOfChars[s[i]]++;

        int countMatches = countUniqueChars;
        for (int i = 0; i < countsOfChars.size(); i++)
            // `countMatches` stores the total number of characters that match the expected criteria
            // in this case, the criteria expects the count for any arbitrary characters in `s` to be >= `t`
            // if it's not, it's not a match and we decrease the `countMatches` value by 1
            if (countsOfChars[i] < inspectChars[i])
                countMatches--;

        // This is a special case where the number of matches is exactly the number of
        // unique characters in `t` in the beginning of the string. Return the current string because
        // this is the minimum size of the result and we can never improve this.
        if (countMatches == countUniqueChars)
            return string(s.begin(), s.begin() + t.size());

        int start = 0;
        int finalStart = 0;
        int finalEnd = s.size() + 1;
        // Using a sliding window technique, we count the number of
        // characters and unique characters that match the criteria until we reach end of the array
        for (int end = t.size(); end < s.size(); end++)
        {
            if (inspectChars[s[end]] == 0)
                continue;

            countsOfChars[s[end]]++;
            if (countsOfChars[s[end]] == inspectChars[s[end]])
                countMatches++;
            while (start < s.size() && start <= end && countMatches == countUniqueChars)
            {
                if (inspectChars[s[start]] == 0)
                {
                    start++;
                    continue;
                }
                
                if (finalEnd == s.size() + 1 || end - start < finalEnd - finalStart)
                {
                    finalEnd = end;
                    finalStart = start;
                }

                countsOfChars[s[start]]--;
                if (countsOfChars[s[start]] == inspectChars[s[start]] - 1)
                    countMatches--; // 2
                
                start++;
            }
        }
        return finalEnd == s.size() + 1 ? "" : string(s.begin() + finalStart, s.begin() + finalEnd + 1);
    }
};
class Solution
{
public:
    // 49. Group Anagrams: https://leetcode.com/problems/group-anagrams/
    
    // Time Complexity: O(n*k)
    // Space Complexity: O(n*k)


    // helper function for groupAnagrams1
    string getCountOfChars(string_view str)
    {
        vector<int> numChars(26, 0);
        for (const auto &c : str)
            numChars[c - 'a']++;

        string res;
        for (const auto &num : numChars)
            res += num;
        return res;
    }

    vector<vector<string>> groupAnagrams1(const vector<string> &strs)
    {
        // Store all groups of anagrams into this map
        // Space Complexity: O(n)
        unordered_map<string, vector<string>> anagramGroups;

        // Loop through each string in the vector
        // Time Complexity: O(n)
        for (const auto &str : strs)
        {
            // getCountOfChars returns string of 26 numbers that indicate number
            // of chars for each letter in alphabet in current string.
            // it is always sorted a-z, which means we can use this as a key to group anagrams
            string sortedString = getCountOfChars(str);
            anagramGroups[sortedString].push_back(str);
        }

        vector<vector<string>> res;
        for (const auto &[key, val] : anagramGroups)
            res.push_back(val);

        return res;
    }

    // Time Complexity: O(n*klogk) where k is the number of characters in string
    // Space Complexity: O(nk)
    vector<vector<string>> groupAnagrams2(const vector<string> &strs)
    {
        // Store all groups of anagrams into this map
        // Space Complexity: O(n)
        unordered_map<string, vector<string>> anagramGroups;

        // Loop through each string in the vector
        // Time Complexity: O(n)
        for (const auto &str : strs)
        {
            string sortString = str;
            
            // Time Complexity: O(klogk) is the max length of the characters in the words
            sort(sortString.begin(), sortString.end());
            
            // use sorted string as key for dictionary entry
            // because if it's an anagram, all letters
            // will be the same and sorted the same way
            anagramGroups[sortString].push_back(str);
        }

        // Space Complexity: O(nk)
        vector<vector<string>> res;
        
        // Time Complexity: O(n)
        for (const auto &[key, val] : anagramGroups)
            res.push_back(val);

        return res;
    }
};
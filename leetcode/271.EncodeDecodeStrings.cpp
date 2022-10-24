class Codec
{
public:
    // 271. Encode and Decode Strings: https://leetcode.com/problems/encode-and-decode-strings/
    // Encode: Space Complexity: O(n); Time Complexity: O(n)
    // Decode: Space Complexity: O(n); Time Complexity: O(n)

    // Encodes a list of strings to a single string.
    string encode(const vector<string> &strs)
    {
        string result;
        // Time complexity: number of words
        // Space complexity: O(n)
        for (int i = 0; i < strs.size(); i++)
            result += to_string(strs[i].size()) + mEncodeStr + strs[i];

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string &s)
    {
        vector<string> result;
        string word;
        int i = 0;
        // Time complexity: number of words that were decoded
        // Space complexity: O(n) for the result vector
        while (i < s.size())
        {
            string tmp;
            while (s[i] != mEncodeStr[0] && i < s.size())
            {
                tmp += s[i];
                i++;
            }

            int lengthOfWord = stoi(tmp);

            result.push_back(s.substr(i + mEncodeStr.size(), lengthOfWord));
            i += mEncodeStr.size() + lengthOfWord;
        }

        return result;
    }

private:
    string mEncodeStr{"@@"};
};
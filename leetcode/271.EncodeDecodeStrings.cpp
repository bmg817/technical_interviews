inline constexpr string_view kEncodeStr = "@";

class Codec
{
public:
    // 271. Encode and Decode Strings: https://leetcode.com/problems/encode-and-decode-strings/
    // Encode: Space Complexity: O(n*l); Time Complexity: O(n*l)
    // Decode: Space Complexity: O(n*l); Time Complexity: O(n*l)

    // Encodes a list of strings to a single string.
    string encode(const vector<string> &strs)
    {
        string result;
        // Time complexity: number of words
        // Space complexity: O(n*l)
        for (int i = 0; i < strs.size(); i++)
            // for each word, store a combination of the
            // number of characters, encode string, and the word itself
            // this makes it easy to decode later
            result += to_string(strs[i].size()) + string(kEncodeStr) + strs[i];

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string &s)
    {
        vector<string> result;
        string word;
        int i = 0;
        // Time complexity: O(n*l) number of words that were decoded and length of each word
        // Space complexity: O(n) for the result vector
        while (i < s.size())
        {
            string lengthBuffer;
            while (s[i] != kEncodeStr[0] && i < s.size())
            {
                // extract the digits prior to the encoding string
                lengthBuffer += s[i];
                i++;
            }

            // use the length of the word to identify indices of substring for word
            int lengthOfWord = stoi(lengthBuffer); // O(k) -- number of digits of word

            result.push_back(s.substr(i + kEncodeStr.size(), lengthOfWord)); // O(l) length of word
            i += kEncodeStr.size() + lengthOfWord;
        }

        return result;
    }
};
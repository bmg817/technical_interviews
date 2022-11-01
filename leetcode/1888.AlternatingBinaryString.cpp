class Solution
{
public:
    int minFlips(string_view s)
    {
        // 1888. Minimum Number of Flips to Make the Binary String Alternating:
        // https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
        // Time Complexity: O(n)
        // Space Complexity: O(1)

        // Note about methodology:
        // This question is actually asking us to find the minimum number of shared characters the input array
        // has with a leading 0 or a leading 1 alternating binary array. This means there are two target solutions.
        // In addition, we can append values to the end of the vector from the beginning of it.
        // For problems where an array must be analyzed and the starting index can be [0 ... n]
        // oftentimes, you can expand the array so that it wraps around from the beginning to the end.
        // An example can include: [1,1,1,0,0,0] -> [1,1,1,0,0,0,1,1,1,0,0,0]
        // This then can be formulated as sliding window problem solution so that you can check all possibilities
        // of the array combinations starting points.

        // In this problem, we compare the inputted array to a leading zero array.
        // The variable rightIsZero shows the status of the alternating array at any arbitrary index.
        // Looping through the input array [1,1,1,0,0,0], we count the changes required for the entire array
        // to match the leading zero array.
        // Next, we loop through the input array again to inspect the wrap around combinations 
        // (i.e. starting at index i = s.size() in this array > [1,1,1,0,0,0,1,1,1,0,0,0]))
        // In this loop, count the total number of changes needed to match the leading zero array if it were extended outward
        // Then subtract the number of changes needed if it had been changed in the first loop.
        // To find the minimum, we need to find the minimum of:
        // 1) total changes at this iteration, 2) leading 1 array changes at this iteration (by finding the complement calculation)
        // and 3) previous min change values
        // return this min value

        bool rightIsZero = true;
        int countChanges = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if ((rightIsZero && s[i] != '0') || (!rightIsZero && s[i] != '1'))
                countChanges++;

            rightIsZero = !rightIsZero;
        }

        bool leftIsZero = true;
        int minChanges = countChanges;
        for (int i = 0; i < s.size(); i++)
        {
            if (rightIsZero && s[i] != '0' || !rightIsZero && s[i] != '1')
                countChanges++;

            if (leftIsZero && s[i] != '0' || !leftIsZero && s[i] != '1')
                countChanges--;

            int complement = s.size() - countChanges;
            minChanges = min(complement, min(countChanges, minChanges));
            rightIsZero = !rightIsZero;
            leftIsZero = !leftIsZero;
        }

        return minChanges;
    }
};
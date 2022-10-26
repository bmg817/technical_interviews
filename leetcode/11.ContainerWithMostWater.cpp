class Solution
{
public:
    // 11. Container With Most Water: https://leetcode.com/problems/container-with-most-water/submissions/
    // Time complexity: O(n)
    // Space complexity: O(1)

    int maxArea(const vector<int> &height)
    {
        int maxVolume = 0;
        int i = 0;
        int j = height.size() - 1;
        
        // Start with the max distance between i and j.
        // Determine the volume for those given pointer locations
        // Replace maxVolume with the current volume if currVolume > maxVol.
        // Because we're about to make the distance smaller between i and j
        // we want the minimum height value to move inward because we can
        // potentially increase that value.
        // Iterate until i >=j.
        while (i < j)
        {
            // Curr Volume = distance between j and i, multiplied by
            // the minimum height of j and i. Anything greater than min height
            // water will overflow over one edge.
            int currVolume = (j - i) * min(height[i], height[j]);
            maxVolume = max(currVolume, maxVolume);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return maxVolume;
    }
};
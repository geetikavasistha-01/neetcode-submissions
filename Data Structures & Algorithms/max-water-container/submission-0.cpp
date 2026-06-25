class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int maxwater = 0;
        int n = heights.size();
        int i = 0;
        int j = n-1; 

        while( i<j)
        {
            int width = j-i;
            int h = min(heights[i], heights[j]);
            int area = width * h;

            maxwater = max(maxwater, area);
            if(heights[i]>heights[j])
            {
                j--;
            }
            else {
                i++;
            }
        }
        
        return maxwater;
    }
};

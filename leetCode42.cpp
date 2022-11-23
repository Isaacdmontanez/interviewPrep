class Solution {
public:
    int trap(vector<int>& height) {
        int curMax = 0;
        int maxRightHeight[20010];
        for(int curPos = height.size() - 1; curPos > -1; curPos--){
            curMax = max(curMax, height[curPos]);
            maxRightHeight[curPos] = curMax;
        }
        curMax = 0;
        long long int output = 0;
        for(int curPos = 0; curPos < height.size(); curPos++){
            output += max(0, min(curMax, maxRightHeight[curPos]) - height[curPos]);
            curMax = max(curMax, height[curPos]);
        }
        return(output);
    }
};

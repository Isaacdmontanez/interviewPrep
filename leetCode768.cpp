class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> chunckMaxNums = {-1};
        int curPos = 0;
        for(int curNum : arr){
            int curMax = curNum;
            while(curNum < chunckMaxNums[curPos]){
                curMax = max(curMax, chunckMaxNums[curPos]);
                chunckMaxNums.pop_back();
                curPos--;
            }
            chunckMaxNums.push_back(curMax);
            curPos++;
        }
        return(curPos);
    }
};

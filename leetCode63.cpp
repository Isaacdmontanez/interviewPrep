class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return(0);
        }
        int xLength = obstacleGrid.size();
        int yLength = obstacleGrid[0].size();
        long long int output = 0, numsPerSquare[110][110];
        memset(numsPerSquare, 0, sizeof(numsPerSquare));
        bool isPlanned[110][110];
        memset(isPlanned, 0, sizeof(isPlanned));
        numsPerSquare[0][0] = 1;
        vector<int> xStack = {0}, yStack = {0};
        for(int curPos = 0; xStack.size() != curPos; curPos++){
            int xPos = xStack[curPos], yPos = yStack[curPos];
            if(xPos + 1 < xLength && !obstacleGrid[xPos + 1][yPos]){
                if(!isPlanned[xPos + 1][yPos]){
                    xStack.push_back(xPos + 1);
                    yStack.push_back(yPos);
                }
                numsPerSquare[xPos + 1][yPos] += numsPerSquare[xPos][yPos];
                isPlanned[xPos + 1][yPos] = 1;
            }
            if(yPos + 1 < yLength && !obstacleGrid[xPos][yPos + 1]){
                if(!isPlanned[xPos][yPos + 1]){
                    xStack.push_back(xPos);
                    yStack.push_back(yPos + 1);
                }
                numsPerSquare[xPos][yPos + 1] += numsPerSquare[xPos][yPos];
                isPlanned[xPos][yPos + 1] = 1;
            }
        }
        return(numsPerSquare[xLength - 1][yLength - 1]);
    }
};

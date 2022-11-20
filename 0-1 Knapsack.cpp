#include <bits/stdc++.h>
using namespace std;

int main(){
    int vals[10] = {4, 7, 3, 15, 3, 2, 7, 3, 5, 7};
    int size[10] = {1, 3, 5, 7,  3, 2, 4, 2, 3, 1};
    int maxSize = 10;
    int bestVals[10][10];
    memset(bestVals, 0, sizeof(bestVals));
    for(int curValsNum = 0; curValsNum < sizeof(vals) / 4; curValsNum++){
        for(int curSize = 0; curSize < maxSize; curSize++){
            int curBestSize = 0;
            if(curValsNum == 0){
                if(curSize >= size[curValsNum]){
                    curBestSize = vals[curValsNum];
                } else {
                    curBestSize = 0;
                }
            } else if (curSize < size[curValsNum]){
                curBestSize = bestVals[curValsNum - 1][curSize];
            } else {
                curBestSize = max(bestVals[curValsNum - 1][curSize], bestVals[curValsNum - 1][curSize - size[curValsNum]] + vals[curValsNum]);
            }
            bestVals[curValsNum][curSize] = curBestSize;
        }
    }
    cout<<bestVals[sizeof(vals) / 4 - 1][maxSize - 1];
}
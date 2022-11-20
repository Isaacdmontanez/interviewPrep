#include <bits/stdc++.h>
using namespace std;

int getPalindromeSequence(int curDistance, int centerPos, int inputLength, string input){
    int evenAdjust;
    centerPos % 2 ? evenAdjust = 0 : evenAdjust = 1;
    centerPos = centerPos / 2 - evenAdjust;
    curDistance /= 2;
    if(centerPos + curDistance + evenAdjust >= inputLength || centerPos - curDistance < 0){
        return(curDistance * 2);
    }
    while(input.at(centerPos + curDistance + evenAdjust) == input.at(centerPos - curDistance)){
        curDistance++;
        if(centerPos + curDistance + evenAdjust == inputLength || centerPos - curDistance < 0){
            break;
        }
    }
    curDistance = curDistance * 2 - (1 - evenAdjust);
    return(curDistance);
}

int manachers(string input){
    int inputLength = input.length();
    int numOfPositions = inputLength * 2 + 1;
    int maxPalindromeLength[5000];
    int centerPointer = 0, leftPointer = 0, rightPointer = 0;
    int maxPalindromeSize = 0;
    for(int curPosition = 0; curPosition < numOfPositions; curPosition++){
        int curPalindromeSize = 0;
        if(centerPointer - (curPosition - centerPointer) >= 0){
            curPalindromeSize = min(maxPalindromeLength[centerPointer - (curPosition - centerPointer)], centerPointer - leftPointer);
        }
        maxPalindromeLength[curPosition] = getPalindromeSequence(curPalindromeSize, curPosition, inputLength, input);
        if(curPosition + maxPalindromeLength[curPosition] >= rightPointer){
            cout<<"LEFT: "<<leftPointer<<" CENTER: "<<centerPointer<<" RIGHT: "<< rightPointer<<" MAX POSITIONS: "<<numOfPositions<<" CURPOS: "<<curPosition<<" MAX LENGTH: "<<maxPalindromeLength[curPosition]<<"\n";
            rightPointer = min(curPosition + maxPalindromeLength[curPosition], numOfPositions);
            leftPointer = max(curPosition - maxPalindromeLength[curPosition] - 1, 0);
            centerPointer = curPosition;
            
        }
        maxPalindromeSize = max(maxPalindromeSize, maxPalindromeLength[curPosition]);
    }
    return(maxPalindromeSize);
}

int main(){
    string input;
    while(true){
        cin>>input;
        cout<<manachers(input)<<"\n";
    }
}
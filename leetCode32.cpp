class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> isValid;
        vector<int> openPos;
        int curPos = -1, curStop = -1;
        for(auto c:s){
            curPos++;
            if(c=='('){
                openPos.push_back(curPos);
                isValid.push_back(0);
                continue;
            }
            if(!openPos.size()){
                isValid.push_back(0);
                curStop = curPos;
                continue;
            }
            int lastOpen = openPos.back();
            openPos.pop_back();
            if(lastOpen > curStop){
                isValid[lastOpen] = 1;
                isValid.push_back(1);
            } else {
                isValid[lastOpen] = -1;
                isValid.push_back(-1);
                curStop = curPos;
            }
        }
        int curLength = 0, output = 0;
        for(int curPos = 0; curPos < s.length(); curPos++){
            isValid[curPos] ? curLength++ : curLength = 0;
            output = max(output, curLength);
        }
        return(output);
    }
};

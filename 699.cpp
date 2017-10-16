class Solution {
public:
    struct square{
        int front;
        int rear;
        int height;
    };
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<square> ss;
        vector<int> ans;
        int htn=0;
        for(int i=0;i<positions.size();i++){
            square now;
            now.front=positions[i].first;
            now.rear=positions[i].first+positions[i].second;
            now.height=positions[i].second;
            htn=max(htn,helper(ss,now));
            ans.push_back(htn);
        }
        return ans;
    }
    int helper(vector<square>& ss, square now){
        int addheight=0;
        for(int i=0;i<ss.size();i++){
            if(ss[i].front>=now.rear || ss[i].rear<=now.front) continue;
            addheight=max(addheight,ss[i].height);
        }
        now.height+=addheight;
        ss.push_back(now);
        return now.height;
    }
};

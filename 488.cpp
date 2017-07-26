class Solution {
public:
    map<pair<string,string>,int> m;
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        string a;
        int L,r=0;
        for (char c:board) // shrink b to remove consecutive identical letters
            if (c-r) if ((L=a.size()) < 2 || c-a[L-1] || c-a[L-2]) a += c, r = 0;
                    else r = c, a.pop_back(), a.pop_back();
        board=a;
        if(m.count(make_pair(board,hand))>0) return m[make_pair(board,hand)];
        if(board.size()==0) return 0;
        else if(hand.size()==0) return -1;
        string l=board+hand;
        for(int i=0;i<board.size();i++){
            if(count(l.begin(),l.end(),board[i])<3){
                m[make_pair(board,hand)]=-1;
                return -1;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<hand.size();i++){
            if(board.find(hand[i])==string::npos || (i>0 && hand[i]==hand[i-1])) continue;
            for(int j=0;j<board.size();j++){
                if(board[j]!=hand[i] || (board[j]==board[j-1] && j>0)) continue;
                string bb(board); bb.insert(bb.begin() + j, hand[i]);
                string hh(hand); hh.erase(hh.begin() + hh.find(hand[i]));
                int x=findMinStep(bb,hh)+1;
                if(x<ans && x!=0) ans=x;
            }
        }
        if(ans==INT_MAX){
            m[make_pair(board,hand)]=-1;
            return -1;
        }else{
            m[make_pair(board,hand)]=ans;
            return ans;
        }
    }
};

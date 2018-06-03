class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> cs, ct;
        // Process string S
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '#'){
                if(cs.size()) cs.pop();
            }
            else cs.push(S[i]);
        }

        // Process string T
        for(int i = 0; i < T.length(); i++){
            if(T[i] == '#'){
                if(ct.size()) ct.pop();
            }
            else ct.push(T[i]);
        }

        if(cs.size() != ct.size()) return false;
        while(cs.size()){
            //cout << cs.top() << " " << ct.top() << endl;
            if(cs.top() != ct.top()) return false;
            cs.pop();
            ct.pop();
        }
        return true;
    }
};

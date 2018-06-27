class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int prev = 0;
        for(int i = 0; i < S.length(); i++){
            // push left parenthesis back
            if(S[i] == '(' ){
                st.push(-1);
            }else{
                // process right parenthesis
                // cur = 1 for the first pair
                int cur = 1;
                i++;
                // pop the left parenthesis
                st.pop();
                // If last one
                if(i == S.length()){
                    if(st.empty()) return 1;
                    if(st.top() == -1) return 2;
                    else{
                        int ans = 0;
                        while(st.size()){
                            ans += st.top();
                            st.pop();
                        }
                        return ans + 1;
                    }
                }
                // process until no more consecutive right parenthesis
                while(S[i] == ')' && i < S.length()){
                    if(st.top() == -1){
                        cur *= 2;
                        st.pop();
                    }else{
                        while(st.top() != -1){
                            cur += st.top();
                            st.pop();
                        }
                        cur *= 2;
                        st.pop();
                    }
                    i++;
                }
                i--;
                st.push(cur);
                if(i == S.length() - 1){
                    int ans = 0;
                    while(st.size()){
                        ans += st.top();
                        st.pop();
                    }
                    return ans;
                }
            }
        }
    }
};

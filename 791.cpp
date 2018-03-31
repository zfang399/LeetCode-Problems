class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map <char, int> seq;
        seq[S[S.length()-1]] = 1;
        for(int i = S.length()-2; i >= 0; i--){
            seq[S[i]] = seq[S[i+1]] + 1;;
        }

        for(int i = 0; i < T.length() - 1; i++){
            if(!seq[T[i]]) continue;
            for(int j = i + 1; j < T.length(); j++){
                if(!seq[T[j]]) continue;
                if(seq[T[i]] < seq[T[j]]){
                    swap(T[i], T[j]);
                }
            }
        }
        return T;
    }
};

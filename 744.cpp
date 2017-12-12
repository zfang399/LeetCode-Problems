class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;
        bool defined = false;
        char smallest;
        bool sd = false;
        for(int i = 0; i < letters.size(); i++){
            if(letters[i] == target) continue;
            if(letters[i] > target && (letters[i] - target < ans - target || !defined)){
                ans = letters[i];
                defined = true;
                continue;
            }
            if(!sd){
                smallest = letters[i];
                sd = true;
                continue;
            }
            if(smallest > letters[i]){
                smallest = letters[i];
            }
        }
        if(defined) return ans;
        return smallest;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        // Generate string recursively
        while(n > 1){
            n--;
            int cur_num = s[0] - '0';
            int cur_count = 1;
            string t = s;
            s = "";
            for(int i = 1; i < t.length(); i++){
                if(t[i] - '0' == cur_num){
                    // Count
                    cur_count++;
                }else{
                    // Say
                    s += to_string(cur_count) + to_string(cur_num);
                    cur_num = t[i] - '0';
                    cur_count = 1;
                }
            }
            // Say
            s += to_string(cur_count) + to_string(cur_num);
        }
        return s;
    }
};

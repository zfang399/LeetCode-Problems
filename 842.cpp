class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        int l = S.length();
        // Try the combinations of first and second number
        for(int i = 0; i < l/2; i++){
            // Get first number
            string xfirst = S.substr(0,i + 1);
            if(stod(xfirst) > (double)INT_MAX) break;
            //cout << xfirst << endl;
            if(S[i + 1] == '0'){
                string first = xfirst;
                int start = i + 2;
                string second = "0";
                //cout << "   " << second << endl;
                bool finished = false;
                vector <int> posans;
                posans.push_back(stoi(first));
                posans.push_back(stoi(second));
                while(!finished){
                    //cout << "       " << first << " " << second << endl;
                    int len1 = first.length();
                    int len2 = second.length();
                    int carry = 0;
                    int cur = 0;
                    string nextfirst = second;
                    if(len1 < len2){
                        string tmp = first;
                        first = second;
                        second = tmp;
                        int t = len1;
                        len1 = len2;
                        len2 = t;
                    }
                    for(int i = 0; i < len2; i++){
                        cur = second[len2 - 1 - i] - '0' + first[len1 - 1 - i] - '0' + carry;
                        carry = cur / 10;
                        cur %= 10;
                        first[len1 - 1 - i] = '0' + cur;
                        //cout << first << endl;
                    }
                    if(carry != 0){
                        if(len1 == len2){
                            first = "1" + first;
                        }else{
                            int xx = 0;
                            while(carry != 0 && len1 - 1 - len2 - xx >= 0){
                                cur = first[len1 - 1 - len2 - xx] - '0' + carry;
                                carry = cur / 10;
                                cur %= 10;
                                first[len1 - 1 - len2 - xx] = cur + '0';
                            }
                            if(carry != 0){
                                first = "1" + first;
                            }
                        }
                    }
                    //cout << "a       " << first << " " << second << endl;
                    if(stod(first) > (double)INT_MAX) break;
                    if(first.compare(S.substr(start,first.length())) == 0){
                        posans.push_back(stoi(first));
                        start = start + first.length();
                        //cout << start << endl;
                        if(start == S.length()){
                            finished = true;
                        }else{
                            second = first;
                            first = nextfirst;
                        }
                    }else{
                        break;
                    }
                }
                if(finished) return posans;
            }else{
                for(int j = i + 1; j < (l + i + 1)/2; j++){
                    string first = xfirst;
                    int start = j + 1;
                    string second = S.substr(i + 1, j - i);
                    if(stod(second) > (double)INT_MAX) break;
                    cout << "   " << second << endl;
                    bool finished = false;
                    vector <int> posans;
                    posans.push_back(stoi(first));
                    posans.push_back(stoi(second));
                while(!finished){
                    int len1 = first.length();
                    int len2 = second.length();
                    int carry = 0;
                    int cur = 0;
                    string nextfirst = second;
                    if(len1 < len2){
                        string tmp = first;
                        first = second;
                        second = tmp;
                        int t = len1;
                        len1 = len2;
                        len2 = t;
                    }
                    for(int i = 0; i < len2; i++){
                        cur = second[len2 - 1 - i] - '0' + first[len1 - 1 - i] - '0' + carry;
                        carry = cur / 10;
                        cur %= 10;
                        first[len1 - 1 - i] = '0' + cur;
                        //cout << first << endl;
                    }
                    if(carry != 0){
                        if(len1 == len2){
                            first = "1" + first;
                        }else{
                            int xx = 0;
                            while(carry != 0 && len1 - 1 - len2 - xx >= 0){
                                cur = first[len1 - 1 - len2 - xx] - '0' + carry;
                                carry = cur / 10;
                                cur %= 10;
                                first[len1 - 1 - len2 - xx] = cur + '0';
                            }
                            if(carry != 0){
                                first = "1" + first;
                            }
                        }
                    }
                    if(stod(first) > (double)INT_MAX) break;
                    if(first.compare(S.substr(start,first.length())) == 0){
                        posans.push_back(stoi(first));
                        start = start + first.length();
                        //cout << start << endl;
                        if(start == S.length()){
                            finished = true;
                        }else{
                            second = first;
                            first = nextfirst;
                        }
                    }else{
                        break;
                    }
                }
                if(finished) return posans;
                }
            }
        }
        return ans;
    }
};

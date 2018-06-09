class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;

        // Initialize variables
        char c = chars[0];
        int start = 0;
        int count = 0;

        for(int i = 1; i < chars.size(); i++){
            // keep counting if the current streak is not over
            if(chars[i] == c) continue;

            // Calculate the length of the last streak, only process if longer than 1
            count = i - start;
            if(count == 1){
                start = i;
                c = chars[i];
                continue;
            }

            // Modify the string in place
            chars.erase(chars.begin() + start + 1, chars.begin() + i);
            i = start + 1;
            while(count > 0){
                i++;
                chars.insert(chars.begin() + start + 1, '0' + count%10 );
                count /= 10;
            }

            // Update the next "start"
            start = i;
            c = chars[i];
        }

        // Take care of the last streak
        count = chars.size() - start;
        if(count == 1) return chars.size();

        chars.erase(chars.begin() + start + 1, chars.begin() + chars.size());
        while(count > 0){
            chars.insert(chars.begin() + start + 1, '0' + count%10 );
            count /= 10;
        }

        return chars.size();
    }
};

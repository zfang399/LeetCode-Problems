class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // get the maximum distance if he sits leftmost
        int left = 0;
        while(seats[left] == 0){
            left++;
        }

        // get the maximum distance if he sits rightmost
        int right = seats.size() - 1;
        while(seats[right] == 0){
            right--;
        }

        // get the maximum distance if he sits somewhere in the middle
        int midleft = 0;
        int midright = 0;
        for(int i = left; i <= right; i++){
            if(seats[i] == 1) continue;
            int l = i;
            int r = i;
            while(seats[r] == 0 && r < right){
                r++;
            }
            r--;
            if(r - l > midright - midleft){
                midleft = l;
                midright = r;
            }
            i = r;
        }

        // return maximum distance
        return max(left, max(int(seats.size()) - 1 - right, (midright - midleft + 2) / 2));
    }
};

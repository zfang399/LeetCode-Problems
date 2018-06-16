class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        unordered_map<int,int> agecount;

        // Count the number of people of each age
        // Get the minimum and maximum ages
        // The smallest age to send request is 15, because we need age[A] < 0.5 * age[A] + 7
        int minage = 120;
        int maxage = 15;
        for(int i = 0; i < ages.size(); i++){
            agecount[ages[i]]++;
            minage = min(minage, ages[i]);
            maxage = max(maxage, ages[i]);
        }
        minage = max(minage, 15);

        // Loop from minimum age to maximum age
        // First,
        //      calculate the range of age [lowerb, upperb] that the people of age i would send request
        // Second,
        //      loop through [lowerb, upperb] to accumulate the number of requests
        //      If the i == j, the number of requests would be agecount[i] * (agecount[i] - 1)
        //      everyone sending requests to everyone else
        int lowerb = 0;
        int upperb = 0;
        for(int i = minage; i <= maxage; i++){
            lowerb = (i / 2) + 8;
            upperb = i;
            for(int j = lowerb; j < upperb; j++){
                ans += agecount[i] * agecount[j];
            }
            ans += agecount[i] * (agecount[i] - 1);
        }

        return ans;
    }
};

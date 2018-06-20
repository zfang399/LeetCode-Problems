class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Ordred map to save the time left to the target, if not stopped by another car
        map<int,double> tleft;
        for(int i = 0; i < position.size(); i++){
            tleft[target - position[i]] = (double)(target - position[i]) / speed[i];
        }
        // Get numbers of fleets
        // If the next car needs more time than the current fleet head to get to the target
        // The next car would be the head of the next fleet
        int ans = 0;
        double fleethead = 0;
        for(auto e:tleft){
            if(e.second > fleethead){
                fleethead = e.second;
                ans++;
            }
        }
        return ans;
    }
};

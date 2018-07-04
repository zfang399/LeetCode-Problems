class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Special cases
        if(bills.size() == 0) return true;
        if(bills[0] != 5) return false;

        // Number of $5 changes and number of $10 changes
        vector<int> changes(2,0);
        changes[0]++;
        for(int i = 1; i < bills.size(); i++){
            if(bills[i] == 5){
                // Get a $5 bill
                changes[0]++;
            }else{
                if(bills[i] == 10){
                    // Get a $10 bill
                    changes[0]--;
                    changes[1]++;
                    if(changes[0] < 0) return false;
                }else{
                    // Get a $20 bill
                    // Use one $10 and one $5 as change first
                    // If impossible, use three $5 as change
                    if(changes[1] > 0){
                        changes[1]--;
                        changes[0]--;
                        if(changes[0] < 0) return false;
                    }else{
                        changes[0] -= 3;
                        if(changes[0] < 0) return false;
                    }
                }
            }
        }

        return true;
    }
};

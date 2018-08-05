class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int, int> w;
        for(int i = 0; i < people.size(); i++) w[people[i]]++;
        int ans = 0;
        map<int,int>::iterator front = w.begin();
        map<int,int>::iterator rear = w.end();
        rear--;

        // Greedy
        while(front->first < rear->first){
            ans++;
            rear->second--;
            if(front->first + rear->first <= limit) front->second--;
            if(rear->second == 0 ) rear--;
            if(front->second == 0) front++;
        }

        // Deal with the rest
        while(front->second > 0){
            ans++;
            if(front->first * 2 <= limit) front->second-=2;
            else front->second--;
        }
        return ans;
    }
};

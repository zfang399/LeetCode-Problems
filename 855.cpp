class ExamRoom {
public:
    unordered_map<int,bool> seated;
    priority_queue<int, vector<int>, greater<int>> q;
    int roomsize = 0;
    ExamRoom(int N) {
        roomsize = N;
    }

    int seat() {
        // No one in the room
        if(q.empty()){
            seated[0] = true;
            leave(-1);
            return 0;
        }
        // Initialize
        int max_left = 0;
        int max_right = 0;
        int last = q.top();
        q.pop();
        // set maximum distance from the first person to 0
        // this would be -1 if 0 is occupied
        int max_dist = last - 1;
        // If only one person is in the room
        if(q.empty()){
            // check if we are sitting on the leftmost seat #0 or right most seat #roomsize - 1
            int sit = (roomsize - 1 - last - 2) / 2 > (last - 2) / 2 ? roomsize - 1 : 0;
            seated[sit] = true;
            leave(-1);
            return sit;
        }
        // Loop through all seated places, find the maximum distance
        while(q.size()){
            if(q.top() - last == 1){
                last = q.top();
                q.pop();
                continue;
            }
            if((q.top() - last - 2) / 2 > max_dist){
                max_dist = (q.top() - last - 2) / 2;
                max_left = last;
                max_right = q.top();
            }
            last = q.top();
            q.pop();
        }
        // If the rightmost seat is not taken, check if sitting there gives the largest distance
        if(last != roomsize - 1){
            if(roomsize - 2 - last > max_dist){
                max_dist = roomsize - 2 - last;
                max_left = roomsize - 1;
                max_right = roomsize - 1;
            }
        }
        // Set the resulting seat as seated and update
        seated[(max_left + max_right) / 2] = true;
        leave(-1);
        return (max_left + max_right) / 2;
    }

    void leave(int p) {
        // Re-enter all the seated seats
        // leave(-1) means purely update.
        while(q.size()) q.pop();
        if(p != - 1) seated[p] = false;
        for(auto e:seated){
            if(e.second){
                q.push(e.first);
            }
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

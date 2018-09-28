class TopVotedCandidate {
public:
    map<int,int> win_at_t;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int psize = persons.size();
        vector<int> votes(psize, 0);
        int max_votes = 0;
        int max_idx = 0;
        for(int i = 0; i < times.size(); i++){
            votes[persons[i]]++;
            if(votes[persons[i]] >= max_votes){
                max_votes = votes[persons[i]];
                max_idx   = persons[i];
            }
            win_at_t[times[i]] = max_idx;
        }
    }

    int q(int t) {
        map<int,int>::iterator iter;
        iter = win_at_t.upper_bound(t);
        iter--;
        return iter->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */

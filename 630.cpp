class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> a,pair<int,int> b){
            return a.first<b.first;
        }
    };
    static bool comp(vector<int> a, vector<int> b){
        return a.back()<b.back();
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int ans=0;
        sort(courses.begin(),courses.end(),comp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        int now=0;
        for(int i=0;i<courses.size();i++){
            if(now+courses[i].front()<=courses[i].back()){
                q.push(make_pair(courses[i][0],courses[i][1]));
                now+=courses[i].front();
            }else if(q.top().first>courses[i].front()){
                now-=q.top().first;
                q.pop();
                now+=courses[i].front();
                q.push(make_pair(courses[i][0],courses[i][1]));
            }
        }
        return q.size();
    }
};

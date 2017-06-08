class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> common;
        vector <string> ans;
        int minin=99999;
        for(int i=0;i<list1.size();i++) common[list1[i]]+=i+1;
        for(int i=0;i<list2.size();i++)
            if(common.count(list2[i])>0)
                if(common[list2[i]]+i<minin) minin=common[list2[i]]+i;
        for(int i=0;i<list2.size();i++)
            if(common.count(list2[i])>0)
                if(common[list2[i]]+i==minin) ans.push_back(list2[i]);
        return ans;
    }
};

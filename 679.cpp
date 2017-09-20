class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> n;
        n.push_back(double(nums[0]));
        n.push_back(double(nums[1]));
        n.push_back(double(nums[2]));
        n.push_back(double(nums[3]));
        cout<<(1-0.25==0.75)<<endl;
        return four(n);
    }
    bool four(vector<double> nums){
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                vector<double> t;
                double a=nums[i],b=nums[j];
                for(int k=0;k<4;k++){
                    if(k!=i && k!=j) t.push_back(nums[k]);
                }
                t.push_back(a+b);
                if(three(t)) return true;
                t.pop_back();

                t.push_back(a-b);
                if(three(t)) return true;
                t.pop_back();

                t.push_back(b-a);
                if(three(t)) return true;
                t.pop_back();

                t.push_back(a*b);
                if(three(t)) return true;
                t.pop_back();

                if(b!=0){
                    t.push_back(double(a)/double(b));
                    if(three(t)) return true;
                    t.pop_back();
                }

                if(a!=0){
                    t.push_back(double(b)/double(a));
                    if(three(t)) return true;
                    t.pop_back();
                }
            }
        }
        return false;
    }
    bool three(vector<double> nums){
        for(int i=0;i<2;i++){
            for(int j=i+1;j<3;j++){
                vector<double> t;
                double a=nums[i],b=nums[j];
                for(int k=0;k<3;k++){
                    if(k!=i && k!=j) t.push_back(nums[k]);
                }
                t.push_back(a+b);
                if(two(t)) return true;
                t.pop_back();

                t.push_back(a-b);
                if(two(t)) return true;
                t.pop_back();

                t.push_back(b-a);
                if(two(t)) return true;
                t.pop_back();

                t.push_back(a*b);
                if(two(t)) return true;
                t.pop_back();

                if(b!=0){
                    t.push_back(double(a)/double(b));
                    if(two(t)) return true;
                    t.pop_back();
                }

                if(a!=0){
                    t.push_back(double(b)/double(a));
                    if(two(t)) return true;
                    t.pop_back();
                }
            }
        }
        return false;
    }
    bool two(vector<double> nums){
        if(abs(nums[0]+nums[1]-24)<0.001) return true;
        if(abs(abs(nums[0]-nums[1])-24)<0.001) return true;
        if(abs(nums[0]*nums[1]-24)<0.001) return true;
        if(nums[1]==0){
            if(abs(nums[0]-24)<0.001) return true;
        }else if(abs(double(nums[0])/nums[1]-24)<0.001) return true;
        if(nums[0]==0){
            if(abs(nums[1]-24)<0.001) return true;
        }else if(abs(double(nums[1])/nums[0]-24)<0.001) return true;
        return false;
    }
};

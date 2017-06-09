class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int front=0,rear=numbers.size()-1;
        while(front<rear){
            if(numbers[front]+numbers[rear]>target){
                rear--;
            }else if(numbers[front]+numbers[rear]<target){
                front++;
            }else{
                ans.push_back(front+1);
                ans.push_back(rear+1);
                return ans;
            }
        }
    }
};

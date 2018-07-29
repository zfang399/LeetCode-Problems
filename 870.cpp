class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        if(A.size() == 1) return A;

        // Sort vector A
        for(int i = 0; i < A.size() - 1; i++){
            for(int j = i + 1; j < A.size(); j++){
                if(A[j] < A[i]) swap(A[j], A[i]);
            }
        }

        // Binary search
        vector<int> ans;
        for(int i = 0; i < B.size(); i++){
            int front = 0;
            int rear = A.size() - 1;
            if(A[0] > B[i]){
                ans.push_back(A[0]);
                A.erase(A.begin());
                continue;
            }
            if(A[A.size() - 1] <= B[i]){
                ans.push_back(A[0]);
                A.erase(A.begin());
                continue;
            }
            while(front < rear){
                int mid = front + (rear - front)/2;
                if(A[mid] > B[i]){
                    rear = mid;
                }else{
                    front = mid + 1;
                }
            }
            ans.push_back(A[rear]);
            A.erase(A.begin() + rear);
        }

        return ans;
    }
};

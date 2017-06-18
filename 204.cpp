class Solution {
public:
    vector<int> primes;
    int countPrimes(int n) {
        if(n<=2) return 0;
        int ans=1;
        for(int i=3;i<n;i+=2){
            if(isprime(i)){
                ans++;
                primes.push_back(i);
            }
        }
        return ans;
    }
private:
    int isprime(int x){
        for(int i=0;i<primes.size();i++){
            if(primes[i]>sqrt(x)) return true;
            if(x%primes[i]==0) return false;
        }
        return true;
    }
};

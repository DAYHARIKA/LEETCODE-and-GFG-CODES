class Solution {
public:
    int countPrimes(int n) {
        //sieve method
        int cnt=0;
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++){
            if(prime[i]){
                cnt++;
                //mark all multiples of i as not prime
                for(int j=i*2;j<n;j=j+i){
                   prime[j]=false;
                }
            }
        }
        return cnt;
    }
};
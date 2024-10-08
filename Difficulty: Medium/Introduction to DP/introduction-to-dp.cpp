//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int mod=1e9+7;
    long long int solve(int n,vector<long long int>& v){
        if(n == 0 || n == 1){
            return n;
        }
        if(v[n] != -1){
            return v[n];
        }
        v[n]=(solve(n-1,v)+solve(n-2,v))%mod;
        return v[n];
    }
    long long int topDown(int n) {
        // code here
        vector<long long int> v(n+1,-1);
        long long int ans=solve(n,v);
        return ans;
    }
    long long int bottomUp(int n) {
        // code here
        if(n<=1) return n;
        long long int prev =1;
        long long int prev2 = 0;
        for(int i=2;i<n+1;i++){
            long long int fibo=(prev+prev2)%mod;
            prev2=prev;
            prev=fibo;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends
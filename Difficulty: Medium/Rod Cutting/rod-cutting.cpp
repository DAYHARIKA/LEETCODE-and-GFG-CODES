//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int price[],int n,vector<int>& dp){
        
        if(n == 0){
            return 0;
        }
        if(n < 0){
            return INT_MIN;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            
            int ans=solve(price,n-i,dp);
            if(ans != INT_MIN){
                maxi=max(maxi,ans+price[i-1]);
            }
        }
        dp[n]=maxi;
        return dp[n];
    }
    int cutRod(int price[], int n) {
        
        //code here
        vector<int> dp(n+1,-1);
        int ans=solve(price,n,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
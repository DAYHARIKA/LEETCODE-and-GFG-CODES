class Solution {
public:
      
    int maxSizeSlices(vector<int>& slices) {
        
        int n=slices.size();
        vector<vector<int>> dp1(n+2,vector<int>(n,0));
        vector<vector<int>> dp2(n+2,vector<int>(n,0));

        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=n/3;j++){
                int include=slices[i]+dp1[i+2][j-1];
                int exclude=0+dp1[i+1][j];

                dp1[i][j]=max(include,exclude);
            }
        }
        int case1=dp1[0][n/3];
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=n/3;j++){
                int include=slices[i]+dp2[i+2][j-1];
                int exclude=0+dp2[i+1][j];

                dp2[i][j]=max(include,exclude);
            }
        }
        int case2=dp2[1][n/3];
        return max(case1,case2);
    }
};
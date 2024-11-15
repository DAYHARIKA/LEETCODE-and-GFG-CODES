class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        vector<int> curr(n+1,0);
        vector<int> prev(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                int ans=0;
                if(s[i] == rev_s[j]){
                    ans=1+prev[j+1];
                }else{
                    int left=curr[j+1];
                    int right=prev[j];
                    ans=max(left,right);
                }
                curr[j]=ans;

            }
            prev=curr;
        }
        return prev[0];
    }
};
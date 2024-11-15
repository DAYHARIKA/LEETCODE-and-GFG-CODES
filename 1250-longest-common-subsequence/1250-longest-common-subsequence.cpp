class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<int> curr(n2+1,0);
        vector<int> prev(n2+1,0);

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){

                int ans=0;
                if(text1[i] == text2[j]){
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
class Solution {
public:
    
    int minDistance(string word1, string word2) {
        
        int n1=word1.length();
        int n2=word2.length();
        if(n1 == 0){
            return n2;
        }
        if(n2 == 0){
            return n1;
        }
        vector<int> curr(n2+1,0);
        vector<int> next(n2+1,0);
        for(int j=0;j<=n2;j++){
            next[j]=n2-j;
        }

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                curr[n2]=n1-i;
                int ans=0;
                if(word1[i] == word2[j]){
                    ans = next[j+1];
                }else{
                    int ins=1+curr[j+1];
                    int del=1+next[j];
                    int rep=1+next[j+1];
                    ans=min(ins,min(del,rep));
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
};
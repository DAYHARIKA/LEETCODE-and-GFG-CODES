class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {

        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> curr(m+1,0);
        for(int i=n-1;i>=0;i--){
            int prev=0;
         for(int j=m-1;j>=0;j--){
            
          int temp=curr[j];
          int adj=curr[j+1];
          int dia=prev;
          int bot=curr[j];

           if(matrix[i][j] == '1'){
            curr[j]=1+min(adj,min(dia,bot));
            maxi=max(maxi,curr[j]);
           }else{
             curr[j]=0;
           }
           prev=temp;
        }  
       }
        return maxi*maxi;
    }
};
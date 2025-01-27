class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         
         int n=matrix.size();
         int m=matrix[0].size();

         for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){

                int temp1=matrix[i][j];
                int  temp2=matrix[j][i];

                if(temp1 != temp2){
                    matrix[i][j]=temp2;
                    matrix[j][i]=temp1;
                }
            }
         }

         for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
         }

    }
};
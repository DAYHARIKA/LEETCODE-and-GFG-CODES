class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),j;
        for(int i=0;i<matrix.size();i++){
            for( j=0;j<i;j++){
               //swap(matrix[i][j],matrix[j][i]);
               int temp=matrix[i][j];
               matrix[i][j]=matrix[j][i];
               matrix[j][i]=temp;
            } 
        }
        for(int i=0;i<matrix.size();i++){
            for( j=0;j<matrix[i].size()/2;j++){
                  swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<matrix[i].size();j++){
        //         swap(matrix[i][j],matrix[i][n-j-1]);
        //     }
        // }
    }
};
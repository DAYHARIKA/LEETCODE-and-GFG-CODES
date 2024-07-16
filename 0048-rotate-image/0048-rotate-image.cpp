class Solution {
public:
    void reverse(vector<int> &temparr,int n){
        int low=0;
        int high=n-1;
        while(low<high){
            int temp=temparr[low];
            temparr[low]=temparr[high];
            temparr[high]=temp;
            low++;
            high--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //transpose of matrix
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse every row
        for(int i=0;i<n;i++){
           reverse(matrix[i],n);
        }
    }
};
class Solution {
public:
    void next_Smallest(vector<int>& mat,vector<int>& next){
        stack<int> s;
        s.push(-1);
        
        for(int i=mat.size()-1;i>=0;i--){
            int curr=mat[i];
            while(s.top() != -1 && mat[s.top()] >= curr){
                 s.pop();
            }
            next[i]=s.top();
            s.push(i);
        }
    }
    void prev_Smallest(vector<int>& mat,vector<int>& prev){
        stack<int> s;
        s.push(-1);
        for(int i=0;i<mat.size();i++){
            int curr=mat[i];
            while(s.top() != -1 && mat[s.top()] >= curr){
                 s.pop();
            }
            prev[i]=s.top();
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& mat) {
        int n=mat.size();
        vector<int> next(n);
        next_Smallest(mat,next);
        vector<int> prev(n);
        prev_Smallest(mat,prev);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=mat[i];
            if(next[i] == -1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int maxarea=l*b;
            area=max(area,maxarea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int sum;
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            sum=0;
           for(int j=0;j<n;j++){             
              sum=sum+(matrix[j][i]-'0');
              if(matrix[j][i] == '0'){
                sum=0;
              }
              mat[j][i]=sum;
           }
        }
        int maxsum=INT_MIN;
        for(int i=0;i<n;i++){

           int sum=largestRectangleArea(mat[i]);
           maxsum=max(sum,maxsum);

        }
        return maxsum;
    }
};
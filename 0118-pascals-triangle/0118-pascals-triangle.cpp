class Solution {
public:                                                                                      vector<int> generate_rows(int i){
               
            int temp_var=1;
             vector<int> temp;
             temp.push_back(temp_var);
             for(int j=1;j<i;j++){
                temp_var =temp_var*(i-j);
                temp_var=temp_var/j;
                temp.push_back(temp_var);
             }
             return temp;
      }                                                
     vector<vector<int>> generate(int numRows) {
          
          vector<vector<int>> ans;
          for(int i=1;i<=numRows;i++){
             
             ans.push_back(generate_rows(i));
          }
          return ans;
    }
};
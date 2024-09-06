class Solution {
public:
    bool check(char s,char ch){
        
        if((ch == '(' && s != ')') || (ch == '[' && s != ']') ||(ch == '{' && s != '}')){
            return true;
        }else{
            return false;
        }

    }
    bool isValid(string s) {
         
         stack<char> st;
         for(int i=0;i<s.length();i++){

            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else if(st.empty()){
                return false;
            }else{
               if(check(s[i],st.top())){
                return false;
               }else{
                st.pop();
               }
            }
            
         }

         return st.empty();
    }
};
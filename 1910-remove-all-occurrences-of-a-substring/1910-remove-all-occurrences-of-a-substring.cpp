class Solution {
public:
    string removeOccurrences(string s, string part) {
         string temp="";
        for(int i=0;i<s.length();i++){
            temp=temp+s[i];
            if(temp.size()>=part.size()){
               string sb=temp.substr(temp.size()-part.size(),part.size());
               if(sb == part){
                  temp.erase(temp.size()-part.size(),part.size());
               }
            }
        }
        return temp;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
         int hash[256];
         int l=0,r=0,minlen=INT_MAX,startindex=-1,cnt=0;
         for(int i=0;i<t.length();i++){
            hash[t[i]]++;
         }
         while(r<s.length()){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt == t.length()){
                if(r-l+1 < minlen){
                    minlen=r-l+1;
                    startindex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
         }
         return (startindex == -1)?"":s.substr(startindex,minlen);
    }
};
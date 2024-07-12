class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 1){
            return chars.size();
        }
        int count=1;
        int index=0;
        int n=chars.size();
        for(int i=1;i<=n;i++){

            if(i<n && chars[i] == chars[i-1]){
              count++;
            }else{
                chars[index]=chars[i-1];
                index++;
                if(count > 1){
                    string ch=to_string(count);
                    for(auto it:ch){
                        chars[index]=it;
                        index++;
                    }
                }
                count=1;
            }
        }
        return index;
    }
};
class Solution {
public:
    bool compstrings(int arr1[26],int arr2[26]){
        for(int i=0;i<26;i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            count1[index]++;
        }
        int count2[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s2[i]-'a';
            count2[index]++;
        }
        if(compstrings(count1,count2)){
            return true;
        }
        for(int i=s1.length();i<s2.length();i++){
             
             char cnew=s2[i];
             int index=cnew-'a';
             count2[index]++;

             char old=s2[i-s1.length()];
             index=old-'a';
             count2[index]--;

             if(compstrings(count1,count2)){
                return true;
             }
        }
        return false;
    }
};
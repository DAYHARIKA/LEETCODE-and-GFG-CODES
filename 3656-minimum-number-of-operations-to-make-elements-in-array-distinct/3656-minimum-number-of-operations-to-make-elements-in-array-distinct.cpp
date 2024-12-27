class Solution {
public:
    bool unique(unordered_map<int,int> &mp){

        for(auto it:mp){
            if(it.second > 1){
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {

        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int min_operations=0;
        int index=0;
        while(!mp.empty() && !unique(mp)){

            min_operations++;
            /*if(mp.size() < 3){
                mp.clear();
                break;
            }*/
            int cnt=0;
            while(cnt != 3 && index<nums.size()){
                if(mp[nums[index]] == 1){
                    mp.erase(nums[index]);
                }
                mp[nums[index]]--;
                index++;
                cnt++;
            }
        }
        return min_operations;
    }
};
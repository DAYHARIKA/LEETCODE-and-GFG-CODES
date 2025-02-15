class Solution {
public:
    int finding_days(vector<int>& weights,int cap,int days){

        int day=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){

            if(weights[i]+sum > cap){
                day++;
                sum=weights[i];
            }else{
                sum += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low <= high){
            int mid=(low+high)/2;
            int no_days=finding_days(weights,mid,days);
            if(no_days <= days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
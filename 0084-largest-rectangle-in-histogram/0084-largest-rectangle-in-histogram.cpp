class Solution {
public:
    void next_Smallest(vector<int>& heights,vector<int>& next){
        stack<int> s;
        s.push(-1);
        
        for(int i=heights.size()-1;i>=0;i--){
            int curr=heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr){
                 s.pop();
            }
            next[i]=s.top();
            s.push(i);
        }
    }
    void prev_Smallest(vector<int>& heights,vector<int>& prev){
        stack<int> s;
        s.push(-1);
        for(int i=0;i<heights.size();i++){
            int curr=heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr){
                 s.pop();
            }
            prev[i]=s.top();
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next_Smallest(heights,next);
        vector<int> prev(n);
        prev_Smallest(heights,prev);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i] == -1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int maxarea=l*b;
            area=max(area,maxarea);
        }
        return area;
    }
};
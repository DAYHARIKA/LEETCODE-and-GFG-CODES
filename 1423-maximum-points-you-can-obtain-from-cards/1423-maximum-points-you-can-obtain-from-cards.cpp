class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxsum = 0, leftsum = 0, rightsum = 0;
        for (int i = 0; i < k; i++) {
            leftsum = leftsum + cardPoints[i];
        }
        maxsum = max(maxsum, leftsum);
        if (k == n) {
            return maxsum;
        }
        int j = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            leftsum = leftsum - cardPoints[i];
            rightsum = rightsum + cardPoints[j];
            maxsum=max(maxsum,rightsum+leftsum);
            j--;
        }
        return maxsum;
    }
};
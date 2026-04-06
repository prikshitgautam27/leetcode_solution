1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int minp=INT_MAX;
5        int maxpro=0;
6        int n=prices.size();
7        for(int i=0;i<n;i++){
8            minp=min(minp,prices[i]);
9            maxpro=max(maxpro,prices[i]-minp);
10        }
11        return maxpro;
12    }
13};
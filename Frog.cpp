// frog jumps from one step to another it may be one or two based upon the energy of the steps difference between and return the smallest energy required

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int frog(vector<int>& heights, int ind,vector<int> & dp){
        if(ind == 0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int left = frog(heights,ind-1,dp)+abs(heights[ind]-heights[ind-1]);
        int right = INT_MAX;
        if(ind>1){
            right =frog(heights,ind-2,dp)+abs(heights[ind]-heights[ind-2]);
        }
        return dp[ind]=min(left,right);
    }
};
int main(){
    int n = 5;
    vector<int> arr ={30,10,60,10,60,50};
    Solution sol;
    vector<int> dp(n+1,-1) ;
    int res = sol.frog(arr,n,dp);
    cout << res<<" ";

}
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool fun(int n, int target, vector<int> &arr,vector<vector<int>> &dp) {
            if (target == 0) return true;
            if (n < 0) return false;
            if(dp[n][target]!=-1) return dp[n][target];
            bool take = false;
            if (arr[n] <= target) {
                take = fun(n-1, target-arr[n], arr,dp);
            }
            bool notTake = fun(n-1, target, arr,dp);
            return dp[n][target]= take || notTake;
        }
        bool SubsequenceSum(vector<int> &arr,int target){
            int n = arr.size();
            // dp[i][t] => using indices [0..i], can we make sum t? -1=unknown, 0=false, 1=true
            vector<vector<int>> dp(n, vector<int>(target+1, -1));
            return  fun(n-1,target,arr,dp);

        }
};

int main(){
    Solution sol;
    vector<int> arr;
    int input;
    while(cin>>input && input!=-1){
        arr.push_back(input);
    }
    bool ans = sol.SubsequenceSum(arr,11);
    cout << ans <<endl;
}
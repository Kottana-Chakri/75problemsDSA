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
    int s=0;
    for(int each : arr){
        s+=each;
    }
    bool ans;
    if(s%2==0){
        ans = sol.SubsequenceSum(arr,s/2);
    }
    else{
        ans = false;
    }
    cout << ans <<endl;
}
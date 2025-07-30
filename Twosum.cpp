#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> twosum(vector<int> & arr, int target){
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            int remain = target-arr[i];
            if(mpp.find(remain)!=mpp.end()){
                return {mpp[remain],i};// both are indices
                break;
            }
            mpp[arr[i]]=i;// here store values with indices
        }
        return{};

    }
};
    
int main(){
    int n;
    vector<int> a;
    while(cin >> n && n !=-1){
        a.push_back(n);
    }
    cout << "target to search :";
    int target;
    cin >> target;
    Solution sol;
    vector<int> result = sol.twosum(a, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " and " << result[1] << "\n";
        cout << "Values: " << a[result[0]] << " + " << a[result[1]] << " = " << target << "\n";
    } else {
        cout << "No two elements found that sum to target.\n";
    }
    return 0;
}
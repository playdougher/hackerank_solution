#include <bits/stdc++.h>
using namespace std;

int maxSubsetSum(vector<int> arr) {
    int dp[arr.size()];
    dp[0]=max(0,arr[0]);
    if(arr.size()>1){
        dp[1]=max(dp[0],arr[1]);
    }
    for(int i=2;i<arr.size();i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    return dp[arr.size()-1];
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << maxSubsetSum(arr);
    return 0;
}


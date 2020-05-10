#include <bits/stdc++.h>
using namespace std;
int pairs(int k, vector<int> arr){
    unordered_set<int> arr_set;
    int ans = 0;
    for(auto t:arr){
        arr_set.insert(t);
    }
    for(auto t:arr_set){
        if(arr_set.count(t+k)) ans++;
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int i = 0;
    while(n--){
        cin >> arr[i++];
    }
    n = i;

    int ans = pairs(k, arr);
    cout << ans;

    return 0;
}


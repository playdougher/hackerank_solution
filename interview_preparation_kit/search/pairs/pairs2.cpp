#include <bits/stdc++.h>
using namespace std;
int pairs(int k, vector<int> arr){
    sort(arr.begin(), arr.end());
    int l = 0;
    int r = 1;
    int ans = 0;
    while(r < arr.size()){
        int abso = abs(arr[l] - arr[r]);
        while(l<r && abso > k){
            l++;
        }
        while(r<arr.size() && abso < k){
            r++;
        }
        if(abso == k){
            ans++;
            l++;
            r++;
        }
    }
    return ans;
}
    

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr[n];
    int i = 0;
    while(n--){
        cin >> arr[i++];
    }
    n = i;
    
    cout << pairs(k, arr);

    return 0;
}

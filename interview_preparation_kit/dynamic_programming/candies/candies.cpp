#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> candies(n);
    candies[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]){
            candies[i] = candies[i-1]+1;
        }
        else candies[i] = 1;
    }
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            candies[i] = max(candies[i], candies[i+1]+1);
        }
    }
    cout << accumulate(candies.begin(), candies.end(), long(0));
    return 0;
}


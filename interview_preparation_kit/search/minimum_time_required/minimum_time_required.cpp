#include <bits/stdc++.h>
using namespace std;
long minTime(vector<long> machines, long goal){
    long l = 0;
    long r = 1e14; //1e9 x 1e5 : machines[i] x n
    long mid = (l+r)/2;
    long ret = mid;
    while(l <= r){
        mid = (l+r)/2;

        int full = 0; //忘初始化
        for(int i = 0; i < machines.size(); i++){
            full += mid/machines[i];
            if(full >= goal) break;
        }

        if(full >= goal){
            r = mid-1;
            ret = mid;
        }
        else{
            l = mid+1;
        }
    }
    return ret;
}

int main(){
    int n, goal;
    cin >> n >> goal;
    vector<long> machines(n);
    for(int i=0; i<n; i++){
        cin >> machines[i];
    }
    cout << minTime(machines, goal);
    return 0;
}


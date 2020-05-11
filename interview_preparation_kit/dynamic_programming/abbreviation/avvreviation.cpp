#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp(int a_j, int b_i){
    if(b_i == -1) return 1;
    while(a_j < a.size() and a[a_j] != b[b_i]){
        a_j--;
    }
    if(a_j == -1) return 0;
    else{
        b_i--;
        dp(b_i, a_j);
    }
}

int main(){
    int q;
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(dp(a.size()-1, b.size()-1)) cout<<  "YES";
        else cout <<  "NO";
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

char upcase(char c){
    if (isupper(c)) return c;
    return (char)(c - 32);
}

int dp[1001][1001];

int main() {
    int q;
    cin >> q;

    while(q--) {
        string a, b;
        cin >> a;
        cin >> b;

        dp[0][0] = 1;
        for(int i = 1; i <= a.size(); i++) {
            for(int j = 1; j <= b.size(); j++) {
                dp[i][j] = 0;
            }
        }

        for(int j = 0;  j <= b.size(); j++){// <=, j==b.size()后, i还要继续往下判断, 若是大写字母, 为0. e.g. a="ABCDEFG", b="ABC"
            for (int i = 0;  i<a.size(); i++){
                if(dp[i][j]){
                    if(j < b.size() && (upcase(a[i]) == b[j])){ // prevent j == b.size()
                        dp[i + 1][j + 1] = 1;
                        //cout << "i+1:" << i+1 << " j+1:"  << j+1 << " dp[i + 1][j + 1]: " <<dp[i + 1][j + 1] << endl;
                    }
                    if(islower(a[i])){
                        dp[i + 1][j] = 1;
                        //cout << "i+1:" << i+1 << " j:"  << j << " dp[i + 1][j]: " <<dp[i + 1][j] << endl;
                    }
                    //cout << endl;
                }
            }
        }
        if(dp[a.size()][b.size()]) cout << "YES" << endl;
        else cout <<"NO" <<endl;
    }
}


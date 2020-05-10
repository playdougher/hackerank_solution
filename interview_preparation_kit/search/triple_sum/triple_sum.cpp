#include <bits/stdc++.h>
using namespace std;
long triplets(vector<int> a, vector<int> b, vector<int> c){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    int b_i = 0;
    long ans = 0;
    while(b_i < b.size()){
        long a_cnt = 0; // [x] int
        long c_cnt = 0;
        a_cnt = upper_bound(a.begin(), a.end(), b[b_i]) - a.begin();
        c_cnt = upper_bound(c.begin(), c.end(), b[b_i]) - c.begin();
        ans += a_cnt * c_cnt;
        b_i++;
    }
    return ans;
}

int main(){
    int lena,lenb,lenc;
    cin >> lena >> lenb >> lenc ;
    vector<int> a(lena), b(lenb), c(lenc);

    int elem;
    for(int i=0; i<lena; i++) cin >> a[i];
    for(int i=0; i<lenb; i++) cin >> b[i];
    for(int i=0; i<lenc; i++) cin >> c[i];

    cout << triplets(a, b, c);

    return 0;
}


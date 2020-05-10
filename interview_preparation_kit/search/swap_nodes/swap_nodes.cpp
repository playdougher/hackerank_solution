#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */
#define MAXN 1024
int l[MAXN], r[MAXN]; // l[i] : i 's left child
int d[MAXN]; //depth
void cal_depth(int i, int depth){ // i: current node
    d[i] = depth;
    if(l[i] > 0) cal_depth(l[i], depth+1);
    if(r[i] > 0) cal_depth(r[i], depth+1);
}

void inorder(int i){ //i: current node
    if(l[i] > 0) inorder(l[i]);
    cout << i << ' ';
    if(r[i] > 0) inorder(r[i]);
}

int main(){
    int n, t;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    cal_depth(1,1);
    cin >> t;
    int k;
    while(t--){
        cin >> k;
        for(int i = 1; i <= n; i++){
            if(d[i]%k == 0){
                swap(l[i],r[i]);
            }
        }
        inorder(1);
        cout << endl;
    }
}


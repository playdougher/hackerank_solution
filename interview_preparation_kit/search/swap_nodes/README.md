# Swap Nodes [Algo]

[题目](https://www.hackerrank.com/challenges/swap-nodes-algo/problem)  

**输入格式：**  
n: 表示有n个值大于0的节点(输入n组孩子)
a,b: a, b为节点的值, 若为空,值为-1
t: t个k
k: 深度为[k, 2k, 3k,...]的节点进行swap操作

## Solution

**实现思路**  
设置 int l[MAXN], r[MAXN]; // l[i] : i 's left child
设置 int d[MAXN]; //depth
进行交换操作时直接swap(l[i], r[i]), 将i的左右子树互换. 

**实现方式**  
```c
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
```

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Complete the arrayManipulation function below.
// 数组须是long long型，因为最大值可能为8字节大小。
int main()
{

    int N,M;
    int a, b, k;
    cin >> N >> M;

    long long *arr = new long long[N+1]();

    while (M--) {
        cin >> a >> b >> k;
        arr[a] += k;
        if ((b+1)<=N) arr[b+1] -= k; //(b+1)
    }

    long long max = 0, sum = 0; 
    for(int i = 1; i < N+1; i++){ 
        sum += arr[i];
        if(max < sum) max = sum;
    }
    cout << max << endl;

    return 0;
}



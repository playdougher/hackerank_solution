#include<bits/stdc++.h>
using namespace std;

int a[100001];
bool visited[100001];

int solve(int n)
{
    int idx[n+1] = {0};

    for (int i = 0; i < n; i++){
        idx[a[i]]=i;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || a[i]==i+1 )
            continue;

        int cycle_size = 0;
        int j = i;

        //Counting the size of the cycle
        while (!visited[j])
        {
            visited[j] = 1;
            j = idx[j+1]; //
            cycle_size++;
        }

        ans += (cycle_size - 1);
    }

    return ans;

}

int main()
{

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = solve(n);
    printf("%d\n", ans);
    return 0;

}


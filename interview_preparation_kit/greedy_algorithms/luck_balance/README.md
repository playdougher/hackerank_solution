# Luck Balance

[题目](https://www.hackerrank.com/challenges/luck-balance/problem)  
题目要求最大luck. luck通过输比赛获得. 赢了会浪费luck.  
同时提供一个k值, T[i]为1的比赛可以有k个让它输. 其他为1只能赢.  
T[i]为0的都算作输

## Solution

**注意点**  
保证size_t不小于0:  
if(arr.size() > k) //[x] (arr.size()-k) > 0, 会是很大的正数, 因为size_t只能是正数

**实现方式**  
```c
int luckBalance(int k, vector<vector<int>> contests) {
    int ans = 0;
    vector<int> arr;
    for(auto &t: contests){
        int luck = t[0];
        int import = t[1];

        if(import == 0) ans += luck;
        else arr.push_back(luck);
    }
    sort(arr.begin(), arr.end());

    int i=0;

    /*
    if((arr.size()-k) > 0){
        cout << arr.size()-k << endl;
    }
    */
    if(arr.size() > k){ //[x] (arr.size()-k) > 0, 会是很大的正数, 因为size_t只能是正数
        for(; i < arr.size()-k; i++){
            ans -= arr[i];
        }
    }

    for(; i < arr.size(); i++){
        ans += arr[i];
    }
    return ans;
}
```

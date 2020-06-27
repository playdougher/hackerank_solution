# Poisonous Plants

[题目](https://www.hackerrank.com/challenges/poisonous-plants/problem)  
 
**实现思路**

法一：O(n):T(n^2)  
每一天都遍历一遍数组，去除死去的植物。

法二：O(n):T(n logn)  
法一中有些重复遍历的情况，经过优化，发现死去植物的附近的植物，才可能发生死亡。  
所以每一天需记录活着的植物 alive ，将死的植物 going_to_die，以及  
下一天会死亡的植物 next_to_die （用于优化法一的方法，即下一天只有上一天死亡的植物附近的植物才会死亡。）,使用二分查找寻找死亡植物的附近植物。  

法三： T(n)  
设一个栈，存放的值为`<毒性，死亡天数>`。  
* 我们可以从头开始遍历。用一个栈保存递增序列：
    * 若当前毒性小于等于栈顶元素：
        * 不断弹出元素，且保存它们天数的最大值max_day。
            * 若栈为空
                * 当前元素不可能死亡
            * 否则
                * 前面有比自己毒性小的植物，当前植物会死亡，压入当前毒性和max_day+1;
    * 否则
        * 第一天就会死, 压入毒性和1

**实现方式**  

1. 法二：O(n):T(n logn)  

```c
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

set<int> alive, going_to_die, next_to_die;
int height[MAX+1];
const int inf = 1000000000;

int main(){
    int i;
    int n,day=0;

    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &height[i]);
    }
    height[0] = inf;

    //initiate set "alive" and set set "going_to_die"
    for(i=1; i<=n; i++){
        alive.insert(i);
        if(height[i] > height[i-1]) going_to_die.insert(i);
    }

    while(going_to_die.size()){
        day++;

        for(auto x:going_to_die){
            alive.erase(x);
        }

        next_to_die.clear();

        // next_to_die
        for(auto x:going_to_die){
            auto itr = alive.lower_bound(x);
            if(itr == alive.begin() || itr == alive.end()) continue;

            auto previous = itr;
            previous--;

            if(height[*itr] > height[*previous]) next_to_die.insert(*itr);
        }

        going_to_die = next_to_die;
    }
    printf("%d\n", day);
    return 0;
}

```

2. 法三： T(n)  

```c

#include <bits/stdc++.h>
using namespace std;

#define MAX 100005


typedef struct plant_info{
    int poison;
    int day;
}plant_info;

void printstk(stack<plant_info> stk){
    while(!stk.empty()){
        cout << stk.top().poison << ' ' << stk.top().day << endl;
        stk.pop();
    }
}

int main(){
    int q;
    cin >> q;
    if(q <= 0){
        cout << "0" << endl;
        return 0;
    }

    vector<int> plants(q);
    int i = 0;
    while(q--){
        cin >> plants[i++];
    }
    
    int maxi = 0;
    stack<plant_info> stk;
    stk.push({plants[0], 0});
    i = 1;


    int stk_max_day = 0;
    while(i < plants.size() and !stk.empty()){
        //printstk(stk);
        //cout << endl;
        stk_max_day = 0;

        if(plants[i] > stk.top().poison){
            stk.push({plants[i],1});
            maxi = max(maxi, 1);
        }
        else{
            while(!stk.empty() and plants[i] <= stk.top().poison){
                int top_day = stk.top().day;
                stk_max_day = max(stk_max_day, top_day);

                stk.pop();
            }
            if(stk.empty()) {
                stk.push({plants[i], 0});
            }
            else {
                stk.push({plants[i], stk_max_day+1});
                maxi = max(maxi, stk_max_day+1);
            }
        }

        i++;
    }
    
    cout << maxi << endl;
    return 0;
}
```

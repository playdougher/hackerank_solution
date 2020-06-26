# Poisonous Plants

[题目](https://www.hackerrank.com/challenges/poisonous-plants/problem)  
 
**实现思路**

法一：O(n):T(n^2)  
每一天都遍历一遍数组，去除死去的植物。

法二：O(n):T(n logn)  
法一中有些重复遍历的情况，经过优化，发现死去植物的附近的植物，才可能发生死亡。  
所以每一天需记录活着的植物 alive ，将死的植物 going_to_die，以及  
下一天会死亡的植物 next_to_die （用于优化法一的方法，即下一天只有上一天死亡的植物附近的植物才会死亡。）,使用二分查找寻找死亡植物的附近植物。  

**实现方式**  

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

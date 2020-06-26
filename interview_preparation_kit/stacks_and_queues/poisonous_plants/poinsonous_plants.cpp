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




#include <bits/stdc++.h>
using namespace std;
/*
 * T(n)
 */

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

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// 要计算插队次数的最小值，只需从最大值开始，计算每个值回退到原来位置所需的步数。
//idx[] : q数组的数组元素作为下标，idx的值为数组元素的索引。q数组索引从0计算。
//
// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    vector<int> idx(q.size()+1);
    int i = 0;
    for (int elem:q) {
        idx[elem] = i++;
    }

    int count = 0;
    for (int val = q.size(); val > 0; --val) {
        int step = val-1-idx[val];
        if(!step) continue;
        if (step > 2) {
            cout << "Too chaotic\n";
            return;
        }
        //范围：(当前索引值, 其值最终所在位置]，即(idx[val],val-1]
        //j为元素val在q中的下标，他需要往队后(增大方向)移动到他原来排的位置。
        for(int j = idx[val]+1; j < val; ++j){
            --idx[q[j]];
            q[j-1] = q[j];
        }
        count += step;
    }
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


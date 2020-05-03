#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    vector<int> count_arr(200);
    int ev_od_f = 0;
    ev_od_f = d%2 ; // odd: 1; even: 0;

    int notif_num = 0;
    for(int i = 0; i+d <= expenditure.size(); i++){ //ji i+d
        //五个数字
        for(int j = i;  j < i+d; j++){
            count_arr[expenditure[j]]++;
        }

        //奇偶
            //找到中位数
        int center = 0;
        int center_num = 0;
        if(ev_od_f){//odd
            center_num = d/2+1;
            for(int j = 0; j < 200; j++){
                if( center_num >= count_arr[j]){
                    center_num -= count_arr[j];
                    center = 2*count_arr[j]; //
                }
                else break;
            }
        }
        else{//even
            center_num = d/2;
            for(int j = 0; j < 200; j++){
                if(center_num >= count_arr[j]{
                    center_num -= count_arr[j];
                    center = count_arr[j];
                }
                else{
                    center += count_arr[j];
                    break;
                }
            }
        }

        //比较
        if(expenditure[i+d] >= center){
            notif_num++;
        }
    }
    return notif_num;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

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


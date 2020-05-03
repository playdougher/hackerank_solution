#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int ev_od_f = d%2;// odd: 1; even: 0;
    int notif_num = 0;
    vector<int> count_arr(201); // position 201 for element "200"

    for(int i = 0;  i < d-1; i++){ // initiate the first d-1 elements.
        count_arr[expenditure[i]]++;
    }

    for(int i = 0; i+d-1 < expenditure.size(); i++){ //ji i+d-1
        count_arr[expenditure[i+d-1]]++; //increase the count of last element.

        int median = 0;
        int half_d = d/2; // half of d
        if(ev_od_f) ++half_d;

        int j = 0;
        for(; j < 200; j++){
            half_d -= count_arr[j]; 
            if(half_d <= 0) break;
        }

        // 偶 && 计数末尾
        if(half_d == 0 && !ev_od_f) median = j+j+1; 
        else median = 2*j;

        if(expenditure[i+d] >= median) notif_num++; 
        count_arr[expenditure[i]]--; // decrease the count of first element
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


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countInversions function below.
long swap_num;
void Merge_sort(vector<int> &arr, int l, int r){
    if(l == r) return;

    int mid = (l+r)/2;
    Merge_sort(arr, l, mid);
    Merge_sort(arr, mid+1, r);

    vector<int> tmp_arr;
    int i = l;
    int j=mid+1;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]) tmp_arr.push_back(arr[i++]);
        else {
            tmp_arr.push_back(arr[j++]);
            swap_num += (mid+1 - i);
        }
    }

    while(j <=r) tmp_arr.push_back(arr[j++]);
    while (i <= mid) tmp_arr.push_back(arr[i++]);

    i = l;
    for(auto t:tmp_arr) arr[i++] = t;
}
// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    swap_num = 0; //initiate;
    Merge_sort(arr, 0, arr.size()-1);
    return swap_num;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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

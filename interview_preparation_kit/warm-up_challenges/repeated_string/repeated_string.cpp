#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
//
long repeatedString(string s, long n) {
    int size = s.size();
    int arr[size] ={0};

    int count = 0;
    for(int i = 0; i < size; i++){
        if(s[i] == 'a') ++count;
        arr[i] = count;
    }
    long result = count * (n/size) + arr[n%size-1];
    return result;
}

int main()
{
    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    cout << result << "\n";

    return 0;
}


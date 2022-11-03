#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> split(string s, string delimiter) {
    vector<string> v;
    long long pos1 = 0;

    for (long long i = 0; i < count(s.begin(), s.end(), delimiter.at(0))+1; ++i)
    {
        
        long long pos2 = s.find(delimiter, pos1);
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2+1;
    }

    return(v);
}

long long sum(vector<long long> list) {
    long long c = 0;
    for (long long i = 0; i < list.size(); ++i)
    {
        c += list[i];
    }
    return(c);
}

long long findIndex(vector<long long> v, long long num) {
    return(distance(v.begin(), find(v.begin(), v.end(), num)));
}

void sortString(string &str)
{
   sort(str.begin(), str.end());
   cout << str;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<vector<string>> input;
    int inputSize = 1;
    int count = 0;
    for (int i = 0; i < inputSize; ++i)
    {

        vector<string> temp;
        for (int i = 0; i < 10; ++i)
        {
            string a;
            cin >> a;
            temp.push_back(a);
        }
        string c;
        cin >> c;
        for (int i = 0; i < 4; ++i)
        {
            string b;
            cin >> b;
            int ree = b.length();
            if ((ree == 2) ||(ree == 3) ||(ree == 4) ||(ree == 7)) {
                count++;
            }
            temp.push_back(b);
        }
    }
    cout << count;

}

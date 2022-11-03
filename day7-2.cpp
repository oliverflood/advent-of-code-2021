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

long long findLowest(vector<long long> v) {
    long long ans = v[0];
    for (long long i = 1; i < v.size(); ++i)
    {
        if (v[i] < ans) {
            ans = v[i];
        }
    }
    return(ans);
}

long long findHighest(vector<long long> v) {
    long long ans = v[0];
    for (long long i = 1; i < v.size(); ++i)
    {
        if (v[i] > ans) {
            ans = v[i];
        }
    }
    return(ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    vector<string> input;
    vector<long long> crabs;
    cin >> s;
    input = split(s, ",");

    for (long long i = 0; i < input.size(); ++i)
    {
        crabs.push_back(stol(input[i]));
    }

    // for (int i = 0; i < crabs.size(); ++i)
    // {
    //     cout << crabs[i] << " ";
    // }

    //cout << findHighest(crabs);
    vector<long long> fuels; // try long
    cout << findHighest(crabs);
    long long e = 0;
    long long n = 0;
    for (long long i = 0; i < findHighest(crabs)+1; ++i)
    {
        for (long long k = 0; k < crabs.size(); ++k)
        {
            e = abs(i-crabs[k]);
            n += (pow(abs(i-crabs[k]),2)+abs(i-crabs[k]))/2;
            e = 0;
        }
        fuels.push_back(n);
        //cout << n << endl;
        n = 0;
    }
    cout << endl << findLowest(fuels);
    cout << endl << endl << endl;
    e = abs(2-5);
    cout << (pow(e,2)+e)/2;
    cout << endl << endl;
    for (int i = 0; i < fuels.size(); ++i)
    {
        cout << fuels[i] << endl;
        if (fuels[i] == 87640208) {
            cout << "^" << endl;
        }
    }

}

//87470545 nope
//87640208
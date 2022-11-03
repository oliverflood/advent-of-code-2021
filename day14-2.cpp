#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int findLowest(vector<int> v) {
    int ans = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] < ans) {
            ans = v[i];
        }
    }
    return(ans);
}

int findHighest(vector<int> v) {
    int ans = v[0];
    for (int i = 1; i < v.size(); ++i)
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
    
    int size = 100;

    string p;
    cin >> p;

    map<string, vector<string>> rules;
    map<string, long long> counts;
    map<string, long long> letterCounts;
    vector<string> stuff;
    vector<string> poly;


    for (int i = 0; i < size; ++i)
    {
        string a, b, c;
        cin >> a >> b >> c;
        vector<string> t;
        t.push_back(a.substr(0,1)+c);
        t.push_back(c+a.substr(1,1));
        rules.insert({a,t});
        stuff.push_back(a);
        poly.push_back(a.substr(0,1));
        poly.push_back(a.substr(1,1));
        poly.push_back(c);
    }

    for (int i = 0; i < p.length()-1; ++i)
    {
        cout << p.substr(i,2) << endl;
        counts[p.substr(i,2)] += 1;
    }
    cout << "here: " << endl;
    for (int i = 0; i < stuff.size(); ++i)
    {
        if (counts[stuff[i]] > 0) {
            cout << stuff[i] << endl;
        }
    }


    cout << endl << endl;

    for (int k = 0; k < 40; ++k)
    {
        map<string, long long> counts2 = counts;
        for (int i = 0; i < stuff.size(); ++i)
        {
            long long reet = counts[stuff[i]];
            
            if (counts[stuff[i]] > 0) {
                // cout << rules[stuff[i]][0] << endl;
                // cout << rules[stuff[i]][1] << endl;
                counts2[rules[stuff[i]][0]] += reet;
                counts2[rules[stuff[i]][1]] += reet;
                counts2[stuff[i]] -= reet;
            }
        }
        counts.clear();
        counts = counts2;
    }

    cout << endl << endl;

    // for (int i = 0; i < stuff.size(); ++i)
    // {
    //     if (counts[stuff[i]] > 0) {
    //         cout << stuff[i] << endl;
    //     }
    // }




    for (int i = 0; i < p.length(); ++i)
    {
        poly.push_back(p.substr(i, 1));
    }

    set<string> temp1(poly.begin(), poly.end());
    vector<string> types(temp1.begin(), temp1.end());

    for (int i = 0; i < types.size(); ++i)
    {
        letterCounts.insert({types[i], 0});
    }

    for (int i = 0; i < stuff.size(); ++i)
    {
        letterCounts[stuff[i].substr(0,1)] += counts[stuff[i]];
        letterCounts[stuff[i].substr(1,1)] += counts[stuff[i]];
    }
    letterCounts[p.substr(0,1)] += 1;
    letterCounts[p.substr(p.length()-1,1)] += 1;

    for (int i = 0; i < types.size(); ++i)
    {
        cout << letterCounts[types[i]]/2 << endl;
    }
    cout << endl << endl << 4213191743184-1060403316668;
    
        
    //cout << counts["NC"];
}

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print(vector<vector<string>> v) {
    for (int i = 0; i < v.size(); ++i)
    {
        for (int k = 0; k < v[i].size(); ++k)
        {
            cout << v[i][k] << " ";
        }
        cout << endl;
    }
}

void printV(vector<int> v) {
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<string> getLine() {
    vector<string> ans;
    string a, b, c;
    cin >> a >> b;
    ans.push_back(a);
    ans.push_back(b);
    if (a != "inp") {
       cin >> c;
       ans.push_back(c);
    }
    return(ans);
}

vector<vector<string>> getInput(int lineCount) {
    vector<vector<string>> input;
    for (int i = 0; i < lineCount; ++i)
    {
        input.push_back(getLine());
    }
    return(input);
}

vector<int> prepVector(long long num) {
    vector<int> ans;
    string a = to_string(num);
    for (int i = 0; i < a.length(); ++i)
    {
        ans.push_back(a.at(i)-'0');
    }
    return(ans);
}

void printVars(map<string, long long> vars) {
    cout << "w: "<<vars["w"]<<"  x: "<<vars["x"]<<"  y: "<<vars["y"]<<"  z: "<<vars["z"] << endl;
}

map<string, long long> run(map<string, long long> vars, vector<vector<string>> monad, int input) {
    for (int i = 0; i < monad.size(); ++i)
    {
        //printVars(vars);
        vector<string> op = monad[i];
        if (op[0] == "inp") {
            vars[op[1]] = input;
        }
        else if (op[0] == "add") {
            if (isdigit(op[2].at(0))) {
                vars[op[1]] = vars[op[1]] + stoi(op[2]);
            }
            else {
                vars[op[1]] = vars[op[1]] + vars[op[2]];
            }
        }
        else if (op[0] == "mul") {
            if (isdigit(op[2].at(0))) {
                vars[op[1]] = vars[op[1]] * stoi(op[2]);
            }
            else {
                vars[op[1]] = vars[op[1]] * vars[op[2]];
            }
        }
        else if (op[0] == "div") {
            if (isdigit(op[2].at(0))) {
                vars[op[1]] = vars[op[1]] / stoi(op[2]);
            }
            else {
                vars[op[1]] = vars[op[1]] / vars[op[2]];
            }
        }
        else if (op[0] == "mod") {
            if (isdigit(op[2].at(0))) {
                vars[op[1]] = vars[op[1]] % stoi(op[2]);
            }
            else {
                vars[op[1]] = vars[op[1]] % vars[op[2]];
            }
            //cout << (char)(vars[op[1]]+'a');
        }
        else if (op[0] == "eql") {
            if (isdigit(op[2].at(0))) {
                vars[op[1]] = (vars[op[1]]==stoi(op[2])?1:0);
            }
            else {
                vars[op[1]] = (vars[op[1]]==vars[op[2]]?1:0);
            }
        }
    }
    //printVars(vars);
    return(vars);
}

long long execute(long long z, int w, vector<int> nums) {
    //cout << "test: " << (z%26)+nums[0] << endl;
    if (w == (z%26)+nums[0]) {
        z = z/nums[2];
        //cout << z << endl;
        return(z);
    }
    else {
        z = z/nums[2];
        return((26*z)+w+nums[1]);
    }
}

long long full(vector<vector<int>> realList, long long in) {
    vector<int> input = prepVector(in);
    long long z = 0;
    for (int i = 0; i < realList.size(); ++i)
    {
        z = execute(z, input[i], realList[i]);
        //cout << i << "  " << z << endl;
    }
    return(z);
}

int checkEx(long long z, vector<int> nums, long long check) {
    for (int i = 1; i <= 9; ++i)
    {
        //cout << "w: " << i << "   " << execute(z, i, nums) << endl;
        if (execute(z, i, nums) == check) {
            return(i);
        }
    }
    return(-1);
}

long long bonk(long long z, int w, vector<int> nums) {
    //cout << "test: " << (z%26)+nums[0] << endl;
    if (nums[2] == 1) {
        return(true);
    }
    if (w == (z%26)+nums[0]) {
        z = z/nums[2];
        //cout << z << endl;
        return(true);
    }
    else {
        z = z/nums[2];
        return(false);
    }
}

void recurse(vector<vector<int>> realList, long long z, int pos, vector<int> wList) {
    //cout << pos << endl;
    if (pos == realList.size()) {
        cout << "z: " << z << endl;
        printV(wList);
        cout << endl << endl;
        cout << wList.size() << endl;
    }
    for (int i = 1; i <= 9; ++i)
    {
        bool thing = bonk(z, i, realList[pos]);
        if (thing) {
            wList.push_back(i);
            cout << pos << " " << i << endl;
            recurse(realList, execute(z, i, realList[pos]), pos+1, wList);
        }
    }
    //wList.pop_back();
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    map<string, long long> vars = {{"w", 0},{"z", 0},{"y", 0},{"x", 0}};

    vector<vector<vector<string>>> monadList;
    for (int i = 0; i < 14; ++i)
    {
        vector<vector<string>> monad = getInput(18); //252
        monadList.push_back(monad);
        monad.clear();
    }
    
    // vector<int> input = prepVector(11479723842138);
    // printV(input);

    vector<vector<int>> realList;

    for (int i = 0; i < monadList.size(); ++i)
    {
        vector<int> temp;
        temp.push_back(stoi(monadList[i][5][2]));
        temp.push_back(stoi(monadList[i][15][2]));
        temp.push_back(stoi(monadList[i][4][2]));
        realList.push_back(temp);
    }

    for (int i = 0; i < realList.size(); ++i)
    {
        printV(realList[i]);
    }
    cout << endl << endl;

    vector<int> wList;
    recurse(realList, 0, 0, wList);

    //cout << full(realList, 11999999999999) << endl;

    //cout << checkEx(0, realList[12], 20) << endl;

    //cout << execute(execute((26*13)+16, 9, realList[12]), 2, realList[13]) << endl;

    // vector<int> wList;
    // vector<int> zList;

    // int c = 0;
    // while(true) {
    //     for (int i = 9; i >= 1; ++i)
    //     {
    //         if (realList[0][2] == 1 || execute(zList[zList.size()-1], i, realList[0]))
    //     }
    // }



    // stoopid brute force
    // for (long long i = 99999999999999; i >=0 ; --i)
    // {
    //     if (i % 100000 == 0) {
    //         cout << i << endl;
    //     }
    //     if (full(realList, i) == 0) {
    //         cout << i << " yay " << endl;
    //         break;
    //     }
    // }

}

// 99999786500000
// ans for highest99911993949684
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
    for (int i = a.length()-1; i >= 0; --i)
    {
        ans.push_back(a.at(i)-'0');
    }
    return(ans);
}

void printVars(map<string, long long> vars) {
    cout << "w: "<<vars["w"]<<"  x: "<<vars["x"]<<"  y: "<<vars["y"]<<"  z: "<<vars["z"] << endl;
}

map<string, long long> run(map<string, long long> vars, vector<vector<string>> monad, vector<int> input) {
    for (int i = 0; i < monad.size(); ++i)
    {
        
        vector<string> op = monad[i];
        if (op[0] == "inp") {
            cout << (i/18)-1 << "   " << vars["z"] << endl;
            vars[op[1]] = input[input.size()-1];
            input.pop_back();
        }
        else if (op[0] == "add") {
            if (isdigit(op[2].at(0)) || op[2].at(0) == '-') {
                vars[op[1]] = vars[op[1]] + stoi(op[2]);
                cout << "stoi " << stoi(op[2]) <<  endl;
            }
            else {
                vars[op[1]] = vars[op[1]] + vars[op[2]];
            }
        }
        else if (op[0] == "mul") {
            if (isdigit(op[2].at(0)) || op[2].at(0) == '-') {
                vars[op[1]] = vars[op[1]] * stoi(op[2]);
            }
            else {
                vars[op[1]] = vars[op[1]] * vars[op[2]];
            }
        }
        else if (op[0] == "div") {
            if (isdigit(op[2].at(0)) || op[2].at(0) == '-') {
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
            if (isdigit(op[2].at(0)) || op[2].at(0) == '-') {
                vars[op[1]] = (vars[op[1]]==stoi(op[2])?1:0);
            }
            else {
                vars[op[1]] = (vars[op[1]]==vars[op[2]]?1:0);
            }
        }
    }
    cout << 13 << "   " << vars["z"] << endl;
    //printVars(vars);
    return(vars);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    map<string, long long> vars = {{"w", 0},{"z", 0},{"y", 0},{"x", 0}};

    // vector<vector<vector<string>>> monadList;
    // for (int i = 0; i < 14; ++i)
    // {
    //     vector<vector<string>> monad = getInput(18); //252
    //     monadList.push_back(monad);
    //     monad.clear();
    // }
    // reverse(monadList.begin(), monadList.end());
    
    vector<vector<string>> monad = getInput(252);

    //3rd digit must be 4?
    vector<int> input = prepVector(11999999999999); //13579246899999
    printV(input);

    vars = run(vars, monad, input);
    cout << vars["z"] << endl;


    // vector<map<string, long long>> varsList;

    // for (int i = 0; i < 1000; i += 1)
    // {
    //     vars["z"] = i;
    //     vars["x"] = 0;
    //     vars["y"] = 0;
    //     //map<string, long long> varsCopy = vars;
    //     varsList.push_back(vars);
    //     // vars = run(vars, monadList[0], input);
    //     // if (vars["z"] == 0) {
    //     //     // printVars(vars);
    //     //     // printVars(varsCopy);
    //     //     // cout << "beans" << endl;
    //     //     varsList.push_back(varsCopy);
    //     // }
    // }

    // int z = 0;
    // for (int i = 0; i < 2; ++i)
    // {
    //     cout << endl << endl << endl << "monadList: " << i << "  z: " << z << endl << endl;
    //     //print(monadList[i]);

    //     for (int k = 0; k < varsList.size(); ++k)
    //     {
    //         for (int w = 1; w <= 9; ++w)
    //         {
    //             vars = varsList[k];
    //             vars = run(vars, monadList[i], w);
    //             if (vars["z"] == z) {
    //                 //varsListNew.push_back(varsList[k]);
    //                 printVars(varsList[k]);
    //                 cout << "w: " << w << endl;
    //                 z = varsList[k]["z"];
    //             }
    //         }
    //     }
    // }



}

//truncation
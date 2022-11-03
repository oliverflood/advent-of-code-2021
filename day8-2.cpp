#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> split(string s, string delimiter) {
    vector<string> v;
    int pos1 = 0;

    for (int i = 0; i < count(s.begin(), s.end(), delimiter.at(0))+1; ++i)
    {
        
        int pos2 = s.find(delimiter, pos1);
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2+1;
    }

    return(v);
}

int findIndex(vector<int> v, int num) {
    return(distance(v.begin(), find(v.begin(), v.end(), num)));
}

void sortString(string &str)
{
   sort(str.begin(), str.end());
}

bool contains(string a, string b) {
    for (int i = 0; i < b.length(); ++i)
    {
        if (a.find(b.substr(i, 1))==std::string::npos) {
            return false;
        }
    }
    return true;
}

bool equivalent(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }
    for (int i = 0; i < b.length(); ++i)
    {
        if (a.find(b.substr(i, 1))==std::string::npos) {
            return false;
        }
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<vector<string>> input;
    vector<vector<string>> input2;
    int inputSize = 200;


    for (int i = 0; i < inputSize; ++i)
    {

        vector<string> temp;
        vector<string> temp2;
        for (int k = 0; k < 10; ++k)
        {
            string a;
            cin >> a;
            temp.push_back(a);
        }

        string c;
        cin >> c;

        for (int k = 0; k < 4; ++k)
        {
            string b;
            cin >> b;
            temp2.push_back(b);
        }

        input.push_back(temp);
        input2.push_back(temp2);
    }
    //input check
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << input[0][i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < 4; ++i)
    // {
    //     cout << input2[0][i] << " ";
    // }

    long answer = 0;

    for (int k = 0; k < inputSize; ++k)
    {
        vector<string> nums;
        for (int i = 0; i < 10; ++i)
        {
            nums.push_back("z");
        }

        for (int i = 0; i < 10; ++i)
        {
            if (input[k][i].length() == 3) { // 7
                nums[7] = input[k][i];
            }
            if (input[k][i].length() == 4) { // 4
                nums[4] = input[k][i];
            }
            if (input[k][i].length() == 2) { // 1
                nums[1] = input[k][i];
            }
            if (input[k][i].length() == 7) { // 8
                nums[8] = input[k][i];
            }
        }
        // 6 segs
        vector<string> six;
        vector<string> five;
        for (int i = 0; i < 10; ++i) // 6
        {
            //cout << input[k][i].length();
            if (input[k][i].length() == 6) {
                six.push_back(input[k][i]);
            }
            if (input[k][i].length() == 5) {
                five.push_back(input[k][i]);
            }
        }
        for (int i = 0; i < 3; ++i) // six segs
        {
            if (!contains(six[i], nums[1])) { // 6
                //cout << six[i];
                nums[6] = six[i];
            }
            if (contains(six[i], nums[4])) { // 9
                nums[9] = six[i];
            }
        }
        for (int i = 0; i < 3; ++i) {
            if ((six[i] != nums[9]) && (six[i] != nums[6])) {
                nums[0] = six[i]; // 0
            }
        }
        for (int i = 0; i < 3; ++i) // five segs
        {
            if (contains(nums[6], five[i])) {
                nums[5] = five[i];
            }
            if (contains(five[i],nums[1])) {
                nums[3] = five[i];
            }
            // if (contains(nums[9], five[i])) {
            //     nums[2] = five[i];
            // }
        }
        for (int i = 0; i < 3; ++i) {
            if ((five[i] != nums[3]) && (five[i] != nums[5])) {
                nums[2] = five[i]; // 0
            }
        }

        //nums check: vvvv

        // for (int i = 0; i < 10; ++i)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        int counter = 0;
        vector<int> helpme;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (equivalent(input2[k][i], nums[j])) {
                    //cout << endl << "j: " << j << " " << input[k][j] << endl;
                    //counter += j*pow(10, 3-i);
                    helpme.push_back(j);
                }
            }
        }
        string help = "";
        for (int i = 0; i < 4; ++i)
        {
            help = help + to_string(helpme[i]);
        }

        //cout << "counter: " << counter << endl;
        answer += stoi(help);
        six.clear();
        five.clear();
        nums.clear();
    }

    cout << endl << "answer: " << answer;
    

    cout << endl << "hello" << endl;
    //cout << input2[199][4];
    //cout << input2[199][3];
}
// 1028908 too low
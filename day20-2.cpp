#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binToDec(vector<bool> bin) {
    reverse(bin.begin(), bin.end());
    int ans = bin[0];
    for (int i = 1; i < bin.size(); ++i)
    {
        ans += bin[i] * pow(2, i);
    }
    return(ans);
}

int countPixels(vector<vector<bool>> image) {
    int ans = 0;
    for (int i = 0; i < image.size(); ++i)
    {
        ans += count(image[i].begin(), image[i].end(), 1);
    }
    return(ans);
}

void print(vector<vector<bool>> image) {
    for (int i = 0; i < image.size(); ++i)
    {
        for (int k = 0; k < image[0].size(); ++k)
        {
            cout << (image[i][k]?"#":".");
        }
        cout << endl;
    }
    cout << endl;
    cout << "pixel count: " << countPixels(image) << endl << endl; 
}

vector<bool> getPixels(vector<vector<bool>> image, int x, int y) {
    vector<bool> ans;
    for (int i = 1; i >= -1; --i)
    {
        for (int k = 1; k >= -1; --k)
        {
            if ((y-i < 0 || y-i > image.size()-1) || (x-k < 0 || x-k > image.size()-1)) {
                ans.push_back(image[0][0]);
            }
            else {
                ans.push_back(image[y-i][x-k]);
            }
        }
    }
    return(ans);
}

vector<vector<bool>> pad(vector<vector<bool>> image, bool item) {  
    for (int i = 0; i < image.size(); ++i)
    {
        image[i].insert(image[i].begin(), item);
        image[i].push_back(item);
    }
    vector<bool> temp;
    for (int i = 0; i < image[0].size(); ++i)
    {
        temp.push_back(item);
    }
    image.insert(image.begin(), temp);
    image.push_back(temp);
    return(image);
}

vector<vector<bool>> enhance(vector<vector<bool>> image, vector<bool> algo) {
    image = pad(image, image[0][0]);
    vector<vector<bool>> answer = image;
    for (int i = 0; i < image.size(); ++i)
    {
        for (int k = 0; k < image.size(); ++k)
        {
            answer[i][k] = algo[binToDec(getPixels(image, k, i))];
        }
    }
    return(answer);
}

vector<bool> getAlgoInput() {
    string algoS;
    cin >> algoS;

    vector<bool> algo;

    for (int i = 0; i < algoS.length(); ++i)
    {
        if (algoS.at(i) == '#') {
            algo.push_back(1);
        }
        else {
            algo.push_back(0);
        }
    }
    return(algo);
}

vector<vector<bool>> getImageInput(int inputSize) {
    vector<vector<bool>> image;
    for (int i = 0; i < inputSize; ++i)
    {
        string s;
        cin >> s;
        vector<bool> temp;
        for (int k = 0; k < inputSize; ++k)
        {
            if (s.at(k) == '#') {
                temp.push_back(1);
            }
            else {
                temp.push_back(0);
            }
        }
        image.push_back(temp);
    }
    return(image);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    vector<bool> algo = getAlgoInput();
    vector<vector<bool>> image = getImageInput(100);

    image = pad(image, 0);
    
    for (int i = 0; i < 50; ++i)
    {
        image = enhance(image, algo);
    }

    cout << "pixel count: " << countPixels(image) << endl << endl; 
}

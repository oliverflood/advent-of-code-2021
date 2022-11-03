#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int findIndex(vector<int> v, int num) {
    return(distance(v.begin(), find(v.begin(), v.end(), num)));
}

int flood(vector<vector<bool>> &visited, int x, int y) {
	vector<vector<int>> v;
	vector<int> temp = {x,y};
	// temp.push_back(x);
	// temp.push_back(y);
	v.push_back(temp);
	int sum = 1;
	if (!visited[y+1][x]) {
		v.push_back({x,y+1});
		visited[y+1][x] = 1;
		sum++;
	}
	if (!visited[y-1][x]) {
		v.push_back({x,y-1});
		visited[y-1][x] = 1;
		sum++;
	}
	if (!visited[y][x+1]) {
		v.push_back({x+1,y});
		visited[y][x+1] = 1;
		sum++;
	}
	if (!visited[y][x-1]) {
		v.push_back({x-1,y});
		visited[y][x-1] = 1;
		sum++;
	}
	visited[y][x] = 1;
	while (v.size() > 0) {
		int ny = v[0][1];
		int nx = v[0][0];
		if (!visited[ny+1][nx]) {
			v.push_back({nx,ny+1});
			visited[ny+1][nx] = 1;
			sum++;
		}
		if (!visited[ny-1][nx]) {
			v.push_back({nx,ny-1});
			visited[ny-1][nx] = 1;
			sum++;
		}
		if (!visited[ny][nx+1]) {
			v.push_back({nx+1,ny});
			visited[ny][nx+1] = 1;
			sum++;
		}
		if (!visited[ny][nx-1]) {
			v.push_back({nx-1,ny});
			visited[ny][nx-1] = 1;
			sum++;
		}
		v.erase(v.begin());
	}
	return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int inputSize = 100;
    vector<string> input;
    vector<vector<int>> graph;

    vector<int> temp;
    for (int i = 0; i < inputSize+2; ++i)
    {
        temp.push_back(9);
    }

    for (int i = 0; i < inputSize; ++i)
    {
        string a;
        cin >> a;
        input.push_back("9"+a+"9");
    }

    graph.push_back(temp);
    for (int i = 0; i < input.size(); ++i)
    {
    	vector<int> temp2;
    	for (int k = 0; k < input[0].length(); ++k)
    	{
    		temp2.push_back(input[i].at(k)-'0');
    	}
    	graph.push_back(temp2);
    }
    graph.push_back(temp);

    vector<vector<bool>> visited;
    for (int i = 0; i < graph.size(); ++i)
    {
    	vector<bool> temp3;
    	for (int k = 0; k < graph[0].size(); ++k)
    	{
    		if (graph[i][k] == 9) {
    			temp3.push_back(1);
    		}
    		else {
    			temp3.push_back(0);
    		}
    	}
    	visited.push_back(temp3);
    }

    // for (int i = 0; i < visited.size(); ++i)
    // {
    // 	for (int k = 0; k < visited[0].size(); ++k)
    // 	{
    // 		cout << visited[i][k];
    // 	}
    // 	cout << endl;
    // }

    int total = 0;
    for (int i = 1; i < inputSize+1; ++i)
    {
        for (int k = 1; k < inputSize+1; ++k)
        {
            if ((graph[i][k] < graph[i+1][k]) &&(graph[i][k] < graph[i-1][k]) &&(graph[i][k] < graph[i][k-1])&&(graph[i][k] < graph[i][k+1])) {
                total += graph[i][k]+1;
            }
        }
    }
    
    vector<int> answers;
    for (int i = 0; i < visited.size(); ++i)
    {
    	for (int k = 0; k < visited[0].size(); ++k)
    	{
    		if (!visited[i][k]) {
    			answers.push_back(flood(visited, k, i));
    		}
    	}
    }

    sort(answers.begin(), answers.end());
    cout << "ans: " << answers[answers.size()-1] *answers[answers.size()-2] *answers[answers.size()-3];
}
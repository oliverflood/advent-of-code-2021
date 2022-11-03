#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); ++i)
    {
        for (int k = 0; k < v[0].size(); ++k)
        {
            cout << (to_string(v[i][k])!="0"?to_string(v[i][k]):".") << " ";
        }
        cout << endl;
    }
}

int dist(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return(0);
    }
    else {
        return((abs(x1-x2)!=0)?(abs(x1-x2)+y1+y2):(abs(y1-y2)));
    }
}

int sum(vector<int> v) {
    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        ans += v[i];
    }
    return(ans);
}

int lowest(vector<vector<int>> board) {
    int bound = 0;
    for (int i = 2; i <= 8; i+=2)
    {
        for (int k = 1; k < 3; ++k)
        {
            if (board[k][i] != 0) {
                bound += dist(i, k, 2+(2*(board[k][i]-1)), 2)*pow(10, board[k][i]-1);
            }
            //cout << board[k][i] << "  " << dist(i, k, 2+(2*(board[2][i]-1)), 2)*pow(10, board[k][i]-1) << "   " << (2+(2*(board[2][i]-1))) << endl;
        }
    }
    for (int i = 2; i <= 8; i+=2) {
        int k = 1;
        if (i == 2+(2*(board[k][i]-1))) {
            if (board[k][i] != board[k+1][i] && board[k][i] != 0 && board[k+1][i] != 0) {
                //cout << "ye at " << board[k][i] << endl;
                bound += pow(10, board[k][i]-1)*4;
            }
        }
    }
    for (int i = 0; i <= 10; i++)
    {
        int k = 0;
        if (board[k][i] != 0) {
            bound += dist(i, k, 2+(2*(board[k][i]-1)), 2)*pow(10, board[k][i]-1);
        }
    }
    return(bound-1111);
}

bool blocked(vector<vector<int>> board, int x1, int y1, int x2, int y2) {
    bool ans = false;
    for (int i = min(x1, x2); i <= max(x1, x2); ++i)
    {
        if (board[0][i] != 0) {
            if (!(y1 == 0 && i == x1)) {
                ans = true;
            }
        }
    }
    if (y1 > 1) {
        if (board[1][x1] != 0) {
            ans = true;
        }
    }
    if (y2 > 0) {
        if (!(board[1][x2] == 0 && board[2][x2] == 0)) {
            if (!(board[1][x2] == 0 && board[2][x2] == board[y1][x1])) {
                ans = true;
            }
        }
    }

    if (x1 == x2 && y1 == y2) {
        ans = true;
    }
    //cout << "ans: " << ans << endl;
    return(ans);
}

// int lowestScore = 0;
// void recurse(vector<vector<int>> board, int score) {
//     for (int i = 8; i >= 2 ; i-=2)
//     {
        
//     }
//         if ()
//         board[1][2+(2*i)] = (a.at(3+(2*i))-'A')+1;
//         board[2][2+(2*i)] = (b.at(1+(2*i))-'A')+1;
// }

pair<vector<vector<int>>, int> precipitate(vector<vector<int>> board, int score) {
    for (int i = 0; i <= 10; ++i)
    {
        if (board[0][i] != 0) {
            int newX = (2*board[0][i]);
            if (board[1][newX] == 0 && board[2][newX] == 0) {
                if (!blocked(board, i, 0, newX, 0)) {
                    score += ceil(dist(i, 0, newX, 2)*(pow(10, board[0][i]-1)));
                    board[2][newX] = board[0][i];
                    board[0][i] = 0;
                }
            }
            else if (board[1][newX] == 0 && board[2][newX] == board[0][i]) {
                //cout << "meow"<< i << " " << newX << " " << !blocked(board, i, 0, newX, 1) << endl;
                if (!blocked(board, i, 0, newX, 1)) {
                    score += ceil(dist(i, 0, newX, 1)*(pow(10, board[0][i]-1)));
                    board[1][newX] = board[0][i];
                    board[0][i] = 0;
                }
            }
        }
    }
    return(pair<vector<vector<int>>, int>(board, score));
}

vector<pair<vector<vector<int>>, int>> listLegals(vector<vector<int>> board, int score) {
    vector<pair<vector<vector<int>>, int>> bList;

    // int temp1 = score;
    // pair<vector<vector<int>>, int> e = precipitate(board, score);
    // board = e.first;
    // score = e.second;
    // if (temp1 == score+1) {
    //     cout << "FUCKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK";
    // }

    for (int i = 0; i <= 10; ++i)
    {
        if (board[0][i] != 0) {
            int newX = (2*board[0][i]);
            if (board[1][newX] == 0 && board[2][newX] == 0) {
                if (!blocked(board, i, 0, newX, 0)) {
                    int tempScore = ceil(dist(i, 0, newX, 2)*(pow(10, board[0][i]-1)));
                    vector<vector<int>> tempBoard = board;
                    tempBoard[2][newX] = tempBoard[0][i];
                    tempBoard[0][i] = 0;
                    bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
                }
            }
            else if (board[1][newX] == 0 && board[2][newX] == board[0][i]) {
                //cout << "meow"<< i << " " << newX << " " << !blocked(board, i, 0, newX, 1) << endl;
                if (!blocked(board, i, 0, newX, 1)) {
                    int tempScore = ceil(dist(i, 0, newX, 1)*(pow(10, board[0][i]-1)));
                    vector<vector<int>> tempBoard = board;
                    tempBoard[1][newX] = tempBoard[0][i];
                    tempBoard[0][i] = 0;
                    bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
                }
            }
        }
    }

    for (int i = 8; i >= 2; i-=2) {
        for (int k = 2; k >= 1; k--)
        {
            if (board[k][i+1] == 0) {
                for (int j = 0; j <= 10; j++)
                {
                    if (j != 2 && j != 4 && j != 6 && j != 8) {
                        if (!blocked(board, i, k, j, 0) && !(k == 2 && board[k][i] == i/2) && !(k == 1 && board[k][i] == i/2 && board[k+1][i] == i/2)) {
                            //cout << i << " " << k << " " << j << endl;
                            vector<vector<int>> tempBoard = board;
                            int tempScore = ceil(dist(i, k, j, 0)*(pow(10, board[k][i]-1)));
                            // if (tempScore == 1) {
                            //     cout << "FUCK" << endl;
                            // }
                            if (tempScore != 0 && tempScore != 1) {
                                tempBoard[0][j] = tempBoard[k][i];
                                tempBoard[k][i] = 0;
                                //cout << "beans";
                                bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
                            }
                        }
                    }
                }
            }
        }
    }
    return(bList); 
}

int findLowestIndex(vector<pair<vector<vector<int>>, int>> boardList) {
    int ans = 0;
    for (int i = 0; i < boardList.size(); ++i)
    {
        if (boardList[i].second+lowest(boardList[i].first) < boardList[ans].second + lowest(boardList[ans].first)) {
            ans = i;
        }
    }
    return(ans);
}

bool isComplete(vector<vector<int>> board) {
    bool ans = true;
    for (int i = 2; i <= 8; i+=2)
    {
        if (!(board[1][i] == i/2 && board[2][i] == i/2)) {
            ans = false;
        }
    }
    return(ans);
}

vector<vector<int>> getInput() {
    string a, b;
    cin >> a >> a >> a >> b;

    vector<vector<int>> board;
    for (int i = 0; i < 3; ++i)
    {
        vector<int> temp;
        for (int k = 0; k < 11; ++k)
        {
            temp.push_back(0);
        }
        board.push_back(temp);
    }
    for (int i = 0; i < 4; ++i)
    {
        board[1][2+(2*i)] = (a.at(3+(2*i))-'A')+1;
        board[2][2+(2*i)] = (b.at(1+(2*i))-'A')+1;
    }
    return(board);
}

// bool impossible(vector<vector<int>> board) {
//     6
// }

int priority(vector<vector<int>> board) {
    int ans = 0;
    for (int i = 2; i <= 8; i+=2)
    {
        if (board[2][i] == i/2) {
            ans++;
            if (board[1][i] == i/2) {
                ans++;
            }
        }
    }
    return(ans);
}



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    vector<vector<int>> board = getInput();
    vector<pair<vector<vector<int>>, int>> boardList = listLegals(board, 0);

    int upper = lowest(board) + 1000;

    print(board);
    cout << lowest(board);
    cout << endl << endl;




    // // lowest function kinda stupid
    // for (int i = 0; i < boardList.size(); ++i)
    // {
    //     if (lowest(boardList[i].first) < upper) {
    //         print(boardList[i].first);
    //         cout << lowest(boardList[i].first) + boardList[i].second;
    //         cout << endl << endl;
    //     }
    // }
    // cout << endl << endl << endl << "other" << endl;

    // other.first[2][8] = 0;
    // boardList = listLegals(other.first, other.second);

    // for (int i = 0; i < boardList.size(); ++i)
    // {
    //     if (lowest(boardList[i].first) < upper+10000) {
    //         print(boardList[i].first);
    //         cout << lowest(boardList[i].first) + boardList[i].second;
    //         cout << endl << endl;
    //     }
    // }

    int c = 0;
    int index = findLowestIndex(boardList);

    while(true)
    {
        c++;
        // 10k = 51s

        if (c > 20000) {
            break;
        }
        pair<vector<vector<int>>, int> currentBoard = boardList[index];
        // if (c < 50 || c%100 == 0) {
        //     print(currentBoard.first);
        //     cout << c << " " << currentBoard.second+lowest(currentBoard.first) << " " << boardList.size() << " " << priority(boardList[index].first) << endl << endl;
        // }
            
        
        if (isComplete(currentBoard.first)) {
            cout << "complete" << endl;
            print(currentBoard.first);
            cout << c << " " << currentBoard.second+lowest(currentBoard.first) << " " << currentBoard.second << " " << boardList.size() << endl << endl;
            break;
        }
        
        vector<pair<vector<vector<int>>, int>> currentBoardList = listLegals(currentBoard.first, currentBoard.second);
        
        //boardList.pop_back();
        for (int k = 0; k < currentBoardList.size(); ++k)
        {
            //upper = 10630;
            if (currentBoardList[k].second + lowest(currentBoardList[k].first) <= upper && !(currentBoardList[k].first[2][8]==3&&currentBoardList[k].first[0][7]==4&&currentBoardList[k].first[0][9]==4)) {
                boardList.push_back(currentBoardList[k]);
            }
        }
        
        boardList.erase(boardList.begin()+index);
        set<pair<vector<vector<int>>, int>> yeet(boardList.begin(), boardList.end());
        vector<pair<vector<vector<int>>, int>> yeet2(yeet.begin(), yeet.end());
        boardList = yeet2;

        index = findLowestIndex(boardList);
        vector<int> indexes;
        for (int i = 0; i < boardList.size(); ++i)
        {
            // if (boardList[i].second+lowest(boardList[i].first) == boardList[index].second+lowest(boardList[index].first)) {
            //     indexes.push_back(i);
            // }
            if (true) {
                indexes.push_back(i);
            }
        }
        int newIndex = indexes[0];
        for (int i = 0; i < indexes.size(); ++i)
        {
            if (priority(boardList[indexes[i]].first) > priority(boardList[newIndex].first)) {
                newIndex = i;
            }
        }
        index = newIndex;

    }

}

// complete 11179?
//sorting only priority
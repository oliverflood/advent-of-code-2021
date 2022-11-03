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

int lowest(vector<vector<int>> board) {
    int bound = 0;
    for (int i = 2; i <= 8; i+=2)
    {
        for (int k = 1; k <= 4; ++k)
        {
            bound += dist(i, k, 2+(2*(board[k][i]-1)), 2)*pow(10, board[k][i]-1);
            //cout << board[k][i] << "  " << dist(i, k, 2+(2*(board[2][i]-1)), 2)*pow(10, board[k][i]-1) << "   " << (2+(2*(board[2][i]-1))) << endl;
        }
    }
    // for (int i = 2; i <= 8; i+=2) {
    //     int k = 1;
    //     if (i == 2+(2*(board[k][i]-1))) {
    //         if (board[k][i] != board[k+1][i]) {
    //             //cout << "ye at " << board[k][i] << endl;
    //             bound += pow(10, board[k][i]-1)*4;
    //         }
    //     }
    // }
    return(bound-6666);
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
    // if (y1 > 1) {
    //     if (board[1][x1] != 0) {
    //         ans = true;
    //     }
    // }
    for (int i = 1; i < y1; ++i)
    {
        if (board[i][x1] != 0) {
            ans = true;
        }
    }
    // if (y2 > 0) {
    //     if (!(board[1][x2] == 0 && board[2][x2] == 0)) {
    //         if (!(board[1][x2] == 0 && board[2][x2] == board[y1][x1])) {
    //             ans = true;
    //         }
    //     }
    // }
    for (int i = 1; i <= y2; ++i)
    {
        if (board[i][x2] != 0 && board[i][x2] != board[y1][x1]) {
            ans = true;
        }
    }

    if (x1 == x2 && y1 == y2) {
        ans = true;
    }
    return(ans);
}

pair<vector<vector<int>>, int> precipitate(vector<vector<int>> board, int score) {
    //cout << board.size() << "   " << board[0].size() << endl;
    //print(board);
    for (int i = 0; i <= 10; ++i)
    {
        if (board[0][i] != 0) {
            //cout << "i " << i << endl;
            int newX = (2*board[0][i]);
            if (!blocked(board, i, 0, newX, 4)) {
                //cout << "not blocked";
                int newY = 50;
                for (int i = 4; i >= 1; --i)
                {
                    if (board[i][newX] == 0) {
                        newY = i;
                    }
                }
                score += ceil(dist(i, 0, newX, newY)*(pow(10, board[0][i]-1)));
                //cout << "score " << score << endl;
                board[newY][newX] = board[0][i];
                board[0][i] = 0;
            }
        }
    }
    // for (int i = 8; i >= 2; i-=2) {
    //     for (int k = 1; k >= 4; k++)
    //     { 
    //         if (board[k][i] != 0) {
    //             //cout << "i " << i << endl;
    //             int newX = (2*board[k][i]);
    //             if (!blocked(board, i, k, newX, 4)) {
    //                 //cout << "not blocked";
    //                 int newY = 4;
    //                 for (int i = 4; i > 0; --i)
    //                 {
    //                     if (board[i][newX] == 0) {
    //                         newY = i;
    //                     }
    //                 }
    //                 score += ceil(dist(i, k, newX, newY)*(pow(10, board[k][i]-1)));
    //                 //cout << "score " << score << endl;
    //                 board[newY][newX] = board[k][i];
    //                 board[k][i] = 0;
    //             }
    //         }
    //     }
    // }
    //print(board);
    return(pair<vector<vector<int>>, int>(board, score));
}

set<pair<vector<vector<int>>, int>> reference;


// vector<pair<vector<vector<int>>, int>> listLegals(vector<vector<int>> board, int score) {
//     vector<pair<vector<vector<int>>, int>> bList;

//     // int temp1 = score;
//     // pair<vector<vector<int>>, int> e = precipitate(board, score);
//     // board = e.first;
//     // score = e.second;

//     for (int i = 0; i <= 10; ++i)
//     {
//         if (board[0][i] != 0) {
//             //cout << "i " << i << endl;
//             int newX = (2*board[0][i]);
//             if (!blocked(board, i, 0, newX, 4)) {
//                 //cout << "not blocked";
//                 int newY = 4;
//                 for (int i = 4; i > 0; --i)
//                 {
//                     if (board[i][newX] == 0) {
//                         newY = i;
//                     }
//                 }
//                 int tempScore = ceil(dist(i, 0, newX, newY)*(pow(10, board[0][i]-1)));
//                 vector<vector<int>> tempBoard = board;
//                 tempBoard[newY][newX] = board[0][i];
//                 tempBoard[0][i] = 0;
//                 bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
//             }
//         }
//     }

//     for (int i = 8; i >= 2; i-=2) {
//         bool start = false;
//         for (int k = 4; k >= 1; k--)
//         {
//             if (board[k][i] != i/2) {
//                 start = true;
//             }
//             if (start && board[k][i] != 0) {
//                 for (int j = 0; j <= 10; j++)
//                 {
//                     if (j != 2 && j != 4 && j != 6 && j != 8) {
//                         if (!blocked(board, i, k, j, 0)) { // !(k == 2 && board[k][i] == i/2)

//                             vector<vector<int>> tempBoard = board;
//                             int tempScore = ceil(dist(i, k, j, 0)*(pow(10, board[k][i]-1)));

//                             if (tempScore != 0 && tempScore != 1) { // EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//                                 tempBoard[0][j] = tempBoard[k][i];
//                                 tempBoard[k][i] = 0;
//                                 //cout << "beans";
//                                 bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return(bList); 
// }

bool isComplete(vector<vector<int>> board) {
    bool ans = true;
    for (int i = 8; i >= 2; i-=2) {
        for (int k = 4; k >= 1; k--)
        { 
            if (board[k][i] != i/2) {
                ans = false;
            }
        }
    }
    return(ans);
}


vector<pair<vector<vector<int>>, int>> listLegals(vector<vector<int>> board, int score) {
    vector<pair<vector<vector<int>>, int>> bList;

    // int temp1 = score;
    // pair<vector<vector<int>>, int> e = precipitate(board, score);
    // board = e.first;
    // score = e.second;
    

    for (int i = 0; i <= 10; ++i)
    {
        if (board[0][i] != 0) {
            //cout << "i " << i << endl;
            int newX = (2*board[0][i]);
            if (!blocked(board, i, 0, newX, 4)) {
                //cout << "not blocked";
                int newY = 4;
                for (int i = 4; i > 0; --i)
                {
                    if (board[i][newX] == 0) {
                        newY = i;
                    }
                }
                int tempScore = ceil(dist(i, 0, newX, newY)*(pow(10, board[0][i]-1)));
                vector<vector<int>> tempBoard = board;
                tempBoard[newY][newX] = board[0][i];
                tempBoard[0][i] = 0;
                bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
            }
        }
    }

    if (isComplete(board)) {
        print(board);
        cout << score << endl;
    }

    for (int i = 8; i >= 2; i-=2) {
        bool start = false;
        for (int k = 4; k >= 1; k--)
        {
            if (board[k][i] != i/2) {
                start = true;
            }
            if (start && board[k][i] != 0) {
                for (int j = 0; j <= 10; j++)
                {
                    if (j != 2 && j != 4 && j != 6 && j != 8) {
                        if (!blocked(board, i, k, j, 0)) { // !(k == 2 && board[k][i] == i/2)

                            vector<vector<int>> tempBoard = board;
                            int tempScore = ceil(dist(i, k, j, 0)*(pow(10, board[k][i]-1)));

                            if (tempScore != 0 && tempScore != 1) { // EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
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

// vector<pair<vector<vector<int>>, int>> listLegals2(vector<vector<int>> board, int score) {
//     vector<pair<vector<vector<int>>, int>> bList;

//     int temp1 = score;
//     pair<vector<vector<int>>, int> e = precipitate(board, score);
//     board = e.first;
//     score = e.second;
//     if (isComplete(board)) {
//         print(board);
//         cout << score << endl;
//     }
//     //bList.push_back(pair<vector<vector<int>>, int>(board, score));

//     for (int i = 8; i >= 2; i-=2) {
//         bool start = false;
//         for (int k = 4; k >= 1; k--)
//         {
//             if (board[k][i] != i/2) {
//                 start = true;
//             }
//             if (start && board[k][i] != 0) {
//                 for (int j = 0; j <= 10; j++)
//                 {
//                     if (j != 2 && j != 4 && j != 6 && j != 8) {
//                         if (!blocked(board, i, k, j, 0)) { // !(k == 2 && board[k][i] == i/2)

//                             vector<vector<int>> tempBoard = board;
//                             int tempScore = ceil(dist(i, k, j, 0)*(pow(10, board[k][i]-1)));

//                             if (tempScore != 0 && tempScore != 1 && score+tempScore <= 50000) { // EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//                                 tempBoard[0][j] = tempBoard[k][i];
//                                 tempBoard[k][i] = 0;
//                                 //cout << "beans";
//                                 if (reference.find(tempBoard) == reference.end()) {
//                                     bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
//                                 }
                                
//                             }
//                             break;
//                         }
//                     }
//                 }
//                 for (int j = 10; j >= 0; j--) {
//                     if (j != 2 && j != 4 && j != 6 && j != 8) {
//                         if (!blocked(board, i, k, j, 0)) { // !(k == 2 && board[k][i] == i/2)

//                             vector<vector<int>> tempBoard = board;
//                             int tempScore = ceil(dist(i, k, j, 0)*(pow(10, board[k][i]-1)));

//                             if (tempScore != 0 && tempScore != 1 && score+tempScore <= 50000) { // EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//                                 tempBoard[0][j] = tempBoard[k][i];
//                                 tempBoard[k][i] = 0;
//                                 //cout << "beans";
//                                 if (reference.find(tempBoard) == reference.end()) {
//                                     bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
//                                 }
//                             }
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return(bList); 
// }

vector<pair<vector<vector<int>>, int>> listLegals3(vector<vector<int>> board, int score) {
    vector<pair<vector<vector<int>>, int>> bList;

    // int temp1 = score;
    // pair<vector<vector<int>>, int> e = precipitate(board, score);
    // board = e.first;
    // score = e.second;

    for (int i = 8; i >= 2; i-=2) {
        for (int k = 4; k >= 1; k--)
        {
            if (board[k][i] != 0) {
                for (int j = 0; j <= 10; j++)
                {
                    if (j != 2 && j != 4 && j != 6 && j != 8) {
                        if (!blocked(board, i, k, j, 0)) { // !(k == 2 && board[k][i] == i/2)

                            vector<vector<int>> tempBoard = board;
                            int tempScore = ceil(dist(i, k, j, 0)*(pow(10, board[k][i]-1)));

                            if (tempScore != 0 && tempScore != 1 && score+tempScore <= 50000) { // EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
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
    for (int i = 0; i <= 10; i++) {
        int k = 0;
        if (board[k][i] != 0) {
            for (int j = 2; j <= 8; j+=2)
            {
                int newY = 4;
                for (int e = 4; e >= 1; --e)
                {
                    if (board[newY][e] == 0) {
                        newY = e;
                        break;
                    }
                }


                if (!blocked(board, i, k, j, newY)) { // !(k == 2 && board[k][i] == i/2)

                    vector<vector<int>> tempBoard = board;
                    int tempScore = ceil(dist(i, k, j, newY)*(pow(10, board[k][i]-1)));

                    if (tempScore != 0 && tempScore != 1 && score+tempScore <= 50000) { // EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                        tempBoard[newY][j] = tempBoard[k][i];
                        tempBoard[k][i] = 0;
                        //cout << "beans";
                        bList.push_back(pair<vector<vector<int>>, int>(tempBoard, score + tempScore));
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
        if (boardList[i].second < boardList[ans].second) {
            ans = i;
        }
    }
    return(ans);
}

int findHighestIndex(vector<pair<vector<vector<int>>, int>> boardList) {
    int ans = 0;
    for (int i = 0; i < boardList.size(); ++i)
    {
        if (boardList[i].second > boardList[ans].second) {
            ans = i;
        }
    }
    return(ans);
}

bool compare(pair<vector<vector<int>>, int>& a, pair<vector<vector<int>>, int>& b) {
    return(a.second < b.second);
}

bool recurse(vector<vector<int>> board, int score) {
    //cout << "hi" << endl;
    vector<pair<vector<vector<int>>, int>> boardList = listLegals(board, score);
    if (boardList.size() == 0) {
        return(false);
    }
    sort(boardList.begin(), boardList.end(), compare);
    // cout << reference.size() << endl;
    // print(boardList[0].first);
    for (int i = 0; i < boardList.size(); ++i)
    {
        // if (boardList[i].first[2][6] == 3) {
        //     print(boardList[i].first);
        // }
        if (isComplete(boardList[i].first)) {
            cout << "YAAAAAAAY" << endl;
            print(boardList[i].first);
            cout << boardList[i].second << endl;
            return(true);
            break;
        }
        else {
            if (reference.find(boardList[i]) == reference.end()) {
                reference.insert(boardList[i]);
                bool b = recurse(boardList[i].first, boardList[i].second);
                if (!b) {
                    reference.insert(boardList[i]);
                }
                else {
                    return(true);
                }
            }
        }
    }
    boardList.clear();
    return(false);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

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

    board.insert(board.begin()+2, {0, 0, 4, 0, 3, 0, 2, 0, 1, 0, 0});
    board.insert(board.begin()+3, {0, 0, 4, 0, 2, 0, 1, 0, 3, 0, 0});

    vector<pair<vector<vector<int>>, int>> boardList;
    vector<pair<vector<vector<int>>, int>> boardList2;
    //boardList.push_back(pair<vector<vector<int>>, int>(board, 0));

    vector<pair<vector<vector<int>>, int>> complete;


    // for (int i = 2; i <= 8; i+=2)
    // {
    //     for (int k = 1; k <= 4; ++k)
    //     {
    //         board[k][i] = i/2;
    //     }
    // }
    // for (int i = 2; i <= 8; i+=2) {
    //     board[1][i] = (10-i)/2;
    // }
    print(board);

    cout << "ans: " << recurse(board, 0) << endl;
    cout << "mew" << endl;

    // reference.insert(board);

    // if (reference.find(board) != reference.end()) {
    //     cout << "found" << endl;
    // }
    // else {
    //     cout << "not found" << endl;
    // }



    // vector<vector<int>> board2 = board;
    // for (int i = 2; i <= 8; i+=2)
    // {
    //     for (int k = 1; k <= 4; ++k)
    //     {
    //         board2[k][i] = i/2;
    //     }
    // }
    // print(board2);




    // cout << endl;
    // board2[0][1] = 4;

    // print(board2);



    //cout << lowest(board);

    //boardList = listLegals(board, 0);

    // for (int i = 0; i < boardList.size(); ++i)
    // {
    //     print(boardList[i].first);
    //     cout << boardList[i].second << endl;
    // }

    // cout << "hi" << endl;

    // boardList = listLegals2(board, 0);
    // cout << "bListSize: " << boardList.size() << endl;
    // sort(boardList.begin(), boardList.end(), compare);
    // for (int i = 0; i < boardList.size(); ++i)
    // {
    //     print(boardList[i].first);
    //     cout << boardList[i].second << endl << endl;
    // }


    // boardList.push_back(pair<vector<vector<int>>, int>(board, 0));
    // for (int i = 0; i < 14; ++i)
    // {
    //     //print(boardList[0].first);
    //     vector<pair<vector<vector<int>>, int>> temp;
    //     //cout << "boardList size: " << boardList.size() << endl;
    //     for (int k = 0; k < boardList.size(); ++k)
    //     {
    //         vector<pair<vector<vector<int>>, int>> currentList = listLegals2(boardList[k].first, boardList[k].second);
    //         //cout << "currentList size: " << currentList.size() << endl;
    //         for (int j = 0; j < currentList.size(); ++j)
    //         {
    //             // cout << "j: " << j << "    k: " << k << endl;
    //             // print(currentList[j].first);
    //             // cout << currentList[j].second << endl;
    //             if (isComplete(currentList[j].first)) {
    //                 //cout << "Early complete" << endl;
    //                 cout << currentList[j].second << endl;
    //                 print(currentList[j].first);
    //                 complete.push_back(currentList[j]);
    //             }
    //             else {
    //                 temp.push_back(currentList[j]);
    //             }
    //         }
    //         currentList.clear();
    //     }
    //     boardList.clear();


    //     if (temp.size() > 0) {
    //         boardList = temp;
    //     }
    //     temp.clear();

    //     set<pair<vector<vector<int>>, int>> yeet(boardList.begin(), boardList.end());
    //     vector<pair<vector<vector<int>>, int>> yeet2(yeet.begin(), yeet.end());
    //     boardList = yeet2;
    //     yeet.clear();
    //     yeet2.clear();

    //     cout << "i: " << i << "  " << boardList.size() << "   lowest: " << boardList[findLowestIndex(boardList)].second;
    //     cout << "    highest: " << boardList[findHighestIndex(boardList)].second << endl;
    // }





    // boardList2.push_back(pair<vector<vector<int>>, int>(board2, 0));
    // for (int i = 0; i < 8; ++i)
    // {
    //     //print(boardList2[0].first);
    //     vector<pair<vector<vector<int>>, int>> temp;
    //     //cout << "boardList2 size: " << boardList2.size() << endl;
    //     for (int k = 0; k < boardList2.size(); ++k)
    //     {
    //         vector<pair<vector<vector<int>>, int>> currentList = listLegals3(boardList2[k].first, boardList2[k].second);
    //         //cout << "currentList size: " << currentList.size() << endl;
    //         for (int j = 0; j < currentList.size(); ++j)
    //         {
    //             // cout << "j: " << j << "    k: " << k << endl;
    //             // print(currentList[j].first);
    //             // cout << currentList[j].second << endl;
    //             if (isComplete(currentList[j].first)) {
    //                 //cout << "Early complete" << endl;
    //                 cout << currentList[j].second << endl;
    //                 print(currentList[j].first);
    //                 complete.push_back(currentList[j]);
    //             }
    //             else {
    //                 temp.push_back(currentList[j]);
    //             }
    //         }
    //         currentList.clear();
    //     }
    //     boardList2.clear();


    //     if (temp.size() > 0) {
    //         boardList2 = temp;
    //     }
    //     temp.clear();

    //     set<pair<vector<vector<int>>, int>> yeet(boardList2.begin(), boardList2.end());
    //     vector<pair<vector<vector<int>>, int>> yeet2(yeet.begin(), yeet.end());
    //     boardList2 = yeet2;
    //     yeet.clear();
    //     yeet2.clear();

    //     cout << "i: " << i << "  " << boardList2.size() << "   lowest: " << boardList2[findLowestIndex(boardList2)].second;
    //     cout << "    highest: " << boardList2[findHighestIndex(boardList2)].second << endl;
    // }



    // cout << "EEEEEEEEEEEEEEEEEEEEEEE" << endl; 

    // cout << "completed: " << complete.size() << endl;
    // for (int i = 0; i < 7; ++i)
    // {
    //     for (int k = 0; k < boardList.size(); ++k)
    //     {
    //         boardList[k] = precipitate(boardList[k].first, boardList[k].second);
    //         if (isComplete(boardList[k].first)) {
    //             complete.push_back(boardList[k]);
    //         }
    //     }
    // }
    // cout << "completed: " << complete.size() << endl;

    // int lowestIndex = 0;
    // for (int i = 0; i < complete.size(); ++i)
    // {
    //     if (complete[i].second < complete[lowestIndex].second) {
    //         lowestIndex = i;
    //     }
    // }

    // print(complete[lowestIndex].first);
    // cout << complete[lowestIndex].second << endl;
    cout << "fin" << endl;
}

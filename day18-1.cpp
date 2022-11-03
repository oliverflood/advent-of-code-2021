#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* parentOf(Node* root, Node* node) {
    Node* left1 = NULL;
    Node* right1 = NULL;
    if (root->left != NULL) {
        if (root->left == node) {
            return(root);
        }
        else {
            left1 = parentOf(root->left, node);
        }
    }
    if (root->right != NULL) {
        if (root->right == node) {
            return(root);
        }
        else {
            right1 = parentOf(root->right, node);
        }
    }

    if (left1 != NULL) {
        return(left1);
    }
    if (right1 != NULL) {
        return(right1);
    }
    //cout << "exited with NULL IN PARENTOF FUNCTION " << endl;
    return(NULL);
}

bool isReal(Node* root, Node* node) {
    if (node->data != -1) {
        Node* temp = parentOf(root, node);
        if (temp->left->data + temp->right->data == node->data-1) {
            return(true);
        }
    }
    return(false);
}

int depth(Node* root, Node* node, int currentDepth) {
    if (root == node) {
        return(0);
    }
    currentDepth++;
    int left1 = -1;
    int right1 = -1;
    if (root->left != NULL) {
        if (root->left == node) {
            return(currentDepth);
        }
        else {
            left1 = depth(root->left, node, currentDepth);
        }
    }
    if (root->right != NULL) {
        if (root->right == node) {
            return(currentDepth);
        }
        else {
            right1 = depth(root->right, node, currentDepth);
        }
    }

    if (left1 != -1) {
        return(left1);
    }
    else if (right1 != -1) {
        return(right1);
    }
    return(-1);
}

int maxDepth(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return(1);
    }
    else {
        return(max(maxDepth(root->left), maxDepth(root->right))+1);
    }
}

vector<Node*> listOut(Node* root, Node* node) {
    vector<Node*> leafList;
    if (node->left == NULL && node->right == NULL) {
        leafList.push_back(node);
        return(leafList);
    }
    else {
        vector<Node*> leafList3 = listOut(root, node->left);
        for (int i = 0; i < leafList3.size(); ++i)
        {
            leafList.push_back(leafList3[i]);
        }
        vector<Node*> leafList2 = listOut(root, node->right);
        for (int i = 0; i < leafList2.size(); ++i)
        {
            leafList.push_back(leafList2[i]);
        }
    }
    return(leafList);
}

void explode(Node* &root) {
    vector<Node*> leafList = listOut(root, root);
    //cout << leafList.size() << endl;
    for (int i = 0; i < leafList.size(); ++i)
    {
        if (depth(root, leafList[i], 0) > 4 && !isReal(root, leafList[i])) {
            if (i > 0) {
                for (int k = i-1; k >= 0; --k)
                {
                    if (isReal(root, leafList[k])) {
                        leafList[k]->data += leafList[i]->data;
                        break;
                    }
                }
            }
            if (i+2 < leafList.size()) {
                for (int k = i+2; k < leafList.size(); ++k)
                {
                    if (isReal(root, leafList[k])) {
                        leafList[k]->data += leafList[i+1]->data;
                        break;
                    }
                }
            }
            Node* parent = parentOf(root, leafList[i]);
            parent->data = 0;
            //cout << "parent of " << leafList[i]->data << " is " << parent->data << endl;

            delete leafList[i];
            parent->left = NULL;
            delete leafList[i+1];
            parent->right = NULL;
            
            break;
        }
    }
}

void split(Node* &node) {
    node->left = new Node(node->data/2);
    node->right = new Node(node->data/2 + node->data%2);
    node->data = -1;
}

// bool isReducable(Node* root) {
//     vector<Node*> leafList = listOut(root, root);
//     for (int i = 0; i < leafList.size(); ++i)
//     {
//         if (depth(root, leafList[i], 0) > 4) {
//             return(true);
//         }
//         if (leafList[i]->data >= 10) {
//             return(true);
//         }
//     }
//     return(false);
// }

Node* maxNode(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return(root);
    }
    else {
        if (maxNode(root->left)->data > maxNode(root->right)->data) {
            return(maxNode(root->left));
        }
        else {
            return(maxNode(root->right));
        }
        //return(maxNode(root->left)->data>maxNode(root->right)->data?root->left:root->right);
        //finesse
    }
}

void reduce(Node* &root) {
    while(maxDepth(root) > 4 || maxNode(root)->data > 9) {
        cout << "beans" << endl;
        vector<Node*> leafList = listOut(root, root);
        if (maxDepth(root) > 4) {
            explode(root);
            continue;
        }
        else {
            for (int i = 0; i < leafList.size(); ++i)
            {
                if (leafList[i]->data >= 10) {
                    split(leafList[i]);
                    break;
                }
            }
        }
    }
}


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    cout << s << endl;

    struct Node* root = new Node(-1);
    struct Node* temp = root;


    for (int i = 1; i < s.length(); ++i)
    {
        if (s.at(i) == '[') {
            
            if (s.at(i-1) == ',') {
                temp->right = new Node(-1);
                temp = temp->right;
            }
            else {
                temp->left = new Node(-1);
                temp = temp->left;
            }
        }
        else if (isdigit(s.at(i))) {
            if (s.at(i-1) == ',') {
                temp->right = new Node(s.at(i)-'0');
            }
            else {
                temp->left = new Node(s.at(i)-'0');
            }
        }
        else if (s.at(i) == ']') {
            temp = parentOf(root, temp);
        }
    }

    //cout << isReal(root, tempo) << endl;

    // cout << "t: " << root->right->right->right->left->data << endl;
    // cout << "p: " << parentOf(root,tempo)->left->data << endl;

    // if (tempo->data != -1) {
    //     Node* temp1 = parentOf(root, tempo);
    //     if (temp1->left->data + temp1->right->data == tempo->data-1) {
    //         cout << "TRUE";
    //     }
    //     else {
    //         cout << "FALSE";
    //     }
    // }
    cout << "dee: " << maxNode(root)->data << endl;


    // vector<Node*> leafList = listOut(root, root);
    // for (int i = 0; i < leafList.size(); ++i)
    // {
    //     cout << leafList[i]->data << endl;
    // }
    // cout << endl << endl;

    // reduce(root);

    // leafList = listOut(root, root);
    // for (int i = 0; i < leafList.size(); ++i)
    // {
    //     cout << leafList[i]->data << endl;
    // }

    cout << endl << "endl" << endl;
}

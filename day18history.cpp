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
 
    // val is the key or the value that
    // has to be added to the data part
    Node(int val)
    {
        data = val;
 
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};

Node* parentOf(Node* root, Node* node) {
    Node* left1;
    Node* right1;
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
    else if (right1 != NULL) {
        return(right1);
    }
    //cout << "exited with NULL IN PARENTOF FUNCTION " << endl;
    return(NULL);
}

Node* rightOf(Node* root, Node* node) {
    while(true) {
        cout << endl;
        if (parentOf(root, node) == NULL) {
            cout << "exited with NULL " << endl;
            return(NULL);
        }
        Node* parent = parentOf(root, node);
        //cout << "parent " << parent->data << "   node " << node->data << endl;
        if (parent->right == node) {
            node = parent;
        }
        else {
            node = parent;
            break;
        }
    }
    node = node->right;
    while(true) {
        if (node->left == NULL) {
            return(node);
        }
        else {
            node = node->left;
        }
    }
}

Node* leftOf(Node* root, Node* node) {
    while(true) {
        cout << endl;
        if (parentOf(root, node) == NULL) {
            cout << "exited with NULL " << endl;
            return(NULL);
        }
        Node* parent = parentOf(root, node);
        //cout << "parent " << parent->data << "   node " << node->data << endl;
        if (parent->left == node) {
            node = parent;
        }
        else {
            node = parent;
            break;
        }
    }
    node = node->left;
    while(true) {
        if (node->right == NULL) {
            return(node);
        }
        else {
            node = node->right;
        }
    }
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

Node* r(Node* root, Node* node) {
    while(true) {
        Node* r1 = rightOf(root, node);
        if (r1 == NULL) {
            return(NULL);
        }
        if (isReal(root, r1)) {
            return(r1);
        }
        else{
            return(r(root, r1));
        }
    }
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
    //cout << "exited with NULL IN PARENTOF FUNCTION " << endl;
    return(-1);
}

vector<Node*> listOut(Node* root, Node* node) {
    vector<Node*> leafList;
    if (node->left == NULL && node->right && NULL) {
        
    }
}

int main()
{
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

    struct Node* tempo = root->right;
    cout << "tempo data " << tempo->data << endl;

    // cout << "parentOf " << parentOf(root, tempo)->data << endl;
    // cout << "r " << rightOf(root, tempo) << endl;

    // if (rightOf(root, tempo) != NULL) {
    //     cout << "r " << rightOf(root, tempo)->data << endl;
    // }
    // else {
    //     cout << "r NULL" << endl;
    // }

    //cout << depth(root, tempo, 0);
    

    cout << "end" << endl;
}

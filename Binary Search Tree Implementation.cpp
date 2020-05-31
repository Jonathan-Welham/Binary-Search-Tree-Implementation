/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw8/challenges/binary-tree-4/submissions/code/1322597168
 * Title: hw8_1.cpp
 * Abstract: This program provides functions for a binary tree
 * Author: Jonathan Welham
 * ID: 6781
 * Date: 04/06/2020
 */

// A simple implementation of a binary tree with "struct" in C++.
// It displays all nodes using the inorder traversal.
// Written by EIR and Dr. Byun for CST370.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

struct Node
{
    // Data part for a node.
    int data;
    Node* left;
    Node* right;
    Node* parent;

    // Constructor for a new node.
    Node(int d)
    {
        data = d;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};


//Function declarations
Node* mkTree(int data, Node* left, Node* right);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);
void commands();
void isBST(Node* root);
void append(Node* root, int data);
void deleteLastNode(Node* root);
int height(int N);
void levelOrder(Node* root);


vector<Node*> _LEAFS;
bool _FLAG = false;
int main()
{
    int rootVal;
    cin >> rootVal;

    Node* root = new Node(rootVal);
    _LEAFS.push_back(root);

    int numCommands;
    cin >> numCommands;

    for(int i = 0; i < numCommands; i++){
        commands();
    }

    return 0;
}

void commands(){
    string temp;
    cin >> temp;

    int caseValue = 0;

    if(temp == "append"){
        int appendValue;
        cin >> appendValue;
        if(_LEAFS.empty()){
            Node* temp = new Node(appendValue);
            _LEAFS.push_back(temp);
        } else {
            for (int i = 0; _FLAG != true; i++) {

                append(_LEAFS[i], appendValue);
            }
            _FLAG = false;
        }
    }
    else if(temp == "isBST"){
        isBST(_LEAFS[0]);
    }
    else if(temp == "height"){
        if(_LEAFS.empty()){
            cout << "-1\n";
        }else {
            cout << height(_LEAFS.size()) << endl;
        }
    }
    else if(temp == "levelOrder"){
        if (!_LEAFS.empty()) {
            levelOrder(_LEAFS[0]);
        }
    }
    else if(temp == "deleteLastNode"){
        if(!_LEAFS.empty()){
            deleteLastNode(_LEAFS[_LEAFS.size()-1]);
        }
    }
    else if(temp == "preOrder"){
        if (!_LEAFS.empty()) {
            preOrder(_LEAFS[0]);
            cout << endl;
        }
    }
    else if(temp == "inOrder"){
        if (!_LEAFS.empty()) {
            inOrder(_LEAFS[0]);
            cout << endl;
        }
    }
    else if(temp == "postOrder"){
        if (!_LEAFS.empty()) {
            postOrder(_LEAFS[0]);
            cout << endl;
        }
    }
}

void append(Node* root, int data){
    //Fix this function
    if(!root){
        return;
    }
    if(!root->left){
        Node* temp = new Node(data);
        root->left = temp;
        temp->parent = root;
        _LEAFS.push_back(temp);
        _FLAG = true;
    }
    else if(!root->right){
        Node* temp = new Node(data);
        root->right = temp;
        temp->parent = root;
        _LEAFS.push_back(temp);
        _FLAG = true;
    }
}

void inOrder(Node* root)
{
    if (root != nullptr)  // Or simply "if (root)"
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

//From: https://www.geeksforgeeks.org/check-if-a-binary-tree-is-bst-simple-and-efficient-approach/
// Utility function to check if Binary Tree is BST
bool isBSTUtil(Node* root, int& prev)
{
    // traverse the tree in inorder fashion and
    // keep track of prev node
    if (root) {
        if (!isBSTUtil(root->left, prev))
            return false;

        // Allows only distinct valued nodes
        if (root->data <= prev)
            return false;

        // Initialize prev to current
        prev = root->data;

        return isBSTUtil(root->right, prev);
    }

    return true;
}

//From: https://www.geeksforgeeks.org/check-if-a-binary-tree-is-bst-simple-and-efficient-approach/
// Function to check if Binary Tree is BST
void isBST(Node* root)
{
    if (root) {
        int prev = INT_MIN;
        bool check = isBSTUtil(root, prev);
        if (check) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
}

int height(int N){
    return ceil(log2(N+1)) - 1;
}

void levelOrder(Node* root){
    if(root){
        for(int i = 0; i < _LEAFS.size(); i++){
            cout << _LEAFS[i]->data << " ";
        }
        cout << endl;
    }
}

void deleteLastNode(Node* root){
    if (root) {
        if(root->parent) {
            if (root->parent->right) {
                root->parent->right = nullptr;
                _LEAFS.pop_back();
                return;
            } else if (root->parent->left) {
                root->parent->left = nullptr;
                _LEAFS.pop_back();
                return;
            }
        }
        else{
            _LEAFS.pop_back();

        }
    }
}

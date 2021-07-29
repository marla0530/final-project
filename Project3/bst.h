#pragma once
using namespace std;
#include <vector>
#include<string>
#include <iostream>
struct node {
    vector<string> teams;
    double powerlevel;
    node* left;
    node* right;
    node(double x, string name) {
        powerlevel = x, left = nullptr, right = nullptr, teams.push_back(name);
    }
};
class BST {
public:
    node* root=nullptr;
    node* insert(node* root, double& key, string& teamName);
    void kLargest(node* root, int& k);
    void top25();
};

node* BST::insert(node* root, double& key, string& teamName) {
    if (root == NULL) {
        return new node(key, teamName);
    }
    else if (root->powerlevel == key) {
        root->teams.push_back(teamName);
        return root;
    }
    if (key < root->powerlevel) {
        root->left = insert(root->left, key, teamName);
    }
    else {
        root->right = insert(root->right, key, teamName);

    }
    return root;
}

void BST::kLargest(node* root, int& k) {
    if (root == NULL) {
        return;
    }
    kLargest(root->right, k);
    if (k <= 0) {
        return;
    }
    else if (k <= root->teams.size()) {
        cout << root->teams[k-1]<<endl;
        k = 0;
        return;
    }
    else {
        k -= root->teams.size();
    }
    kLargest(root->left, k);
}

void BST::top25() {
    for (int i = 1; i < 26; i++) {
        cout << i << ", ";
        int temp = i;
        kLargest(root, temp);
    }
}
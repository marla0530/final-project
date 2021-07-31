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


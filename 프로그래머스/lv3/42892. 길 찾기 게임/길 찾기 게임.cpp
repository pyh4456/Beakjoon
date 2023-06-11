#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> preorder, postorder;

class node {
public:
    int x;
    int y;
    int v;
    node* right = nullptr;
    node* left = nullptr;
    node* parent = nullptr;

    node(int x, int y, int v) {
        this->y = y;
        this->x = x;
        this->v = v;
    }

    void insert(int x, int y, int v) {
        if (x > this->x) {
            if (right == nullptr) {
                right = new node(x, y, v);
            }
            else {
                right->insert(x, y, v);
            }
        }
        else {
            if (left == nullptr) {
                left = new node(x, y, v);
            }
            else {
                left->insert(x, y, v);
            }
        }
    }

    void preorder_traverse() {
        preorder.push_back(this->v);
        if (left != nullptr) {
            left->preorder_traverse();
        }
        if (right != nullptr) {
            right->preorder_traverse();
        }
    }

    void postorder_traverse() {

        if (left != nullptr) {
            left->postorder_traverse();
        }
        if (right != nullptr) {
            right->postorder_traverse();
        }
        postorder.push_back(this->v);
    }
};

bool compare(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }

    return a[1] > b[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i + 1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), compare);

    node tree(nodeinfo[0][0], nodeinfo[0][1], nodeinfo[0][2]);

    for (int i = 1; i < nodeinfo.size(); i++) {
        tree.insert(nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2]);
    }

    tree.preorder_traverse();
    tree.postorder_traverse();

    answer.push_back(preorder);
    answer.push_back(postorder);


    return answer;
}
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    vector<int> data;
    Node *left;
    Node *right;

    // Val is the key or the value that has to be added to the data part
    Node(vector<int> val)
    {
        data = val;
        // Left and right child for node will be initialized to null
        left = NULL;
        right = NULL;
    }
};

Node *CreateNode(vector<int> data)
{
    Node *newNode = new Node(data);
    if (!newNode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->left = newNode->right = NULL;
    return newNode;
}

void InsertNode(Node *root, vector<int> data)
{
    // If the tree is empty, assign new node address to root.
    if (root == NULL)
    {
        root = CreateNode(data);
        return;
    }
    Node *tmp = root;

    while (true)
    {
        Node *tmp2 = tmp;
        if (tmp2->data[0] > data[0])
        {
            if (tmp2->left == NULL)
            {
                tmp2->left = CreateNode(data);
                break;
            }
            else
                tmp = tmp->left;
        }
        else
        {
            if (tmp2->right == NULL)
            {
                tmp2->right = CreateNode(data);
                break;
            }
            else
                tmp = tmp->right;
        }
    }
}

bool y_sort(vector<int> a, vector<int> b)
{
    return a[1] > b[1];
}

void preorder(struct Node *node, vector<int> &ret, map<vector<int>, int> &map)
{
    if (node == NULL)
        return;
    ret.push_back(map[node->data]);
    preorder(node->left, ret, map);
    preorder(node->right, ret, map);
}

void postorder(struct Node *node, vector<int> &ret, map<vector<int>, int> &map)
{
    if (node == NULL)
        return;
    postorder(node->left, ret, map);
    postorder(node->right, ret, map);
    ret.push_back(map[node->data]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    map<vector<int>, int> map;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        map.insert(pair<vector<int>, int>(nodeinfo[i], i + 1));
    }

    sort(nodeinfo.begin(), nodeinfo.end(), y_sort);
    Node *root = new Node(nodeinfo[0]);
    for (int i = 1; i < nodeinfo.size(); i++)
    {
        InsertNode(root, nodeinfo[i]);
    }

    vector<int> pre_order;
    vector<int> post_order;
    preorder(root, pre_order, map);
    postorder(root, post_order, map);
    answer.push_back(pre_order);
    answer.push_back(post_order);

    return answer;
}

int main()
{
    vector<vector<int>> a = {
        {5, 3},
        {11, 5},
        {13, 3},
        {3, 5},
        {6, 1},
        {1, 3},
        {8, 6},
        {7, 2},
        {2, 2}};
    solution(a);
}

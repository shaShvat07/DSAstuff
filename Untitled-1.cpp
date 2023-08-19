#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#define ll long long
#define MOD 1000000007
#define f(i, n) for (int i = 0; i < n; i++)
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cin >> leftChildData;

        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        int RightChildData;
        cin >> RightChildData;

        if (RightChildData != -1)
        {
            BinaryTreeNode<int> *RightChild = new BinaryTreeNode<int>(RightChildData);
            front->right = RightChild;
            pendingNodes.push(RightChild);
        }
    }
    return root;
}

int findCousinSum(BinaryTreeNode<int> *root, int val)
{
    if (root == NULL || root->data == val)
        return -1;

    int temp = 0;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    bool check = false;

    while (!q.empty())
    {
        if (check == true)
        {
            return temp;
        }

        int size = q.size();
        temp = 0;

        while (size > 0)
        {
            root = q.front();
            q.pop();
            if ((root->left && root->left->data == val) || (root->right && root->right->data == val))
            {
                check = true;
            }
            else
            {
                if (root->left)
                {
                    temp += root->left->data;
                    q.push(root->left);
                }
                if (root->right)
                {
                    temp += root->right->data;
                    q.push(root->right);
                }
            }
            size--;
        }
    }
    return -1;
}

int main()
{
    int k;
    cin >> k;
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << findCousinSum(root, k) << "\n";
    return 0;
}

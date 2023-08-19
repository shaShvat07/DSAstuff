#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>
void printLevelWise(BinaryTreeNode<int> *root)
{
    // Write your code here
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        cout << front->data << ":";
        pendingNodes.pop();

        if (front->left == NULL)
        {
            cout << "L:-1,";
        }
        else
        {
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }

        if (front->right == NULL)
        {
            cout << "R:-1";
        }
        else
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data : " << endl;
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

        cout << "Enter Left Child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;

        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout << "Enter Right Child of " << front->data << endl;
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

void PrintBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << ",";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }

    cout << endl;
    PrintBinaryTree(root->left);
    PrintBinaryTree(root->right);
}

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + numNodes(root->left) + numNodes(root->right);
}

void inOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// Height of tree
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}
// Diameter of tree
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = height(root->right) + height(root->left);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh,rh);
    int diameter = max(lh+rh , max(ld,rd));

    pair <int , int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here

	if (root == NULL)
	return NULL; 
	else if ( root != NULL  && root -> left == NULL && root-> right == NULL)
	{
		delete root; 
	}
	if(root->left != NULL )
	root->left = removeLeafNodes(root->left);

	if(root->right != NULL)
	root->right = removeLeafNodes(root->right);

	return root;
}
int findCousinSum(BinaryTreeNode<int>* root, int val)
{
    if (root == NULL || root->data == val)
        return -1;
 
    int temp = 0;
 
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
 
    bool check = false;
 
    while (!q.empty()) {
 
        if (check == true) {
            return temp;
        }
 

    int size = q.size();
        temp = 0;
 
        while (size > 0) {
            root = q.front();
            q.pop();

            if ((root->left && root->left->data == val)
                || (root->right && root->right->data == val)) {
                check = true;
            }
 

            else {
                if (root->left) {
                    temp += root->left->data;
                    q.push(root->left);
                }
 
                if (root->right) {
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
    BinaryTreeNode<int> *root = takeInputLevelWise();
   
    // root = removeLeafNodes(root);
    printLevelWise(root);
    cout << "Ans" << endl;
    cout << findCousinSum(root, 13) << "\n";
    cout << findCousinSum(root, 7) << "\n";
    
    return 0;
}
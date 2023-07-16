#include <iostream>
using namespace std;
#include <queue>
#include "treeNode.cpp"

treeNode<int> *takeLevelwiseInput()
{
	int rootData;
	cout << "Enter data : " << endl;
	cin >> rootData;
	treeNode<int> *root = new treeNode<int>(rootData);

	queue<treeNode<int> *> pendingNodes;

	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		treeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter no. of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++)
		{
			int childData;
			cout << "Enter " << i + 1 << "th child of " << front->data << endl;
			cin >> childData;
			treeNode<int> *child = new treeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

treeNode<int> *takeInput()
{
	int rootData;
	cout << "Enter data : " << endl;
	cin >> rootData;
	treeNode<int> *root = new treeNode<int>(rootData);
	int n;
	cout << "Enter number of branches: " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		treeNode<int> *child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(treeNode<int> *root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->data << ": ";
	for (int i = 0; i < root->children.size(); i++)
	{
		if (i == root->children.size() - 1)
			cout << root->children[i]->data;
		else
			cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); i++)
	{
		printTree(root->children[i]);
	}
}

void printLevelwiseTree(treeNode<int> *root)
{
	if (root == NULL)
		return;

	queue<treeNode<int> *> nodeHero;
	nodeHero.push(root);
	while (nodeHero.size() != 0)
	{
		treeNode<int> *front = nodeHero.front();
		nodeHero.pop();
		cout << front->data << ": ";
		for (int i = 0; i < front->children.size(); i++)
		{
			cout << front->children[i]->data << "  ";
			nodeHero.push(front->children[i]);
		}
		cout << endl;
	}
}

void printAtlevelK(treeNode<int> *root, int k)
{
	if (root == NULL)
		return;

	if (k == 0)
	{
		cout << root->data << " ";
		return;
	}

	for (int i = 0; i < root->children.size(); i++)
	{
		printAtlevelK(root->children[i], k - 1);
	}
}

void preOrder(treeNode<int> *root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";

	for (int i = 0; i < root->children.size(); i++)
	{
		preOrder(root->children[i]);
	}
}

void postOrder(treeNode<int> *root)
{
	if (root == NULL)
		return;

	if (root->children.size() == 0)
	{
		cout << root->data << " ";
		return;
	}

	for (int i = 0; i < root->children.size(); i++)
	{
		postOrder(root->children[i]);
	}
	cout << root->data << " ";
}

int main()
{
	treeNode<int> *root = takeLevelwiseInput();
	cout << "Enter level" << endl;
	int k;
	cin >> k;
	printAtlevelK(root, k - 1);
	cout << endl;
	cout << "Preorder " << endl;
	preOrder(root);
	cout << endl;
	cout << "Postorder" << endl;
	postOrder(root);
	delete root;
	return 0;
}

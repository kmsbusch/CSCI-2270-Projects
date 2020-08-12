#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

MovieTree::MovieTree()
{
	root = NULL;
}

void deleteAllLists(TreeNode *node)
{
	if (node == NULL)
		return;

	LLMovieNode *temp = node->head;
	while (temp != NULL)
	{
		LLMovieNode *LLNode = temp->next;
		delete temp;
		temp = LLNode;
	}
	//delete node->head;

	deleteAllLists(node->rightChild);
	deleteAllLists(node->leftChild);
}

void deleteTree(TreeNode *&node)
{
	if (node == NULL)
	{
		return;
	}

	deleteTree(node->leftChild);
	deleteTree(node->rightChild);

	delete node;
}

MovieTree::~MovieTree()
{
	deleteAllLists(root);
	deleteTree(root);
}

////////////////////////////////////////////////////////////////////

void printLinkedList(LLMovieNode *node)
{
	LLMovieNode *temp = node;
	while (temp != NULL)
	{
		cout << " >> " << temp->title << " " << temp->rating << endl;
		temp = temp->next;
	}
}

void printTree(TreeNode *node)
{
	if (node == NULL)
	{
		return;
	}

	printTree(node->leftChild);
	cout << "Movies starting with letter: " << node->titleChar << endl;
	printLinkedList(node->head);
	printTree(node->rightChild);
}

void MovieTree::printMovieInventory()
{
	printTree(root);
}

/////////////////////////////////////////////////////////////////////////////////////////

TreeNode *existsTreeNode(TreeNode *node, char target)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (node->titleChar == target)
	{
		return node;
	}

	TreeNode *temp1 = existsTreeNode(node->rightChild, target);
	TreeNode *temp2 = existsTreeNode(node->leftChild, target);

	if (temp1 == NULL && temp2 == NULL)
	{
		return NULL;
	}
	else
	{
		return (temp1 == NULL) ? temp2 : temp1;
	}
}

void addTreeNode(TreeNode *&node, TreeNode *nodeParent, char c)
{
	if (node == NULL)
	{
		TreeNode *temp = new TreeNode;
		temp->titleChar = c;
		temp->parent = nodeParent;
		node = temp;
		return;
	}
	if (c < node->titleChar)
	{
		addTreeNode(node->leftChild, node, c);
	}
	else
	{
		addTreeNode(node->rightChild, node, c);
	}
	return;
}

void insertLinkedList(LLMovieNode *&head, LLMovieNode *&node)
{
	if (head == NULL)
	{
		head = node;
		return;
	}

	LLMovieNode *point = head;
	LLMovieNode *lag = NULL;
	while (point != NULL)
	{
		if (node->title < point->title)
		{
			if (lag == NULL)
			{
				node->next = head;
				head = node;
			}
			else
			{
				node->next = point;
				lag->next = node;
			}
			return;
		}
		lag = point;
		point = point->next;
	}
	lag->next = node;
}

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
	LLMovieNode *node = new LLMovieNode(ranking, title, year, rating);
	TreeNode *targetNode = existsTreeNode(root, title[0]);
	if (targetNode == NULL)
	{
		addTreeNode(root, NULL, title[0]);
		targetNode = existsTreeNode(root, title[0]);
	}

	insertLinkedList(targetNode->head, node);
}

////////////////////////////////////////////////////////////////////////////////////////

TreeNode *findNode(TreeNode *node, char c)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (node->titleChar == c)
	{
		return node;
	}

	TreeNode *temp1 = findNode(node->rightChild, c);
	TreeNode *temp2 = findNode(node->leftChild, c);

	return (temp1 == NULL && temp2 == NULL) ? NULL : (temp1 == NULL) ? temp2 : temp1;
}

TreeNode *findMinVal(TreeNode *node)
{
	if (node->leftChild == NULL)
		return node;
	return findMinVal(node->leftChild);
}

TreeNode *deleteNode(TreeNode *node, char c)
{
	if (node == NULL)
	{
		return NULL;
	}
	else if (c < node->titleChar)
	{
		node->leftChild = deleteNode(node->leftChild, c);
	}
	else if (c > node->titleChar)
	{
		node->rightChild = deleteNode(node->rightChild, c);
	}
	else
	{
		if (node->leftChild == NULL && node->rightChild == NULL)
		{
			delete node;
			node = NULL;
		}
		else if (node->leftChild == NULL)
		{
			TreeNode *temp = node;
			node = node->rightChild;
			delete temp;
		}
		else if (node->rightChild == NULL)
		{
			TreeNode *temp = node;
			node = node->leftChild;
			delete temp;
		}
		else
		{
			TreeNode *min = findMinVal(node->rightChild);
			node->titleChar = min->titleChar;
			node->head = min->head;
			node->rightChild = deleteNode(node->rightChild, node->titleChar);
		}
	}
	return node;
}

void MovieTree::deleteMovie(string title)
{
	TreeNode *node = findNode(root, title[0]);
	if (node != NULL)
	{
		LLMovieNode *point = node->head;
		LLMovieNode *lag = NULL;
		while (point != NULL)
		{
			if (point->title == title)
			{
				LLMovieNode *temp = point;

				if (lag == NULL)
				{
					node->head = temp->next;
				}
				else
				{
					lag->next = temp->next;
				}

				delete temp;

				if (node->head == NULL)
				{
					root = deleteNode(root, title[0]);
				}
				//				cout << root->titleChar << endl;
				return;
			}

			lag = point;
			point = point->next;
		}
	}

	cout << "Movie: " << title << " not found, cannot delete." << endl;
}

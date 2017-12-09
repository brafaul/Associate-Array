//Name: assoc.cpp
//Description: Implements the associative array class
//Author: Brayden Faulkner

#include "assoc.h"
#include <iostream>
#include <fstream>

using namespace std;

Node::Node(string key)
{
	left = NULL;
	right = NULL;
	this->key = key;
}
/*
string Node::getKey()
{
	return key;
}
*/
/*
void Node::setKey(string key)
{
	this->key = key;
}
*/
assoc::assoc()
{
	root = NULL;
}

assoc::~assoc()
{
	destructorHelper(root);
}

void assoc::destructorHelper(Node *current)
{
	if(current != NULL)
	{
		destructorHelper(current->left);
		destructorHelper(current->right);
		delete current;
	}
}

void assoc::insert(string insertKey, int data)
{
	if(root == NULL)
	{
		root = new Node(insertKey);
		root->data = data;
	}
	else
		insertHelper(root, insertKey, data);
}

void assoc::insertHelper(Node *current, std::string insertKey, int value)
{
	if(insertKey.compare(current->key) < 0){
		if(current->left == NULL)
		{
			current->left = new Node(insertKey);
			current->left->data = value;
		}
		else
			insertHelper(current->left, insertKey, value);
	}
	else 
	{
		if(current->right == NULL)
		{
			current->right = new Node(insertKey);
			current->right->data = value;
		}
		else
			insertHelper(current->right, insertKey, value);
	}
}
void assoc::find(string key)
{
	findHelp(root, key);
}
void assoc::findHelp(Node *current, string key)
{
	if(current == NULL)
		return;
	else if(key.compare(current->key) < 0)
		findHelp(current->left, key);
	else if(key.compare(current->key) > 0)
		findHelp(current->right,key);
	else
		cout << current->key << " " << current->data << endl;
}
void assoc::print()
{
	printHelper(root);
	cout << endl;
}
void assoc::printHelper(Node *current)
{
	if(current != NULL)
	{
		printHelper(current->left);
		cout << current->key << " " << current->data << endl;
	        printHelper(current->right);	
	}
}
void assoc::min()
{
	if(root != NULL)
		minHelp(root);
	else
		cout << "Array is empty." << endl;
}
void assoc::minHelp(Node *current)
{
	if(current->left == NULL)
		cout << current->key << " " << current->data <<endl;
	else
		minHelp(current->left);
}
void assoc::max()
{
	if(root != NULL)
		maxHelp(root);
	else
		cout << "Array is empty." << endl;
}
void assoc::maxHelp(Node *current)
{
	if(current->right == NULL)
		cout << current->key << " " << current->data <<endl;
	else 
		maxHelp(current->right);
}
void assoc::save_file(string fileName)
{
	ofstream output(fileName.c_str());
	saveHelp(root, fileName, output);
}
void assoc::saveHelp(Node *current, string fileName, ofstream& output)
{
	if(current != NULL)
	{
		saveHelp(current->left, fileName, output);
		output << current->key << " " << current->data << endl;
		saveHelp(current->right, fileName, output);
	}
}
void assoc::deleteNode(string deleteKey)
{
	deleteHelp(root, deleteKey);
}
void assoc::deleteHelp(Node *current, string deleteKey)
{
	if(current == NULL)
		return;
	else if(deleteKey.compare(current->key) < 0)
		deleteHelp(current->left, deleteKey);
	else if(deleteKey.compare(current->key) > 0)
		deleteHelp(current->right, deleteKey);
	else
	{
		Node *temp;
		if(current->left == NULL &&  current->right ==NULL)
			delete current;
		else if(current->left == NULL)
		{
			temp = current->right;
			delete current;
			current = temp;
		}
		else if(current->right == NULL)
		{
			temp = current->left;
			delete current;
			current = temp;
		}
		else
		{
			temp = current->right;
			Node *parent = NULL;
			while(temp->left != NULL)
			{
				parent = temp;
				temp = temp->left;
			}
			current->key = temp->key;
			current->data = temp->data;
			if(parent != NULL)
				deleteHelp(parent->left, parent->left->key);
			else
				deleteHelp(current->right, current->right->key);
		}

	}
}
/*int &assoc::operator[](string opKey)
{
	return operatorHelp(root, opKey);

}
&int assoc::operatorHelp(Node *current, std::string opKey)
{
	if(opKey.compare(current->key) == 0)
	{
		int& temp = current->data;
		return temp;
	}
		
}
*/

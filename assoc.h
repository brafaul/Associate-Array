//Name: assoc.h
//Description: Declaration of the associated array class
//Author: Brayden Faulkner
#ifndef ASSOC_H
#define ASSOC_H

#include <string>
#include <fstream>

class Node 
{
	private:
		//std::string key;
	public:
		Node(std::string key);
		std::string key;
		//void setKey(std::string key) ;
		//std::string getKey();
		Node *left, *right;
		int data;
};

class assoc
{
	public:
		assoc();
		//Default Constructor: Intializes the root value to NULL
		~assoc();
		//Destructor
		void insert(std::string insertKey, int data);
		//Inserts a new node into the associated array
		void find(std::string key);
		//Finds a a value in the tree based on the key that is given
		void print();
		//Prints out the tree
		void min();
		//Prints out the value associated with the smallest key
		void max();
		//Prints out the value associated with the largest key
		void save_file(std::string fileName);
		//Saves the tree to the file
		void deleteNode(std::string deleteKey);
		//Deletes a node from the tree
		//int &operator[](std::string opKey);
	private:
		Node *root;
		void destructorHelper(Node *current);
		void insertHelper(Node *current, std::string insertKey, int value);
		void findHelp(Node *current, std::string key);
		void printHelper(Node *current);
		void minHelp(Node *current);
		void maxHelp(Node *current);
		void saveHelp(Node *current, std::string fileName, std::ofstream& output);
		void deleteHelp(Node *current, std::string deleteKey);
		//int *operatorHelp(Node *current, std::string opKey);
};
#endif

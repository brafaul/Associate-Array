//Name: main.cpp
//Description: Serves as the driver for the associated array program
//Author: Brayden Faulkner

#include <iostream>
#include <fstream>
#include "assoc.h"

using namespace std;

int main()
{
	int command = -1;
	assoc array;
	while(command != 9)
	{
		cout << "Welcome to the UTM Associated Array program. What would you like to do?" << endl;
		cout << "1. Insert a value into the array" << endl;
		cout << "2. Read a file into the array" << endl;
		cout << "3. Find a value in the array" << endl;
		cout << "4. Print out the array" << endl;
		cout << "5. Find the smallest key in the array" << endl;
		cout << "6. Find the largest key in the array" << endl;
		cout << "7. Save the array to the file" << endl;
		cout << "8. Delete a value from the file" << endl;
		cout << "9. Quit" << endl;
		cout << "Enter your command now" << endl;
		cin >> command;
		if(command == 1)
		{
			string key;
			int data;
			cout << "What is the key you would like to enter?" << endl;
			cin >> key;
			cout << "What is the value you would like to enter?" << endl;
			cin >> data;
			array.insert(key, data);
		}
		if(command == 2)
		{
			string fileName;
			cout << "What is the name of the file you want to read from?" << endl;
			cin >> fileName;
			ifstream input(fileName.c_str());
			int i = 0;
			while(input)
			{
				string word;
				char x;
				word.clear();
				x = input.get();
				while(x != ' ' || x != '.' || x != '?' || x != '!' || x != ',' || x != '*' || x != '#' || x != '1' || x != '2' || x != '3' || x != '4' || x != '5' || x != '6' || x != '7' || x != '8' || x != '9' || x != '0' )
				{
					word = word + x;
					x = input.get();
				}
				array.insert(word, i);
				i++;
			}
		}
		if(command == 3)
		{
			string key;
			cout << "What is the key you would like to find?" << endl;
		       	cin >> key;	
			array.find(key);
		}
		if(command == 4)
		{
			array.print();
		}
		if(command == 5)
		{
			array.min();
		}
		if(command == 6)
		{
			array.max();
		}
		if(command == 7)
		{
			string fileName;
			cout << "What is the name of the file you would like to save to?" << endl;
			cin >> fileName;
			array.save_file(fileName);
		}
		if(command == 8)
		{
			string key;
			cout << "What is the key you would like to delete" << endl;
			cin >> key;
			array.deleteNode(key);
		}

	}
}

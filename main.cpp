#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include<string>
using namespace std;

/**
 *  IMPORTANT!! YOU MUST USE THE FOLLOWING LINES OF CODE FOR PROMPTS AND OUTPUTS:
 *  To output size of tree: cout << "Size of tree: " << size << "\n";
 *  To output height of tree: cout << "Height of tree: " << height << "\n";
 *  To prompt the user to enter a name: cout << "Enter actor/actress name: " << "\n";
 *  To tell the user that actor/actress name was found: cout << name << " found!" << "\n";
 *  To tell the user that actor/actress name was NOT found: cout << name << " NOT found" << "\n";
 *  To prompt the user for the number of actors: cout << "Number of subsequent actors to list:" << "\n";
 *  To tell the user that there are no more actors: cout << "There are no subsequent actors to display" << "\n";
 *  To prompt the user to try again: cout << "Search again? (y/n)" << "\n";
 *
 *  Use cin to process user input.
 *
 *  You MUST output size, then height, then prompt the user to search, as above.
 *
 *  You MUST have the prompt for entering the name appear if and only if 
 *  the user input for trying again is "y" followed by the return key
 *  You MUST have the program exit (exiting the prompt loop) if and only if
 *  the user input for trying again is "n" followed by the return key
 *  You should handle other inputs for the retry prompt,
 *  but we will not be testing them.
 *
 *  Note that size, height, and name are local variables in main that you 
 *  should update accordingly. Also note that actor/actress names will be 
 *  in all caps, last name followed by first name 
 *  (except in odd cases, eg. "50 CENT" and "ICE-T")
*/

using namespace std;

int main(int argc, char* argv[])
{
	//Size of tree should be stored in local variable size.
	//Height of tree should be stored in local variable height.
	//Input name will be stored in a string name
	unsigned int size = 0;
	unsigned int height = 0;
	string name = "";

	//Check for Arguments
	if(argc != 2){
		cout << "Invalid number of arguments.\n" 
		     << "Usage: ./main <input filename>.\n";
		return -1;
	}

	//Open file 
	ifstream in;
	in.open(argv[1], ios::binary);

	//Check if input file was actually opened
	if(!in.is_open()) 
	{
		cout<< "Invalid input file. No file was opened. Please try again.\n";
		return -1;
	}

	//Check for empty file
	in.seekg(0, ios_base::end); 
	unsigned int len = in.tellg();
	if(len==0) 
	{
		cout << "The file is empty. \n";
		return -1;
	}

	//Resets the stream to beginning of file
	in.seekg(0, ios_base::beg); 

	// My implementation start
 
	BST<string> tree = BST<string>();
	string line;

	// Parse file for actor names and populate tree
	// hint: you can use getline
	
	// store the height and size of the tree and print

	cout << "Size of tree: " << size << "\n";
	cout << "Height of tree: " << height << "\n";

	char response = 'y';
	while(response == 'y') {
		cout << "Enter actor/actress name: " << "\n";

		// Read user input for name of the actor
		// hint: you can use getline or directly use cin >>
		
        // Find the actor in the tree
		// set found to true of actor was found
		bool found; 
		

		if (found) {
			cout << name << " found!" << "\n";

			// Read user input for number of subsequent actors
			// hint: you can use getline or directly use cin >>
			int numberOfActors;
			cout << "Number of subsequent actors to list:" << "\n";
			
			// Print out subsequent actors
			
		}
		else {
			cout << name << " NOT found" << "\n";
		}


		cout << "Search again? (y/n)" << "\n";

		// Read user input for y or n and store inside the variable response
		// hint: you can use getline or directly use cin >>
		
		}
	}

	if(in.is_open())
	{
		in.close();
	}
	
	return 0;
}

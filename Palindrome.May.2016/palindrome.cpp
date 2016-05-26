#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string word;
	int top;
	bool palindrome; //trigger whether or not word is palindrome

	do
	{
		top = 0;
		palindrome = true;
		cout << "-------------------" << endl;
		cout << "Palindrome Checker!" << endl;
		cout << "-------------------" << endl;
		cout << "To exit, enter 0." << endl << endl;
		cout << "Enter word > ";
		cin >> word; //store word in string 
		vector <char>original(word.begin(), word.end()); //initializing vector to the word
		vector <char>reversed; //used to store the word read backwards

		for (int i = original.size()-1; i >= 0; i--)
		{
			reversed.push_back(original.at(i));
			//if one of the characters don't match, the word is not palindrome
			if (reversed.at(top) != original.at(top))
			{
				palindrome = false;
			}
			top++;

		}
		if (!palindrome)
		{
			cout << "The word is not a palindrome." << endl;

		}
		else
		{
			cout << "The word is a palindrome." << endl;
		}
		//spaces to look more presentable
		for (int a = 0; a < 10; a++)
		{
			cout << endl;
		}
	} while (word[0] != '0');

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string word;
	int top;
	bool palindrome;

	do
	{
		top = 0;
		palindrome = true;
		cout << "-------------------" << endl;
		cout << "Palindrome Checker!" << endl;
		cout << "-------------------" << endl;
		cout << "To exit, enter 0." << endl << endl;
		cout << "Enter word > ";
		cin >> word;
		vector <char>original(word.begin(), word.end());
		vector <char>reversed;

		for (int i = original.size()-1; i >= 0; i--)
		{
			reversed.push_back(original.at(i));
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
		for (int a = 0; a < 10; a++)
		{
			cout << endl;
		}
	} while (word[0] != '0');

	return 0;
}
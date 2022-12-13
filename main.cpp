#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	/*
	* Login Feature.
	* Signup Feature.
	* Files are our database
	* 
	* 1- Open the file
	* 2- We prompt the user what they wanna do 
	*	- Login: Go into the users file, find the username & pass
	*			prompt back with the result
	*	- Signup: Go into the users file, APPEND new user
	*/

	int choice;
	cout << "Please choose what you want to do" << endl;
	cout << "1- Login" << endl
		<< "2- Sign up ";
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			fstream users("users.txt", fstream::in | fstream::out | fstream::app);
			// get username
			// get password
			// find username and password combination
			string username, password, readLine;
			bool _userFound = false;
			bool _password = false;
			cout << "Enter the username: "; cin >> username;
			cout << "Enter the password: "; cin >> password;
			while (getline(users, readLine, ';')) // username
			{
				if (readLine == username)
				{
					_userFound = true;
					getline(users, readLine, ';'); // password
					if (readLine == password)
					{
						_password = true;
						cout << "Logged in... You may continue doing whatever you like";
					}
				}
			}
			if (!_userFound)
			{
				cout << "User does not exist... Please sign up" << endl;
			}
			if (!_password && _userFound)
			{
				cout << "User exists... But the password is WRONG please try again" << endl;
			}
			users.close();
		}
			break;
		case 2:
		{
			fstream users("users.txt", fstream::in | fstream::out | fstream::app);
			// get input
			// we can check for usernames
			// append to file
			string username, password, readLine;
			bool _userFound = false;
			cout << "Enter the username: "; cin >> username;
			cout << "Enter the password: "; cin >> password;
			while (getline(users, readLine, ';')) // username
			{
				readLine = (readLine[0] == '\n') ? string(readLine.begin() + 1, readLine.end()) : readLine;
				if (readLine == username)
				{
					_userFound = true;
					cout << "The username already exists" << endl;
					break;
				}
				getline(users, readLine, ';');
			}
			users.clear();
			users.seekg(0);
			users.seekp(0);
			if (!_userFound)
			{
				users << "\n" << username << ";" << password << ";";
			}
			users.close();
		}
			break;
		default:
			cout << "WRONG INPUT BUDDY PLEASE TRY AGAIN";
			break;
		}
	} while (choice != 1 && choice != 2);
}

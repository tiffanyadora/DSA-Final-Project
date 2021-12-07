#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

int main()
{
    string uname = ""; //for signing up
    string pword = "";
    string input_uname = ""; //for logging in
    char ch;
    char choice;
    int usercount = 0;
    ofstream myfile;

    void signUp() //function for signing up
    {
        myfile.open("accounts.txt"); //open txt file
        
        cout << "\nPlease decide on a username and a password" << endl;
        cout << "Username: ";
        cin >> uname;
        cout << "Password: ";
        cin >> pword;

        usercount++;
    }
    
    cout << "Welcome to the Vaccine Management System!" << endl;
    cout << "Would you like to sign up or log in? (S/L)" << endl;
    cin >> choice;

    toupper(choice);
    
    if (choice == 'S')
    {
        signUp();
    }
        
    else if (choice == 'L') //needs fixing in username and password recording
    {
        cout << "\nUsername: " << endl;
        cin >> input_uname;
        cout << "\nPassword: " << endl;
        ch = getch();
        
        while(ch != 13) //to know when to stop the asterisks from hiding the password because the 13th character is enter
        {
            pword.push_back(ch); 
            cout << '*';
            ch = getch();
        }

        if(pword == "PASSWORD") //this is for password checking. please work on the account records first
        {
            cout << "\nAccess granted." << endl;
            cout << "Welcome!" << endl;
        }
        else
        {
            cout << "\nAccess denied." << endl;
        }
    }

    else
    {
        cout << "Invalid input. Please try again." << endl;
    }
  return 0;
}

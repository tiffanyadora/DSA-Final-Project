#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include "vaccine_inventory_system.cpp"
#include "VacRegis.cpp"
using namespace std;

int main()
{
    string uname = ""; //for signing up
    string pword = "";
    string input_uname = ""; //for logging in
    string input_pword = "";
    int repeat_whole = 1, repeat_hospital = 1; //add repeat_patient, repeat_newuser
    char ch;
    char c;
    char choice1;
    char choice2;
    vector<string> username = {"rsupfatmawati", "rsudkebayoranbaru", "mayapadahospital"}; //the hospitals accounts are reserved
    vector<string> password = {"fatmawati", "kebayoran", "mayapada"};
    vector<string> usertype = {"Hospital", "Hospital", "Hospital"};
    vaccineInventory inventory1; //create a new object inventory1
    registration registration1; //create a new object registration1

    while (repeat_whole != 0) //repeats the program continuously
    {
        cout << "=============================================" << endl;
        cout << "\nWelcome to the Vaccine Management System!\n" << endl;
        cout << "=============================================" << endl;
        cout << "\nWhat would you like to do?" << endl;
        cout << "Press S to sign up" << endl;
        cout << "Press L to log in" << endl;
        cin >> choice1;
        
        if (choice1 == 'S' or choice1 == 's')
        {
            cout << "\nPlease decide on a username and a password" << endl;
            cout << "Username: ";
            cin >> uname;
            cout << "Password (do not use backspace): ";
            c = getch();
            
            while(c != 13) //to know when to stop the asterisks from hiding the password because the 13th character is enter
            {
                pword.push_back(c); 
                cout << '*';
                c = getch();
            }

            username.push_back(uname);
            password.push_back(pword);
            usertype.push_back("User");
            cout << "\n\nUsername and password registered." << endl; 
            cout << "Welcome, " << uname << endl;
            cout << "\nWhat would you like to do?" << endl;

            registration1.regisMenu(uname);
        }
            
        else if (choice1 == 'L' || choice1 == 'l')
        {
            cout << "\nUsername: ";
            cin >> input_uname;
            cout << "Password (do not use backspace): ";
            ch = getch();
            
            while(ch != 13) //to know when to stop the asterisks from hiding the password because the 13th character is enter
            {
                input_pword.push_back(ch); 
                cout << '*';
                ch = getch();
            }
            
            for(int x = 0; x < username.size(); x++) //check whether the username and password exists
            {
                if(input_uname == username[x])
                {
                    if(input_pword == password[x])
                    {
                        if(usertype[x] == "Hospital") //hospital accounts have more access
                        {
                            cout << "\n\nAccess granted." << endl;
                            cout << "Welcome, " << input_uname << endl;
                            
                            while (repeat_hospital != 0) 
                            {
                                cout << "Press V to check vaccine information" << endl;
                                cin >> choice2;
                                
                                if (choice2 == 'V' || choice2 == 'v')
                                {
                                    inventory1.inventoryMenu(); //calls the menu function to start the vaccine management
                                    repeat_hospital = 0; 
                                }
                                else
                                {
                                    cout << "Invalid input. Please try again." << endl;
                                    repeat_hospital = 1; //repeats if the input is incorrect
                                }
                            }
                        }
                        else if(usertype[x] == "User")
                        {
                            cout << "\n\nAccess granted." << endl;
                            cout << "Welcome, " << input_uname << endl;
                            registration1.regisMenu(input_uname);
                        }
                    }
                }
            }
            repeat_whole = 1; //repeats the entire program due to incorrect input
        }
        else
        {
            cout << "Invalid input. Please try again.\n" << endl;
            repeat_whole = 1; //repeats the entire program due to incorrect input
        }
    }
}

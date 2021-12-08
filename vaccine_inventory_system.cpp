#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include<conio.h>

using namespace std;

/*Class vaccineInventory*/
class vaccineInventory{
    private:
        // Linked list for Vaccine Data
        struct Node
        {
            // Members
            int code; // for the Vaccine ID
            string name; // for the Vaccine tag name
            int quantity; // for the Vaccine Units
            int gap; // for the Vaccine interval between two doses
            struct Node *next;
        };

    public:
        // Global variables to be used in several functions
        int vacID, vacCount, vacInterval, option;

        Node *front = NULL,*rear,*temp;

        // All features of Vaccine Inventory Program
        void menu();
        void add_new_vaccine();
        void delete_vaccine();
        void display_vaccine();
        void search_vaccine();
        void update_vaccine();
        void check_vaccine_status();
};

/* Function to insert new vaccine to the inventory */
void vaccineInventory::add_new_vaccine()
{
	temp = new Node;
	string inputName;

	// User prompt
	cout<<" Enter vaccine code\t\t\t: ";
    cin>>vacID;
    cin.ignore(1,'\n');
    cout<<" Enter name of the vaccine\t\t: ";
    getline(cin,inputName);
    cout<<" Enter Initial Quantity\t\t\t: ";
    cin>>vacCount;
    cout<<" Enter the Gap between 2 Doses (days)\t: ";
    cin>>vacInterval;

    // Pointer to store input data and access to the member of Node
	temp->code=vacID;
	temp->name=inputName;
	temp->quantity=vacCount;
	temp->gap=vacInterval;
	temp->next=NULL;

    // If list is empty, the input will be the front
	if(front==NULL)
		front=rear=temp;

	else
	{
	    // If list contain something, the input will be the rear
		rear->next=temp;
		rear=temp;
	}
	cout<<"\nNew Vaccine Added Successfully!";
	getch();
}

/* Function to remove vaccine from the inventory */
void vaccineInventory::delete_vaccine()
{
	Node *temp;
    temp=front;
    int currID;
    int is_found=0;
    // If the front is not empty
    if(front != NULL)
    {
        // User prompt
        cout<<"\n Enter vaccine code to be deleted\t: ";
        cin>>currID;

        // The current ID match with the first vaccine
        if(currID==temp->code)
        {
            Node *temp=front;
            front=front->next;
            delete temp;
            cout<<"\n Vaccine deleted successfully.";
            is_found++;
        }

        else
        {
            // If not, search through the list one by one
            Node *ptr = front;
            Node *temp = front;
            while (temp != NULL)
            {
                if(currID == temp->code){
                    ptr -> next = temp -> next;
                    delete temp;
                    cout<<"\n Vaccine deleted successfully.";
                    is_found++;
                    break;
                }
                ptr = temp;
                temp = temp-> next;
            }
        }

        // If the vaccine is not found
        if(is_found==0)
        {
        cout<<" Data of vaccine is not found.";
        }
    }

    // If the linked list is still empty
    else cout<<" There are no data of vaccine currently.\n";
    getch();
}

/* Function to show all available vaccines in the inventory */
void vaccineInventory::display_vaccine()
{
    // If the linked list is still empty
	if(front==NULL)
		{cout<<" There are no data of vaccine currently.\n";
		getch();}

    // If the linked list is not empty
	else
	{
		temp=front;
		cout<<"\n Table of Available Vaccines\n";
		cout<<" +------------------------+-----------------------+-------------------------------+\n";
		cout<<" |\tVaccine name\t  |\tVaccine code\t  |\t  Available quantity\t  |\n";
		cout<<" +------------------------+-----------------------+-------------------------------+\n";

		// Printing all available vaccines
		while(temp!=NULL)
		{
        cout << " |" << setw(20) << temp->name << setw(5) //setw is to arrange it neatly
             << "|" << setw(19) << temp->code << setw(5)
             << "|" << setw(20) << temp->quantity << setw(12)
             << "|" << endl;

			temp=temp->next;
		}
		cout<<" +--------------------------------------------------------------------------------+"<<endl;
		getch();
	}
}

/* Function to search the information of vaccine by the code*/
void vaccineInventory::search_vaccine()
{
    Node *temp;
    temp=front;
    int currID;
    int is_found=0;
    // If the linked list is not empty
    if(front != NULL)
    {
        // User prompt
        cout<<"\n Enter vaccine code to be searched\t: ";
        cin>>currID;
        // Iterating to find the specific vaccine in the list
        while(temp!=NULL)
        {
            temp->code;
            if(currID==temp->code)
            {
                cout<<"\n\n>>>  The data of vaccine is found!  <<<"<<endl;

                // Print all the info and details
                cout<<" Vaccine Name\t\t: "<<temp->name<<endl;
                cout<<" Current Quantity\t: "<<temp->quantity<<endl;
                cout<<" Gap between Dose\t: "<<temp->gap<<endl;
                cout<<" ------------------------------------------------"<<endl;
                cout<<"\n\n";
              is_found=1;
            }
            temp=temp->next;
        }
        // If the vaccine is not found
        if(is_found==0)
        {
            cout<<" Data of vaccine is not found.";
        }
    }
    // If the linked list is still empty
    else cout<<" There are no data of vaccine currently.";
    getch();
}

/* Function to modify the vaccine's quantity either adding or taking some units */
void vaccineInventory::update_vaccine()
{
    Node *temp;
    temp=front;
    int is_found=0;

    // If the linked list is not empty
    if(front != NULL)
    {
        // User prompt
        cout<<"\n Enter vaccine code to be updated\t: ";
        cin>>vacID;
        cout<<endl;

        // Iterate for the vaccine data list
        while(temp!=NULL)
        {
            temp->code;
            if(vacID==temp->code)
            {
                tryUpdate:
                cout<<" 1. Add quantity \n";
                cout<<" 2. Take quantity \n";
                cout<<" Enter your choice\t: ";
                cin>>option; // user choose want to add or take vaccine

                // For adding the vaccine units
                if(option==1)
                {
                    // User prompt
                    cout<<"\n Initial Quantity\t\t: "<<temp->quantity<<endl;
                    cout<<" How much you want to add?\t: ";
                    cin>>vacCount;

                    temp->quantity=temp->quantity+vacCount; // Sum it up and store again
                    cout<<" Updated Quantity\t\t: "<<temp->quantity<<endl;
                    cout<<" ------------------------------------------------"<<endl;
                    cout<<"\n";
                    is_found=1;
                }

                // For taking the vaccine units
                else if(option==2)
                {
                    // User prompt
                    cout<<"\n Initial Quantity\t\t: "<<temp->quantity;
                    tryAgain:
                    cout<<"\n How much you want to take?\t: ";
                    cin>>vacCount;

                    // If the amount of vaccine is insufficient
                    if(temp->quantity<vacCount)
                    {
                        cout<<" Sorry, the number of vaccine is not enough.";
                        goto tryAgain;
                    }

                    // If yes, proceed to take the units of vaccines
                    else
                    {
                        temp->quantity=temp->quantity-vacCount; // Substract it and store again
                        cout<<" Updated Quantity\t\t: "<<temp->quantity<<endl;
                        cout<<" ------------------------------------------------"<<endl;
                        cout<<"\n";
                    }
                    is_found=1;
                }
                else {cout<<"Invalid Input!\n"; goto tryUpdate;}
            }
            temp=temp->next;
        }

        // If the vaccine is not found
        if(is_found==0)
        {
            cout<<" Data of vaccine is not found.";
        }
    }

    // If the linked list is still empty
    else cout<<" There are no data of vaccine currently.";
    getch();
}

/* Function to check the availability status of a specific vaccine*/
void vaccineInventory::check_vaccine_status()
{
    Node *temp;
    temp=front;
    int is_found=0;

    // If the linked list is not empty (at least have 1)
    if(front != NULL)
    {
        // User prompt
        cout<<"\n Enter vaccine code to be checked\t: ";
        cin>>vacID;

        // Iteration for checking through linked list
        while(temp!=NULL)
        {
            temp->code;
            if(vacID==temp->code)
            {
                // The number of vaccine is 0, none left
                if(temp->quantity<=0){
                    cout<< "\n Vaccine CODE [" <<temp->code<< "] needs to be restocked!";
                }

                // There are still units of vaccine left. Print it.
                else{
                    cout<< "\n Vaccine CODE [" <<temp->code<< "] is available. "<<temp->quantity<<" units left.";
                }
                is_found=1;
            }
            temp=temp->next;
        }

        // If the vaccine is not found
        if(is_found==0)
        {
            cout<<" Data of vaccine is not found.";
        }
    }

    // If the linked list is still empty
    else cout<<" There are no data of vaccine currently.";
    getch();
}

/* Program menu */
void vaccineInventory::menu(){
    int option,vacID,vacCount;

    // Menu interface
	while(1)
	{
	    system("cls");
	    cout<<"=========================================================";
	    cout<<"\n                Vaccine Inventory System             ";
		cout<<"\n=========================================================\n";
		cout<<"\n                        Main Menu                    ";
		cout<<"\n 1. Add New Vaccine";
		cout<<"\n 2. Update Vaccine Quantity";
		cout<<"\n 3. Search Vaccine";
		cout<<"\n 4. Show Vaccine List";
		cout<<"\n 5. Check Vaccine Status";
		cout<<"\n 6. Delete Vaccine";
		cout<<"\n 7. Exit";

        // User prompt
		cout<<"\n\n Enter your choice (1-7): ";
		cin>>option;
		cout<<"\n=========================================================";
		cout<<"\n";

		// The program will do based on user choice
		switch(option)
		{
			case 1:
			    add_new_vaccine();
                break;
            case 2:
                update_vaccine();
                break;
            case 3:
                search_vaccine();
                break;
			case 4:
			    display_vaccine();
                break;
            case 5:
                check_vaccine_status();
                break;
            case 6:
			    delete_vaccine();
			    break;
			case 7:
			    exit(0);
                break;

            // If input out of bound, prompt user to enter again.
			default:
			    cout<<"Invalid input, please try again. (press any key)";
			    getch();
		}
	}
}

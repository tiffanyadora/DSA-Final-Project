#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include<conio.h>

using namespace std;

class vaccineInventory{
    private:
        struct Node
        {
            int code;
            string name;
            int quantity;
            int gap;
            struct Node *next;
        };
    public:
        int vacID, vacCount, vacGap, option;
        Node *front = NULL,*rear,*temp;
        void menu();
        void add_new_vaccine();
        void delete_vaccine();
        void display_vaccine();
        void search_vaccine();
        void update_vaccine();
        void check_vaccine_quantity();
};

void vaccineInventory::add_new_vaccine()
{
	temp = new Node;
	string inputName;
	cout<<" Enter vaccine code\t\t: ";
    cin>>vacID;
    cin.ignore(1,'\n');
    cout<<" Enter name of the vaccine\t: ";
    getline(cin,inputName);
    cout<<" Enter Initial Quantity\t\t: ";
    cin>>vacCount;
    cout<<" Enter the Gap between 2 Doses\t: ";
    cin>>vacGap;
	temp->code=vacID;
	temp->name=inputName;
	temp->quantity=vacCount;
	temp->gap=vacGap;
	temp->next=NULL;

	if(front==NULL)
		front=rear=temp;
	else
	{
		rear->next=temp;
		rear=temp;
	}
	cout<<"\nNew Vaccine Added Successfully!";
	getch();
}

void vaccineInventory::delete_vaccine()
{
	/*if(front==NULL)
		{cout<<" Data of vaccine is not found.\n";
		getch();}
	else
	{

		temp=front;
		front=front->next;
		cout<<" Vaccine with "<<temp->code<<" and its data are deleted successfully!\n";
		delete(temp);
		getch();
	}
	*/
}

void vaccineInventory::display_vaccine()
{
	if(front==NULL)
		{cout<<" There are no data of vaccine currently.\n";
		getch();}
	else
	{
		temp=front;
		cout<<"\n List of Available Vaccines\n";
		cout<<" +------------------------+-----------------------+-------------------------------+\n";
		//cout<<setw()
		cout<<" |\tVaccine name\t  |\tVaccine code\t  |\t  Available quantity\t  |\n";
		cout<<" +------------------------+-----------------------+-------------------------------+\n";
		while(temp!=NULL)
		{
        cout << " |" << setw(20) << temp->name << setw(5)
             << "|" << setw(19) << temp->code << setw(5)
             << "|" << setw(20) << temp->quantity << setw(12)
             << "|" << endl;

			temp=temp->next;
		}
		cout<<" +--------------------------------------------------------------------------------+"<<endl;
		getch();
	}
}

void vaccineInventory::search_vaccine()
{
	
}

void vaccineInventory::update_vaccine()
{
	
}

void vaccineInventory::check_vaccine_quantity()
{
    Node *temp;
    temp=front;
    int is_found=0;
    if(front != NULL)
    {
        cout<<"\n Enter vaccine code to be checked\t: ";
        cin>>vacID;
	    
        while(temp!=NULL)
        {
            temp->code;
            if(vacID==temp->code)
            {
                cout<<" Total number of Vaccine ["<<temp->code<< "]\t\t: "<<temp->quantity;
                is_found=1;
            }
            temp=temp->next;
        }
	    
        if(is_found==0)
        {
            cout<<" Data of vaccine is not found.";
        }
    }
    else cout<<" There are no data of vaccine currently.";
    getch();
}

void vaccineInventory::menu(){
    int option,vacID,vacCount;
	while(1)
	{
	    system("cls");
	    cout<<"=================================================";
	    cout<<"\n            Vaccine Inventory System             ";
		cout<<"\n=================================================\n";
		cout<<"\n                    Main Menu                    ";
		cout<<"\n 1. Add New Vaccine";
		cout<<"\n 2. Update Vaccine Quantity";
		cout<<"\n 3. Check Vaccine Quantity";
		cout<<"\n 4. Show Vaccine List";
		cout<<"\n 5. Search Vaccine";
		cout<<"\n 6. Delete Vaccine";
		cout<<"\n 7. Exit";
		cout<<"\n\n Enter your choice (1-7): ";
		cin>>option;
		cout<<"\n=================================================";
		cout<<"\n";
		switch(option)
		{
			case 1:
			    add_new_vaccine();
                break;
            case 2:
                update_vaccine();
                break;
            case 3:
                check_vaccine_quantity();
                break;
			case 4:
			    display_vaccine();
                break;
            case 5:
                search_vaccine();
                break;
            case 6:
			    delete_vaccine();
			    break;
			case 7:
			    exit(0);
                break;
			default:
			    cout<<"Invalid input, please try again. (press any key)";
			    getch();
		}
	}
}

int main()
{
    vaccineInventory inventory1;
    inventory1.menu();
}

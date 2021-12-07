#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include<conio.h>

using namespace std;

// Global variable
int vacID, vacCount, vacGap, option;

/* Link list node */
struct Node
{
    int code;
	string name;
	int quantity;
	int gap;
	struct Node *next;

}*front = NULL,*rear,*temp;

void add_new_vaccine(){
}

void delete_first_vaccine(){
}

void display_vaccine(){
}

void search_vaccine(){
}

void void update_vaccine(){
}

void check_vaccine_quantity(){
}

int main()
{
	int option,vacID,vacCount;
	while(1)
	{
	    system("cls");
	    cout<<"\n=================================================";
	    cout<<"\n            Vaccine Inventory System             ";
		cout<<"\n=================================================\n";
		cout<<"\n                    Main Menu                    ";
		cout<<"\n 1. Add New Vaccine";
		cout<<"\n 2. Update Vaccine Quantity";
		cout<<"\n 3. Check Vaccine Quantity";
		cout<<"\n 4. Show Vaccine List";
		cout<<"\n 5. Search Vaccine";
		cout<<"\n 6. Delete Vaccine";
		cout<<"\n 7. Keluar";
		cout<<"\n\n Masukkan Pilihan (1-4): ";
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
			    delete_first_vaccine();
			    break;
			case 7:
			    exit(0);
                break;
			default:
			    cout<<"Invalid input, please enter again. (press any key)";
			    getch();
		}
	}
	return 0;
}

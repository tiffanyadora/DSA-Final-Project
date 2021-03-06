#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
using namespace std;

class loc{
	private:
		string name;
		vector<loc> children;
	
	public:
		loc(string name){
			this->name = name;
		}
		
		void setName(string name) { this->name = name; } 
		string getName() { return this->name; }
		
		loc* addChildren(string inName){
			loc ph = loc(inName);
			(this->children).push_back(ph);
			return &this->children[this->children.size() - 1];
		}
		
		loc* addChildren(string inName, string inHospital){
			loc ph = loc(inName);
			(this->children).push_back(ph);
			this->children[this->children.size() - 1].addChildren(inHospital);
			
			return &this->children[this->children.size() - 1];
		}
		vector<loc> * getChildren() { return &this->children; }
};

class patient{
	private:
		string name;
		string vtype;
		string dose;
		string hospital;
		string location;
		string ticketId;

	public:
		patient(){
		}
		patient(string name){
			this->name = name;
		}
		
		void setVtype(string vtype) { this->vtype = vtype; } 
		string getVtype() { return this->vtype; }
		
		void setName(string name) { this->name = name; } 
		string getName() { return this->name; }
		
		void setDose(string dose) { this->dose = dose; } 
		string getDose() { return this->dose; }
		void setHospital(string hospital) { this->hospital = hospital; } 
		string getHospital() { return this->hospital; }
		void setLocation(string location) { this->location = location; } 
		string getLocation() { return this->location; }
		void setTicketId(string ticketId) { this->ticketId = ticketId; } 
		string getTicketId() { return this->ticketId; }
};

class registration{
	public:
		vector<patient> patients;
		void regisMenu(string username){
			string name = username;
			
			int p;
			bool newr = true;
			for(p = 0; p < patients.size(); p++){
				if(name == patients[p].getName()){
					newr = false;
					break;
				}
			}
			
			patient newPatient;
			if(newr){
				newPatient = patient(name);
				newPatient.setLocation("Jakarta Selatan");
				
				system("cls");
			    cout<<"=========================================================";
			    cout<<"\n             Vaccination Registration System             ";
				cout<<"\n=========================================================\n";
				cout<<"\n                Registration Procedure                   \n";
				cout<<"\n 1. Pick Vaccine Type";
				cout<<"\n 2. First/Second Vaccination";
				cout<<"\n 3. Location of Vaccination\n";
				
				
				int inc;
				
				while(1){
					cout<<"\n Vaccine Types: 1.Pfizer 2.Sinovac 3.Moderna 4.AstraZeneca ";
					cout<<"\n Select: ";
					cin >> inc;
					if(inc < 4 && inc > 0) {
						if(inc == 1) newPatient.setVtype("Pfizer");
						if(inc == 2) newPatient.setVtype("Sinovac");
						if(inc == 3) newPatient.setVtype("Moderna");
						if(inc == 4) newPatient.setVtype("AstraZeneca");
						break;
					}
					else cout << "Invalid Input!" << endl;
				}
				
				while(1){
					cout<<"\n First/Second Dose? (1/2) ";
					cout<<"\n Select: ";
					cin >> inc;
					if(inc == 1 || inc == 2){
						if(inc == 1) newPatient.setDose("First");
						if(inc == 2) newPatient.setDose("Second");
						break;
					} else cout << "Invalid Input!" << endl;
				}
				
				cout<<"\nJakarta Selatan\n";
				
				loc root = loc("Jakarta Selatan");
				
				loc * cil = root.addChildren("Cilandak");
				cil->addChildren("Cilandak Barat", "RS Cilandak");
				cil->addChildren("Cipete Selatan", "RS Cilandak");
				cil->addChildren("Gandaria Selatan", "RS Siloam TB Simatupang");
				cil->addChildren("Lebak Bulus", "RS Siloam TB Simatupang");
				cil->addChildren("Pondok Labu", "RS Siloam TB Simatupang");
				
				loc * jag = root.addChildren("Jagakarsa");
				jag->addChildren("Ciganjur", "RS Zahirah");
				jag->addChildren("Cipedak", "RS Zahirah");
				jag->addChildren("Jagakarsa", "RS Zahirah");
				jag->addChildren("Lenteng Agung", "RS Zahirah");
				jag->addChildren("Srengseng Sawah", "RS Zahirah");
				jag->addChildren("Tanjung Barat", "RS Zahirah");
			
				jag = root.addChildren("Kebayoran Baru");
				jag->addChildren("Cipete Utara", "RS Kebayoran");
				jag->addChildren("Gandaria Utara", "RS Kebayoran");
				jag->addChildren("Gunung", "RS Kebayoran");
				jag->addChildren("Kramat Pela", "RS Kebayoran");
				jag->addChildren("Petogogan", "RS Kebayoran");
				jag->addChildren("Pulo", "RS Kebayoran");
				jag->addChildren("Rawa Barat", "RS Senayan");
				jag->addChildren("Selong", "RS Senayan");
				jag->addChildren("Senayan", "RS Senayan");
				
				loc * target = &root;
				vector<loc> * targetsChildren = target->getChildren();
				for(int i = 0; i < 2; i ++){
					for(int j = 0; j < targetsChildren->size(); j++){
						cout << j+1 << " " << targetsChildren->at(j).getName() << " ";
					}
					cout << endl << "Your Location: ";
					int pick;
					cin >> pick;
					
					newPatient.setLocation(targetsChildren->at(pick-1).getName() + ", " + newPatient.getLocation());
					
					target = &targetsChildren->at(pick-1);
					targetsChildren = target->getChildren();
				}
				newPatient.setHospital(targetsChildren->at(0).getName());
				
				patients.push_back(newPatient);
			}else{
				newPatient = patients[p];
			}
			
			system("cls");
		    cout<<"=========================================================";
		    cout<<"\n             Vaccination Registration System             ";
			cout<<"\n=========================================================\n";
			cout<<"\n                Your Vaccination Ticket                  \n";
			cout<<"\n 1. Name: ";
			cout<< newPatient.getName();
			cout<<"\n 2. Vaccine Type: ";
			cout<< newPatient.getVtype();
			cout<<"\n 3. Dosage: ";
			cout<< newPatient.getDose();
			cout<<"\n 4. Hospital: ";
			cout<< newPatient.getHospital();
			cout<<"\n 5. Address: ";
			cout<< newPatient.getLocation();
			
			cout<<"\n\n Back to Main Menu (press any key)";
			getch();
			system("cls");
			return;
		}
		
};

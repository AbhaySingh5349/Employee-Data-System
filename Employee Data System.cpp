#include <bits/stdc++.h>
#include <windows.h> // to use Sleep() function
#include <conio.h> // to use goto functon
using namespace std;

struct employee{
	string name, id, address;
	int contact, salary;
};

struct employee emp[1001]; // array of employees to store data
int total=0; // keeping count of total number of employees

void enterData(){
	int count; // number of employee data to be entered at this moment
	
	cout<<"How many employees data do you want to enter?"<<"\n";
	cin>>count;
	cout<<"-----------------------------------------------------------------------------------"<<"\n";
	for(int i=total;i<total+count;i++){
		cout<<"Enter data of employee "<<i+1<<"\n";

		cout<<"Enter employee name: ";
		cin>>emp[i].name;

		cout<<"Enter id: ";
		cin>>emp[i].id;

		cout<<"Enter address: ";
		cin>>emp[i].address;

		cout<<"Enter contact: ";
		cin>>emp[i].contact;

		cout<<"Enter salary: ";
		cin>>emp[i].salary;
		
		cout<<"-----------------------------------------------------------------------------------"<<"\n";
	}
	total+=count;
}

void showData(){
	cout<<"-----------------------------------------------------------------------------------"<<"\n";
	if(total!=0){
		for(int i=0;i<total;i++){
			cout<<"Data of employee "<<i+1<<endl;
	
			cout<<"Name: "<<emp[i].name<<endl;
	
			cout<<"ID: "<<emp[i].id<<endl;
	
			cout<<"Address: "<<emp[i].address<<endl;
	
			cout<<"Contact: "<<emp[i].contact<<endl;
	
			cout<<"Salary: "<<emp[i].salary<<endl;
		}
	}else{
		cout<<"No data is entered"<<"\n";
	}
	cout<<"-----------------------------------------------------------------------------------"<<"\n";
}

int searchData(){
	int idx=-1;
	if(total!=0){
		string id;
		cout<<"Enter id of employee which you want to search"<<"\n";
		cin>>id;
		
		for(int i=0;i<total;i++){

			if(emp[i].id==id){
				cout<<"Data of employee "<<i+1<<"\n";
		
				cout<<"Name: "<<emp[i].name<<endl;
				cout<<"ID: "<<emp[i].id<<endl;
				cout<<"Address: "<<emp[i].address<<endl;
				cout<<"Contact: "<<emp[i].contact<<endl;
				cout<<"Salary: "<<emp[i].salary<<endl;
				idx=i;
				break;
			}
		}
		if(idx==-1) cout<<"No such record found"<<"\n";
	}else{
		cout<<"No data is entered"<<"\n";
	}
	return idx;
}

void updateData(){
	int idx=searchData();
	if(idx!=-1){
		cout<<"Update data of employee "<<"\n";

		cout<<"Enter employee name: ";
		cin>>emp[idx].name;

		cout<<"Enter id: ";
		cin>>emp[idx].id;

		cout<<"Enter address: ";
		cin>>emp[idx].address;

		cout<<"Enter contact: ";
		cin>>emp[idx].contact;

		cout<<"Enter salary: ";
		cin>>emp[idx].salary;
	}
}

void deleteData(){
	if(total!=0){
		cout<<"Press 1 to delete specific record"<<"\n";
		cout<<"Press 2 to delete full record"<<"\n";
		
		int inp;
		cin>>inp;
		if(inp==1){
			int idx=searchData();
			if(idx!=-1){
				for(int i=idx+1;i<total;i++){
					emp[i-1]=emp[i];
				}
				total--;
			}
		}else if(inp==2){
			total=0;
			cout<<"All record is deleted"<<endl;
		}else{
			cout<<"Invalid input"<<"\n";
		}
	}else{
		cout<<"No data is entered"<<"\n";
	}
}

int main(){
	cout<<"----------------------------Employee Mangement System----------------------------"<<"\n\n";
	
	cout<<"**********************************Sign Up**********************************"<<"\n";
	string usernameSignUp, passwordSignUp;
	cout<<"Enter Username"<<"\n";
	cin>>usernameSignUp;
	cout<<"\nEnter Password"<<"\n";
	cin>>passwordSignUp;
	cout<<"\nPlease wait, your ID is getting created";
	for(int i=0;i<7;i++){ // adding '.' after every 1 second
		cout<<".";
		Sleep(1000);
	}
	cout<<"\nYour ID created successfully!!!"<<"\n"; 
	
	system("CLS"); // starting new Screen
	start: // jump from statements when user want to Log Out or enter invalid credentials
	
	cout<<"----------------------------Employee Mangement System----------------------------"<<"\n\n";
	
	cout<<"**********************************Log In**********************************"<<"\n";
	string usernameLogIn, passwordLogIn;
	cout<<"Username: ";
	cin>>usernameLogIn;
	cout<<"Password: ";
	cin>>passwordLogIn;
	if(usernameSignUp==usernameLogIn && passwordSignUp==passwordLogIn){
		cout<<"You are successfully Logged In..."<<"\n";
		
		system("CLS"); // starting new Screen

		int inp;
	
		while(1){
			cout<<"\n\nPress 1 to enter data"<<endl;
			cout<<"Press 2 to show data"<<endl;
			cout<<"Press 3 to search data"<<endl;
			cout<<"Press 4 to update data"<<endl;
			cout<<"Press 5 to delete data"<<endl;
			cout<<"Press 6 to logout"<<endl;
			cout<<"Press 7 to exit"<<endl;
			
			cin>>inp;
			
			switch(inp){
				case 1:
					enterData();
					break;
				case 2:
					showData();
					break;
				case 3:
					searchData();
					break;
				case 4:
					updateData();
					break;
				case 5:
					deleteData();
					break;
				case 6:
					goto start;
					break;	
				default:
					cout<<"\aInvalid Input";
					break; // '\a' produces error message sound					
			}
		}
	}else{
		cout<<"Invalid credentials"<<"\n";
		Sleep(3000);
		goto start; // used for unconditional jump: here allowing user to add credentials again
	}
    return 0;
}

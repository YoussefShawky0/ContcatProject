#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct node
{
public:
	int number;
    string name;
	node* next;
	node()
	{
		next=NULL;
	}
};
class ContactList
{
private:
	node* head;
public:
ContactList(){
    head = NULL;
}
void addToContacts();
void display();
void searchByName();
void searchByNumber();
void deleteAllContacts();
int deleteContact();
void editContactByName();
void structure();
};

void ContactList::addToContacts(){
    node* p= new node;
    string y;
    int x;
    cout<<"Add to contacts"<<"\n";
    cout<<"Enter Name: "<<"\n";
    cin>>y;
    p->name=y;
    cout<<"Enter Number: "<<"\n";
    cin>>x;
    p->number=x;
    p->next=head;
    head=p;
    cout<<"------------------\n";
    cout<<"Contact Added Successfully"<<"\n";
}

void ContactList::display()
{
	node *p=head;
    int count=0;

    if(p==NULL){
        cout<<"------------------\n";
        cout<<"  No Contacts... Please Add Some Contacts"<<"\n";
    }
    else{
        cout<<"  Name: "<<"      Number: \n"<<endl;
	    while(p!=NULL)
        {
	        count++;
		    cout<<"  "<<p->name;
		    cout<<"          "<<p->number<<"\n";
    		p=p->next;		
	    }
	    cout<<"  Total contacts: "<<count<<"\n";
	}
}

void ContactList :: searchByNumber(){
node *p = head;
cout<<"Search by number"<<"\n";
cout<<"Enter The Number : "<<"\n";
int n;
cin >> n;
bool found = false;
if(head == NULL)
cout<<"List is empty"<<"\n";
else{
while(p != NULL){
    if(p->number == n){
     found = true;
     break;
    }
     p = p-> next;
}
}
if(found)
    cout<<"Name : "<< p-> name << " Number : "<< p-> number <<"\n";
else 
 cout<<"Contact is not found"<<"\n";
}

void ContactList :: searchByName(){
node *p = head;
cout<<"Search by name"<<"\n";
cout<<"Enter Name : "<<"\n";
string n;
cin >> n;
bool found = false;
if(head == NULL)
cout<<"List is empty"<<"\n";
else{
while(p != NULL){
    if(p->name == n){
     found = true;
     break;
    }
     p = p-> next;
}
}
if(found)
    cout<<"Name : "<< p-> name << " Number : "<< p-> number <<"\n";
else 
 cout<<"Contact is not found"<<"\n";
}

int ContactList::deleteContact(){
    cout<<"Enter Name :"<<"\n";
    string m;
    cin>>m;
 node* p = head;
 node* prev = NULL;

        while (p != nullptr) {
            if (p->name == m) {
                if (prev == NULL) {
                    head = p->next;
                } else {
                    prev->next = p->next;
                }
                delete p;
                cout<<"------------------\n";
                cout<<"Contact Deleted"<<"\n";
                return 0;
            }
            prev = p;
            p = p->next;
        }
        cout<<"------------------\n";
        cout<<"Contact Not Found"<<"\n";
    }


void ContactList::deleteAllContacts() {
	
        node* temp = head;
        node* next;

        while (temp != NULL) {
            next = temp->next;
            delete temp;
            temp = next;
        }
		head = NULL;
        cout<<"------------------\n";
    cout<<" All Contacts Deleted Successfully"<<"\n";
    }

void ContactList::editContactByName(){
	node *p = head;
	cout<<"Edit by name "<<"\n";
	cout<<"Enter Name : "<<"\n";
	string n;
	cin >> n;

    bool found = false;
    if(head == NULL)
    cout<<"List is empty"<<"\n";
    else{
    while(p != NULL){
    if(p->name == n){
     found = true;
     break;
    }
     p = p-> next;
    }
    }
    if(found){
        cout<<"Name : "<< p-> name << " Number : "<< p-> number <<"\n";
        string x;
        int y;
        cout<<"  Enter New Name: ";
    	cin>>x;
	    cout<<"  Enter New Number: ";
	    cin>>y;
	        		
	    p->name=x;
	    p->number=y;
	    cout<<"------------------\n";
	    cout<<"  Contact Edited Successfully"<<endl;
    }
    else 
    cout<<"Contact is not found"<<"\n";
	
}

void ContactList::structure() {
    int choice = 0;

    while (choice != 7) {
        cout<<"------------------"<<"\n";
        cout << "1. Add Contact\n";
        cout << "2. Edit the Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Search Contact\n";
        cout << "5. Display All Contacts\n";
        cout << "6. Delete All Contacts\n";
        cout << "7. Exit\n";

        cout << "Choose number: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addToContacts();
                break;
            case 2:
                editContactByName();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                int s;
                cout << "1. Search by name\n";
                cout << "2. Search by number\n";
                cin >> s;
                if (s == 1)
                    searchByName();
                else if (s == 2)
                    searchByNumber();
                else
                    cout << "You Entered A Wrong Number\n";
                break;
            case 5:
                display();
                break;
            case 6:
                deleteAllContacts();
                break;
            case 7:
                cout << "Exiting the Contact List\n";
                break;
            default:
                cout << "You Entered A Wrong Number\n";
                break;
        }
    }
}

int main(){
 ContactList c;
c.structure();
    return 0;
}
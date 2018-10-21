#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
using namespace std;

class AddressBook {
  private:
    person contacts[100]; //note: 100 also shows up in "i<100" in forloop
    int count;
  public:
    void setCountToZero(){count = 0;}
    void countFindLastPosition();
    void addAddress();
    void viewSpecificContact();
    void editPerson(int);
    void deletePerson(int);
		void sortByLastName(); //sort alphabetically by last name and print
    
    void displayContactsListLF(){
      cout<<"Here are all your contacts:"<<endl;
      for(int o = 0; o < count; o++){
        cout<<"Contact #"<<o+1<<". "<<contacts[o].getLN()<<", "<<contacts[o].getFN()<<endl;
      }
    }
    void displaySingleContact(int);
};

#endif
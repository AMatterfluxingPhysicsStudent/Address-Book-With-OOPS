#include "Person.H"
#include "AddressBook.H"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string displaySecondaryMenu(){
  string string1;
  string firstLet;
  cout<<"Press C to Create a New Contact."<<endl;
  cout<<"V to View, Edit, Or Delete a Contact."<<endl;
  cout<<"S to Alphabetically Reorder the Contacts List By Last Name."<<endl;
  cout<<"Q to Quit otherwise."<<endl;
  getline(cin,string1);
  firstLet = string1[0];
  return firstLet;
}

void callingChosenFunction(AddressBook &book1, string menuChoice, int &loopConstraints){
  if (menuChoice == "C"||menuChoice == "c"){
    book1.addAddress();
  }
  else if (menuChoice == "V"||menuChoice == "v"){
    book1.viewSpecificContact();
  }
  else if (menuChoice == "S"||menuChoice == "s"){
    book1.sortByLastName();
  }
  else if (menuChoice == "Q"||menuChoice == "q"){
    loopConstraints = 10;
  }
}//Wanted to put this into the class as well; class would not accept functions that pass in by reference, says it doesn't match and it provided 3 variables when only 2 (menuchoice and loopconstraints) were defined. does the pass by reference one count twice?

void displayMainMenu(AddressBook &book1){
  string menuChoice;
  book1.setCountToZero();//setting count to zero
  int loopConstraints = 2;
  while (loopConstraints <8){
    cout<<"This is the main menu. ";
    cout<<"Here are all your contacts:"<<endl;
    book1.displayContactsListLF();
      cout<<endl;
    menuChoice = displaySecondaryMenu();
    callingChosenFunction(book1, menuChoice, loopConstraints);
      cout<<endl;
  }
}

int main() {
  AddressBook book1; //must instantiate AD first;
  displayMainMenu(book1);
}

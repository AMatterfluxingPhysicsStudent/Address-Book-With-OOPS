#include "Person.H"
#include "AddressBook.H"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void AddressBook::sortByLastName(){//leave this as an option instead of planting the function at the end of every other updating function? tf why? plant it.
  
  //Convert Last Names list to list of only the first letter
    int lPP = 0;//letter position to parse
    int q = 0;
    char pL1[count];//parsedLetters1
    char firstLetter;
    string nameRetrieved;
    for(q = 0; q < count; q++) {
      nameRetrieved = contacts[q].getLN();
      firstLetter = nameRetrieved[lPP];
      pL1[q] = firstLetter;
    }//generating pL1[] array.

  //Convert first letter list called pL1[] to numbers list called numberArray[], for comparison;
    int numberArray[count];
    string upperCaseAlphaBetArray = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerCaseAlphaBetArray = "abcdefghijklmnopqrstuvwxyz";

    for(q = 0; q < count; q++) {
      for(int b = 1; b <= 26; b++) {
        if (pL1[q] == upperCaseAlphaBetArray[b-1]||pL1[q] == lowerCaseAlphaBetArray[b-1]){
          numberArray[q] = b;
        }
      }
    }

  //Compare the numbers, selection sort the numbers, swap the attached arrays at the same time;
    string H1;
    string HMin;
    for(int i=0; i< count; i++){
      int minValue = i; //minValue holder is set to i, the starting point
      for (int j = i; j< count; j++) {// checks against all other values in array
        if(numberArray[j] < numberArray[minValue])
          minValue = j;//address is passed, no real moving is done
      }
      swap(numberArray[i],numberArray[minValue]);//swap;
      swap(pL1[i],pL1[minValue]);

      H1 = contacts[i].getLN(); HMin = contacts[minValue].getLN();
      swap(H1, HMin);
      contacts[i].setLN(H1); contacts[minValue].setLN(HMin);

      H1 = contacts[i].getFN(); HMin = contacts[minValue].getFN();
      swap(H1, HMin);
      contacts[i].setFN(H1); contacts[minValue].setFN(HMin);

      H1 = contacts[i].getPN(); HMin = contacts[minValue].getPN();
      swap(H1, HMin);
      contacts[i].setPN(H1); contacts[minValue].setPN(HMin);

      H1 = contacts[i].getE(); HMin = contacts[minValue].getE();
      swap(H1, HMin);
      contacts[i].setE(H1); contacts[minValue].setE(HMin);

      H1 = contacts[i].getA(); HMin = contacts[minValue].getA();
      swap(H1, HMin);
      contacts[i].setA(H1); contacts[minValue].setA(HMin);

      H1 = contacts[i].getZ(); HMin = contacts[minValue].getZ();
      swap(H1, HMin);
      contacts[i].setZ(H1); contacts[minValue].setZ(HMin);
    }
}

void AddressBook::countFindLastPosition(){//is safety check
  int a = 0;
  string eS = "";
  while(contacts[a].getLN() != eS && contacts[a].getFN() != eS && contacts[a].getPN() != eS && contacts[a].getE() != eS && contacts[a].getA() != eS && contacts[a].getZ() !=eS){
    a++;
  }
  if (count < a){
    count = a;
  }

}

void AddressBook::deletePerson(int addressPosition){
  string choiceToDelete;
  string cTD;
  cout<<"This contact's contents will be permenantly deleted. Are you sure? Y/N"<<endl;
  getline(cin, choiceToDelete);
  cTD = choiceToDelete[0];
  if (cTD == "Y"||cTD == "y"){
    string emptyString = "";
    string eS = emptyString;
    contacts[addressPosition].setLN(eS);
    contacts[addressPosition].setFN(eS);
    contacts[addressPosition].setPN(eS);
    contacts[addressPosition].setE(eS);
    contacts[addressPosition].setA(eS);
    contacts[addressPosition].setZ(eS);

    int t;
    //safety check
      countFindLastPosition();


    string LNHolder = contacts[addressPosition+1].getLN();
    string FNHolder = contacts[addressPosition+1].getFN();
    string PNHolder = contacts[addressPosition+1].getPN();
    string EHolder = contacts[addressPosition+1].getE();
    string AHolder = contacts[addressPosition+1].getA();
    string ZHolder = contacts[addressPosition+1].getZ();

    for(t = 0; t < (count-addressPosition); t++){
      LNHolder = contacts[addressPosition+1+t].getLN();
      FNHolder = contacts[addressPosition+1+t].getFN();
      PNHolder = contacts[addressPosition+1+t].getPN();
      EHolder = contacts[addressPosition+1+t].getE();
      AHolder = contacts[addressPosition+1+t].getA();
      ZHolder = contacts[addressPosition+1+t].getZ();

      contacts[addressPosition+t].setLN(LNHolder);
      contacts[addressPosition+t].setFN(FNHolder);
      contacts[addressPosition+t].setPN(PNHolder);
      contacts[addressPosition+t].setE(EHolder);
      contacts[addressPosition+t].setA(AHolder);
      contacts[addressPosition+t].setZ(ZHolder);
    }
    contacts[count-1].setLN(eS);
    contacts[count-1].setFN(eS);
    contacts[count-1].setPN(eS);
    contacts[count-1].setE(eS);
    contacts[count-1].setA(eS);
    contacts[count-1].setZ(eS);
    count--;
  }
}

void AddressBook::editPerson(int addressPosition){
  int loopC = 2;
  while(loopC < 7){
    string editChoice;
    string e;  
    cout<<"Press L to Edit "<<contacts[addressPosition].getLN()<<endl;
    cout<<"Press F to Edit "<<contacts[addressPosition].getFN()<<endl;
    cout<<"Press P to Edit "<<contacts[addressPosition].getPN()<<endl;
    cout<<"Press E to Edit "<<contacts[addressPosition].getE()<<endl;
    cout<<"Press A to Edit "<<contacts[addressPosition].getA()<<endl;
    cout<<"Press Z to Edit "<<contacts[addressPosition].getZ()<<endl;
    cout<<"Press Q to Return to Previous Menu."<<endl;
    getline(cin, editChoice);
    e = editChoice[0];

    if (e == "L"||e == "l"){
      string newLastName;
      cout<<"Enter new last name: ";
      getline(cin, newLastName);
      contacts[addressPosition].setLN(newLastName);
    }
    else if (e == "F"||e == "f"){
      string newFirstName;
      cout<<"Enter new First Name: ";
      getline(cin, newFirstName);
      contacts[addressPosition].setFN(newFirstName);
    }
    else if (e == "P"||e == "p"){
      string newPhoneNum;
      cout<<"Enter new Phone Number: ";
      getline(cin, newPhoneNum);
      contacts[addressPosition].setPN(newPhoneNum);
    }
    else if (e == "E"||e == "e"){
      string newEmail;
      cout<<"Enter new Email: ";
      getline(cin, newEmail);
      contacts[addressPosition].setE(newEmail);
    }
    else if (e == "A"||e == "a"){
      string newAddress;
      cout<<"Enter new Address: ";
      getline(cin, newAddress);
      contacts[addressPosition].setA(newAddress);
    }
    else if (e == "Z"||e == "z"){
      string newZip;
      cout<<"Enter new Zip: ";
      getline(cin, newZip);
      contacts[addressPosition].setZ(newZip);
    }
    else if (e == "Q"||e == "q"){
      loopC = 10;
    }
    cout<<endl;
  }
}


void AddressBook::displaySingleContact(int contactPosition){
  cout<<"Contact #"<<contactPosition+1<<": "<<endl;
  cout<<"Last Name:"<<contacts[contactPosition].getLN()<<endl;
  cout<<"First Name:"<<contacts[contactPosition].getFN()<<endl;
  cout<<"Phone Number:"<<contacts[contactPosition].getPN()<<endl;
  cout<<"Email:"<<contacts[contactPosition].getE()<<endl;
  cout<<"Address:"<<contacts[contactPosition].getA()<<endl; 
  cout<<"Zip:"<<contacts[contactPosition].getZ()<<endl;
  cout<<endl;
}

void AddressBook::viewSpecificContact(){
  string holder;
  string searchMethodSelection;
  cout<<"Press N to Select Contact by its Position in the Entries."<<endl;
  cout<<"Press L to Search For Contact by Last Name."<<endl;
  cout<<"Press F to Search For Contact by First Name."<<endl;
  cout<<"Press P to Search For Contact By Phone Number."<<endl;
  cout<<"Press E to Search For Contact By Email."<<endl;
  cout<<"Press A to Search For Contact By Address."<<endl;
  cout<<"Press Z to Search For Contact By Zip."<<endl;
  cout<<"Press Q to Return to Previous Menu."<<endl;
  getline(cin, holder);
  searchMethodSelection = holder[0];

  int contactPosition[100];//I could did a linked list, but I deemed it overly complicated
  string lookFor;
  string nameHolder;
  int howManyMatches;
  //remove one of the arrays and somply and then set array[99] to be the size;

  //option branches
    if(searchMethodSelection == "N"||searchMethodSelection == "n"){
      string nth;
      int n1;
      cout<<"Enter entry #:";
      getline(cin, nth);
      n1 = stoi(nth);
      howManyMatches = 1;
      contactPosition[0] = n1-1;
    }
    else if(searchMethodSelection == "L"||searchMethodSelection == "l"){
      cout<<"Enter Last Name to Search By: ";
      getline(cin, lookFor);
      howManyMatches = 0;

      for(int i = 0; i < 100; i++){//count is unreliable
        nameHolder = contacts[i].getLN();
        if (nameHolder == lookFor){
          howManyMatches++;
        }
      }
      int u = 0;
      for(int k = 0; k < 100; k++){
        nameHolder = contacts[k].getLN();
        if (nameHolder == lookFor){
          contactPosition[u] = k;
          u++;
        }
      }
    }
    else if(searchMethodSelection == "F"||searchMethodSelection == "f"){
      cout<<"Enter First Name to Search By: ";
      getline(cin, lookFor);
      howManyMatches = 0;
      for(int i = 0; i < 100; i++){//count is unreliable
        nameHolder = contacts[i].getFN();
        if (nameHolder == lookFor){
          howManyMatches++;
        }
      }
      int u = 0;
      for(int k = 0; k < 100; k++){
        nameHolder = contacts[k].getFN();
        if (nameHolder == lookFor){
          contactPosition[u] = k;
          u++;
        }
      }
    }
    else if(searchMethodSelection == "E"||searchMethodSelection == "e"){
      cout<<"Enter Email to Search By: ";
      getline(cin, lookFor);
      howManyMatches = 0;

      for(int i = 0; i < 100; i++){//count is unreliable
        nameHolder = contacts[i].getE();
        if (nameHolder == lookFor){
          howManyMatches++;
        }
      }
      int u = 0;
      for(int k = 0; k < 100; k++){
        nameHolder = contacts[k].getE();
        if (nameHolder == lookFor){
          contactPosition[u] = k;
          u++;
        }
      }

    }
    else if(searchMethodSelection == "P"||searchMethodSelection == "p"){
      cout<<"Enter Phone Number to Search By: ";
      getline(cin, lookFor);
      howManyMatches = 0;

      for(int i = 0; i < 100; i++){//count is unreliable
        nameHolder = contacts[i].getPN();
        if (nameHolder == lookFor){
          howManyMatches++;
        }
      }
      int u = 0;
      for(int k = 0; k < 100; k++){
        nameHolder = contacts[k].getPN();
        if (nameHolder == lookFor){
          contactPosition[u] = k;
          u++;
        }
      }

    }
    else if(searchMethodSelection == "A"||searchMethodSelection == "a"){
      cout<<"Enter Address to Search By: ";
      getline(cin, lookFor);
      howManyMatches = 0;

      for(int i = 0; i < 100; i++){//count is unreliable
        nameHolder = contacts[i].getA();
        if (nameHolder == lookFor){
          howManyMatches++;
        }
      }
      int u = 0;
      for(int k = 0; k < 100; k++){
        nameHolder = contacts[k].getA();
        if (nameHolder == lookFor){
          contactPosition[u] = k;
          u++;
        }
      }
    }
    else if(searchMethodSelection == "Z"||searchMethodSelection == "z"){
      cout<<"Enter Zip to Search By: ";
      getline(cin, lookFor);
      howManyMatches = 0;

      //find how many matches there are
        for(int i = 0; i < 100; i++){//count is unreliable
          nameHolder = contacts[i].getZ();
          if (nameHolder == lookFor){
            howManyMatches++;
          }
        }
      //...and then reel them in; so howManyMatches could be used as a reference;
        int u = 0;
        for(int k = 0; k < 100; k++){
          nameHolder = contacts[k].getZ();
          if (nameHolder == lookFor){
            contactPosition[u] = k;
            u++;
          }
        }
    }
    else if(searchMethodSelection == "Q"||searchMethodSelection == "q"){
      return;
    }

  if (howManyMatches > 1){
    cout<<endl;
    cout<<"More than 1 matches found."<<endl;
    cout<<endl;
  }
  cout<<endl;
  for(int p = 0; p < howManyMatches; p++){ //using the size data stored in the 
    displaySingleContact(contactPosition[p]);
  }//or declare 1 large array and store the number it goes up to 

  int addressPosition;
  
  if (howManyMatches == 1){
    addressPosition = contactPosition[0];
  }
  else if (howManyMatches > 1){
    cout<<"Select contact via First Name below."<<endl;
    cout<<"Enter First Name to search by:"<<endl;
    string FNHolder;
    getline(cin, FNHolder);
    int b = 0;
    int contactsFound2[howManyMatches];
    for(int v = 0; v < howManyMatches; v++){
      if(contacts[contactPosition[v]].getFN() == FNHolder){
        contactsFound2[b] = contactPosition[v];
        b++;
      }
    }
    if (b == 1){
      addressPosition = contactsFound2[0];
    }
    else if (b > 1){
      cout<<"More than 1 matches found."<<endl;
      for(int p = 0; p < b; p++){ //using the size data stored in the 
        if(p == 0){
          cout<<endl;
        }
        displaySingleContact(contactsFound2[p]);
      }
      cout<<"Select contact via numbers below:"<<endl;
      string selection1;
      string s;
      int input;
      getline(cin, selection1);
      s = selection1[0];
      input = stoi(s);
      int input2 = input - 1;
      addressPosition = input2;
      cout<<endl;
      displaySingleContact(addressPosition);
    }
  }

  string choice;
  string ch;

  cout<<"Press E to edit the Contact."<<endl;
  cout<<"Press D to delete the Contact."<<endl;
  cout<<"Press R to return to main menu."<<endl;
  getline(cin, choice);
  ch = choice[0];

  if(ch == "E"||ch == "e"){
    editPerson(addressPosition);
  }
  if(ch == "D"||ch == "d"){
    deletePerson(addressPosition);
  }
  if(ch == "R"||ch == "r"){
    
  }
}

void AddressBook::addAddress() {
  //declaring variables to pass info
    string personLastName;
    string personFirstName;
    string phoneNumber;
    string address;
    string email;
    string zip;
  //data requesting
    cout<<"Enter the new contact's Last Name:"<<endl;
    getline(cin, personLastName);
    cout<<"Enter the new contact's First Name:"<<endl;
    getline(cin, personFirstName);
    cout<<"Enter the new contact's Phone Number:"<<endl;
    getline(cin, phoneNumber);
    cout<<"Enter the new contact's Email:"<<endl;
    getline(cin, email);
    cout<<"Enter the new contact's Address:"<<endl;
    getline(cin, address);  
    cout<<"Enter the new contact's Zip:"<<endl;
    getline(cin, zip);
  //setting
    contacts[count].setLN(personLastName);
    contacts[count].setFN(personFirstName);
    contacts[count].setPN(phoneNumber);
    contacts[count].setE(email);
    contacts[count].setA(address);
    contacts[count].setZ(zip);
  //accounting
    count++;
    cout<<"There are now "<<count<<" contacts in this address book."<<endl;
}


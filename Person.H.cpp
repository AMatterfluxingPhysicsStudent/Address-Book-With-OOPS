#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class person {
  private:
    string personLastName;
    string personFirstName;
    string phoneNumber;
    string email;
    string address; //will be exclusively using getline(), thus should be more efficient and effective than separate street-city-etc; zip
    string zip;
  public:
    //setter functions
      void setLN(string LN) {personLastName = LN;}
      void setFN(string FN) {personFirstName = FN;}
      void setPN(string PN) {phoneNumber = PN;}
      void setE(string E) {email = E;}
      void setA(string A) {address = A;}
      void setZ(string Z) {zip = Z;}

    //getter functions
      string getLN() const {return personLastName;}
      string getFN() const {return personFirstName;}
      string getPN() const {return phoneNumber;}
      string getE() const {return email;}
      string getA() const {return address;}
      string getZ() const {return zip;}
};
#endif
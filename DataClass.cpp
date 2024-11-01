/*
    Title: DataClass.cpp
    Authors: Jack Bender, Cole Wilson
    Date: 11-01-24
    Purpose: this where we have functions to actually modify the data 
*/

//inclusions
#include "DataClass.h"


/*############################################
    Function: userInputInfo
    Purpose: get necessary data from user to later add to class/list
############################################*/
Data userInputInfo()
{
    //local variables to get values
    double resistance, powerRating; 
    string colorCode; 
    Data newResistor; 

    //output message to tell user what to do
    cout << "\n\nPlease enter the following information of your resistor: \n\n"; 

    //resistance 
    cout << "RESISTANCE (as an number): ";  
        //input validation
            while(!(cin >> resistance))
            {
                //have user input another input 
                cout << "\nPlease enter a valid choice: ";
                cin.clear();
                cin.ignore(100, '\n'); 
            }

    //power rating 
    cout << "\nPOWER RATING (as an number): ";  
    cin.ignore(); 
        //input validation
            while(!(cin >> powerRating))
            {
                //have user input another input 
                cout << "\nPlease enter a valid choice: ";
                cin.clear();
                cin.ignore(100, '\n'); 
            }

    cin.ignore();
    //color code
    cout << "\nRESISTOR COLOR CODE (as one/more words): "; 
    getline(cin, colorCode); 
    
    //use setter to assign these to class proper 
    newResistor.setResistance(resistance); 
    newResistor.setPowerRating(powerRating); 
    newResistor.setColorCode(colorCode); 
    return newResistor;
    
}


/*############################################
    Function: deleteMemory
    Purpose: delete unwanted memory whenever the resistors are removed from the circuit
############################################*/
void deleteMemory()
{
    
}
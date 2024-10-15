/*
    Title: DataClass.cpp
    Authors: Jack Bender, Cole Wilson
    Date: 10-15-24
    Purpose: this where we have functions to actually modify the data 
*/

#include "DataClass.h"

//functions for DataClass will go here
//probably be the functions that get the data from the user to make driver shorter

/*
    Function: userInputInfo
    Purpose: get necessary data from user to later add to class/list
*/
void userInputInfo()
{
    //local variables to get values
    int resistance, powerRating; 
    string colorCode; 
    Data newResistor; 

    //output message to tell user what to do
    cout << "\n\nPlease enter the following information of your resistor: \n\n"; 

    //resistance 
    cout << "RESISTANCE (as an number): "; 
    cin >> resistance; 
    cin.ignore(); 
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
    cin >> powerRating; 
    cin.ignore(); 
        //input validation
            while(!(cin >> powerRating))
            {
                //have user input another input 
                cout << "\nPlease enter a valid choice: ";
                cin.clear();
                cin.ignore(100, '\n'); 
            }

    //color code
    cout << "\nRESISTOR COLOR CODE (as one/more words): "; 
    getline(cin, colorCode); 
    
    //use setter to assign these 
    newResistor.setResistance(resistance); 
    newResistor.setPowerRating(powerRating); 
    newResistor.setColorCode(colorCode); 
    
}

//delete memory functions
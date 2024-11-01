/*
    Title: Driver.cpp
    Authors: Jack Bender, Cole Wilson
    Date: 11-01-24
    GitHub Link: https://github.com/ColeWilson-code/Resistor-Series-Circuit-Simplifier
    Purpose: This program allows one to put resistors in series and simplify or remove. Driver navigates the program. 
*/

//library inclusions
#include "LinkedList.h"
#include "DataClass.h"

int main ()
{
    LinkedList<Data> resistorList;
    
    //below vars used for switch statements
    int menuChoice = 0; 
    int subChoice = 0; 
    int addChoice, removeChoice;  
    Data newResistor;

    cout << "\n\nHello! Welcome to the Resitor Series Circuit Simplifier Program!"; 
    
    //repeat program until user finished 
    do
    {

        cout << "\n\n1. View existing resistors"; 
        cout << "\n2. Add a new resitor"; 
        cout << "\n3. Remove an existing resistor"; 
        cout << "\n4. Simplify circuit"; 
        cout << "\n5. Exit Program"; 

        cout << "\n\nPlease enter an integer from the menu: ";  

        //input validation
            while(!(cin >> menuChoice) || (menuChoice < 1 || menuChoice > 5))
            {
                //have user input another input 
                cout << "\nPlease enter a valid choice: ";
                cin.clear();
                cin.ignore(100, '\n'); 
            }

        switch (menuChoice)
        {

            //view existing resistors
            case 1: 
                int sortChoice; 

                cout << "\n\nWould you like to sort your resistors by resistance?"; 
                cout << "\nPlease enter 1 for yes and 2 for no: "; 

                //input validation
                while(!(cin >> sortChoice) || (sortChoice != 1 && sortChoice != 2))
                {
                    //have user input another input 
                    cout << "\nPlease enter a valid choice: ";
                    cin.clear();
                    cin.ignore(100, '\n'); 
                }
                
                //just print the resistors as is 
                if (sortChoice == 2)
                {
                    resistorList.displayList();
                }
                else if (sortChoice == 1) //otherwise print it sorted using funny functions
                {   
                    resistorList.displaySortedResistance();
                }

                break; 

            //add a new resistor 
            case 2: 
                //need to use DataClass functions to actually store info 
                newResistor = userInputInfo();

                //after have the info ask user how they want to add the resistor
                cout << "\n\nHow would you like to add the resistor to the circuit?"; 

                cout << "\n\n1. To the front"; 
                cout << "\n2. To the back"; 
                cout << "\n3. At a specific location"; 

                cout << "\n\nPlease enter an integer from the menu: "; 
                //input validation
                while(!(cin >> subChoice) || (subChoice < 1 || subChoice > 3))
                {
                    //have user input another input 
                    cout << "\nPlease enter a valid choice: ";
                    cin.clear();
                    cin.ignore(100, '\n'); 
                }

                //switch statement for adding options
                switch(subChoice)
                {
                    //prepend to front 
                    case 1: 
                        resistorList.prependNode(newResistor); 
                        break; 

                    //append to back
                    case 2: 
                        resistorList.appendNode(newResistor);
                        break; 

                    //at a specific spot
                    case 3: 
                        cout << "\n\nPlease enter the position of the resistor in the circuit as an integer between 0 and " << resistorList.getLength() << ": "; 

                        //input validation
                        while(!(cin >> addChoice) || (addChoice < 0 || addChoice > resistorList.getLength()))
                        {
                            //have user input another input 
                            cout << "\nPlease enter a valid choice: ";
                            cin.clear();
                            cin.ignore(100, '\n'); 
                        }

                        resistorList.insertNode(addChoice,newResistor);
                        break; 
                }
                break; 

            //remove an existing resistor 
            case 3: 
                cout << "\n\nPlease enter the position of the resistor in the circuit as an integer between 0 and " << resistorList.getLength() << ": "; 
                cout << "\nNote: this will remove the resistors completely without simplifying it with the circuit\n"; 
                resistorList.displayList();

                cout << "\n\nPlease enter the resistance of the resistors in the circuit you want to remove: "; 

                //input validation
                while((!(cin >> removeChoice)) || ((removeChoice < 0) && (removeChoice > resistorList.getLength())))
                {
                    //have user input another input 
                    cout << "\nPlease enter a valid choice: ";
                    cin.clear();
                    cin.ignore(100, '\n'); 
                }

                resistorList.deleteNode(removeChoice-1);
                break; 

            //Simplify the circuit 
            case 4: 
                //pop repeated until whole circuit simplified
                resistorList.simplifyCircuit();     
                break; 

            //Exit program 
            case 5: 
                //simple goodbye message
                cout << "\n\nThank you for using the Resistor Series Circuit Simplifier Program!"; 
                cout << "\n\nRemember to like, share, and subscribe!" << endl; //the funny (unless this program actually takes off)
                break; 
            }

    } while (menuChoice != 5); //end do while loop 

    //end program 
    return 0; 
}
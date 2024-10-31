/*
    Title: DataClass.h
    Authors: Jack Bender, Cole Wilson
    Date: 11-01-24
    Purpose: store information to be later modified plus some comparison and stream operator overloads 
*/

#ifndef DATA_CLASS_H
#define DATA_CLASS_H


//inclusions
#include "LinkedList.h"


/*############################################
	Class: Data
	Purpose: stores info about the resistors to be put in linked list
############################################*/
class Data
{
    private: 
        //stores resistor info 
        double resistance, powerRating; 
        string colorCode; 

    public: 

        //getters 
        string getColorCode(){return colorCode;}
        double getResistance(){return resistance;}
        double getPowerRating(){return powerRating;}

        //setters 
        void setColorCode(string newColorCode){colorCode = newColorCode;}
        void setResistance(double newResistance){resistance = newResistance;}
        void setPowerRating(double newPowerRating){powerRating = newPowerRating;}


        //comparison and stream operator overloads

            // <<
            friend ostream& operator << (ostream& os, const Data& D)
            {
                os << "\n\nRESISTANCE: " << D.resistance << "\nPOWER RATING: " << D.powerRating << "\nCOLOR CODE: " 
                << D.colorCode << "\n\n"; 
                
                return os; 
            }

            // <
            friend bool operator < (const Data& D1, const Data& D2)
            {
                return (D1.resistance < D2.resistance);
                //power and color less important 
            }

            // >
            friend bool operator > (const Data& D1, const Data& D2)
            {
                //check if resistance greater than other 
                return (D1.resistance > D2.resistance);
                //power and color less important
            }

            // ==
            friend bool operator == (const Data& D1, const Data& D2)
            {
                //check if resistance is equal
                return (D1.resistance == D2.resistance);
                //power and color less important
            }

}; 

#endif
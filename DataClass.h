/*
    Title: DataClass.h
    Authors: Jack Bender, Cole Wilson
    Date: 10-23-24
    Purpose: store information to be later modified plus some comparison and stream operator overloads 
*/

#ifndef DATA_CLASS_H
#define DATA_CLASS_H


//inclusions
#include "LinkedList.h"

class Data
{
    private: 
        //stores resistor info 
        double resistance, powerRating; 
        string colorCode; 

    public: 

        //getters 
        string getColorCode(){return colorCode;}
        int getResistance(){return resistance;}
        int getPowerRating(){return powerRating;}

        //setters 
        void setColorCode(string newColorCode){colorCode = newColorCode;}
        void setResistance(int newResistance){resistance = newResistance;}
        void setPowerRating(int newPowerRating){powerRating = newPowerRating;}


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
                
                //check if resistance less than other
                if (D1.resistance < D2.resistance)
                    return true; 

                //power and color less important 

            }

            // >
            friend bool operator > (const Data& D1, const Data& D2)
            {
                //check if resistance greater than other 
                if (D1.resistance > D2.resistance)
                    return true; 

                //power and color less important
            }

            // ==
            friend bool operator == (const Data& D1, const Data& D2)
            {
                //check if resistance is equal
                if (D1.resistance == D2.resistance)
                    return true; 

                //power and color less important
            }


}; 




#endif
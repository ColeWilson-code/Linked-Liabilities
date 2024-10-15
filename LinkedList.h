/*
    Title: LinkedList.h
    Authors: Jack Bender, Cole Wilson
    Date: 10-15-24
    Purpose: create the LinkedList class and the Template helper class
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H



//library inclusions 
#include <iostream>
#include <list>
using namespace std; 

//LinkedList class
//need at least 10 functions 
class LinkedList
{
    private: 
        //attributes
       


        //constructor 
        LinkedList()
        {
           
        }

        //destructor 
        //~LinkedList()


    public: 
        //add functions 

            //append 



            //prepend



            //insert



        //get functions

            //back



            //front



            //at



        //remove functions 

            //pop

            //erase 


            //remove



        //friend functions

            //sort
                //needs to be able to sort in ascending and descending order
                //maybe use a bool to specify direction your sorting?



            //stream operator



};



//template to be used with TemplateHelper class
template <typename T>

//Template Helper class is like List Node but seperate class
//List node same file
class TemplateHelper
{
    private: 
        //stores data of the template type
        T data; 
        
        //holds two pointers to another list node
        TemplateHelper *next; 
        TemplateHelper *previous; 

    public: 
        //get data at this location 

        //iterate forward and backwards

        //set data, next and previous 

}; 




#endif 
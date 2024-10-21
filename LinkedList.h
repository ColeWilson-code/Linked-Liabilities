/*
    Title: LinkedList.h
    Authors: Jack Bender, Cole Wilson
    Date: 10-15-24
    Purpose: create the LinkedList class and the Template helper class
*/

//define header
#ifndef LINKED_LIST_H
#define LINKED_LIST_H



//library inclusions 
#include <iostream>
#include <list>
using namespace std; 

//template to be used with TemplateHelper class
template <typename T>

//LinkedList class
//need at least 10 functions 
class LinkedList
{
    private: 
        //attributes
        struct LinkedList
        {
            int value;
            string colorCode; 
            int powerRating; 

            //two pointers, one to next and one to previous for bi-directional navigation  
            struct ListNode *next; 
            struct List *previous;
        };

		ListNode *head;		// List head pointer
		ListNode *tail;	    //list tail pointer

    public: 
        //constructor 
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        //destructor 
        ~LinkedList();


        // IS_EMPTY
		bool isEmpty(){
            return (head == NULL);
        }

        //GET LENGTH
		int getLength(){
            int counter = 0;
	        ListNode *nodePtr;
	
	        nodePtr = head;
	
	        //list traversal
	        while(nodePtr != tail)
	        {
		        counter++;
		        nodePtr = nodePtr->next;
		        if (nodePtr == tail)
		    	    counter++;
	        }
	        return counter;
        }

        //GET_NODE_VALUE NEED TO CHANGE THIS WHEN WE HAVE RESISTORS SET UP 
		//double getNodeValue(int){}


        //insert at the end of the list
		void LinkedList::appendNode(double num){
	        ListNode *newNode;  // To point to a new node
	        ListNode *nodePtr;  // To move through the list

	        // Allocate a new node and store num there.
	        newNode = new ListNode;
            //Resistor Values need to be changed here
	        newNode->value = num;
	        newNode->next = NULL;
	        newNode->previous = NULL;

	        // If there are no nodes in the list make newNode the first node.
	        if (head == NULL ) 
	        {
	        	head = newNode;
	        	tail = newNode;
	        }
	        else  // Otherwise, insert newNode at end.
	        {
		        //set the current last node's next pointer to the new node
	        	tail->next = newNode;
	        	newNode->previous = tail;
		
	        	//now the tail is the new node
	        	tail = newNode;
	        }
        }

		void insertNode(int, double){
	        ListNode *nodePtr;
	        ListNode *newNode;
	
	        newNode = new ListNode;
	        newNode->value = num;
	
	        if(!head)
	        {
	        	if(position != 0)
	        	{
	        		//can't insert node at position (>0) if there is not already a node
	        		cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
	        	}
	        	head = newNode;
	        	tail = newNode;
	        }
	        else
	        {
	        	nodePtr = head;
	        	int nodeCount = 0;
	        	if(position == 0)
	        	{
	        		newNode->next = head;
	        		head->previous = newNode;
	        		head = newNode;
	        	}
	        	while(nodePtr != tail && nodeCount < position)
	        	{
	        		nodeCount++;
	        		if(nodeCount == position)
	        			break;
	        		nodePtr = nodePtr->next;
	        	}
		
	        	//now nodePtr is positioned 1 node BEFORE the node we want to insert
	        	if(nodePtr->next == NULL) //we are appending this node to the end
	        		tail = newNode;

	        	//set up newNode's links
	        	newNode->next = nodePtr->next;
	        	newNode->previous = nodePtr;

	        	//change the node on the left
	        	nodePtr->next = newNode;
		
	        	//change the node on the right (if there is a node on the right)
	        	if(newNode->next)
		        {
		        	nodePtr = newNode->next; 
		        	nodePtr->previous = newNode;
		        }
	        }
        }







		void deleteNode(double);
		void displayList() const;

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
        T getData()
        {

        }

        //iterate forward and backwards

            //forward 
            void moveForward()
            {
                data = data->next; 
            }


            //backwards 
            void moveBackward()
            {
                data = data->previous; 
            }

        //set data, next and previous 

            //data
            void setData(T)
            {
                
            }

            //next
            void setNext(T)
            {

            }

            //previous
            void setPrevious(T)
            {

            }

}; 











#endif 
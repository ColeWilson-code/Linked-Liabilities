/*
    Title: LinkedList.h
    Authors: Jack Bender, Cole Wilson
    Date: 10-23-24
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
//need at least 10   
class LinkedList
{
    private: 
        
		//Node class decleration
        ResistorNode node;

		ListNode *head;		// List head pointer
		ListNode *tail;	    //List tail pointer

    public: 
        //constructor 
        LinkedList()
        {
			//creates an empty list by assigning NULL to head and tail
            head = NULL;
            tail = NULL;
        }

        //destructor WORK ON THIS FUNCTION 
        ~LinkedList();


        // IS_EMPTY
		bool isEmpty(){
            return (head == NULL);
        }

        //GET LENGTH
		int getLength(){
            int counter = 0;
			//pointer to traverse list 
	        ResistorNode *nodePtr;

			//put traversal pointer at head
	        nodePtr = head;
	
	        //list traversal
			//loop while the traversal pointer is not at the tail
	        while(nodePtr != tail)
	        {
		        counter++;
				//update the traversal pointer to point to the next node 
		        nodePtr = nodePtr->next;
				//check if traversal is pointing to tail to make sure last increment happens
		        if (nodePtr == tail)
		    	    counter++;
	        }
	        return counter;
        }

        //GET_NODE_VALUE NEED TO CHANGE THIS WHEN WE HAVE RESISTORS SET UP 
		//double getNodeValue(int){}

		template <typename T>
        //insert at the end of the list
		void appendNode(T ohms, T colorCode, T powerRating){
	        ResistorNode *newNode;  // To point to a new node by declaring a newNode pointer
	        ResistorNode *nodePtr;  // To move through the list //traversal popinter

	        // Allocate a new node and store num there.
	        newNode = new ResistorNode;
            //Resistor Values setData
	        newNode->setData(ohms,colorCode,powerRating);

			//setting next and previous to NULL
	        newNode->next = NULL;
	        newNode->previous = NULL;

	        // If there are no nodes in the list make newNode the first node.
	        if (head == NULL ) 
	        {
				//both head and tail
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

		void insertNode(int position, T ohms, T colorCode, T powerRating){
	        //traversal pointer
			ResistorNode *nodePtr;
			//new node pointer
	        ResistorNode *newNode;
	
	        newNode = new ResistorNode;
	        newNode->setData(ohms,colorCode,powerRating);
	
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

		//DELETE NODE
	
		void deleteNode(T ohms, T colorCode, T powerRating){
			ListNode *nodePtr;       // To traverse the list
			ListNode *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
				return;

			// Determine if the first node is the one.
			if (head->ohmsValue == ohms && head->colorCode == ohms && head->powerRating == ohms)
			{
				nodePtr = head->next;
				delete head;
				if(nodePtr != NULL)
				{
					head = nodePtr;
					head->previous = NULL;
				}
				else
					head = NULL;
			}
			else
			{
				// Initialize nodePtr to head of list
				nodePtr = head;

				// Skip all nodes whose value member is 
				// not equal to num.
				while (nodePtr && head->ohmsValue != ohms && head->colorCode != ohms && head->powerRating != ohms)
				{  
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
				}

				// If nodePtr is not at the end of the list, 
				// link the previous node to the node after
				// nodePtr, then delete nodePtr.
				if (nodePtr)
				{
					if(nodePtr == tail)
					{
						tail = previousNode;
					}
					previousNode->next = nodePtr->next;
					delete nodePtr;
					if(previousNode != tail)
					{
						nodePtr = previousNode->next;
						nodePtr->previous = previousNode;
					}
				}
	
			}
		}

		void displayList() const{
			ResistorNode *nodePtr;  // To move through the list

			// Position nodePtr at the head of the list.
			nodePtr = head;

			if(nodePtr == NULL){
				cout << "The list does not contain any elements."
				return; 
			}

			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				// Display the value in this node.
				cout << nodePtr->ohmValue << endl;
				cout << nodePtr->colorCode << endl;
				cout << nodePtr->powerRating << endl;

				// Move to the next node.
				nodePtr = nodePtr->next;
			}
		}


        //friend functions
            //sort
                //needs to be able to sort in ascending and descending order
                //maybe use a bool to specify direction your sorting?
				//ADDED MERGE SORT EXAMPLE CODE to get an idea, would need to MODIFY/adjust/change for it to be usable
					//example code organizes array, we need to organize 
			friend MergeSort(int arr[], int beg, int end) 
			{
				int mid = 0;
				
				if (beg < end)  //recursive case (when beg == end then that is base case) 
				{
						mid = (beg + end) / 2;  // Find the midpoint in the partition

						MergeSort(arr, beg, mid); //recursively sort left partition
						MergeSort(arr, mid + 1, end); //recursively sort right partition

						// Merge left and right partition in sorted order
						Merge(arr, beg, mid, end);
				}
			}
			friend Merge(int arr[], int beg, int mid, int end) 
			{
				int mergedSize = end - beg + 1;                // Size of merged partition
				int mergePos = 0;                          // Position to insert merged number
				int leftPos = 0;                           // Position of elements in left partition
				int rightPos = 0;                          // Position of elements in right partition
				int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array for merged array
				
				leftPos = beg;                               // Initialize left partition position
				rightPos = mid + 1;                          // Initialize right partition position
   
				// Add smallest element from left or right partition to merged arr
				while (leftPos <= mid && rightPos <= end) 
				{
					if (arr[leftPos] < arr[rightPos]) {
						mergedNumbers[mergePos] = arr[leftPos];
						++leftPos;
					}
					else {
						mergedNumbers[mergePos] = arr[rightPos];
						++rightPos;
						
					}
					++mergePos;
				}
   
				// If left partition is not empty, add remaining elements to merged numbers
				while (leftPos <= mid) 
				{
					mergedNumbers[mergePos] = arr[leftPos];
					++leftPos;
					++mergePos;
				}
				
				// If right partition is not empty, add remaining elements to merged numbers
				while (rightPos <= end) 
				{
					mergedNumbers[mergePos] = arr[rightPos];
					++rightPos;
					++mergePos;
				}
				
				// Copy merge number back to arr
				for (mergePos = 0; mergePos < mergedSize; ++mergePos) 
				{
					arr[beg + mergePos] = mergedNumbers[mergePos];
				}
				
				delete [] mergedNumbers;

			}



            //stream operator << 
            friend ostream& operator << (ostream& os, const LinkedList& L)
            {
                os << ; //GENERAL FORM, ADD THE ACTUAL STATEMENT
                
                return os; 
            }

};


//template to be used with TemplateHelper class
template <typename T>
//Template Helper class is like List Node but seperate class
//List node same file
class ResistorNode
{
    private: 
        //stores data of the template type
        T ohmsValue; 
		T colorCode;
		T powerRating;
        
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
            void setData(T ohms,T colors, T pR)
            {
				ohmsValue = ohms;
				colorCode = colors;
				powerRating = pR;
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
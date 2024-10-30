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
//#include <list>
using namespace std; 

//template to be used with TemplateHelper class
template <typename T>
//Template Helper class is like List Node but seperate class
//List node same file
class ListNode
{
    private: 
        //stores data of the template type
        T data;
        
        //holds two pointers to another list node
        ListNode *next; 
        ListNode *previous; 

    public: 
        	
			//constructor 
			ListNode(T newData)
			{
				//list empty
				data = newData; 
			}
			
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
            void setData(T var)
            {
				data = var; 
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

//LinkedList class
//need at least 10  
template <typename T> 
class LinkedList
{
    private: 

		ListNode<T> *head;		//List head pointer
		ListNode<T> *tail;	    //List tail pointer

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


        /*
			Function: isEmpty
			Purpose: check if the list is empty or not 
		*/
		bool isEmpty(){
            return (head == NULL);
        }

  
		/*
			Function: getLength
			Purpose: find length of list 
		*/
		int getLength(){
            int counter = 0;
			//pointer to traverse list 
	        ListNode<T> *nodePtr;

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

		/*
			Function: appendNode
			Purpose: insert data at the end of the list 
		*/
		void appendNode(T newData){
	        ListNode<T> *newNode;  // To point to a new node by declaring a newNode pointer
	        ListNode<T> *nodePtr;  // To move through the list //traversal popinter

	        // Allocate a new node and store num there.
	        newNode = new ListNode<T>(newData);
            //Resistor Values setData
	        newNode->data = newData;

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

		/*
			Function: prependNode
			Purpose: insert data at the beginning of the list 
		*/
		void prependNode(T newData){
	        ListNode<T> *newNode;  // To point to a new node by declaring a newNode pointer
	        ListNode<T> *nodePtr;  // To move through the list //traversal popinter

	        // Allocate a new node and store num there.
	        newNode = new ListNode<T>(newData);
            //Resistor Values setData
	        newNode->data = newData;

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
		        //set the current first node's previous pointer to the new node
	        	tail->next = head;
	        	newNode->previous = newNode;
		
	        	//now the tail is the new node
	        	head = newNode;
	        }
        }


		/*
			Function: insertNode
			Purpose: insert the data a specific node 
		*/
		void insertNode(int position, T newData){
	        //traversal pointer
			ListNode<T> *nodePtr;
			//new node pointer
	        ListNode<T> *newNode;
	
	        newNode = new ListNode<T>(newData);
	        newNode->data = newData;
	
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
		

		/*
			Function: deleteNode
			Purpose: delete the data a node 
		*/
		 void deleteNode(int position){
			ListNode<T> *nodePtr;       // To traverse the list
			ListNode<T> *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
				cout << "The list is already empty.\n";
				return;

			// Determine if the first node is the one.
			if (position == 0)
			{
				head = nodePtr->next;
				if(head != NULL){
					head->previous == NULL; //update the previous to NULL because nothing is before it 
				}else{
					tail == NULL; //if list is empty update tail to NULL
				}
				delete nodePtr;
				return;
			}else{
				//traverse to position passed in argument 
				for(int i = 0; i < position; i++){
					nodePtr = nodePtr->next; //traversing by setting next to nodePtr and then looping
				}

				if(nodePtr->previous != NULL){
					nodePtr->previous_>next = nodePtr->next; //bypasses the current node in the next direction, this hurts my head
				}
				if(nodePtr->next != NULL){
					nodePtr->next->previous = nodePtr->previous; //bypasses the position node in the previous direction, this hurts my head
				}
				if(nodePtr == tail){
					tail = nodePtr->previous; //update tail to be the previous node
				}
				delete nodePtr;
				return;
			}
		}


		void displayList() const{
			ListNode<T> *nodePtr;  // To move through the list

			// Position nodePtr at the head of the list.
			nodePtr = head;

			if(nodePtr == NULL){
				cout << "The list does not contain any elements." << endl;
				return; 
			}

			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				// Display the value in this node.
				cout << nodePtr->data << endl;

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
			friend MergeSort(LinkedList myList) 
			{
				//use function to get list length
				int listLength = 0; 						
				listLength = getLength(); 		

				//initialize the midpoint of list using the length
				int mid;									
				mid = listLength/2; 

				//traversal pointer
				ListNode<T> *nodePtr;

				//new node pointer
				ListNode<T> *newNode;

				//sort until reach end of list
				if (nodePtr != NULL)  
				{
					//recursively sort left partition
					MergeSort(myList, mid); 

					//recursively sort right partition
					MergeSort(myList, mid + 1); 

					//Merge left and right partition in sorted order
					Merge(myList, mid);
				}
			}
			friend Merge(LinkedList myList, int mid, &nodePtr, &newNode) 
			{
				// Dynamically allocates temporary list for merged list
				T* mergedNumbers = new T[listLength];  
				
				// Initialize left partition position to beginning of list
				int leftPos;
				leftPos = head;              

				// Initialize right partition position to midpoint +1      
				int rightPos;   
				rightPos = mid + 1;                          
   
				// Add smallest element from left or right partition to merged arr
				while (leftPos <= mid && rightPos != NULL) 
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
                os << L.data; 
                
                return os; 
            }

};

#endif 
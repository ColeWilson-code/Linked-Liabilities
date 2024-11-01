/*
    Title: LinkedList.h
    Authors: Jack Bender, Cole Wilson
    Date: 11-01-24
    Purpose: create the LinkedList class and the Template helper class
*/

//define header
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


//library inclusions 
#include <iostream>
using namespace std; 


//template to be used with TemplateHelper class
template <typename T>


/*############################################
	Class: ListNode
	Purpose: template helper class to help move through the list
############################################*/
class ListNode
{
    private: 
        //stores data of the template type
        T data;
        

    public: 
        	
			//holds two pointers to another list node
			ListNode *next; 
			ListNode *previous; 

			//constructor 
			ListNode()
			{
				//list empty
				next = NULL;
				previous = NULL;
			}
			
			//get data at this location 
        	T getData()
        	{
				return data; 
        	}

			ListNode* getNext(){
				return next;
			}

			ListNode* getPrevious(){
				return previous;
			}

		/*
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
		*/

        //set data, next and previous 

            //data
            void setData(T var)
            {
				data = var; 
            }

            //next
            void setNext(ListNode* newNext)
            {
				next = newNext; 
            }

            //previous
            void setPrevious(ListNode* newPrevious)
            {
				previous = newPrevious; 
            }
}; 


template <typename T> //put this here again cause it got mad when I took it away

/*############################################
	Class: LinkedList
	Purpose: this is our linked list where we chain together our resistors
############################################*/
class LinkedList
{
    private: 

		ListNode<T> *head;		//List head pointer
		ListNode<T> *tail;	    //List tail pointer

    public: 
	
        /*############################################
			Function: constructor 
			Purpose: initialize the list
		#############################################*/ 
        LinkedList()
        {
			//creates an empty list by assigning NULL to head and tail
            head = NULL;
            tail = NULL;
        }

        /*############################################
			Function: destructor 
			Purpose: say goodbye to the resistors 
		#############################################*/
        ~LinkedList()
		{
			while(!isEmpty()){
				pop();
			}
		}


        /*############################################
			Function: isEmpty
			Purpose: check if the list is empty or not 
		############################################*/
		bool isEmpty(){
            return (head == NULL);
        }

		/*############################################
			Function: getHead
			Purpose: return head node 
		############################################*/
		ListNode<T>* getHead() const{
    		return head;
		}

  
		/*############################################
			Function: getLength
			Purpose: find length of list 
		############################################*/
		int getLength() const{
            int counter = 0;
			//pointer to traverse list 
	        ListNode<T> *nodePtr = this->getHead();
	
	        //list traversal
			//loop while the traversal pointer is not at the tail
	        while(nodePtr != tail)
	        {
		        counter++;
				//update the traversal pointer to point to the next node 
		        nodePtr = nodePtr->getNext();
				//check if traversal is pointing to tail to make sure last increment happens
		        if (nodePtr == tail)
		    	    counter++;
	        }
	        return counter;
        }

		/*############################################
			Function: appendNode
			Purpose: insert data at the end of the list 
		############################################*/
		void appendNode(T newData){
	        ListNode<T> *newNode;  // To point to a new node by declaring a newNode pointer
	        ListNode<T> *nodePtr = this->getHead();  // To move through the list //traversal popinter

	        // Allocate a new node and store num there.
	        newNode = new ListNode<T>;
            //Resistor Values setData
			newNode->setData(newData);

			//setting next and previous to NULL
			newNode->setNext(NULL);
	        newNode->setPrevious(NULL);

	        // If there are no nodes in the list make newNode the first node.
	        if (head == NULL) 
	        {
				//both head and tail
	        	head = newNode;
	        	tail = newNode;
	        }
	        else  // Otherwise, insert newNode at end.
	        {
		        //set the current last node's next pointer to the new node
	        	tail->setNext(newNode);
				newNode->setPrevious(tail);
		
	        	//now the tail is the new node
	        	tail = newNode;
	        }
        }

		/*############################################
			Function: prependNode
			Purpose: insert data at the beginning of the list 
		############################################*/
		void prependNode(T newData){
	        ListNode<T> *newNode;  // To point to a new node by declaring a newNode pointer
	        ListNode<T> *nodePtr = this->getHead();;  // To move through the list //traversal popinter

	        // Allocate a new node and store num there.
	        newNode = new ListNode<T>;
            //Resistor Values setData
			newNode->setData(newData);

			//setting next and previous to NULL
	        newNode->setNext(NULL);
	        newNode->setPrevious(NULL);

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
	        	newNode->setNext(head);
				head->setPrevious(newNode);		
		
	        	//now the tail is the new node
	        	head = newNode;
	        }
        }


		/*############################################
			Function: insertNode
			Purpose: insert the data a specific node 
		############################################*/
		void insertNode(int position, T newData){
	        //traversal pointer
			ListNode<T> *nodePtr = this->getHead();
			//new node pointer
	        ListNode<T> *newNode;
	
	        newNode = new ListNode<T>;
			newNode->setData(newData);
	
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
	        	int nodeCount = 0;
	        	if(position == 0)
	        	{
	        		newNode->setNext(head);
					head->setPrevious(newNode);
	        		head = newNode;
	        	}
	        	while(nodePtr != tail && nodeCount < position)
	        	{
	        		nodeCount++;
	        		if(nodeCount == position)
	        			break;
	        		nodePtr = nodePtr->getNext();
	        	}
		
	        	//now nodePtr is positioned 1 node BEFORE the node we want to insert
	        	if(nodePtr->next == NULL) //we are appending this node to the end
	        		tail = newNode;

	        	//set up newNode's links
	        	newNode->setNext(nodePtr->getNext());
				newNode->setPrevious(nodePtr);

	        	//change the node on the left
	        	nodePtr->setNext(newNode);
		
	        	//change the node on the right (if there is a node on the right)
	        	if(newNode->next)
		        {
		        	nodePtr = newNode->getNext(); 
					nodePtr->setPrevious(newNode);
		        }
	        }
        }
		

		/*############################################
			Function: deleteNode
			Purpose: delete the data a node 
		############################################*/
		 void deleteNode(int position){
			ListNode<T> *nodePtr = this->getHead();       // To traverse the list
			ListNode<T> *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
				cout << "The list is already empty.\n";
				return;

			// Determine if the first node is the one.
			if (position == 0)
			{
				head = nodePtr->getNext(); 
				if(head != NULL){
					head->setPrevious(NULL); //update the previous to NULL because nothing is before it 
				}else{
					tail = NULL; //if list is empty update tail to NULL
				}
				delete nodePtr;
				return;
			}

			else
			{
				//traverse to position passed in argument 
				for(int i = 0; i < position; i++){
					nodePtr = nodePtr->getNext(); //traversing by setting next to nodePtr and then looping
				}

				if(nodePtr->getPrevious() != NULL){
					nodePtr->getPrevious()->setNext(nodePtr->getNext()); //bypasses the current node in the next direction, this hurts my head
				}
				if(nodePtr->getNext() != NULL){
					nodePtr->getNext()->setPrevious(nodePtr->getPrevious()); //bypasses the position node in the previous direction, this hurts my head
				}
				if(nodePtr == tail){
					tail = nodePtr->getPrevious(); //update tail to be the previous node
				}
				delete nodePtr;
				return;
			}
		}

		/*############################################
			Function: displayList
			Purpose: get all the values in the  list
		#############################################*/
		void displayList() const
		{
			ListNode<T> *nodePtr = this->getHead();  // To move through the list

			if(nodePtr == NULL){
				cout << "The list does not contain any elements." << endl;
				return; 
			}

			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				// Display the value in this node.
				cout << nodePtr->getData() << endl;

				// Move to the next node.
				nodePtr = nodePtr->getNext();
			}
		}

		/*############################################
			Function: getFront
			Purpose: get value at front of list
		#############################################*/
		T getFront()
		{
			
			ListNode<T> *nodePtr = this->getHead();  // To move through the list

			//if there is nothing there
			if(nodePtr == NULL)
			{
				cout << "The list does not contain any elements." << endl;
				return NULL; 
			}

			//get the data at the front of the list
			return nodePtr->getData();

		}

		/*############################################
			Function: pop
			Purpose: pop the resistor at the front of list
		#############################################*/
		void pop()
		{
			ListNode<T> *nodePtr = this->getHead();       // To traverse the list
			ListNode<T> *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
			{
				cout << "\nThe list is already empty.\n";
				return;
			}
				
			//if there is crap there then we do stuff
			head = nodePtr->getNext();
			
			if(head != NULL)
			{
				head->setPrevious(NULL);
			}

			else
			{
				tail = NULL; //if list is empty update tail to NULL
			}

			delete nodePtr;
			return;
				
		}
		
		/*############################################
			Function: StoreResistanceForMerge
			Purpose: put resistance values from linked list into array, sort the array, thereby sorting list values 
		#############################################*/
		void StoreResistanceForMerge(int length) const 
		{
			//use getLength function to get size of array 
			int listLength = getLength(); 

			//make an array to hold resistor values
			int* resistors = new int[listLength];
			ListNode<T> *nodePtr = this->getHead();  // To move through the list

			if(nodePtr == NULL){
				cout << "The list does not contain any elements." << endl;
				delete [] resistors;
				return; 
			}

			int i = 0; 
			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				resistors[i] = nodePtr->getData().getResistance();

				// Move to the next node.
				nodePtr = nodePtr->getNext();

				i++;
			}
			MergeSort(resistors,0, listLength);
			delete [] resistors;
		}


		void MergeSort(int arr[], int beg, int end) const {
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

		void Merge(int arr[], int beg, int mid, int end) const {
   			int mergedSize = end - beg + 1;                // Size of merged partition
   			int mergePos = 0;                          // Position to insert merged number
   			int leftPos = 0;                           // Position of elements in left partition
   			int rightPos = 0;                          // Position of elements in right partition
   			int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
                                              // for merged arr
   
   			leftPos = beg;                               // Initialize left partition position
   			rightPos = mid + 1;                          // Initialize right partition position
   
   			// Add smallest element from left or right partition to merged arr
   			while (leftPos <= mid && rightPos <= end) {
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
   			while (leftPos <= mid) {
    			mergedNumbers[mergePos] = arr[leftPos];
    			++leftPos;
    			++mergePos;
			}
   
			// If right partition is not empty, add remaining elements to merged numbers
			while (rightPos <= end) {
    			mergedNumbers[mergePos] = arr[rightPos];
    			++rightPos;
    			++mergePos;
			}
   
			// Copy merge number back to arr
   			for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
    			arr[beg + mergePos] = mergedNumbers[mergePos];
			}

			for(int j = 0; j < mergedSize; j++){
				cout << mergedNumbers[j] << " OHMS " << endl; 
			}
			delete [] mergedNumbers;
		}
		
		/*############################################
		Function: stream operator << 
		Purpose: make outputting easier 
		#############################################*/
        friend ostream& operator << (ostream& os, const LinkedList& L)
        {
            ListNode<T> *nodePtr = L.getHead();  // To move through the list

			while(nodePtr){
				os << nodePtr->getData() << " ";
            	nodePtr = nodePtr->getNext();
			}
			return os;
        }
	
};
#endif 
# Resistor-Series-Circuit-Simplifier
Program 2 assignment for CSC 1310


Authors: Jack Bender, Cole Wilson 


Assigned: 10-9-24


Completed: 10-30-24

## Description
Program contains a linked list class, data class, and template helper class. Linked List connects the data together and organizes it, data class stores info about individual items, 
and template helper provides a way to move through the linked list and get the data from items. 

## Outline
This program is intended to utilize linked lists to represent Resistor series circuits. When you have resistors in series, you simply add them together to get an equivalent resistance: 


  Req = R1 + R2


This program is designed that whenever you pop or remove an item (resistor) from the linked list you will be simplifying the circuit, 
with an additional option to just remove the resistor completely and ignore it. 


This provides some useful functionality for simple circuit evaluations as well as demonstrating understanding of linked lists. 

## Classes 
### Linked List
Acts as a series circuit, with the items of the list being the resistors connected together. This will allow us to represent the circuit connnections in order to 
later perform simplifications. This class contains functions to add, remove, and look at the list. 
### Data 
Stores the data about the resistors 

- Resistance

- Power Rating

- Color Code


Uses getters/setters to allow data to be modified in function calls. 
### List Node 
This will store data of the template type and have a few functions used for iterating through the list and getting the data at its location

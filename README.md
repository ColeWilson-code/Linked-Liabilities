# Resistor-Series-Circuit-Simplifier
Program 2 assignment for CSC 1310


Authors: Jack Bender, Cole Wilson 


Assigned: 10-9-24


Completed: 11-01-24

## Description
Program contains a linked list class, data class, and template helper class. Linked List connects the data together and organizes it, data class stores info about individual items, 
and template helper provides a way to move through the linked list and get the data from items. 

## Outline
This program utilizes linked lists to represent Resistor series circuits. When you have resistors in series, you simply add them together to get an equivalent resistance: 


  Req = R1 + R2


Using this principle, we can achieve some basic circuit simplification processes by using pop functions with some extra math. 


This provides some useful functionality for simple circuit evaluations as well as demonstrating understanding of linked lists. 

## Classes 
### Linked List
Acts as a series circuit, with the items of the list being the resistors connected together. This allows us to represent the circuit connnections in order to 
later perform simplifications. This class contains functions to add, remove, and look at the list. 
### Data 
Stores the data about the resistors 

- Resistance

- Power Rating

- Color Code


Uses getters/setters to allow data to be modified in function calls. Also contains comparison and stream operator overloads to allow for easy comparisons of data 
### List Node 
This stores data of the template type and has a few functions used for iterating through the list and getting the data at certain locations

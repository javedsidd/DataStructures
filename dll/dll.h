/***********************************************************************************
*** File Name: dll.h
***   Purpose: header file containing function prototype for doubly linked list
***    Author: Mohammad Javed Akhtar
***    
***********************************************************************************/



#include <stdio.h>
#include <stdlib.h>

typedef struct dll_node 
{
	struct dll_node *prev;
	int data;
	struct dll_node *next;
}Dll_Node;

Dll_Node* make_new_node(int data);

int isEmpty(Dll_Node *);

//adding functions
void add_node_at_begin(Dll_Node**,Dll_Node**,int);
void add_node_at_end(Dll_Node**,Dll_Node**,int);
void sorted_add_ascending(Dll_Node**,Dll_Node**,int);
void sorted_add_decending(Dll_Node**,Dll_Node**,int);

//count function
int node_count(Dll_Node*);

//print functions
void display_forward(Dll_Node*);
void display_backward(Dll_Node*);
void display_nth_node_from_first(Dll_Node*,int);
void display_nth_node_from_last(Dll_Node*,Dll_Node*,int);
void print_middle_node(Dll_Node *);

//delete functions
void delete_all(Dll_Node **);
void delete_nth_node(Dll_Node**,int);
void delete_duplicate_nodes_from_unsorted_list(Dll_Node **);
void delete_duplicate_nodes_from_sorted_list(Dll_Node **);
void delete_middle_node(Dll_Node **);

//reverse functions
void reverse_by_data(Dll_Node**);
void reverse_by_link(Dll_Node**);

//search functions
void search_a_node(Dll_Node*,int);
void find_nth_node_from_last_node(Dll_Node*,int);




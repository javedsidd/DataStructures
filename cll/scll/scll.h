/***********************************************************************************
*** File Name: scll.h
***   Purpose: header file containing function prototype for singly circular linked list
***    Author: Mohammad Javed Akhtar
***    
***********************************************************************************/



#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *next;
}Node;

Node* make_new_node(int data);

int isEmpty(Node *);

//adding functions
void add_node_at_begin(Node**,int);
void add_node_at_end(Node**,int);
void sorted_add_ascending(Node**,int);
void sorted_add_decending(Node**,int);

//count function
int node_count(Node*);

//print functions
void display_all(Node*);
void display_nth_node(Node*,int);
void print_middle_node(Node *);

//delete functions
void delete_all(Node **);
void delete_nth_node(Node**,int);
void delete_duplicate_nodes_from_unsorted_list(Node **);
void delete_duplicate_nodes_from_sorted_list(Node **);
void delete_middle_node(Node **);

//reverse functions
void reverse_by_data(Node**);
void reverse_by_link(Node**);

//search functions
void search_a_node(Node*,int);
void find_nth_node_from_last_node(Node*,int);




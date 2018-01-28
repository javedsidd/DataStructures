/***********************************************************************************
*** File Name: sll_main.c
***   Purpose: Test Applicarion programs for single linked list functions defined in sll.c
***    Author: Mohammad Javed Akhtar
***    
***********************************************************************************/

#include "sll.h"

int main(int c, char **v)
{
	if(c<2)
	{
		printf("usage: ./sll <n1><n2><n3>...\n");
		return -1;
	}

Node *headptr=NULL;

	int i=1;
	for(  ; i < c ; i++)
	{
		sorted_add_ascending(&headptr,atoi(v[i]));
		
		//add_node_at_begin(&headptr,atoi(v[i]));
		//add_node_at_end(&headptr,atoi(v[i]));

		//sorted_add_decending(&headptr,atoi(v[i]));
	}

int n;
	display_all(headptr);

	do
	{
		printf("Enter the node number to display its data:");
		scanf("%d",&n);
		display_nth_node(headptr,n);
		if(n==-1) break;
		printf("\nEnter the node number to delete:");
		scanf(" %d",&n);
		//if(n==-1) break;
		delete_nth_node(&headptr, n);
		display_all(headptr);
		printf("\nEnter the key/data to search:");
		scanf(" %d",&n);
		search_a_node(headptr,n);
		
		printf("\nEnter the node number to find from last:");
		scanf(" %d",&n);
		find_nth_node_from_last_node(headptr,n);
		if(n==-1) break;
		display_all(headptr);
		print_middle_node(headptr);
	}while(n!=-1);

	//delete_duplicate_nodes_from_unsorted_list(&headptr);
	//delete_duplicate_nodes_from_sorted_list(&headptr);
	//print_middle_node(headptr);
	//delete_middle_node(&headptr);

	display_all(headptr);

	//print_middle_node(headptr);
	
	
	reverse_by_data(&headptr);
	display_all(headptr);

	reverse_by_link(&headptr);	
	display_all(headptr);

	
	delete_all(&headptr);
	display_all(headptr);
return 0;
}

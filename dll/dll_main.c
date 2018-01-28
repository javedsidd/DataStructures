/***********************************************************************************
*** File Name: dll_main.c
***   Purpose: Test Applicarion programs for doubly linked list functions defined in dll.c
***    Author: Mohammad Javed Akhtar
***    
***********************************************************************************/

#ifndef _DLL_H_
#define _DLL_H_

#include "dll.h"

int main(int c, char **v)
{

	if(c<2)
	{
		printf("usage: ./dll <n1><n2><n3>...\n");
		//return -1;
	}

Dll_Node *head=NULL;
Dll_Node *tail=NULL;

	int i=1;
	for(  ; i < c ; i++)
	{
		//sorted_add_ascending(&head,&tail,atoi(v[i]));
		
		//add_node_at_begin(&head,&tail,atoi(v[i]));
		
		//add_node_at_end(&head,&tail,atoi(v[i]));

		sorted_add_decending(&head,&tail,atoi(v[i]));
	}
	display_forward(head);
	display_backward(tail);
int n;
	do
	{
		printf("Enter a node number to see it's data [-1 to skip]:");
		scanf("%d",&n);	

		display_nth_node_from_first(head,n);

		display_nth_node_from_last(head,tail,n);

		delete_nth_node(&head, n); 

		display_forward(head);
	}while(n!=-1);	


	print_middle_node(head);
	display_forward(head);
	delete_all(&head);
	display_forward(head);
}

#endif /* _DLL_H_ */

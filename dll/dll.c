/***********************************************************************************
*** File Name: dll.c
***   Purpose: Implementation of functions related to doubly linked list
***    Author: Mohammad Javed Akhtar
***    
***********************************************************************************/

#ifndef _DLL_H_
#define _DLL_H_

#include "dll.h"


/***********************************************************************************
*** Function Name: make_new_node
***   Purpose: it dynamically allocate memory and creates node and fill the data 
*** Arguments: Takes an integer value
*** Return type: address of the newly created node
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
Dll_Node* make_new_node(int data)
{
	Dll_Node* newNode= (Dll_Node*) malloc(sizeof(Dll_Node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;

return newNode;
}

/***********************************************************************************
*** Function Name: isEmpty
***   Purpose: checks for an empty doubly linked list 
*** Arguments: Takes a pointer to head pointer 
*** Return type: return 1 if linked list is Empty else returns 0
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
int isEmpty(Dll_Node *hptr)
{
	if(hptr==NULL)
	return 1;
	else return 0;
}

int node_count(Dll_Node*hptr)
{
	int c=0;
	if(isEmpty(hptr) == 1)
	{
		printf("\n------ Double linked list is empty --------\n");
		return 0 ;
	}	
	while(hptr)
	{
		c++;
		hptr=hptr->next;
	}
return c;
}

void add_node_at_begin(Dll_Node**hptr,Dll_Node**tptr,int val)
{
	Dll_Node *newNode= make_new_node(val);
	 
	if(*hptr == NULL)
	{
		*hptr= newNode;
		*tptr=newNode;
	}
	else
	{
		newNode->next=*hptr;
		(*hptr)->prev=newNode;
		*hptr=newNode;
	}

}


void add_node_at_end(Dll_Node**hptr,Dll_Node**tptr,int val)
{
	static Dll_Node* last;
	
	Dll_Node *newNode= make_new_node(val);
	 
	if(*hptr == NULL)
	{
		*hptr= newNode;
		last=newNode;	
		*tptr=newNode;
	}
	else
	{
		last->next=newNode;
		newNode->prev=last;
		last=newNode;
		*tptr=newNode;
	}

}
	
void sorted_add_ascending(Dll_Node**hptr,Dll_Node**tptr,int val)
{
	Dll_Node *curNode;
	Dll_Node *newNode= make_new_node(val);
	 
	if(*hptr==NULL || (*hptr)->data > val)
	{
		if(*hptr==NULL)
		*tptr=newNode;		
	
		if(*hptr != NULL)
		(*hptr)->prev=newNode;
	
		newNode->next=*hptr;
		*hptr=newNode;	

	}
	else
	{
			curNode=*hptr;
			while(curNode != NULL)
			{
				if(curNode->next == NULL)
				{

					*tptr=newNode;					
					curNode->next=newNode;
					newNode->prev=curNode;
					break;
				}	
				else if (curNode->next->data > newNode->data)
				{	
					curNode->next->prev=newNode;
					newNode->next=curNode->next;
					newNode->prev=curNode;
					curNode->next=newNode;
					break;
				}

			curNode=curNode->next;			
			}	
	}
}

void sorted_add_decending(Dll_Node**hptr,Dll_Node**tptr,int val)
{
	Dll_Node *curNode;
	Dll_Node *newNode= make_new_node(val);
	 
	if(*hptr==NULL || (*hptr)->data < val)
	{
		if(*hptr==NULL)
		*tptr=newNode;		
	
		if(*hptr != NULL)
		(*hptr)->prev=newNode;
	
		newNode->next=*hptr;
		*hptr=newNode;	

	}
	else
	{
			curNode=*hptr;
			while(curNode != NULL)
			{
				if(curNode->next == NULL)
				{

					*tptr=newNode;					
					curNode->next=newNode;
					newNode->prev=curNode;
					break;
				}	
				else if (curNode->next->data < newNode->data)
				{	
					curNode->next->prev=newNode;
					newNode->next=curNode->next;
					newNode->prev=curNode;
					curNode->next=newNode;
					break;
				}

			curNode=curNode->next;			
			}	
	}
}

void display_forward(Dll_Node *hptr)
{	
printf("\n--- Displaying in forward manner---\n");		
	
	int c;
	if((c=node_count(hptr)) != 0)
	{
		printf("---Total nodes: %d\n",c);
	}
	while(hptr!=NULL)
	{
		printf("%d ", hptr->data);
		hptr=hptr->next;
		
	}	
printf("\n");
}

void display_backward(Dll_Node *tptr)
{	
printf("\n--- Displaying in backward manner---\n");	
	if(isEmpty(tptr) == 1)
	{
		printf("\n------ Double linked list is empty --------\n");
		return ;
	}
	else while(tptr!=NULL)
	{
		printf("%d ", tptr->data);
		tptr=tptr->prev;
		
	}	
printf("\n");
}


void display_nth_node_from_first(Dll_Node*hptr,int n)
{
int c=node_count(hptr);
	if(isEmpty(hptr) == 1)
	{
		printf("\n------ Double linked list is empty --------\n");
		return ;
	}
	else if ( n<=0 || n >c)
	{
		printf("\n---Wrong Input!! Please enter a node number between 1 to %d.----\n",c);
		return ;
	}
	else	
	{
		int i=1;
		while(i++ < n)
		hptr=hptr->next;
		printf("\n--- node [%d] from begining is : %d\n",n,hptr->data);
	}
}

void display_nth_node_from_last(Dll_Node*hptr,Dll_Node*tptr,int n)
{
int c=node_count(hptr);
	if(isEmpty(hptr) == 1)
	{
		printf("\n------ Double linked list is empty --------\n");
		return ;
	}
	else if ( n<=0 || n >c)
	{
		printf("\n---Wrong Input!! Please enter a node number between 1 to %d.----\n",c);
		return ;
	}
	else	
	{
		int i=1;
		while(i++ < n)
		tptr=tptr->prev;
		printf("\n--- node [%d] from last is : %d\n",n,tptr->data);
	}
}


void print_middle_node(Dll_Node *hptr)
{
	Dll_Node *slow=hptr;
	Dll_Node *fast=hptr;
	int midnode=0;
		if(isEmpty(hptr) == 1)
	{
		printf("\n------ Double linked list is empty --------\n");
		return ;
	}
	else while(fast!=NULL && fast->next!=NULL)
	{
		
		fast=fast->next->next;
		slow=slow->next;
		midnode++;
	}

	printf("\n---- node [%d] is Middle node and it's data is:%d\n",midnode,slow->data);

}



void delete_all(Dll_Node **hptr)
{

	if(isEmpty(*hptr) == 1)
	{
		printf("\n------ Nothing to delete --------\n");
		return ;
	}
	else
	{
		while(*hptr)
		{
			Dll_Node *temp=(*hptr);
			(*hptr)=(*hptr)->next;
			printf("Deleting Node: %d\n ",temp->data);	
		}
	}
}

void delete_nth_node(Dll_Node**hptr,int n)
{
int c=node_count(*hptr);
	if(isEmpty(*hptr) == 1)
	{
		printf("\n------ Nothing to delete --------\n");
		return ;
	}
	else if ( n<=0 || n >c)
	{
		printf("\n---Wrong Input!! Please enter a node number between 1 to %d.----\n",c);
		return ;
	}
	else	
	{
		int i=1;
		Dll_Node *temp=*hptr;
		while(i < n)
		{
			temp=temp->next;
			i++;
		}
		
		if(temp->next==NULL &&  temp->prev==NULL)  //for only one node
		{
			free(temp);
			*hptr=NULL;
		}
		else if(temp->prev ==NULL) //for first node
		{
			temp->next->prev=temp->prev;
			*hptr=temp->next;
		}
		else if(temp->next==NULL) //for last node
		{
			temp->prev->next=temp->next;
		}
		else //any node except first and last
		{

			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
		}
		
		printf("\n--- deleting node [%d] from begining : %d\n",n,temp->data);
		free(temp);
		
	}
}

#endif /* _DLL_H_ */



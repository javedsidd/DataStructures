/***********************************************************************************
*** File Name: sll.c
***   Purpose: Implementation of functions related to single linked list
***    Author: Mohammad Javed Akhtar
***    
***********************************************************************************/


#include "sll.h"

/***********************************************************************************
*** Function Name: make_new_node
***   Purpose: it dynamically allocate memory and creates node and fill the data 
*** Arguments: Takes an integer value
*** Return type: address of the newly created node
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
Node* make_new_node(int data)
{
	Node* newNode= (Node*) malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;

return newNode;
}

/***********************************************************************************
*** Function Name: isEmpty
***   Purpose: checks for an empty singly linked list 
*** Arguments: Takes a pointer to head pointer 
*** Return type: return 1 if linked list is Empty else returns 0
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
int isEmpty(Node *hptr)
{
	if(hptr==NULL)
	return 1;
	else return 0;
}


/***********************************************************************************
*** Function Name: node_count
***   Purpose: counts the number of nodes present in the singly linked list 
*** Arguments: Takes a pointer to head pointer 
*** Return type: count of nodes 
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
int node_count(Node*hptr)
{
	int c=0;
	if(isEmpty(hptr)==1)
	{
		printf("\n---Nothing to count ---\n");
		return c;
	}
	else
	{
		while(hptr)
		{
			c++;
			hptr=hptr->next;
		}
	}
return c;	
}


/***********************************************************************************
*** Function Name: add_node_at_begin
***   Purpose: adds node at the begining of a singly linked list 
*** Arguments: Takes a pointer to head pointer and an integer value
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void add_node_at_begin(Node **hptr,int val)
{
	Node* newNode=make_new_node(val);
        newNode->next=*hptr;
	*hptr=newNode;
	
}



/***********************************************************************************
*** Function Name: add_node_at_end
***   Purpose: adds node at the end of a singly linked list 
*** Arguments: Takes a pointer to head pointer and an integer value
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void add_node_at_end(Node**hptr,int val)
{
	
	Node* newNode=make_new_node(val);
	
	static Node* lastNode;

	if(*hptr==NULL)
	{
	 	newNode->next=*hptr;
		*hptr=newNode;
		lastNode=*hptr;	
	} 
	else
	{
		lastNode->next=newNode;
		lastNode=newNode;	
	}
}


/***********************************************************************************
*** Function Name: sorted_add_ascending
***   Purpose: adds node in sorted ascending fashion to a singly linked list 
*** Arguments: Takes a pointer to head pointer and an integer value
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void sorted_add_ascending(Node**hptr,int val)
{
	Node* newNode=make_new_node(val);
	
	if( *hptr==NULL || (*hptr)->data > newNode->data)
	{
		newNode->next=*hptr;
		*hptr=newNode;	
	}
	else
	{
		Node *CurNode=*hptr;
		while(CurNode)
		{
			if(CurNode->next==NULL)	
			{	
				CurNode->next=newNode;
				break;
			}
			else if(CurNode->next->data > newNode->data)
			{
				newNode->next=CurNode->next;
				CurNode->next=newNode;
				break;
			}
			CurNode=CurNode->next;
		}
	}
}




/***********************************************************************************
*** Function Name: sorted_add_decending
***   Purpose: adds node in sorted decending fashion to a singly linked list 
*** Arguments: Takes a pointer to head pointer and an integer value
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void sorted_add_decending(Node**hptr,int val)
{
	Node* newNode=make_new_node(val);
	
	if( *hptr==NULL || (*hptr)->data < newNode->data)
	{
		newNode->next=*hptr;
		*hptr=newNode;	
	}
	else
	{
		Node *CurNode=*hptr;
		while(CurNode)
		{
			if(CurNode->next==NULL)	
			{	
				CurNode->next=newNode;
				break;
			}
			else if(CurNode->next->data < newNode->data)
			{
				newNode->next=CurNode->next;
				CurNode->next=newNode;
				break;
			}
			CurNode=CurNode->next;
		}
	}
}


/***********************************************************************************
*** Function Name: display_all
***   Purpose: print all nodes present in the singly linked list one by one 
*** Arguments: Takes a pointer to head pointer
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void display_all(Node*hptr)
{
	if(isEmpty(hptr)==1)
	{
		printf("\n----Nothing to display----\n");
		return;
	}
	else
	{
		printf("\n---- displaying ----");
		printf("\n---- Total nodes: %d ----\n", node_count(hptr));
		while(hptr)
		{
			printf("%d ",hptr->data);
			hptr=hptr->next;
		}
	}

printf("\n");
}

/***********************************************************************************
*** Function Name: display_nth_node
***   Purpose: print nth node of the singly linked list
*** Arguments: Takes a pointer to head pointer and an integer value
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void display_nth_node(Node* hptr, int n)
{
int c= node_count(hptr);
	if(isEmpty(hptr)==1)
	{
		printf("\n----Nothing to display----\n");
		return;
	}
	else if(n <=0 || n>c)
	{
		printf("---- Oops!!No such node!! please enter node between 1 to %d----\n",c);
		return;
	}
	else
	{
		printf("\n---- displaying ----\n");
		int i=1;
		while(i++ < n)
		hptr=hptr->next;
		
		printf("%d Node data is: %d\n",n,hptr->data);
	}

printf("\n");
}



/***********************************************************************************
*** Function Name: print_middle_node
***   Purpose: print middle node of the singly linked list
*** Arguments: Takes a pointer to head pointer
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void print_middle_node(Node *hptr)
{
	Node *slow=hptr;
	Node *fast=hptr;

	if(isEmpty(slow)==1)
	{
		printf("\n-------Nothing to delete-----\n");
		return;
	}
	else while(fast!=NULL && fast->next !=NULL)
	{

		fast=fast->next->next;
		slow=slow->next;

	}

	printf("\n----Middle node's data is %d \n",slow->data);

}


/***********************************************************************************
*** Function Name: delete_all
***   Purpose: delete each nodes of the linked list i.e. delete whole linked list
*** Arguments: Takes a double pointer to head pointer
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void delete_all(Node **hptr)
{
	Node *temp=*hptr;
	if(isEmpty(temp)==1)
	{
		printf("\n-------Nothing to delete-----\n");
		return;
	}
	else
	{
		while(*hptr!=NULL)
		{
			temp=*hptr;
			*hptr=(*hptr)->next;
			//printf("deleting node: %d\n",temp->data);
			free(temp);
		}
	
	}
}


/***********************************************************************************
*** Function Name: delete_nth_node
***   Purpose: delete nth node of the singly linked list
*** Arguments: Takes a pointer to head pointer and an integer value
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void delete_nth_node(Node**hptr, int n )
{
Node *curNode=*hptr;
Node *nextNode,*prevNode;

int c=node_count(curNode);

	if(isEmpty(curNode)==1)
	{
		printf("\n-------Nothing to delete-----\n");
		return;
	}
	else if(n <=0 || n>c)
	{
		printf("---- Oops!!No such node!! please enter node between 1 to %d----\n",c);
		return;
	}
	else
	{
		int i=1;
		if(n==1)
		{
			*hptr=(*hptr)->next;
			printf("deleting node %d --it's data is: %d\n",n,curNode->data);
			free(curNode);
		}
		else
		{
			while(i++ < n)
			{
				prevNode=curNode;				
				curNode=curNode->next;
				nextNode=curNode->next;			

			}

			prevNode->next=nextNode;
			printf("deleting node %d --it's data is: %d\n",n,curNode->data);
			free(curNode);			
		}
		

	}

}


/***********************************************************************************
*** Function Name: delete_middle_node
***   Purpose: delete middle node of the singly linked list
*** Arguments: Takes a pointer to head pointer
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void delete_middle_node(Node **hptr)
{
	Node *slow=*hptr;
	Node *fast=*hptr;
	Node *prev=*hptr;
	if(isEmpty(slow)==1)
	{
		printf("\n-------Nothing to delete-----\n");
		return;
	}
	else while(fast!=NULL && fast->next !=NULL)
	{
		
		prev=slow;
		fast=fast->next->next;
		slow=slow->next;
	}
	
	prev->next=slow->next;
	printf("\n----Deleting Middle node!! it's data is %d \n",slow->data);
	free(slow);
}


/***********************************************************************************
*** Function Name: delete_duplicate_nodes_from_unsorted_list
***   Purpose: delete duplicate nodes present in the unsorted singly linked list
*** Arguments: Takes a double pointer to head pointer
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void delete_duplicate_nodes_from_unsorted_list(Node **hptr)
{
/*Write a removeDuplicates() function which takes a list and deletes any duplicate nodes from the list.
	The list is not sorted.  
*/


	Node *ptr=*hptr;
	Node *dup;
	Node *ptr2;
	char dupfound=0;
	if(isEmpty(ptr)==1)
	{
		printf("\n-------Nothing to delete-----\n");
		return;
	}
	else
	{	

		while(ptr!=NULL && ptr->next!=NULL)
		{
			dupfound=0;
			ptr2=ptr;		
			while(ptr2->next!= NULL)
			{
				if(ptr->data == ptr2->next->data)
				{
					dupfound=1;
					dup=ptr2->next;
					ptr2->next=ptr2->next->next;
					printf(" Deleted duplicate node is : %d\n",dup->data);
					free(dup);		
				}
				else //only advance if there is no deletion
				ptr2=ptr2->next;
			}
		ptr=ptr->next;			
		}

		if(dupfound==0)
		{
			printf("\n----No duplicates found!!----\n");
		}

	}
	
}



/***********************************************************************************
*** Function Name: delete_duplicate_nodes_from_sorted_list
***   Purpose: delete duplicate nodes present in the sorted singly linked list
*** Arguments: Takes a double pointer to head pointer
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void delete_duplicate_nodes_from_sorted_list(Node **hptr)
{
	Node *curNode=*hptr;
	Node *nextNextNode;
	Node *dup;
	char dupfound=0;
	if(isEmpty(curNode)==1)
	{
		printf("\n-------Nothing to delete-----\n");
		return;
	}
	else
	{
		while( curNode->next!=NULL)
		{	
			dupfound=0;

			if(curNode->data == curNode->next->data)
			{
				dupfound=1;
				nextNextNode=curNode->next->next;
				dup=curNode->next	;
				printf(" Deleted duplicate node is : %d\n",dup->data);
				free(dup);
				curNode->next=nextNextNode;
			}
			else //only advance if there is no deletion
			curNode=curNode->next;
		}
		
			if(dupfound==0)
			{
			printf("\n----No duplicates found!!----\n");
			}
	}
}

/***********************************************************************************
*** Function Name: reverse_by_link
***   Purpose: reverse the singly linked list by reversing the links
*** Arguments: Takes a double pointer to head pointer 
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void reverse_by_link(Node**hptr)
{
	Node *cur=*hptr;
	Node *prev=0;
	Node *next;
	
	if(isEmpty(cur)==1)
	{
		printf("\n-------Nothing to delete-----\n");
		return;
	}
	else while(cur!=NULL)
	{
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	*hptr=prev;
}


/***********************************************************************************
*** Function Name: reverse_by_link
***   Purpose: reverse the singly linked list by swaping the data
*** Arguments: Takes a double pointer to head pointer 
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/

void reverse_by_data(Node**hptr)
{
	Node* temp1=*hptr;
	Node*  temp2=*hptr;
	int count= node_count(temp1);
	
	if(isEmpty(temp1)==1)
	{
		printf("\n-------Nothing to delete-----\n");
		return;
	}
	else
	{
		int i=0,j,k=count-1,t;
		while(i < k)
		{
			j=0;
			while(j < k)
			{
				temp2=temp2->next;
				j++;	
			}
					
			t=temp1->data;
			temp1->data=temp2->data;
			temp2->data=t;
			
			i++;
			k--;

		temp1=temp1->next;
		temp2=*hptr; //very important
		}
	}
}



/***********************************************************************************
*** Function Name: search_a_node
***   Purpose: search for a value/key in the linked list 
*** Arguments: Takes a pointer to linked list and a intger value  
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/

void search_a_node(Node*hptr,int key)
{

	int nodeNum=0;
	int keyfound=0;
	if(isEmpty(hptr)==1)
	{
		printf("\n-------Linked list is empty-----\n");
		return;
	}
	else while(hptr)
	{
		nodeNum++;
		if(hptr->data == key)
		{
			keyfound=1;
			printf(" %d Found at node number [%d]\n",key,nodeNum);
			return;
		}
		
		hptr=hptr->next;
	}
	
	if(keyfound==0)
	{
		printf("---Sorry!! %d is not found in the linked List.----\n",key);
	}
}


/***********************************************************************************
*** Function Name: find_nth_node_from_last_node
***   Purpose: find a node by a node number from the last of the linked list 
*** Arguments: Takes a pointer to linked list and a intger value  
*** Return type: void
***   Author: Mohammad Javed Akhtar 
***********************************************************************************/
void find_nth_node_from_last_node(Node*hptr,int n)
{
	
	//method 2 using two pointers
	Node *temp=hptr;
	if(isEmpty(hptr)==1)
	{
		printf("\n-------Linked list is empty-----\n");
		return;
	}
	else
	{
		int i=0;	
		while(i < n)	 //move this pointer by n 
		{
			if(temp==NULL)
			{
				printf("---- given node number %d is greater than numbers of nodes in the list.---\n",n);
				return ;
			}			
			temp=temp->next;
			i++;
		}


		while(temp!=NULL)
		{
			hptr=hptr->next;	
			temp=temp->next;
		}
	printf(" [%d] node from last node is: %d\n",n,hptr->data);	
	}


	//method 1 using node count
/*	int c=node_count(hptr);
	int m=c-n;
	int i=0;
	if(isEmpty(hptr)==1)
	{
		printf("\n-------Linked list is empty-----\n");
		return;
	}
	else if(n <=0 || n>c)
	{
		printf("---- Oops!!No such node!! please enter node between 1 to %d----\n",c);
		return;
	}
	else while(i < m )
	{
		hptr=hptr->next;
		i++;
	}
	
	printf(" [%d] node from last is: %d\n",n,hptr->data);
*/
}


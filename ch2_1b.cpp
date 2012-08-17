/*Write code to remove duplicates from an unsorted linked list. FOLLOW UP. How would you solve this problem if temporary buffer is not allowed*/

#include <stdio.h>
#include <cstddef> //For NULL
#include <iostream>
#include <map>

using namespace std;

struct Node{
	int x;
	Node *next;
};


class List{
	Node* head;

	public:
	List() { head = NULL;};

	void PrintList();
	void AddNode(int data);
	void RemoveDuplicates();
};


void List::AddNode(int data){

	Node* newNode = new Node();
	newNode->x = data;
	newNode->next = NULL;
	//printf("%d-- ", newNode->x);

	Node *traversal = head;

	if(traversal == NULL){
		head = newNode;
		return;	
	}
	else{
		while(traversal->next != NULL){
			traversal = traversal->next;
		}
		traversal->next = newNode;
	}
	return;
}

void List::PrintList(){
	Node *traverse = head;

	if(traverse == NULL){
		printf("%s\n", "...empty list\n");
		return;
	}
	else{
		do{
	    		printf("%d--", traverse->x);
			traverse = traverse->next;
    		}while(traverse != NULL);
		return;
	}
}

void List::RemoveDuplicates(){
	Node *traversal = head;

	if(traversal == NULL){
		printf("%s\n", "...empty list\n");
		return;
	}
	else if(traversal->next == NULL){
		printf("%s\n", "...there are no duplicates\n");
		return;
	}
	else{	
		while(traversal->next != NULL){
			Node *prev = head;
			Node *current = head->next;
			printf("Traversal: %d\n", traversal->x);

			while(current!=NULL)
			{	
				printf("prev: %d\n", prev->x);
				printf("current: %d\n", current->x);
				if(traversal->x==current->x && traversal !=current)
				{
					if(current->next == NULL)
					{
						printf("...last element equal\n");
						Node *temp = current;
						prev->next==NULL;
						delete[] temp;
						break;
					}else{
						printf("...middle element equal\n");
						Node *temp = current;
						prev->next = current->next;
						
						delete[] temp;
						break;
					}
				}
				prev = current;
				current = current->next;
			}					
			traversal = traversal->next;
		}		
	}			
}

int main()
{
	List list;

	list.AddNode(1);
	list.AddNode(2);
	list.AddNode(2);
	list.AddNode(3);
	list.AddNode(3);
	list.AddNode(3);	
	list.AddNode(4);
	list.AddNode(1);
	list.PrintList();
	list.RemoveDuplicates();
	list.PrintList();
	
}

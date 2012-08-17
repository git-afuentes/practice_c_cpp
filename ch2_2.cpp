/* Implement an algorithm to find the kth to last element of a singly linked list */

#include <stdio.h>
#include <cstddef> //For NULL
#include <iostream>

using namespace std;

struct Node{
	int x;
	Node *next;
};


class List{
	Node* head;

	public:
	List() { 
		head = NULL;
	};

	void PrintList();
	void AddNode(int data);
	void FindKthToLastElement(int k);
};

void List::AddNode(int data){

	Node* newNode = new Node();
	newNode->x = data;
	newNode->next = NULL;

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

void List::FindKthToLastElement(int k){
	Node *traverse = head;
	int kthToLast, totalElements = 0;

	while(traverse != NULL){
		totalElements++;
		traverse = traverse->next;
	}
	printf("TotalElements: %d\n", totalElements);
	
	kthToLast = totalElements - k -1;
	printf("kthToLast: %d\n", kthToLast);

	traverse = head;
	while(kthToLast !=0 ){
		traverse = traverse->next;
		kthToLast--;	
	}
	printf("Number: %d\n", traverse->x);
}

int main()
{
	List list;

	list.AddNode(1);
	list.AddNode(2);
	list.AddNode(3);	
	list.AddNode(4);
	list.AddNode(5);
	list.PrintList();
	list.FindKthToLastElement(3);
	list.FindKthToLastElement(1);
	list.FindKthToLastElement(4);
}






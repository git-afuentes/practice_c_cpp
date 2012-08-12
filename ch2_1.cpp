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
	map<char, int>mymap;

	if(traversal == NULL){
		printf("%s\n", "...empty list\n");
		return;
	}
	else if(traversal->next == NULL){
		printf("%s\n", "...there are no duplicates\n");
		return;
	}
	else{
		do{
			if(mymap.find(traversal->x) == mymap.end())
				mymap[traversal->x] = true;
			else{
				printf("%s\n", "  there are duplicates");
				return;
			}
			traversal = traversal->next;				
		}while(traversal != NULL);
		printf("%s\n", "there are no duplicates");
	}			
}

int main()
{
	List list;

	list.AddNode(1);
	list.AddNode(2);
	list.AddNode(3);	
	list.AddNode(4);
	list.AddNode(1);
	list.PrintList();
	list.RemoveDuplicates();
	
}

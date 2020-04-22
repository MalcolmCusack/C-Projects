#include <stdio.h>
#include "student.h"

// This file implments selection sort

void SortInsert(Node_t**, Node_t*);

void SortGrades(Node_t** head) {
	Node_t* sorted = NULL;	 // creates a new linked list called sorted

	Node_t* cur = *head;	// creates a node tracker then loops though the list	
	while (cur != NULL) {
		
		Node_t* next = cur->next; //moves to the next node
		SortInsert(&sorted, cur);  // implements the slection sort

		cur = next;
	}

	*head = sorted;
	return;
}	

// moves each node from the old list to the new sorted list in the right order
// from highest to lowest grade
void SortInsert(Node_t** head, Node_t* new_node) {
	
	Node_t* cur;

	// makes a new node at the head
	if (*head == NULL || (*head)->stu->grade <  new_node->stu->grade) {
		
		new_node->next = *head;
		*head = new_node;
	// sorting the list	
	} else {
		cur = *head;
		while (cur->next != NULL && cur->next->stu->grade > new_node->stu->grade) {
			
			cur = cur->next;
		}
		new_node->next = cur->next;
		cur->next = new_node;
	}
	return;
}

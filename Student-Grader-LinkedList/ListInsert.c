#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void ListInsert(Node_t** head, Student_t* stu) {

    Node_t* new_node = malloc(sizeof(Node_t));	// Create memory for the nodes
    new_node->stu = stu;	// insert student into the node
    new_node->next = NULL;	

    Node_t* old_head = *head;	// move the head of the list
    *head = new_node;

    new_node->next = old_head;

    return;
}


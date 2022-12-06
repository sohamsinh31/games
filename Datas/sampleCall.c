//
// Created by soham on 6/12/22.
//

#include <Python.h>
#include "stdio.h"
#include <stdlib.h>

//Call for data for on internet.
struct data
{
    int data;
    char *name;
    struct data *next;
    int (*func)(int x, int y);
};

int *max(int x,int y){
    printf("\n%d and %d\n",x,y);
}

void addLast(struct data **head, int val,char* name)
{
    //create a new data
    struct data *newData = malloc(sizeof(struct data));
    newData->data = val;
    newData->name= name;
    newData->next = NULL;
    newData->func = max(10,20);

    //if head is NULL, it is an empty list
    if(*head == NULL)
        *head = newData;
        //Otherwise, find the last data and add the newData
    else
    {
        struct data *lastData = *head;

        //last data's next address will be NULL.
        while(lastData->next != NULL)
        {
            lastData = lastData->next;
        }

        //add the newData at the end of the linked list
        lastData->next = newData;
    }

}

void printList(struct data *head)
{
    struct data *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
        printf("%s->", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

int call()
{
    struct data *head = NULL;

    addLast(&head, 10, (char *) "soham");

    printList(head);

    return 0;
}



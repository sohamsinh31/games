//
// Created by soham on 3/12/22.
//
//#include <Python.h>
//#include "stdio.h"
//#include "headers/snake.h"
//#include<stdlib.h>
//
//struct data
//{
//    int data;
//    char *name;
//    struct data *next;
//};
//
//
//void addLast(struct data **head, int val,char* name)
//{
//    //create a new data
//    struct data *newData = malloc(sizeof(struct data));
//    newData->data = val;
//    newData->name= name;
//    newData->next = NULL;
//
//    //if head is NULL, it is an empty list
//    if(*head == NULL)
//        *head = newData;
//        //Otherwise, find the last data and add the newData
//    else
//    {
//        struct data *lastData = *head;
//
//        //last data's next address will be NULL.
//        while(lastData->next != NULL)
//        {
//            lastData = lastData->next;
//        }
//
//        //add the newData at the end of the linked list
//        lastData->next = newData;
//    }
//
//}
//
//void printList(struct data *head)
//{
//    struct data *temp = head;
//
//    //iterate the entire linked list and print the data
//    while(temp != NULL)
//    {
//        printf("%s->", temp->name);
//        temp = temp->next;
//    }
//    printf("NULL\n");
//}
//
//int main()
//{
//    struct data *head = NULL;
//
//    addLast(&head, 10, (char *) "soham");
//    addLast(&head,20,(char*) "jatin");
//    addLast(&head,30,(char*) "hii");
//
//    printList(head);
//
//    return 0;
//}
//
//

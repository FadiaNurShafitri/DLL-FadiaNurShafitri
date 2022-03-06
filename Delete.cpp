#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void deleteFirst(node **head)
{
    node *temp = *head;
    (*head) = temp->next;
    temp->next = NULL;
    (*head)->prev = NULL;
}

void deleteLast(node **head)
{
    node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    temp->prev = NULL;
}

void deleteAfter(node *prevNode)
{
    node *temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    prevNode->next->prev = prevNode;
    temp->next = NULL;
    temp->prev = NULL;
}

void deleteBefore(node *nextNode)
{
	node *temp = nextNode->prev;
    nextNode->prev = nextNode->prev->prev;
    nextNode->prev->next = nextNode;
    temp->next = NULL;
    temp->prev = NULL;
}

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void createList(node **head)
{
    node *first = new node();
    node *second = new node();
    node *third = new node();
    node *forth = new node();
    node *fifth = new node();
    node *sixth = new node();
    node *seventh = new node();
    node *mid = new node();
	node *last = new node();
    
    first->data = 11;
    first->next = second;
    first->next->next = third;
    first->prev = NULL;
    first->next->next->next = mid;
    mid->next = fifth;
    mid->next->next = sixth;
    mid->next->next->next = last;
    mid->prev = third;
    
    second->data = 12;
    third->data = 13;
    mid->data = 14;
    fifth->data = 17;
    sixth->data = 19;
    last->data = 25;
    last->prev = sixth;
    last->next = NULL;

    (*head) = first;
    printList(first);
}

void searchNode(node **head, int id)
{
    int currentID = 1;
    node *temp = *head;
    while (temp->next != 0 && currentID != id)
    {
        temp = temp->next;
        currentID++;
    }
    cout << temp->data << " ditemukan di baris " << currentID;
}

int main()
{
    node *head = NULL;
    createList(&head);
    cout << "Deletion  : ";
    deleteFirst(&head);
    deleteLast(&head);
    deleteAfter(head->next);
    printList(head);
    searchNode(&head, 2);
}

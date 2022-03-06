#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

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
    node *mid = new node();
    node *last = new node();

    first->data = 12;
    first->prev = NULL;
    first->next = mid;
    mid->data = 20;
    mid->prev = first;
    mid->next = last;
    last->data = 35;
    last->prev = mid;
    last->next = NULL;

    (*head) = first;
    printList(first);
}

void insertFirst(node **head, int temp)
{
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = (*head);
    newNode->prev = NULL;
    (*head) = newNode;
}

void insertBefore(node **head, node *nextNode, int temp)
{
    node *current = *head;
    while (current->data != nextNode->data)
        current = current->next;
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;
    nextNode->prev->next = newNode;
    nextNode->prev = newNode;
}

void insertAfter(node **head, node *prevNode, int temp)
{
    node *first = *head;
    if (prevNode == NULL) {
    	insertFirst(&first, temp);
    	return;
	}
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
}

void insertLast(node **head, int temp)
{
    node *newNode = new node();
    node *last = *head;
    newNode->data = temp;
    newNode->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
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
    cout << "Insertion : ";
    insertFirst(&head, 8);
    insertAfter(&head, head->next->next, 24);
    insertBefore(&head, head->next->next, 15);
    insertLast(&head, 40);
    printList(head);
    searchNode(&head, 2);
}

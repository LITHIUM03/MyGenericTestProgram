#ifndef FC40982D_8C38_4DEC_9C5C_B6D85190AD1B
#define FC40982D_8C38_4DEC_9C5C_B6D85190AD1B

#include <stdbool.h>

typedef struct LinkedListNode LinkedListNode;
struct LinkedListNode
{
    void *element;
    LinkedListNode *nextNode;

};

typedef struct LinkedList LinkedList;
struct LinkedList
{
    int size;
    LinkedListNode *frontNode;
    LinkedListNode *backNode;

    void (*PrintElemFunc)(void *);
    void (*DestroyElemFunc)(void *);
    void *(*CopyElemFunc)(void *);
    bool (*CompareElemFunc)(void *, void *);
};

LinkedList *CreateEmptyList();
LinkedList *DeepCopyList(LinkedList *);
void DestroyList(LinkedList *);

void SetPrintElemFunc(LinkedList *, void (*)(void *));
void SetDestroyElemFunc(LinkedList *, void (*)(void *));
void SetCopyElemFunc(LinkedList *, void (*)(void *));
void SetCompareElemFunc(LinkedList *, void (*)(void *, void *));

bool IsListInitialized(LinkedList *);

void PrintList(LinkedList *);
void PrintListFront(LinkedList *);
void PrintListBack(LinkedList *);

LinkedListNode *FindElement(LinkedList *, void *); // returns the first node with with value supplied

bool InsertFront(LinkedList *, void *);
bool InsertBack(LinkedList *, void *);
bool InsertAfter(LinkedList *, LinkedListNode *, void *);

#endif /* FC40982D_8C38_4DEC_9C5C_B6D85190AD1B */
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

LinkedListNode *FindElement(void *); // returns the first node with with value supplied

void InsertFront(LinkedList *, void *);
void InsertBack(LinkedList *, void *);
void InsertAfter(LinkedList *, LinkedListNode *, void *);
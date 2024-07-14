#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList *CreateEmptyList()
{
    LinkedList *result = malloc(sizeof(LinkedList));
    if (NULL == result)
    {
        return NULL;
    }
    result->backNode = NULL;
    result->frontNode = NULL;
    result->CompareElemFunc = NULL;
    result->CopyElemFunc = NULL;
    result->DestroyElemFunc = NULL;
    result->PrintElemFunc = NULL;
    result->size = 0;
    return result;
}

LinkedList *DeepCopyList(LinkedList *src)
{
    if (NULL == src)
        return NULL;
    LinkedList *result = CreateEmptyList();
    if (NULL == result)
    {
        return NULL;
    }
    result->CompareElemFunc = src->CompareElemFunc;
    result->CopyElemFunc = src->CopyElemFunc;
    result->DestroyElemFunc = src->DestroyElemFunc;
    result->PrintElemFunc = src->PrintElemFunc;

    LinkedListNode *currentNode = src->frontNode;
    while (NULL != currentNode)
    {
        bool insertionRes = InsertBack(result,currentNode->element);
        if(!insertionRes)
        {
            DestroyList(result);
            return NULL;
        }
    }
    return result;
}

void DestroyList(LinkedList *list)
{
    if (NULL == list)
    {
        return;
    }
    LinkedListNode *currentNode = list->frontNode;
    while (NULL != currentNode)
    {
        LinkedListNode *nextNode = currentNode->nextNode;
        list->DestroyElemFunc(currentNode->element);
        currentNode->element = NULL;
        free(currentNode);
        currentNode = nextNode;
    }
    list->backNode = NULL;
    list->frontNode = NULL;
    list->CompareElemFunc = NULL;
    list->CopyElemFunc = NULL;
    list->DestroyElemFunc = NULL;
    list->PrintElemFunc = NULL;
    list->size = 0;
    free(list);
}

void SetPrintElemFunc(LinkedList *list, void (*func)(void *))
{
    if (NULL == list)
        return;
    list->PrintElemFunc = func;
}

void SetDestroyElemFunc(LinkedList *list, void (*func)(void *))
{
    if (NULL == list)
        return;
    list->DestroyElemFunc = func;
}

void SetCopyElemFunc(LinkedList *list, void* (*func)(void *))
{
    if (NULL == list)
        return;
    list->CopyElemFunc = func;
}

void SetCompareElemFunc(LinkedList *list, bool (*func)(void *, void *))
{
    if (NULL == list)
        return;
    list->CompareElemFunc = func;
}

bool IsListInitialized(LinkedList *list)
{
    return (NULL != list &&
            NULL != list->CompareElemFunc &&
            NULL != list->CopyElemFunc &&
            NULL != list->DestroyElemFunc &&
            NULL != list->PrintElemFunc);
}

void PrintList(LinkedList *list)
{
    printf("{ ");
    if (NULL == list)
    {
        printf("}");
        return;
    }
    LinkedListNode *head = list->frontNode;
    while (NULL != head)
    {
        list->PrintElemFunc(head->element);
        if (NULL != head->nextNode)
        {
            printf(", ");
        }
        head = head->nextNode;
    }
    printf("}");
    return;
}

void PrintListFront(LinkedList *list)
{
    if (NULL == list)
    {
        return;
    }
    if (NULL != list->frontNode)
    {
        list->PrintElemFunc(list->frontNode->element);
    }
    return;
}

void PrintListBack(LinkedList *list)
{
    if (NULL == list)
    {
        return;
    }
    if (NULL != list->backNode)
    {
        list->PrintElemFunc(list->backNode->element);
    }
    return;
}

LinkedListNode *FindElement(LinkedList *list, void *elem)
{
    if (NULL == list)
    {
        return NULL;
    }

    if (NULL == list->frontNode)
    {
        return NULL;
    }

    LinkedListNode *currentNode = list->frontNode;
    while (NULL != currentNode)
    {
        if (list->CompareElemFunc(currentNode->element, elem))
        {
            return currentNode;
        }
        currentNode = currentNode->nextNode;
    }
    return NULL;
}

bool InsertFront(LinkedList *list, void *elem)
{
    if (NULL == list)
    {
        return false;
    }
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (NULL == node)
        return false;
    void *elemCpy = list->CopyElemFunc(elem);
    if (NULL == elemCpy)
    {
        free(node);
        return false;
    }
    node->element = elemCpy;
    node->nextNode = NULL;
    LinkedListNode *previousHead = list->frontNode;
    LinkedListNode *previousBack = list->backNode;

    list->frontNode = node;
    node->nextNode = previousHead;

    if (0 == list->size)
    {
        list->backNode = node;
    }
    list->size += 1;
    return true;
}

bool InsertBack(LinkedList *list, void *elem)
{
    if (NULL == list)
    {
        return false;
    }
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (NULL == node)
        return false;
    void *elemCpy = list->CopyElemFunc(elem);
    if (NULL == elemCpy)
    {
        free(node);
        return false;
    }
    node->element = elemCpy;
    node->nextNode = NULL;

    LinkedListNode *previousHead = list->frontNode;
    LinkedListNode *previousBack = list->backNode;

    list->backNode = node;
    if (NULL != previousBack)
        previousBack->nextNode = node;

    if (0 == list->size)
    {
        list->frontNode = node;
    }
    list->size += 1;
    return true;
}

bool InsertAfter(LinkedList *list, LinkedListNode *preceedigElem, void *elem)
{
    if (NULL == list || NULL == preceedigElem)
    {
        return false;
    }
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (NULL == node)
        return false;
    void *elemCpy = list->CopyElemFunc(elem);
    if (NULL == elemCpy)
    {
        free(node);
        return false;
    }
    node->element = elemCpy;

    node->nextNode = preceedigElem->nextNode;
    preceedigElem->nextNode = node;
    if (NULL == node->nextNode)
    {
        list->backNode = node;
    }
    list->size += 1;
    return true;
}
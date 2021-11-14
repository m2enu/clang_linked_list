/**
 * @file    singly_linked_list.c
 * @brief   Implementation of Singly Linked List
 * @author  m2enu
 * @par     License
 * https://github.com/m2enu/clang_linked_list/blob/main/LICENSE
 */
#include "singly_linked_list.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/** Allocate Singly Linked List Class into heap
 */
static inline SinglyLinkedListClass* LinkedListAlloc(void);

/** Purge allocated linked list
 */
static inline void LinkedListFree(SinglyLinkedListClass* pThis);

static inline SinglyLinkedListClass* LinkedListAlloc(void)
{
    return malloc(sizeof(SinglyLinkedListClass));
}

static inline void LinkedListFree(SinglyLinkedListClass* pThis)
{
    if (pThis != NULL)
    {
        free(pThis);
    }
}

SinglyLinkedListClass* SinglyLinkedListCreate(void)
{
    SinglyLinkedListClass* pRet = LinkedListAlloc();
    if (pRet == NULL)
    {
        return NULL;
    }
    return pRet;
}

LinkedListError SinglyLinkedListAdd(
    SinglyLinkedListClass*  pThis,
    LinkedListItemType      pItemToAdd)
{
    if ((pThis == NULL) || (pItemToAdd == NULL))
    {
        return LINKED_LIST_ERROR_PARAMETER;
    }

    /* Allocate new linked list */
    SinglyLinkedListClass* pListToAdd = SinglyLinkedListCreate();
    if (pListToAdd == NULL)
    {
        return LINKED_LIST_ERROR_NO_MEMORY;
    }
    pListToAdd->pItem = pItemToAdd;

    /* Search the tail of linked list */
    SinglyLinkedListClass* p = pThis;
    while (p->pNext != NULL)
    {
        p = p->pNext;
    }

    /* Join the item at the tail of linked list */
    p->pNext = pListToAdd;

    return LINKED_LIST_ERROR_NONE;
}

LinkedListError SinglyLinkedListRemove(
    SinglyLinkedListClass*  pThis,
    LinkedListItemType      pItemToRemove)
{
    if ((pThis == NULL) || (pItemToRemove == NULL))
    {
        return LINKED_LIST_ERROR_PARAMETER;
    }

    /* Search specified data from the list */
    LinkedListError ret = LINKED_LIST_ERROR_NOT_FOUND;
    SinglyLinkedListClass* pCurr = pThis->pNext;
    SinglyLinkedListClass* pPrev = pThis;
    while (pCurr!= NULL)
    {
        if (pCurr->pItem == pItemToRemove)
        {
            ret = LINKED_LIST_ERROR_NONE;
            pPrev->pNext = pCurr->pNext;
            LinkedListFree(pCurr);
            pCurr = pPrev->pNext;
        }
        else
        {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }
    }

    return ret;
}


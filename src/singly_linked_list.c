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

#define ALLOC(x)            malloc(x)   /**< Macro for memory allocation */
#define FREE(x)             free(x)     /**< Macro for free */

#if defined(NDEBUG)
#define ASSERT(x)
#else
#include <assert.h>
#define ASSERT(x)           assert(x)
#endif

SinglyLinkedListClass* SinglyLinkedListCreate(void)
{
    SinglyLinkedListClass* pRet = ALLOC(sizeof(SinglyLinkedListClass));
    if (pRet == NULL)
    {
        return NULL;
    }

    /* The 1st item of SinglyLinkedListClass.pItem is dummy. */
    pRet->pItem = ALLOC(sizeof(SinglyLinkedListItem));
    if (pRet->pItem == NULL)
    {
        return NULL;
    }

    pRet->NumberOfItems = 0u;
    return pRet;
}

LinkedListError SinglyLinkedListAdd(SinglyLinkedListClass* pThis, void* pValueToAdd)
{
    if ((pThis == NULL) || (pValueToAdd == NULL))
    {
        return LINKED_LIST_ERROR_PARAMETER;
    }

    /* Allocate new linked list */
    SinglyLinkedListItem* pListToAdd = ALLOC(sizeof(SinglyLinkedListItem));
    if (pListToAdd == NULL)
    {
        return LINKED_LIST_ERROR_NO_MEMORY;
    }
    pListToAdd->pNext  = NULL;
    pListToAdd->pValue = pValueToAdd;

    /* Search the tail of linked list */
    SinglyLinkedListItem* pItem = pThis->pItem;
    while (pItem->pNext != NULL)
    {
        pItem = pItem->pNext;
    }

    /* Join the item at the tail of linked list */
    pItem->pNext = pListToAdd;
    pThis->NumberOfItems++;

    return LINKED_LIST_ERROR_NONE;
}

LinkedListError SinglyLinkedListRemove(SinglyLinkedListClass* pThis, void* pValueToRemove)
{
    if ((pThis == NULL) || (pValueToRemove == NULL))
    {
        return LINKED_LIST_ERROR_PARAMETER;
    }

    /* Search specified data from the list */
    LinkedListError ret = LINKED_LIST_ERROR_NOT_FOUND;
    SinglyLinkedListItem* pCurr = pThis->pItem->pNext;
    SinglyLinkedListItem* pPrev = pThis->pItem;
    while (pCurr!= NULL)
    {
        if (pCurr->pValue == pValueToRemove)
        {
            ASSERT(pThis->NumberOfItems > 0u);
            ret = LINKED_LIST_ERROR_NONE;
            pPrev->pNext = pCurr->pNext;
            FREE(pCurr);
            pCurr = pPrev->pNext;
            pThis->NumberOfItems--;
        }
        else
        {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }
    }

    return ret;
}

SinglyLinkedListItem* SinglyLinkedListHead(const SinglyLinkedListClass* pThis)
{
    if (pThis == NULL)
    {
        return NULL;
    }
    return pThis->pItem->pNext;
}

SinglyLinkedListItem* SinglyLinkedListNext(const SinglyLinkedListItem* pItem)
{
    if (pItem == NULL)
    {
        return NULL;
    }
    return pItem->pNext;
}

void* SinglyLinkedListValue(const SinglyLinkedListItem* pItem)
{
    if (pItem == NULL)
    {
        return NULL;
    }
    return pItem->pValue;
}

uint32_t SinglyLinkedListNumberOfItems(const SinglyLinkedListClass* pThis)
{
    return pThis->NumberOfItems;
}

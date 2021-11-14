/**
 * @file    singly_linked_list.h
 * @brief   Implementation of Singly Linked List
 * @author  m2enu
 * @par     License
 * https://github.com/m2enu/clang_linked_list/blob/main/LICENSE
 */
#ifndef SINGLY_LINKED_LIST_H_INCLUDE
#define SINGLY_LINKED_LIST_H_INCLUDE

#include "linked_list.h"
#include <stdint.h>

/** Item of the Singly Linked List
 */
typedef struct SinglyLinkedListItem
{
    void*                           pValue; /**< Pointer to the value */
    struct SinglyLinkedListItem*    pNext;  /**< Pointer to next list item */
} SinglyLinkedListItem;


/** Class of Singly Linked List
 */
typedef struct SinglyLinkedListClass
{
    struct SinglyLinkedListItem*    pItem;          /**< Pointer to the list */
    volatile uint32_t               NumberOfItems;  /**< Number of linked list item */
} SinglyLinkedListClass;

/** Create the instance of Singly Linkded List
 * @return  Pointer to created Linked List
 * @retval  NULL    Creation Failed
 */
SinglyLinkedListClass* SinglyLinkedListCreate(void);

/** Add data to Singly Linked List
 * @param   pThis           Pointer to the Singly Linked List class
 * @param   pValueToAdd     Pointer to the value that will be added to the list
 * @return  Error code of Linked List APIs
 * @retval  LINKED_LIST_ERROR_NONE          Success
 * @retval  LINKED_LIST_ERROR_PARAMETER     One or more specified pointer is NULL
 * @retval  LINKED_LIST_ERROR_NO_MEMORY     No available memory
 */
LinkedListError SinglyLinkedListAdd(SinglyLinkedListClass* pThis, void* pItemToAdd);

/** Remove specified data from Singly Linked List
 * @param   pThis           Pointer to the Singly Linked List class
 * @param   pValueToRemove  Pointer to the value that will be be removed from the list
 * @return  Error code of Linked List APIs
 * @retval  LINKED_LIST_ERROR_NONE          Success
 * @retval  LINKED_LIST_ERROR_PARAMETER     One or more specified pointer is NULL
 * @retval  LINKED_LIST_ERROR_NOT_FOUND     No value found in the list
 */
LinkedListError SinglyLinkedListRemove(SinglyLinkedListClass* pThis, void* pValueToRemove);

/** Acquire pointer to the top of linked list
 * @param   pThis   Pointer to the Singly Linked List class
 * @return  Pointer to the top of linked list
 * @retval  NULL    No available item
 */
SinglyLinkedListItem* SinglyLinkedListHead(const SinglyLinkedListClass* pThis);

/** Acquire pointer to the next item of linked list
 * @param   pItem   Pointer to the linked list item
 * @return  Pointer to the next item of linked list
 * @retval  NULL    No next item
 */
SinglyLinkedListItem* SinglyLinkedListNext(const SinglyLinkedListItem* pItem);

/** Acquire pointer to the value of specified item
 * @param   pItem   Pointer to the linked list item
 * @return  Pointer to the value of specified item
 * @retval  NULL    pItem is invalid
 */
void* SinglyLinkedListValue(const SinglyLinkedListItem* pItem);

/** Acquire the number of items in the list
 * @param   pThis   Pointer to the Singly Linked List class
 * @return  Number of items in the list
 */
uint32_t SinglyLinkedListNumberOfItems(const SinglyLinkedListClass* pThis);

#endif

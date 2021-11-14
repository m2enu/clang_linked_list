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

/** Class of Singly Linked List
 */
typedef struct SinglyLinkedListClass
{
    struct SinglyLinkedListClass*   pNext;  /**< Pointer to next linked list */
    LinkedListItemType              pItem;  /**< Pointer to the data */
} SinglyLinkedListClass;

/** Create the instance of Singly Linkded List
 * @return  Pointer to created Linked List
 * @retval  NULL    Creation Failed
 */
SinglyLinkedListClass* SinglyLinkedListCreate(void);

/** Add data to Singly Linked List
 * @param   pThis       Pointer to the Singly Linked List class
 * @param   pItemToAdd  Pointer to be add to the linked list
 * @return  Error code of Linked List APIs
 * @retval  LINKED_LIST_ERROR_NONE          Success
 * @retval  LINKED_LIST_ERROR_PARAMETER     One or more specified pointer is NULL
 * @retval  LINKED_LIST_ERROR_NO_MEMORY     No available memory
 */
LinkedListError SinglyLinkedListAdd(
    SinglyLinkedListClass*  pThis,
    LinkedListItemType      pItemToAdd);

/** Remove specified data from Singly Linked List
 * @param   pThis           Pointer to the Singly Linked List class
 * @param   pItemToRemove   Pointer to be removed from the linked list
 * @return  Error code of Linked List APIs
 * @retval  LINKED_LIST_ERROR_NONE          Success
 * @retval  LINKED_LIST_ERROR_PARAMETER     One or more specified pointer is NULL
 */
LinkedListError SinglyLinkedListRemove(
    SinglyLinkedListClass*  pThis,
    LinkedListItemType      pItemToRemove);

#endif

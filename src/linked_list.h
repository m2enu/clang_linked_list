/**
 * @file    linked_list.h
 * @brief   Parameter definition for Linked List
 * @author  m2enu
 * @par     License
 * https://github.com/m2enu/clang_linked_list/blob/main/LICENSE
 */
#ifndef LINKED_LIST_H_INCLUDE
#define LINKED_LIST_H_INCLUDE

/** The data type of linked list */
typedef void*   LinkedListItemType;

/** Error code for Linked List APIs
 */
typedef enum LinkedListError
{
    LINKED_LIST_ERROR_NONE          =  0,   /**< No error */
    LINKED_LIST_ERROR_PARAMETER     = -1,   /**< Invalid parameter */
    LINKED_LIST_ERROR_NO_MEMORY     = -2,   /**< No available memory */
    LINKED_LIST_ERROR_NOT_FOUND     = -3,   /**< Item not found */
} LinkedListError;

#endif

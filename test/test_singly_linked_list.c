/**
 * @file    test_singly_linked_list.c
 * @brief   Unit test for Singly Linked List
 * @author  m2enu
 * @par     License
 * https://github.com/m2enu/clang_linked_list/blob/main/LICENSE
 */
#include "test_singly_linked_list.h"
#include "singly_linked_list.h"
#include "unity.h"
#include <stdint.h>
#include <stddef.h>

void TestSinglyLinkedList(void)
{
    /* Prepare test target */
    SinglyLinkedListClass* pList = SinglyLinkedListCreate();
    TEST_ASSERT_NOT_EQUAL(NULL, pList);
    TEST_ASSERT_EQUAL(0u, pList->NumberOfItems);

    LinkedListError err;

    /* Add items */
    int32_t d0 = 100;
    err = SinglyLinkedListAdd(pList, &d0);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NONE, err);
    TEST_ASSERT_EQUAL(1u, pList->NumberOfItems);
    TEST_ASSERT_EQUAL(100, *(int32_t *)(pList->pItem->pNext->pValue));

    int32_t d1 = 200;
    err = SinglyLinkedListAdd(pList, &d1);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NONE, err);
    TEST_ASSERT_EQUAL(2u, pList->NumberOfItems);
    TEST_ASSERT_EQUAL(200, *(int32_t *)(pList->pItem->pNext->pNext->pValue));

    /* Remove existing item */
    err = SinglyLinkedListRemove(pList, &d0);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NONE, err);
    TEST_ASSERT_EQUAL(1u, pList->NumberOfItems);
    TEST_ASSERT_EQUAL(NULL, pList->pItem->pNext->pNext);
    TEST_ASSERT_EQUAL(200, *(int32_t *)(pList->pItem->pNext->pValue));

    /* Remove not existing item */
    err = SinglyLinkedListRemove(pList, &d0);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NOT_FOUND, err);
    TEST_ASSERT_EQUAL(1u, pList->NumberOfItems);

    /* Remove existing item */
    err = SinglyLinkedListRemove(pList, &d1);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NONE, err);
    TEST_ASSERT_EQUAL(0u, pList->NumberOfItems);
    TEST_ASSERT_EQUAL(NULL, pList->pItem->pNext);
}


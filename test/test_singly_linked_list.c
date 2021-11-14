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
    TEST_ASSERT_EQUAL(0u, SinglyLinkedListNumberOfItems(pList));

    LinkedListError err;

    /* Add items */
    int32_t d0 = 100;
    err = SinglyLinkedListAdd(pList, &d0);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NONE, err);
    TEST_ASSERT_EQUAL(1u, SinglyLinkedListNumberOfItems(pList));
    const SinglyLinkedListItem* pItem0_0 = SinglyLinkedListHead(pList);
    TEST_ASSERT_EQUAL(100, *(int32_t *)SinglyLinkedListValue(pItem0_0));

    /* Add items */
    int32_t d1 = 200;
    err = SinglyLinkedListAdd(pList, &d1);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NONE, err);
    TEST_ASSERT_EQUAL(2u, SinglyLinkedListNumberOfItems(pList));
    const SinglyLinkedListItem* pItem1_0 = SinglyLinkedListNext(pItem0_0);
    TEST_ASSERT_EQUAL(200, *(int32_t *)SinglyLinkedListValue(pItem1_0));

    /* Remove existing item */
    err = SinglyLinkedListRemove(pList, &d0);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NONE, err);
    TEST_ASSERT_EQUAL(1u, SinglyLinkedListNumberOfItems(pList));
    const SinglyLinkedListItem* pItem0_1 = SinglyLinkedListHead(pList);
    TEST_ASSERT_EQUAL(200, *(int32_t *)SinglyLinkedListValue(pItem0_1));
    TEST_ASSERT_EQUAL(NULL, SinglyLinkedListNext(pItem0_1));

    /* Remove not existing item */
    err = SinglyLinkedListRemove(pList, &d0);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NOT_FOUND, err);
    TEST_ASSERT_EQUAL(1u, SinglyLinkedListNumberOfItems(pList));

    /* Remove existing item */
    err = SinglyLinkedListRemove(pList, &d1);
    TEST_ASSERT_EQUAL(LINKED_LIST_ERROR_NONE, err);
    TEST_ASSERT_EQUAL(0u, SinglyLinkedListNumberOfItems(pList));
    TEST_ASSERT_EQUAL(NULL, SinglyLinkedListHead(pList));
}


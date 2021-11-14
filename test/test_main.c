/**
 * @file    test_main.c
 * @brief   Unit test main
 * @author  m2enu
 * @par     License
 * https://github.com/m2enu/clang_linked_list/blob/main/LICENSE
 */
#include "unity.h"
#include "test_singly_linked_list.h"

/** Unused indicator to suppress compiler warning
 */
#define UNUSED_PARAMETER(x)         ((void)x)

/** Unit test setup
 */
void setUp(void)
{
}

/** Unit test teardown
 */
void tearDown(void)
{
}

/** Unit test main
 */
int main(int argc, char **argv)
{
    UNUSED_PARAMETER(argc);
    UNUSED_PARAMETER(argv);

    UNITY_BEGIN();
    RUN_TEST(TestSinglyLinkedList);
    return UNITY_END();
}

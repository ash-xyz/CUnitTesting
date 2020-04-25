#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "avg_and_max.h"

void runTests();

/*Tests the average() function*/
void average_test_normal(); //Tests basic inputs for average
void average_test_same(); //Tests when all values are the same
void average_test_empty();//Tests there are no values in the array
void average_test_single();//Tests when there is only a single value in the array

/*Tests the max() function*/

int main() {
    runTests();
    return 0;
}

void runTests() {
    CU_initialize_registry();
    CU_pSuite average_suite = CU_add_suite("avg_suite", 0, 0);

    CU_ADD_TEST(average_suite, average_test_normal);
    CU_ADD_TEST(average_suite, average_test_same);
    CU_ADD_TEST(average_suite, average_test_empty);
    CU_ADD_TEST(average_suite, average_test_single);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}

void average_test_normal() {
    double test1[] = {1.1, 2.2, 3.3, 4.4};
    CU_ASSERT_DOUBLE_EQUAL(average(test1, 4), 2.75, 0.0001);
    double test2[] = {5.6, 1.2, 4.3};
    CU_ASSERT_DOUBLE_EQUAL(average(test2, 3), 3.7, 0.0001);
    double test3[] = {1, 2, 3, 4, 5, 6};
    CU_ASSERT_DOUBLE_EQUAL(average(test3, 6), 3.5, 0.0001);
}

void average_test_same() {
    double test1[10];
    for (int i = 0; i < 10; i++) {
        test1[i] = 1.618;
    }
    CU_ASSERT_DOUBLE_EQUAL(average(test1, 10), 1.618, 0.0001);
    double test2[15];
    for (int i = 0; i < 15; i++) {
        test2[i] = 3.1415;
    }
    CU_ASSERT_DOUBLE_EQUAL(average(test2, 15), 3.1415, 0.0001);
}

void average_test_empty() {
    double test1[] = {};
    CU_ASSERT(isnan(average(test1, 0)));
}

void average_test_single() {
    double test1[] = {4};
    CU_ASSERT_DOUBLE_EQUAL(average(test1, 1), 4, 0.0001);
    double test2[] = {-0.404};
    CU_ASSERT_DOUBLE_EQUAL(average(test2, 1), -0.404, 0001)
}
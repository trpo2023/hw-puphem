#include "../src/libgeometry/check.h"
#include "../thirdparty/ctest.h"

#include <stdio.h>

CTEST(INPUT_CHECK, WORD_1)
{
    char* a = "circle(4 2, 8)";
    char* b = "circle";
    int error = 0;

    double expec = 0;
    check_word(a, b, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, WORD_2)
{
    char* a = "circle(4 2, 8)";
    char* b = "circle";
    int error = 0;

    int expec = 0;
    check_word(a, b, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, OPEN_BRACKET_INDEX_1)
{
    // correct input check
    char* a = "circle(4 2, 8)";
    char* b = "circle";
    int error = 0;

    int expec = 0;
    check_word(a, b, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, OPEN_BRACKET_INDEX_2)
{
    // correct input check
    char* a = "circle4 2, 8)";
    char* b = "circle";
    int error = 0;

    int expec = 1;
    check_word(a, b, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, SEARCH_CLOSE_BRACKET_1)
{
    char* a = "circle(4 2, 8)";
    int length = 14;

    int expec = 13;
    int real = search_close_bracket_index(a, &length);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, SEARCH_CLOSE_BRACKET_2)
{
    char* a = "circle(4 2, 8";
    int length = 13;

    int expec = 0;
    int real = search_close_bracket_index(a, &length);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, FIRST_NUMBER_1)
{
    char* a = "circle(4 2, 8)";
    int open_bracket_index = 6;
    int error = 0;

    int expec = 7;
    int real = check_first_number(a, &open_bracket_index, &error);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, FIRST_NUMBER_2)
{
    char* a = "circle(q 2, 8)";
    int open_bracket_index = 6;
    int error = 0;

    int expec = 1;
    check_first_number(a, &open_bracket_index, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, SECOND_NUMBER_1)
{
    char* a = "circle(4 2, 8)";
    int first_num_elem_index = 7;
    int error = 0;

    int expec = 9;
    int real = check_second_number(a, &first_num_elem_index, &error);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, SECOND_NUMBER_2)
{
    char* a = "circle(4 d, 8)";
    int first_num_elem_index = 7;
    int error = 0;

    int expec = 1;
    check_second_number(a, &first_num_elem_index, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, THIRD_NUMBER_1)
{
    char* a = "circle(4 2, 8)";
    int second_num_elem_index = 9;
    int close_bracket_index = 13;
    int error = 0;

    int expec = 12;
    int real = check_third_number(
            a, &second_num_elem_index, &close_bracket_index, &error);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, THIRD_NUMBER_2)
{
    char* a = "circle(4 2, G)";
    int second_num_elem_index = 9;
    int close_bracket_index = 13;
    int error = 0;

    int expec = 1;
    check_third_number(a, &second_num_elem_index, &close_bracket_index, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, CHECK_CLOSE_BRACKET_1)
{
    char* a = "circle(4 2, 8)";
    int third_num_elem_index = 12;
    int length = 14;
    int error = 0;

    int expec = 13;
    int real = check_close_bracket_index(
            a, &third_num_elem_index, &length, &error);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, CHECK_CLOSE_BRACKET_2)
{
    char* a = "circle(4 2, 8X";
    int third_num_elem_index = 12;
    int length = 14;
    int error = 0;

    int expec = 1;
    check_close_bracket_index(a, &third_num_elem_index, &length, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, UNEXPECTED_TOKENS_1)
{
    char* a = "circle(4 2, 8)";
    int close_bracket_index = 13;
    int length = 14;
    int error = 0;

    int expec = 0;
    int real
            = check_unexpected_tokens(a, &close_bracket_index, &length, &error);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, UNEXPECTED_TOKENS_2)
{
    char* a = "circle(4 2, 8)B";
    int close_bracket_index = 13;
    int length = 15;
    int error = 0;

    int expec = 1;
    check_unexpected_tokens(a, &close_bracket_index, &length, &error);
    int real = error;

    ASSERT_EQUAL(expec, real);
}

CTEST(INTERSECTION, CIRCLES_1)
{
    int figure_amount = 2;

    float x_arr[figure_amount];
    x_arr[0] = 4;
    x_arr[1] = 2;

    float y_arr[figure_amount];
    y_arr[0] = 2;
    y_arr[1] = 2;

    float radius_arr[figure_amount];
    radius_arr[0] = 8;
    radius_arr[1] = 8;

    int expec = 1;
    int real = intersects(x_arr, y_arr, radius_arr, figure_amount);

    ASSERT_EQUAL(expec, real);
}

CTEST(INTERSECTION, CIRCLES_2)
{
    int figure_amount = 3;

    float x_arr[figure_amount];
    x_arr[0] = 4;
    x_arr[1] = 2;
    x_arr[2] = 8;

    float y_arr[figure_amount];
    y_arr[0] = 2;
    y_arr[1] = 2;
    y_arr[2] = 2;

    float radius_arr[figure_amount];
    radius_arr[0] = 8;
    radius_arr[1] = 8;
    radius_arr[2] = 2;

    int expec = 1;
    int real = intersects(x_arr, y_arr, radius_arr, figure_amount);

    ASSERT_EQUAL(expec, real);
}

CTEST(INTERSECTION, CIRCLES_3)
{
    int figure_amount = 2;

    float x_arr[figure_amount];
    x_arr[0] = 4;
    x_arr[1] = 2;

    float y_arr[figure_amount];
    y_arr[0] = 2;
    y_arr[1] = 2;

    float radius_arr[figure_amount];
    radius_arr[0] = 8;
    radius_arr[1] = 21;

    int expec = 0;
    int real = intersects(x_arr, y_arr, radius_arr, figure_amount);

    ASSERT_EQUAL(expec, real);
}

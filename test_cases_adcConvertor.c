#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "main.h"

void test_cases_adcConverter(void)
{
    // Test case to check the input to adc converter and output with single element
    int data[] = {4000, 3000};
    float result[] = {10, 7};
    float output[2];
    convertA2D(data, 2, output);
    assert(memcmp(output,result,2)==0);

    // Test to check the converter and the converter avoids invalid sensor values
    int data1[] = {4000, 3000, 5000};
    float result1[] = {10, 7};
    float output1[2];
    int outCnt = 0;
    outCnt = convertA2D(data1, 2, output1);
    assert(memcmp(output1,result1,2)==0);
    assert(outCnt == 2);

    // Test the valid sample value check function
    assert(checkValidSample(-1) == 0);
    assert(checkValidSample(0) == 1);
    assert(checkValidSample(1000) == 1);
    assert(checkValidSample(4094) == 1);
    assert(checkValidSample(4096) == 0);

    // Test the sample conversion with the round of values
    int data2[] = {4000, 3000};
    float result2[] = {10, 7};
    float output2[2];
    int outCnt2 = 0;
    outCnt2 = convertA2D(data2, 2, output2);
    assert(memcmp(output2,result2,2)==0);
    assert(outCnt2 == 2);

}

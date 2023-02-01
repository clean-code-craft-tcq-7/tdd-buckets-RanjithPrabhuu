#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "main.h"

//function definition to get the data range
void getRange(int* data, int dataCount, char* buff)
{
    char showData[100];
    memset(showData, 0, 100);
    sprintf(showData,"%s\n","Range, Readings");
    
    if((data != NULL) && (dataCnt > 0))
    {
          orderAscending(data,dataCount);
          getRangesAndCount(data, dataCnt, &showData[strlen("Range, Readings") + 1]);
    }   
    strncpy(buff,showData,strlen(showData));

//function definition to get the data range and count
void getRangesAndCount(int* data, int len,char* strVal)
{
    int minIdx = 0, maxIdx = 0;
    char rangeInfo[20];

    while(maxIdx < len)
    {
        maxIdx = isConsecutive(data, minIdx, len);
        if(data[minIdx] != data[maxIdx - 1])
        {
            memset(rangeInfo,0,20);
            sprintf(rangeInfo,"%d-%d, %d\n", data[minIdx], data[maxIdx - 1], (maxIdx - minIdx));
            strncpy(strVal,rangeInfo,strlen(rangeInfo));
            strVal += strlen(rangeInfo);
        }
        minIdx = maxIdx;
    }
}

//function definition to check whether the data is consecutive
int isConsecutive(int* arr, int min, int len)
{
    int i;
    for(i= min + 1; i<len; i++)
    {
        if((arr[i] - (arr[i-1]+1)) > 0)
        {
            return i;
        }
    }
    return i;
}
//function definition to sort the data in ascending
void orderAscending(int* data, int length)
{
    int temp,i,j;
    for(i = 0; i < length; i++)
    {
        for(j = i + 1; j < length; j++)
        {
            if(data[i] > data[j])
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

//main function
int main(void)
{
    char output[100];
    memset(output, 0, 100);

    // Test case to check the count
    int data[]={4,5};
    getRange(data, 2, output);
    assert(strcmp(output,"Range, Readings\n4-5, 2\n") == 0);
    
    // Test case to check in reverse order
    int data1[] = {5,4};
    memset(output, 0, 100);
    getRange(data1, 2, output);
    assert(strcmp(output,"Range, Readings\n4-5, 2\n") == 0);
    
    //Test case with empty array as input
    int data2[2];
    memset(output, 0, 100);
    getRange(data2, 0, output);
    assert(strcmp(output,"Range, Readings\n") == 0);

    //Test case with empty array as input but valid length value
    memset(output, 0, 100);
    getRange(NULL, 2, output);
    assert(strcmp(output,"Range, Readings\n") == 0);

    //Test case with empty array as input and invalid length value
    memset(output, 0, 100);
    getRange(NULL, 0, output);
    assert(strcmp(output,"Range, Readings\n") == 0);

    //Test case with multiple ranges
    int data3[]= {3, 3, 5, 4, 10, 11, 12};
    memset(output, 0, 100);
    getRange(data3, 7, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n10-12, 3\n") == 0);

    //Test case with one range and non range values
    int data4[]= {3, 3, 5, 4, 10, 20};
    memset(output, 0, 100);
    getRange(data4, 6, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n") == 0);
    
    return 0;
}

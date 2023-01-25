#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "main.h"

//function definition to get the data range
void getRange(int* data, int dataCount, char* buff)
{
    char showData[100];
    int countInRange;

    memset(showData, 0, 100);
    orderAscending(data,dataCount);
    countInRange = getCountInRange(data, dataCount, data[0], data[dataCount - 1]);
    sprintf(showData,"%s\n%d-%d, %d\n","Range, Readings",data[0],data[dataCount - 1], countInRange);
    strncpy(buff,showData,strlen(showData));
}

//function definition to find the count which is in range
int getCountInRange(int* data, int cnt, int min, int max)
{
    int i,occurCount = 0;
    for(i=0; i< cnt; i++)
    {
        occurCount += checkRange(data[i], min, max);
    }
    return occurCount;
}

//function definition to the range
int checkRange(int value, int min, int max)
{
    if(value >= min || value <= max)
    {
        return 1;
    }
    return 0;
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
    
    return 0;
}

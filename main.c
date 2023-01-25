#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "main.h"

//function definition to get the data range
void getRange(int* data, int dataCnt, char* buff)
{
    char printData[100];
    int cntInRange;

    memset(printData, 0, 100);
    sortInAscending(data,dataCnt);
    cntInRange = getCountInRange(data, dataCnt, data[0], data[dataCnt - 1]);
    sprintf(printData,"%s\n%d-%d, %d\n",HEADER_CHAR,data[0],data[dataCnt - 1], cntInRange);
    strncpy(buff,printData,strlen(printData));
}

//function definition to find the count which is in range
int getCountInRange(int* data, int cnt, int min, int max)
{
    int i,occurCnt = 0;
    for(i=0; i< cnt; i++)
    {
        occurCnt += checkWithinRange(data[i], min, max);
    }
    return occurCnt;
}

//function definition to the range
int checkWithinRange(int value, int min, int max)
{
    if(value >= min || value <= max)
    {
        return 1;
    }
    return 0;
}

//function definition to sort the data in ascending
void sortInAscending(int* data, int length)
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
    getRangeData(data, 2, output);
    assert(strcmp(output,"Range, Readings\n4-5, 2\n") == 0);
    // Test case to check in reverse order
    int data1[] = {5,4};
    memset(output, 0, 100);
    getRangeData(data1, 2, output);
    assert(strcmp(output,"Range, Readings\n4-5, 2\n") == 0);
    
    return 0;
}

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
    
    if((data != NULL) && (dataCount > 0))
    {
          orderAscending(data,dataCount);
          getRangeCount(data, dataCount, &showData[strlen("Range, Readings") + 1]);
    }   
    strncpy(buff,showData,strlen(showData));
} 

//function definition to get the data range and count
void getRangeCount(int* data, int len,char* strVal)
{
    int minIdx = 0, maxIdx = 0;
    char rangeData[20];

    while(maxIdx < len)
    {
        maxIdx = isSequential(data, minIdx, len);
        if(data[minIdx] != data[maxIdx - 1])
        {
            memset(rangeData,0,20);
            sprintf(rangeData,"%d-%d, %d\n", data[minIdx], data[maxIdx - 1], (maxIdx - minIdx));
            strncpy(strVal,rangeData,strlen(rangeData));
            strVal += strlen(rangeData);
        }
        minIdx = maxIdx;
    }
}

//function definition to check whether the data is consecutive
int isSequential(int* arr, int min, int len)
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

//function definition to convert analog data to digital
int convertA2D(int* data, int len, float* output)
{
    int count = 0, outIdx = 0;
    float tempVal;

    while(count < len)
    {
        if(checkSample(data[count]))
        {
            tempVal =(float)((float)10 * ((float)data[count] / (float)4094));
            output[outIdx] = round(tempVal);
            outIdx++;
        }
        count++;
    }
    return outIdx;
}

//function defintion to check whether sample is valid or not
int checkSample(int value)
{
    if( (value >= 0) && (value <= 4094))
    {
        return 1;
    }

    return 0;
}

//main function
int main(void)
{
    test_cases_rangeProcessing();
    
    return 0;
}

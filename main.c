#include <stdio.h>
#include <string.h>
#include <assert.h>

void getRange(int* data, int dataCnt, char* buff)
{

}

int main(void)
{
    int rangeData[]={4,5};
    char rangeOutput[20];

    getRange(rangeData, 2, rangeOutput);
    assert(strcmp(rangeOutput,"Range, Readings\n4-5, 2\n") == 0);

    return 0;
}

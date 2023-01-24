#include <stdio.h>
#include <string.h>

#include "ccp_finder.h"

int main()
{
    int current_pair[2] = {4,5};
    char ccp_pair_output[100];
    memset(ccp_pair_output, 0, 100);
    findCurrentPairs(current_pair, 2, ccp_pair_output);
    assert(strcmp(ccp_pair_output, "Range, Readings\n4-5, 2\n"));
    return 0;
}

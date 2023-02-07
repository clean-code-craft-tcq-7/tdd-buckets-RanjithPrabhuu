//function declaration to get the range
void getRange(int* data, int dataCnt, char* buff);
//function definition to get the data range and count
void getRangeCount(int* data, int len,char* strVal);
//function definition to check whether the data is consecutive
int isSequential(int* arr, int min, int len);
//function declaration to sort the data in ascending
void orderAscending(int* data, int length);

//extern for the range processing function
extern void test_cases_rangeProcessing(void);

//function declaration to convert analog data to digital
int convertA2D(int* data, int len, float* output);
//function declaration to check whether sample is valid or not
int checkSample(int value);

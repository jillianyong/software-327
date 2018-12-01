#ifndef functions_h
#define functions_h

//function prototypes

void initialize();
bool checkCode(char);
void writeDataToFile(const char *);
void readDataFromFile(const char *);
double findNyanCatValue(double first, double last, double delta);
int factorial(int number);
int fibonacci(int number);
double findSqrtValue(double first, double last, double delta);
double naturalLog(double first, double last, double delta);
int findNextOddValue(int userfirst, int userlast);

#endif

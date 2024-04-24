#include <stdio.h>
void __real_fred(int);
void __real_john(double);

void __wrap_fred(int arg)
{
	__real_fred(arg);
	printf("This is the Fred wrapper\n");

}
void __wrap_john(double arg)
{
	__real_john(arg);
	printf("This is the John wrapper\n");

}


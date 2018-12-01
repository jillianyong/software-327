/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Simple Exception Class containing a message pointer

#ifndef Input_Handling_h
#define Input_Handling_h

class Invalid_Input
{
public:
	Invalid_Input(const char* in_ptr) : msg_ptr(in_ptr) {}
	const char * const msg_ptr;

private:
	Invalid_Input(); //no default construction
};

#endif
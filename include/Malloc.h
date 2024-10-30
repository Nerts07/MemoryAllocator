
#include <iostream>
#include <cstdlib> // Include for std::malloc

#ifndef LINUX
#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#endif

void* Halloc(size_t size);
void FreeHalloc(void* h_ptr);
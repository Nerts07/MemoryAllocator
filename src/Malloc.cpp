// MemoryAllocator.cpp : Defines the entry point for the application.
//

#include "Malloc.h"
#include "assert.h"

using namespace std;
struct Block
{
	bool free;
	size_t size;
	Block* next;
};
Block* head = nullptr;

void* Halloc(size_t size)
{
	Block* curr = head;
	Block* prev = nullptr;

	while (curr && !(curr->free && curr->size >= size))
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr)
	{
		curr->free = false;
	}
	else
	{
		void* mem = (void*)malloc(size + sizeof(Block));
		assert(mem != (void*) - 1);

		curr = (Block*)mem;
		curr->size = size;
		curr->free = false;
		curr->next = nullptr;

		if (prev)
		{
			prev->next = curr;
		}
		else
		{
			head = curr;
		}
	}
	return (void*)(curr + 1);
}

void FreeHalloc(void* h_ptr)
{
	assert(h_ptr);
    Block* block = (Block*)h_ptr - 1;
    block->free = true;
}
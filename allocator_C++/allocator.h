#pragma once

void makeAllocator(size_t maxSize);
char* alloc(size_t size);
void reset();
void delAllocator(void);

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "some_heap.h"

/*
Assignment 5: integer minheap
*/

unsigned long long rand_between(unsigned long long min, unsigned long long max)
{
    unsigned long long range = max - min;
    return min + (rand() % range);
}

void test_heap(void)
{
    heap_t* heap = heap_create(200);
    for (heap_key_t ix = 0; ix < 20; ix++) {
        heap_key_t key = rand_between(0, 1000);
        heap_insert(heap, key, (heap_value_t)(uintptr_t)key);
        heap_print(heap);
    }
    for (int ix = 0; ix < 10; ix++) {
        heap_value_t removed_value = heap_remove_min(heap);
        if (removed_value != NULL) {
            printf(
                "Removed %llu\n", (unsigned long long)(uintptr_t)removed_value);
        } else {
            printf("Heap is empty!\n");
        }
        heap_print(heap);
    }
    heap_free(heap);
}

int main(int argc, char* argv[])
{
    FILE* file = freopen("output.txt", "w", stdout);

    if (file == NULL) {
        perror("Error w file");

        return EXIT_FAILURE;
    }

    srand(time(NULL));

    test_heap();

    fclose(file);
    return EXIT_SUCCESS;
}

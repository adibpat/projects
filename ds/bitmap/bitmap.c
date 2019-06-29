/*
 * bitmap.c
 * 
 * Aditya Patwardhan
 * June 2019
 */
#include <stdio.h>
#include "bitmap.h"

int
mybitmap_set_bit (int id, unsigned char *bitmap, int bit_index)
{
    /* Find the byte */
    int byte = bit_index/2;
    if (bit_index%2) {
        id = id & 0x0f;
        bitmap[byte] = bitmap[byte] | id;
    } else {
        id = id << 4;
        id = id & 0xf0;
        bitmap[byte] = bitmap[byte] | id;
    }
    printf("New value %d index at %d set\n", id, bit_index);
    return (0);
}

int
mybitmap_find_first_free_rev_helper (unsigned char *bitmap, int max_resources)
{
    int i, last = BYTES_REQUIRED(max_resources)-1;
    if (!(max_resources%2) && (!(bitmap[last] & SECOND_HALF_MASK))) {
        return (last*2 + 1);
    }
    if (!(bitmap[last] & FIRST_HALF_MASK)) {
        return (last*2);
    }
    for (i = last-1; i >= 0; i--) {
        if (!(bitmap[i] & SECOND_HALF_MASK)) {
            return (i*2+1);
        } else if (!(bitmap[i] & FIRST_HALF_MASK)) {
            return (i*2);
        }
    }
    return (max_resources+1);
}    

int
mybitmap_find_first_free (unsigned char *bitmap, int max_resources, int reverse)
{
    if (reverse) {
        return (mybitmap_find_first_free_rev_helper(bitmap, max_resources));
    }
    
    int i, last = BYTES_REQUIRED(max_resources)-1;
    for (i = 0; i < last; i++) {
        if (!(bitmap[i] & FIRST_HALF_MASK)) {
            return (i*2);
        } else if (!(bitmap[i] & SECOND_HALF_MASK)) {
            return (i*2 + 1);
        }
    }
    if (!(bitmap[last] & FIRST_HALF_MASK)) {
        return (last*2);
    }
    if (!(max_resources%2) && (!(bitmap[last] & SECOND_HALF_MASK))) {
        return (last*2 + 1);
    }
    return (max_resources+1);
}

int
mybitmap_clear_all (unsigned char *bitmap, int max_resources)
{
    int i;
    for (i = 0; i < BYTES_REQUIRED(max_resources); i++) {
        bitmap[0] = 0;
    }
    return (0);
}

int
mybitmap_clear_bit (unsigned char *bitmap, int bit_index)
{
    int byte = bit_index/2;
    int val;
    if (bit_index%2) {
        val = bitmap[byte] & 0x0f;
        bitmap[byte] = bitmap[byte] & 0xf0;
    } else {
        val = bitmap[byte] & 0xf0;
        val = val >> 4;
        bitmap[byte] = bitmap[byte] & 0x0f;
    }
    printf("Old value %d at index %d freed\n", val, bit_index);
    return (0);
}

int
mybitmap_print (unsigned char *bitmap, int max_resource)
{
    int bytes = max_resource/2;
    int i, val;
    for (i = 0; i < BYTES_REQUIRED(max_resource); i++) {
        val = bitmap[i] & 0xf0;
        val = val >> 4;
        printf("%d ---- %d\n", i*2, val);
        val = bitmap[i] & 0x0f;
        printf("%d ---- %d\n", i*2+1, val);
    }
    return (0);
}

int
mybitmap_get_id_by_position (unsigned char *bitmap, int bit_index)
{
    int byte = bit_index/2;
    int val;
    if (bit_index%2) {
        val = bitmap[byte] & 0x0f;
    } else {
        val = bitmap[byte] & 0xf0;
        val = val >> 4;
    }
    return (val);
}
    

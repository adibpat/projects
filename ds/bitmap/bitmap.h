/********************
 * bitmap.h
 *
 * Aditya Patwardhan
 * June 2019
 ********************/

#ifndef __MYBITMAP_H__
#define __MYBITMAP_H__

#define BITS_PER_RESOURCE (4)
#define BYTE_SIZE         (8)

#define BYTES_REQUIRED(num_resources) ((((num_resources)*(BITS_PER_RESOURCE))+(BYTE_SIZE - 1))/(BYTE_SIZE))

#define FIRST_HALF_MASK (0xf0)
#define SECOND_HALF_MASK (0x0f)

#define BITMAP(name,num_resources)\
    unsigned char name[BYTES_REQUIRED(num_resources)];

/*
 * Set an index in the bitmap as used
 * Set client id in the bitmap for faster searching
 */
int
mybitmap_set_bit(int id, unsigned char *bitmap, int bit_index);

/*
 * Find the first free entry in the bitmap
 */
int
mybitmap_find_first_free(unsigned char *bitmap, int max_resources, int rev);

/*
 * Clear the bitmap
 */
int
mybitmap_clear_all(unsigned char *bitmap, int max_resources);

/*
 * Mark an entry in the bitmap as free 
 */
int
mybitmap_clear_bit(unsigned char *bitmap, int bit_index);

/* 
 * Print the contents of the bitmap
 */
int
mybitmap_print(unsigned char *bitmap, int max_resource);

int
mybitmap_get_id_by_position(unsigned char *bitmap, int bit_index);

#endif /* __MYBITMAP_H__ */

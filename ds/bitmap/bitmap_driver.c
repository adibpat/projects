#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

#define MAX_RES (5)

int main ()
{
    int id;
    int res, rc;
    BITMAP(aditya,MAX_RES);
    char c; int index;
    mybitmap_clear_all(aditya, MAX_RES);
    mybitmap_clear_all(aditya, MAX_RES);
    while (1) {
        printf("a: allocate, f: free, q: quit\n");
        scanf("%c*", &c); getchar();
        printf("\n");
        switch(c)
        {
        case 'a':
            res = mybitmap_find_first_free(aditya, MAX_RES, 1);
            if (res > MAX_RES) {
                printf("No resource left\n");
                break;
            }
            printf("Enter client id:\n");
            scanf("%d*", &id); getchar();
            printf("Free id %d found. Settting %d as id\n", res, id);
            rc = mybitmap_set_bit(id, aditya, res);
            break;
        case 'f':
            printf("Enter id to free\n");
            scanf("%d*", &index); getchar();
            printf("\n");
            rc = mybitmap_clear_bit(aditya, index);
            break;
        case 'p':
            mybitmap_print(aditya, MAX_RES);
            break;
        case 'v':
            printf("Enter position: \n");
            scanf("%d*", &index); getchar();
            printf("Value at index %d is %d\n", index, mybitmap_get_id_by_position(aditya, index));
            break;
        case 'q':
            return (0);
            break;
        default:
            printf("Invalid option %c \n", c);
            break;
        }
    }
    return (0);
}

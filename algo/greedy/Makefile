CC=gcc
SUB_INC=include/
LIB_INC=/Users/abpatwar/my_projects/projects/algo/greedy_lib/
CFLAGS=-I$(SUB_INC)
LFLAGS=-L$(LIB_INC)

all: union_find activity_select

activity_select: activity_select.o
	$(CC) -o activity_select activity_select.c $(CFLAGS) -L. -lmysortlib

union_find: union_find.c 
	$(CC) -o $@ driver.c union_find.c $(CFLAGS)

activity_select.o: activity_select.c
	$(CC) -c activity_select.c 

clean:
	rm activity_select.o union_find activity_select
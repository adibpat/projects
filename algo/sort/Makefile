CC=gcc

all : qsort

qsort : sort_driver.o libmysortlib.so
	$(CC) -o qsort sort_driver.o -L. -lmysortlib

sort_driver.o: sort_driver.c
	$(CC) -c sort_driver.c 

libmysortlib.so : quick_sort.o
	$(CC) -shared -o libmysortlib.so quick_sort.o

quick_sort.o : quick_sort.c
	$(CC) -c quick_sort.c 

clean:
	rm libmysortlib.so quick_sort.o sort_driver.o qsort
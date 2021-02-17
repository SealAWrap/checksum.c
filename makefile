CCFLAGS=-g -DMAIN
SOURCE=ints2bytes.c checksum.c

all: ints2bytes checksum

test: checksum create_input
	./checksum < 156.bytes
	./checksum < 229.bytes
	./checksum < 81.bytes
	./checksum< 47201.bytes

create_input: ints2bytes
	./ints2bytes < 156.txt > 156.bytes
	./ints2bytes < 229.txt > 229.bytes
	./ints2bytes < 81.txt > 81.bytes
	./ints2bytes < 47201.txt > 47201.bytes

display_input:
	od -t u1 156.bytes
	od -t u1 229.bytes
	od -t u1 81.bytes
	od -t u1 47201.bytes

ints2bytes: ints2bytes.c

checksum: checksum.o

checksum.o: checksum.c 
	$(CC) -o checksum.o -c $(CCFLAGS) checksum.c

checksum.i: checksum.c 
	$(CC) -o checksum.i -E checksum.c

checksum.s: checksum.c 
	$(CC) -o checksum.s -S checksum.c

checksum.x86: tube.s
	ln -s cheksum.x86 checksum.s checksum.x86

checksum.mips: checksum.o
	echo "Go to the website: http://reliant.colab.duke.edu/c2mips/"
	echo "enter the file checksum.c"
	touch checksum.mips

clean:
	rm -f ints2bytes *.bytes
	rm -f checksum checksum.o checksum.i checksum.s checksum.x86
	rm -f *~ \#*





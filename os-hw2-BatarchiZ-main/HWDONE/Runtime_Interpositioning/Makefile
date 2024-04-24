JUNK=*~ *.bak *.old
GENERATES=*.o prog

all: prog

prog: prog.o wrapstat.o libfoostat.a libfooshar.so libwrap.so
	cc -Wl,--wrap,fred -Wl,--wrap,john -o $@ prog.o  wrapstat.o -lfoostat -lfooshar -lm -L.

libwrap.so: wrapshar.o
	cc -Wall -shared -o $@ $^ -ldl

wrapshar.o: wrapshar.c
	cc -Wall -fPIC $< -c

libfooshar.so: bill.o sam.o 
	cc -shared -o $@ $^ -lm

wrapstat.o: wrapstat.c
	cc -Wall -c $<
prog.o: prog.c
	cc $< -c
libfoostat.a: fred.o john.o
	ar crv $@ $^
bill.o:	bill.c
	cc -fPIC $< -c
fred.o: fred.c
	cc $< -c
john.o: john.c
	cc $< -c
sam.o: sam.c
	cc -fPIC $< -c
clean:
	rm *.o *.a prog

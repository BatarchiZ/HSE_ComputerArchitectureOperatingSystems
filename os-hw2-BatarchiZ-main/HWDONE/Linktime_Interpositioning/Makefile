JUNK=*~ *.bak *.old
GENERATES=*.o prog

all: prog

prog: prog.o bill.o sam.o wrapstat.o libfoostat.a
	cc -Wl,--wrap,fred -Wl,--wrap,john -o $@ prog.o bill.o sam.o wrapstat.o -lm -lfoostat -L.
wrapstat.o: wrapstat.c
	cc -Wall -c $<
prog.o: prog.c
	cc $< -c
libfoostat.a: fred.o john.o
	ar crv $@ $^
bill.o:	bill.c
	cc $< -c
fred.o: fred.c
	cc $< -c
john.o: john.c
	cc $< -c
sam.o: sam.c
	cc $< -c
clean:
	rm *.o *.a prog

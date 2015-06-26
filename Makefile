OBJS = libfoo-internal.o

all: libfoo.so test-client run-test-client get-syms libfoo.so.xml

PHONY: run-test-client get-syms

libfoo.so: $(OBJS) Makefile
	gcc \
	  -o $@ \
	  -shared \
	  $(OBJS) \
	-lstdc++ \
	  -Wl,--version-script=libfoo.map \
	  -Wl,-soname,libfoo.so.0

libfoo.so.0: libfoo.so
	ln -s $< $@

clean:
	-rm *.o
	-rm *.so

libfoo-internal.o: libfoo-internal.cc
	gcc -c -o $@ $< -fPIC -g

test-client: test-client.o
	gcc -o $@ $< -L. -lfoo

run-test-client: test-client libfoo.so.0
	LD_LIBRARY_PATH=. ./test-client

get-syms: libfoo.so
	eu-readelf -s libfoo.so

PATH_TO_ABIGAIL_BUILD=/home/david/coding-3/gcc-git-jit-libabigail/libabigail/build

libfoo.so.xml: libfoo.so
	$(PATH_TO_ABIGAIL_BUILD)/tools/abidw $< > $@

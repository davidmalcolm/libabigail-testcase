OBJS = test-file1.o test-file2.o
libtest.so: $(OBJS)
	gcc \
	  -o $@ \
	  -shared \
	  $(OBJS) \
	  -Wl,--version-script=libtest.map \
	  -Wl,-soname,libtest.so.0

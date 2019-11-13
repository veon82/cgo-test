%.o: %.c
	$(CC) -o $@ -c -fPIC $< $(CFLAGS)

clean:
	rm -f *.o *.so

libperson: person.o
	$(CC) -o libperson.so -shared $<

cgo-test: libperson
	$(shell go build)


project : main.o employee.o nbilling.o products.o
		cc main.o employee.o nbilling.o products.o -o project
main.o: main.c header.h
		cc -c main.c
employee.o: employee.c header.h
		cc -c employee.c
nbilling.o: nbilling.c header.h
		cc -c nbilling.c
products.o: products.c header.h
		cc -c products.c
clean :
		rm -f *.o project

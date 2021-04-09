TARGETS	=	p3

all:	$(TARGETS)

p3:	main.o Record.o ReportGenerator.o Report3.o
	g++ -o p3 main.o Record.o ReportGenerator.o Report3.o

main.o:	main.cc ReportGenerator.h
	g++ -c main.cc

Record.o:Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

Report3.o: Report3.cc Report3.h
	g++ -c Report3.cc
	
clean:
	rm -f *.o p3

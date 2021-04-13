TARGETS	=	p3

all:	$(TARGETS)

p3:	main.o Record.o ReportGenerator.o Report3.o Report2.o Report1.o View.o Control.o
	g++ -o p3 main.o Record.o ReportGenerator.o Report3.o Report2.o Report1.o View.o Control.o

main.o:	main.cc Report3.h Report2.h
	g++ -c main.cc

Record.o:Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

Report3.o: Report3.cc Report3.h
	g++ -c Report3.cc
	
Report2.o: Report2.cc Report2.h
	g++ -c Report2.cc
	
Report1.o: Report1.cc Report1.h
	g++ -c Report1.cc
	
View.o: View.cc View.h
	g++ -c View.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc
	
clean:
	rm -f *.o p3

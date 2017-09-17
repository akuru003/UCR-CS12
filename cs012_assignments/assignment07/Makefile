all: main.cpp BBoard.o User.o Message.o Topic.o Reply.o
	g++ -W -Wall -ansi -pedantic main.cpp BBoard.o User.o Message.o Reply.o Topic.o
BBoard.o: BBoard.cpp BBoard.h Message.h User.h Reply.h Topic.h
	g++ -W -Wall -ansi -pedantic -c BBoard.cpp
Message.o: Message.cpp Message.h
	g++ -W -Wall -ansi -pedantic -c Message.cpp
User.o: User.cpp User.h
	g++ -W -Wall -ansi -pedantic -c User.cpp
Topic.o: Topic.cpp Topic.h Message.h
	g++ -W -Wall -ansi -pedantic -c Topic.cpp
Reply.o: Reply.cpp Reply.h Message.h
	g++ -W -Wall -ansi -pedantic -c Reply.cpp
clean: 
	rm a.out *.o
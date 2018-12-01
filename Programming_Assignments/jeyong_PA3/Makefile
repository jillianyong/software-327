#EC327 Programming Assignment 3 Makefile
GCC=g++

OBJS=main.o Cart_Point.o Cart_Vector.o Game_Object.o Game_Command.o Oxygen_Depot.o Astronaut.o Model.o Person.o Space_Station.o View.o

default: PA3

PA3: $(OBJS)
	$(GCC) -o PA3 $(OBJS) 

Cart_Vector.o: Cart_Vector.cpp Cart_Vector.h
	$(GCC) -c Cart_Vector.cpp -o Cart_Vector.o 
	
Cart_Point.o: Cart_Point.cpp Cart_Point.h Cart_Vector.h
	$(GCC) -c Cart_Point.cpp -o Cart_Point.o 

Game_Object.o: Game_Object.cpp Game_Object.h Cart_Point.h Cart_Vector.h
	$(GCC) -c Game_Object.cpp -o Game_Object.o 

Oxygen_Depot.o: Oxygen_Depot.cpp Oxygen_Depot.h Game_Object.h Cart_Point.h
	$(GCC) -c Oxygen_Depot.cpp -o Oxygen_Depot.o 

Astronaut.o: Astronaut.cpp Astronaut.h Person.h Game_Object.h Oxygen_Depot.h Space_Station.h Cart_Point.h Cart_Vector.h
	$(GCC) -c Astronaut.cpp -o Astronaut.o 

Model.o: Model.cpp Model.h Game_Object.h Person.h Space_Station.h Oxygen_Depot.h Astronaut.h View.h
	$(GCC) -c Model.cpp -o Model.o 

Space_Station.o: Space_Station.cpp Space_Station.h Game_Object.h Cart_Point.h
	$(GCC) -c Space_Station.cpp -o Space_Station.o 

View.o: View.cpp View.h Game_Object.h Cart_Point.h
	$(GCC) -c View.cpp -o View.o 

Person.o: Person.cpp Person.h Game_Object.h Cart_Point.h Cart_Vector.h Space_Station.h Oxygen_Depot.h
	$(GCC) -c Person.cpp -o Person.o

Game_Command.o: Game_Command.cpp Game_Command.h Model.h Game_Object.h Person.h Space_Station.h Oxygen_Depot.h Astronaut.h
	$(GCC) -c Game_Command.cpp -o Game_Command.o

main.o: main.cpp Cart_Point.h Cart_Vector.h Game_Command.h Oxygen_Depot.h Astronaut.h Model.h Person.h Space_Station.h Game_Object.h View.h
	$(GCC) -c main.cpp

clean: 
	rm $(OBJS) PA3


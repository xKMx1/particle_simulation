LIBS:=-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

all: ParticleSimulation

main.o: main.cpp particle.h
	g++ -Isrc/include -c main.cpp

particle.o: particle.cpp particle.h
	g++ -Isrc/include -c "particle.cpp" -o particle.o

ParticleSimulation: main.o particle.o
	g++ -o ParticleSimulation main.o particle.o $(LIBS)
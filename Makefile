LIBS:=-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

all: ParticleSimulation

main.o: main.cpp particle.h
	g++ -Isrc/include -c main.cpp

particle.o: particle.cpp particle.h vectorMath.h
	g++ -Isrc/include -c "particle.cpp" -o particle.o

vector.o: vectorMath.cpp vectorMath.h
	g++ -Isrc/include -c "vectorMath.cpp" -o vector.o

ParticleSimulation: main.o particle.o vector.o
	g++ -o ParticleSimulation main.o particle.o vector.o $(LIBS)
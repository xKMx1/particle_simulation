LIBS:=-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

all: ParticleSimulation

main.o: main.cpp particle.h AppObject.h
	g++ -Isrc/include -c main.cpp

particle.o: particle.cpp particle.h vectorMath.h
	g++ -Isrc/include -c "particle.cpp" -o particle.o

vector.o: vectorMath.cpp vectorMath.h
	g++ -Isrc/include -c "vectorMath.cpp" -o vector.o

AppObject.o: AppObject.cpp particle.h Button.h
	g++ -Isrc/include -c "AppObject.cpp" -o AppObject.o

Button.o: Button.cpp button.h
	g++ -Isrc/include -c "Button.cpp" -o Button.o

ParticleSimulation: main.o particle.o AppObject.o vector.o Button.o
	g++ -o ParticleSimulation main.o particle.o AppObject.o vector.o Button.o $(LIBS)
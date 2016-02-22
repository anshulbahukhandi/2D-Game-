CC=g++
FILE=main.cpp game.cpp texturepool.cpp parameter.cpp gameobject.cpp player.cpp enemy.cpp myvector.cpp inputhandler.cpp
FLAGS= -w -lSDL2 -lSDL2_image
OUTPUT=a.out

all:${OUTPUT}
	

${OUTPUT}: clean
	${CC} ${FILE} ${FLAGS} -o ${OUTPUT}


clean:
	rm -rf *o ${OUTPUT}

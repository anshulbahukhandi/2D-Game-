CC=g++
FILE=main.cpp game.cpp texturepool.cpp parameter.cpp gameobject.cpp player.cpp enemy.cpp myvector.cpp inputhandler.cpp statemachine.cpp playstate.cpp button.cpp pausestate.cpp gameoverstate.cpp animatedgraphics.cpp gameobjectfactory.cpp mainmenustate.cpp stateparser.cpp tinyxml.cpp tinystr.cpp tinyxmlerror.cpp tinyxmlparser.cpp
FLAGS= -w -lSDL2 -lSDL2_image -std=c++11
OUTPUT=a.out

all:${OUTPUT}
	

${OUTPUT}: clean
	${CC} ${FILE} ${FLAGS} -o ${OUTPUT}


clean:
	rm -rf *o ${OUTPUT}

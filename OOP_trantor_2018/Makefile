##
## EPITECH PROJECT, 2018
## USP_cloning_trantor_2018
## File description:
## Makefile
##

JAVAC = javac
RM = rm -f
JAVASRC = 	src/main/java/eu/epitech/trantor/Team.java \
			src/main/java/eu/epitech/trantor/Item.java \
			src/main/java/eu/epitech/trantor/Drone.java \
			src/main/java/eu/epitech/trantor/Map.java \
			src/main/java/eu/epitech/trantor/Commands.java \
			src/main/java/eu/epitech/trantor/Case.java\
			src/main/java/eu/epitech/trantor/Server.java \
			src/main/java/eu/epitech/trantor/Main.java
CLASSES = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE = trantor-1.0.0

all: fclean package

package:
	mvn package
	mkdir dist
	mv target/$(JARFILE).jar dist/
	rm -rf target/

build:
	mvn compile

run:
	mvn exec:java -Dexec.mainClass="eu.epitech.trantor.Main"

test:
	mvn test

deps:
	mvn dependency:resolve

clean:
	mvn clean

fclean: clean
	$(RM) -rf dist

re: fclean all
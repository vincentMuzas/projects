##
## EPITECH PROJECT, 2018
## USP_cloning_trantor_2018
## File description:
## Makefile
##

RM = rm -f
JAVASRC = 	src/main/java/solitr/App \
		src/main/java/solitr/Displayer \
		src/main/java/solitr/Solitr	\
		src/main/java/solitr/Deck	\
		src/main/java/solitr/DummyCard.java

CLASSES = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE = solitr

all: fclean package

package:
	mvn package
#	mv target/$(JARFILE).jar dist/
#	rm -rf target/

build:
	mvn compile

run:
	mvn  exec:java -Dexec.mainClass="solitr.App"

test:
	mvn test

deps:
	mvn dependency:resolve

clean:
	mvn clean

fclean: clean
	$(RM) -rf dist solitr

re: fclean all
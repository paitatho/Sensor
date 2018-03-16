# Nom du projet
EXE=maina
MAKEDEPFILE=Dependencies-$(EXE)

SOURCES=$(wildcard $(EXE)*.c)

OBJETS=$(SOURCES:%.cpp=%.o)

# Nom du compilateur
CC=gcc
MAKEDEP=gcc -M -MF $(MAKEDEPFILE) -lwiringPi

all: depend build

build: $(EXE)

$(EXE): $(OBJETS)
	@echo "Edition de liens"
	$(CC) -o $@ $(OBJETS) $(CFLAGS)

%.o: %.cpp
		$(CC) $*.c -c $(CFLAGS)

clean:
	\rm -f *~

reset: clean
	\rm -f *.o

depend:
	@echo "Calcul des dépendances"
	$(MAKEDEP) $(CFLAGS) $(SOURCES)

-include $(MAKEDEPFILE)

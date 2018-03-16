# Nom du projet
EXE=mystr
MAKEDEPFILE=Dependencies-$(EXE)

SOURCES=$(wildcard $(EXE)*.c)

OBJETS=$(SOURCES:%.c=%.o)

# Nom du compilateur
CC=gcc
MAKEDEP=gcc -M -MF $(MAKEDEPFILE)

all: depend build

build: $(EXE)

$(EXE): $(OBJETS)
	@echo "Edition de liens"
	$(CC) -o $@ $(OBJETS) $(CFLAGS)

%.o: %.c
		$(CC) $*.c -c $(CFLAGS)

clean:
	\rm -f *~

reset: clean
	\rm -f *.o

depend:
	@echo "Calcul des dépendances"
	$(MAKEDEP) $(CFLAGS) $(SOURCES)

-include $(MAKEDEPFILE)
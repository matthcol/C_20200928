OBJS = list.o main.o
CFLAGS += -g -O0
# LDFLAGS +=  <flags pour la phase de link>

#all:	appList.exe
all:	appList

#appList.exe:	$(OBJS)
appList:	$(OBJS)
	# $CXX : compilateur g++
	# $CC : compilateur gcc
	# $@ : nom de la cible
	# $^ : la liste des dépendances 
	$(CC) $(LDFLAGS) -o $@ $^

%.o:	%.c
	# $< : fichier.c 
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	# del appList.exe $(OBJS)
	rm -f appList $(OBJS)
	

CC = g++
FEATDIR = ../feature_code
LNKS = -lgtest -lgcov
CFLAGS = -g -fprofile-arcs -ftest-coverage

all: path_testing feature
	$(CC) -o path_testing $(CFLAGS) path_testing.o Link_List.o $(LNKS) 
path_testing: path_testing.cpp
	$(CC) -o path_testing.o ${CFLAGS}  -c path_testing.cpp $(LNKS) 
feature: $(FEATDIR)/Link_List.h $(FEATDIR)/Link_List.cpp
	$(CC) -o Link_List.o -c $(CFLAGS)  $(FEATDIR)/Link_List.cpp $(LNKS) 

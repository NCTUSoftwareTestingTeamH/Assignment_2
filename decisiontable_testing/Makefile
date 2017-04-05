CC = g++
FEATDIR = ../feature_code
CFLAGS = -lpthread -lgtest

all: decisiontable_testing feature
	$(CC) -o decisiontable_testing $(CFLAGS) decisiontable_testing.o Link_List.o
decisiontable_testing: decisiontable_testing.cpp
	$(CC) -o decisiontable_testing.o ${CFLAGS} -c decisiontable_testing.cpp
feature: $(FEATDIR)/Link_List.h $(FEATDIR)/Link_List.cpp
	$(CC) -o Link_List.o -c $(FEATDIR)/Link_List.cpp

# Makefile
CC = g++
CFLAGS = -Wall -Wextra -std=c++98

all: btc

btc: main.cpp BitcoinExchange.cpp
	$(CC) $(CFLAGS) -o btc main.cpp BitcoinExchange.cpp

clean:
	rm -f btc

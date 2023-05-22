CC = g++
CPPFLAGS = -std=c++11 -Wall -g

main: activity.o tools.o activitylist.o main.o

activity.o: activity.h

activitylist.o: activitylist.h tools.h

tools.o: tools.h activity.h

driver.o: tools.h activity.h

clean:
	rm main *.o
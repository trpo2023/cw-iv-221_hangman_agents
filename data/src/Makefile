CPP = g++
TARGET =  main
CFLAGS = -Wall -g3 -O0
FILES = main.cpp library/info/info.cpp library/music/music.cpp library/missions/choise_mission.cpp library/missions/mission_test.cpp

$(TARGET)1 : 
	$(CPP) $(CFLAGS) $(FILES) -o $(TARGET)
run : 
	./$(TARGET)
clean : 
	rm $(TARGET)
debag :
	gdb ./$(TARGET)
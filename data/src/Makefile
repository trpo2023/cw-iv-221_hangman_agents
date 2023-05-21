CPP = g++
TARGET =  main
CFLAGS = -Wall -g3 -O0
FILES = main.cpp library/info/info.cpp library/music/music.cpp

$(TARGET)1 : 
	$(CPP) $(CFLAGS) $(FILES) -o $(TARGET)
run : 
	./$(TARGET)
clean : 
	rm $(TARGET)
debag :
	gdb ./$(TARGET)
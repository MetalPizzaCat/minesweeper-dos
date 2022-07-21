OUTPUT_NAME = msweep.com
OUTPUT_FOLDER = ~/dosprogs
OUTPUT_PLATFORM = DOS
CC = owcc
CCFLAGS = -O2 -Wall
INCLUDE_DIRS = -I/
SOURCE_FILES = main.c mouse.c video.c bitmap.c
all: main
main:
	$(CC) $(CCFLAGS) $(INCLUDE_DIRS) -b $(OUTPUT_PLATFORM)  $(SOURCE_FILES) -o $(OUTPUT_NAME) -v

install: main
	cp ./$(OUTPUT_NAME) $(OUTPUT_FOLDER)
	cp ./face.bmp $(OUTPUT_FOLDER)

clean:
	$(RM) ./$(OUTPUT_NAME)
	$(RM) ./*.o
	$(RM) ./*.err
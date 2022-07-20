OUTPUT_NAME = msweep.com
OUTPUT_FOLDER = ~/dosprogs
OUTPUT_PLATFORM = DOS
all: main
main:
	owcc -I/ -O2 -Wall -b $(OUTPUT_PLATFORM)  main.c -o $(OUTPUT_NAME) -v

install: main
	cp ./$(OUTPUT_NAME) $(OUTPUT_FOLDER)

clean:
	rm rf ./$(OUTPUT_NAME)
	rm rf ./main.o
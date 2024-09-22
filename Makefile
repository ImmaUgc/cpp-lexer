CXX = g++
OUTPUT_FILE = lexer
SOURCE_DIR = source
SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.cpp)

all:
	$(CXX) $(SOURCE_FILES) -o $(OUTPUT_FILE).exe

clean:
	rm $(OUTPUT_FILE).exe
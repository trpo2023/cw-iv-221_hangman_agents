APP_NAME = hangman
LIB_NAME = library
TEST_NAME = test

CFLAGS = -I src -I thirdparty
CPPFLAGS = -MMD
COMP = g++

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test
THIRDPARTY_DIR = thirdparty

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
DATA_PATH = $(BIN_DIR)/$(DATA_NAME)
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SOURCES = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.cpp)
APP_OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.cpp)
LIB_OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(LIB_SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(TEST_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

create: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(COMP) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lSDL2 -lSDL2_mixer

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(COMP) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< -lSDL2 -lSDL2_mixer

clean:
	$(RM) $(APP_PATH) $(OBJ_DIR)/$(SRC_DIR)/*/*.[aod] $(TEST_PATH) $(OBJ_DIR)/$(TEST_DIR)/*.[aod]

run:
	./$(APP_PATH)

test: $(TEST_PATH)

-include $(DEPS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(COMP) $(CFLAGS) $(CPPFLAGS) $^ -o $@ -lSDL2 -lSDL2_mixer

runtest:
	./$(TEST_PATH)

.PHONY: clean create run test runtest
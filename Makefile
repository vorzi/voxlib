CC = gcc

CFLAGS = -Wall -Wextra -O2 -fPIC -Iinclude
LDFLAGS = -lX11

BUILD = build
FILE_BUILD = $(BUILD)/file

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,$(BUILD)/%.o,$(SRC))

LIB_STATIC = $(FILE_BUILD)/libvoxlib.a
LIB_SHARED = $(FILE_BUILD)/libvoxlib.so

EXAMPLE = $(FILE_BUILD)/main
EXAMPLE_SRC = main.c


all: lib example


$(BUILD):
	mkdir -p $(BUILD)


$(FILE_BUILD):
	mkdir -p $(FILE_BUILD)

lib-static: $(LIB_STATIC)

$(LIB_STATIC): $(OBJ) | $(FILE_BUILD)
	ar rcs $@ $^

lib-shared: $(LIB_SHARED)

$(LIB_SHARED): $(OBJ) | $(FILE_BUILD)
	$(CC) -shared -o $@ $^ $(LDFLAGS)


lib: lib-static lib-shared


$(BUILD)/%.o: src/%.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@


example: lib | $(FILE_BUILD)
	$(CC) $(EXAMPLE_SRC) \
		-Iinclude \
		$(LIB_STATIC) \
		$(LDFLAGS) \
		-o $(EXAMPLE)


clean:
	rm -rf $(BUILD)


.PHONY: all lib lib-static lib-shared example clean
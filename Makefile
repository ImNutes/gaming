CC = em++
SRC_DIRS := ./src
BUILD_DIR := ./docs
SRCS := $(shell find $(SRC_DIRS) -name '*.cc' -or -name '*.c' -or -name '*.s')

waking-plains:
	$(CC) -o $(BUILD_DIR)/index.html $(SRCS) -Os -Wall -I emsdk/upstream/emscripten/cache/sysroot/include -L emsdk/upstream/emscripten/cache/sysroot/lib/libraylib.a -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB emsdk/upstream/emscripten/cache/sysroot/lib/libraylib.a -g

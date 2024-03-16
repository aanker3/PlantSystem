# Arduino CLI Configuration
BOARD := arduino:renesas_uno:unor4wifi
PORT := COM3make
SKETCH_DIR := .

# Specify the directory for build output (relative to project_root)
BUILD_DIR := ../build
SYMLINK_SENSORS_DIR := $(SKETCH_DIR)/sensors

# Default target: Compile the sketch
all: compile

# Compile the sketch using arduino-cli
compile:
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD_DIR) $(SKETCH_DIR)

# Upload the sketch to the board
upload:
	arduino-cli upload -p $(PORT) --fqbn $(BOARD) --input-dir $(BUILD_DIR)

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all compile upload clean

PROJ_NAME=seat_heater

TARGET=atmega328

OPTIMISE = -Os

BUILD_DIR = build

PROJ_PATH = $(BUILD_DIR)/$(PROJ_NAME)

# All Source code files
SRC = project_main.c\
src/activity1.c\
src/activity2.c\
src/activity3.c\
src/project_config.c

# All header file paths
INC = -I inc

# Find out the OS and configure the variables accordingly
ifdef OS	# All configurations for Windwos OS
# Delete command 
   RM = del /q
# Move command
   MOV = Move-Item
# Correct the path based on OS
   FixPath = $(subst /,\,$1)
# Name of the compiler used
   CC = avr-gcc.exe
# Name of the elf to hex file converter used
   AVR_OBJ_CPY = avr-objcopy.exe
else #All configurations for Linux OS
   ifeq ($(shell uname), Linux)
# Delete command
    RM = rm -rf
# Move command
   MOV = mv	
# Correct the path based on OS
    FixPath = $1				
# Name of the compiler used
	CC = avr-gcc
# Name of the elf to hex file converter used
	AVR_OBJ_CPY = avr-objcopy 
   endif
endif

# Command to make to consider these names as targets and not as file names in folder
.PHONY:all analysis clean doc

all: $(PROJ_PATH).elf
	# Generate hex file from elf file
	$(AVR_OBJ_CPY) -j .text -j .data -O ihex $(call FixPath,$(PROJ_PATH).elf) $(call FixPath,$(PROJ_PATH).hex)

$(PROJ_PATH).elf: $(PROJ_PATH).o
	# Generate elf file from object file
	$(CC) -g -mmcu=$(TARGET) -o $(call FixPath,$(PROJ_PATH).elf) $(call FixPath,$(BUILD_DIR)/*.o)

$(PROJ_PATH).o: $(SRC) $(BUILD_DIR)
	# Compile and generate object file from c file
	$(CC) -g -Wall $(OPTIMISE) -mmcu=$(TARGET) -c $(INC) $(SRC)
	$(MOV) *.o $(BUILD_DIR)

$(BUILD_DIR):
	# Create new build folder if not present
	mkdir build

analysis: $(SRC)
# Analyse the code using Cppcheck command line utility
	cppcheck --enable=all $^

doc:
# Build the code code documentation using Doxygen command line utility
	make -C documentation

clean:
# Remove all the build files and generated document files
	$(RM) $(call FixPath,$(BUILD_DIR))
	make -C documentation clean
	$(RM) *.o
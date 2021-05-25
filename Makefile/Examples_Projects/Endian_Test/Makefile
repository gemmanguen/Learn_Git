PRO_DIR := .
PATH_OUTPUT = output
PROJ_NAME := endian

INC_DIRS = D:/FPT/GAM_DAP_Traning/Makefile/Examples/Endian_Test/include
SRC_DIRS = D:/FPT/GAM_DAP_Traning/Makefile/Examples/Endian_Test/source

SRC_FILES := $(foreach SRC_DIRS, $(SRC_DIRS),$(wildcard $(SRC_DIRS)/*))
INC_FILES := $(foreach INC_DIRS, $(INC_DIRS),$(wildcard $(INC_DIRS)/*))

LINKER_FILE := $(PRO_DIR)/linker/stm_ls.ld
COMPILER_DIR := C:/GNU_Toolchain/GCC_NEW

# Compiler and linker flags
CC := $(COMPILER_DIR)/bin/arm-none-eabi-gcc
LD := $(COMPILER_DIR)/bin/arm-none-eabi-ld

# Compiler and linker option
CC_OPT := -mcpu=cortex-m4 -c -std=gnu11 -o0 -g -mthumb -I$(INC_DIRS)
LD_OPT := -T $(LINKER_FILE) -Map $(PATH_OUTPUT)/$(PROJ_NAME).map

# Object files
OJB_FILES := $(notdir $(SRC_FILES))
OJB_FILES := $(subst .c,.o, $(OJB_FILES))
PATH_OJBS := $(foreach OJB_FILES, $(OJB_FILES),$(PATH_OUTPUT)/$(OJB_FILES))

# search all path .c and .h files
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)

.PHONY: build
build: $(OJB_FILES) $(LINKER_FILE)
	$(LD) $(LD_OPT) $(PATH_OJBS) -o $(PATH_OUTPUT)/$(PROJ_NAME).elf
	$(COMPILER_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$(PATH_OUTPUT)/$(PROJ_NAME).elf" "$(PATH_OUTPUT)/$(PROJ_NAME).hex"
	size $(PATH_OUTPUT)/$(PROJ_NAME).elf
	
%.o: %.c $(INC_FILES)
	$(CC) $(CC_OPT) -c $< -o $(PATH_OUTPUT)/$@
	
.PHONY: clean
clean:
	@rm $(PATH_OUTPUT)/*

print-%:
	@echo $($(subst print-,,$@))
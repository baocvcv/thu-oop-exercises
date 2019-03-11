# makefile for single directory c++ projects

# macros
CC := g++
CCFLAG := -std=c++11
DBGFLAG := -g -Wall -std=c++11
CCOBJFLAG := $(CCFLAG) -c

# target & files
TARGET := main
DBG_SUFFIX := _dbg
TARGET_DEBUG := $(addsuffix $(DBG_SUFFIX), $(TARGET))
MAIN_SRC := $(addsuffix .cpp, $(TARGET))
SRC := $(basename $(wildcard *.c*))

#default rule
defualt:all

# targets
$(TARGET): $(addsuffix .o, $(SRC))
	$(CC) $(CCFLAG) -o $@ $^

%.o: %.c*
	$(CC) $(CCOBJFLAG) -o $@ $<

$(TARGET_DEBUG): $(addsuffix $(DBG_SUFFIX).o, $(SRC))
	$(CC) $(CCFLAG) $(DBGFLAG) -o $@ $^

%$(DBG_SUFFIX).o: %.c*
	$(CC) $(CCOBJFLAG) $(DBGFLAG) -o $@ $<

# phony
.PHONY: all
all: $(TARGET)

.PHONY: debug
debug: $(TARGET_DEBUG)

.PHONY: clean
clean:
	rm -f *.o

.PHONY: swipe
swipe:
	rm -f *.o
	rm -f $(TARGET) $(TARGET_DEBUG)

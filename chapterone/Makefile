
CFLAGS += -I../include
CFLAGS += -g

SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
EXES=$(patsubst %.c,%,$(SRCS))

CC = gcc

all: $(EXES)

$(EXES): $(OBJS)

%.o: %.c
	${CC} -c $< -o $@

%: %.o
	${CC} $< -o $@

clean:
	-rm $(OBJS) $(EXES)


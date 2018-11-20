CFLAGS += -std=gnu99 -g -O0 -Wall -Werror -rdynamic -D_GNU_SOURCE -DNDEBUG -I.

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean: 
	rm -f $(PROGS) *.log *.gz *.scap

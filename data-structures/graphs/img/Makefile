SRCS = $(wildcard *.dot)
PROGS = $(patsubst %.dot,%.svg,$(SRCS))

all: $(PROGS)

%.svg: %.dot
	dot -Tsvg -o $@ $<
clean: 
	rm -f $(PROGS)
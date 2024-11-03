src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

producer_consumer: $(obj)
	g++ -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) merge_files

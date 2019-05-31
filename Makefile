CPPFLAGS += -O2
CXXFLAGS += -std=c++14
LDLIBS += -lginac

bin/example: *.cpp
	mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -rf build bin
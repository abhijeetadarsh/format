CC := g++

src := ./src/
bin := ./bin/
test := ./test/
installation_dir := ~/lib/

mainfile := main.cpp
binfile := format.out
testfile := test_input.cpp

$(bin)$(binfile): $(src)$(mainfile)
	$(CC) $^ -o $(bin)$(binfile)

clean:
	rm $(bin)*

test: $(bin)$(binfile)
	$(bin)$(binfile) $(test)$(testfile)

install: $(bin)$(binfile)
	cp $(bin)$(binfile) $(installation_dir)format
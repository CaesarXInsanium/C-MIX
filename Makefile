DIR=build

all: $(DIR)
	meson compile -C build
vm: all
	./$(DIR)/cmixvm
asm: all
	./$(DIR)/cmixasm
$(DIR):
	meson setup $(DIR)
clean:
	rm -r $(DIR)

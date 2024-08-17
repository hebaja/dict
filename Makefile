all: rush02
	@echo "All done!"
rush02:
	@echo "Compiling..."
	@gcc src/*.c -o rush02
clean:
	@echo "All cleaned!"
	@rm -rf rush02

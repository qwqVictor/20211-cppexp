josephus: josephus.cpp
	g++ -o josephus josephus.cpp

.PHONY: clean
clean:
	rm -f josephus

.PHONY: test
test:
	@make josephus
	./josephus < __gitignored_data_input.txt
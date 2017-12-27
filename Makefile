SRC_DIR = src
BIN_DIR = bin
EXEC = tp3

exec: source bindir
	cp $(SRC_DIR)/tp2 $(BIN_DIR)

bindir:
	mkdir -p $(BIN_DIR)

clean:
	$(MAKE) clean -C $(SRC_DIR)
	rm -rf $(BIN_DIR)

source:
	$(MAKE) -C $(SRC_DIR)

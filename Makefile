TARGET=pantomime

CFLAGS = -I. -I./source/include -DDEBUG=1 -g

OBJ = source/main.o \
	  source/html_attributeparser.o \
	  source/html_parser.o \
	  source/html_data.o \
	  source/util.o

all: $(OBJ)
	@echo Linking..
	@$(CC) $(DEBUG) -o $(TARGET) $(OBJ)
	@echo Built!

clean:
	@rm -rf  *.o $(TARGET) $(TARGET).tgz
	@echo Done

package:
	$(MAKE) clean
	@tar czf $(TARGET).tgz *
	@echo Your gzip tarball is completed: $(TARGET).tgz	

blame:
	@echo Cypress is to blame of course!

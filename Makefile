TARGET=pantomime

CFLAGS := -I. -I./source/include

OBJ = source/main.o \
	  source/html_attributeparser.o \
	  source/html_parser.o \
	  source/html_data.o \
	  source/util.o

ifeq ($(DEBUG),1)
	CFLAGS += -g
endif

all: $(OBJ)
	@echo Linking..
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo Built!

clean:
	@rm -rf  source/*.o $(TARGET) $(TARGET).tgz
	@echo Done

package:
	$(MAKE) clean
	@tar czf $(TARGET).tgz *
	@echo Your gzip tarball is completed: $(TARGET).tgz	

blame:
	@echo Cypress is to blame of course!

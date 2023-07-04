TARGET=pantomime

CFLAGS := -I. -I./include

COMMON_OBJS = \
	source/main.o \
	source/util.o

PROTOCOL_OBJS = \
	source/prtcl/prtcl_file.o \
	source/prtcl/prtcl_main.o

HTML_OBJS = \
	source/html/html_attributeparser.o \
	source/html/html_parser.o \
	source/html/html_data.o

OBJ = $(COMMON_OBJS) $(PROTOCOL_OBJS) $(HTML_OBJS)

ifeq ($(DEBUG),1)

CFLAGS += -g -Wall

endif

all: $(OBJ)
	@echo Linking..
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo Built!

clean:
	@find . -type f -name '*.o' -exec rm {} +
	@rm -rf  $(TARGET) $(TARGET).tgz
	@echo Done

package:
	$(MAKE) clean
	@tar czf $(TARGET).tgz *
	@echo Your gzip tarball is completed: $(TARGET).tgz	

blame:
	@echo Cypress is to blame of course!

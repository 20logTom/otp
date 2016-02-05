CC      = clang
BIN     = configgen keygen otp
DIRS    = objdir cfgdir keydir
SRC     = main.c config_file_generator.c key_generator.c otp.c utils.c
LIBS    = -lm
CFLAGS  = -g3 -Wall
MKDIR   = mkdir
EXT     = c
SRCDIR  = src
OBJDIR  = obj
CFGDIR  = cfg
KEYDIR  = key
OBJ     := $(subst .$(EXT),.o,$(SRC))
OBJ     := $(addprefix $(OBJDIR)/, $(OBJ))
 
all: $(DIRS) $(BIN)

objdir:
	$(MKDIR) -p $(OBJDIR)

cfgdir:
	$(MKDIR) -p $(CFGDIR)

keydir:
	$(MKDIR) -p $(KEYDIR)

# noising: $(OBJDIR)/noising.o $(OBJDIR)/error.o $(OBJDIR)/png_io.o $(OBJDIR)/utils.o
# 	@echo "Link $< ..."
# 	@$(CC) -o $@ $(OBJDIR)/error.o $(OBJDIR)/png_io.o $(OBJDIR)/utils.o $(OBJDIR)/noising.o $(LIBS)
 
configgen: $(OBJDIR)/config_file_generator.o $(OBJDIR)/utils.o
	@echo "Link $< ..."
	@$(CC) -o $@ $(OBJDIR)/config_file_generator.o  $(OBJDIR)/utils.o $(LIBS)
 
keygen: $(OBJDIR)/key_generator.o $(OBJDIR)/utils.o
	@echo "Link $< ..."
	@$(CC) -o $@ $(OBJDIR)/key_generator.o  $(OBJDIR)/utils.o $(LIBS)
 
otp: $(OBJDIR)/main.o $(OBJDIR)/otp.o $(OBJDIR)/utils.o
	@echo "Link $< ..."
	@$(CC) -o $@ $(OBJDIR)/otp.o  $(OBJDIR)/utils.o $(OBJDIR)/main.o $(LIBS)
       
$(OBJDIR)/utils.o: $(SRCDIR)/utils.c
	@echo "Compile $< ..."
	@$(CC) -c $(CFLAGS) -o $@ $<
       
$(OBJDIR)/config_file_generator.o: $(SRCDIR)/config_file_generator.c
	@echo "Compile $< ..."
	@$(CC) -c $(CFLAGS) -o $@ $<
       
$(OBJDIR)/key_generator.o: $(SRCDIR)/key_generator.c
	@echo "Compile $< ..."
	@$(CC) -c $(CFLAGS) -o $@ $<
       
$(OBJDIR)/otp.o: $(SRCDIR)/otp.c
	@echo "Compile $< ..."
	@$(CC) -c $(CFLAGS) -o $@ $<
       
$(OBJDIR)/main.o: $(SRCDIR)/main.c
	@echo "Compile $< ..."
	@$(CC) -c $(CFLAGS) -o $@ $<
 
clean:
	rm -r configgen keygen otp $(OBJDIR)

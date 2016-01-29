CC      = clang
BIN     = config_gen key_gen otp
DEFDIRS = objdir logdir
SRC     = main.c config_file_generator.c key_generator.c otp.c
LIBS    = -lm
CFLAGS  = -g3 -Wall
MKDIR   = mkdir
EXT     = c
SRCDIR  = src
OBJDIR  = obj
LOGDIR  = log
OBJ     := $(subst .$(EXT),.o,$(SRC))
OBJ     := $(addprefix $(OBJDIR)/, $(OBJ))
 
all: $(DEFDIRS) $(BIN)

objdir:
	$(MKDIR) -p $(OBJDIR)

logdir:
	$(MKDIR) -p $(LOGDIR)

# noising: $(OBJDIR)/noising.o $(OBJDIR)/error.o $(OBJDIR)/png_io.o $(OBJDIR)/utils.o
# 	@echo "Link $< ..."
# 	@$(CC) -o $@ $(OBJDIR)/error.o $(OBJDIR)/png_io.o $(OBJDIR)/utils.o $(OBJDIR)/noising.o $(LIBS)
 
config_gen: $(OBJDIR)/config_file_generator.o
	@echo "Link $< ..."
	@$(CC) -o $(OBJDIR)/config_file_generator.o $(LIBS)
 
key_gen: $(OBJDIR)/key_generator.o
	@echo "Link $< ..."
	@$(CC) -o $(OBJDIR)/key_generator.o $(LIBS)
 
otp: $(OBJDIR)/main.o $(OBJDIR)/otp.o
	@echo "Link $< ..."
	@$(CC) -o $@ $(OBJDIR)/otp.o $(OBJDIR)/main.o $(LIBS)
       
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
	rm -r config_gen key_gen otp $(OBJDIR)

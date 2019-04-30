CC = msp430-gcc
CFLAGS = -mmcu=msp430g2553 -std=gnu99 \
	 -Os

CSRC = board.c \
       delay.c \
       i2c.c \
       lcd.c \
       temp.c \
       main.c
COBJ = $(patsubst %.c, %.o, $(CSRC))

ELF = main.elf

all: $(ELF)

clean:
	@echo "  CLEAN"
	@rm -f $(ELF) $(COBJ)

$(ELF): $(COBJ)
	@echo "  CC    " $@
	@$(CC) $(CFLAGS) $(COBJ) -o $(ELF)

%.o: %.c
	@echo "  CC    " $<
	@$(CC) $(CFLAGS) -c $< -o $@


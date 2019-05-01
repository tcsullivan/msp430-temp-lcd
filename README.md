# msp430-temp-lcd

This is a project for the MSP430 processor, that uses an LCD to print readings
from a TMP006 infrared temperature sensor. The specific processor used for this
project is the MSP430G2553.

### Compiling

The code may be compiled through the Makefile by simply running `make`.

Code Composer Studio may be used as well: create an empty project for the
MSP430G2553, selecting the GNU compiler, then copy all header and source files
into that project's directory.

### Uploading

Upload the program to the MSP430 either with `mspdebug` or Code Composer Studio.


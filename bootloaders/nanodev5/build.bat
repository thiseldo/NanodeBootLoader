make 
avrdude -c usbtiny -p m328p -U flash:w:optiboot_nanodev5.hex -U lfuse:w:0xff:m -U hfuse:w:0xda:m -U efuse:w:0x05:m 
avrdude -c usbtiny -p m328p -U lfuse:w:0xff:m -U hfuse:w:0xda:m -U efuse:w:0x05:m 


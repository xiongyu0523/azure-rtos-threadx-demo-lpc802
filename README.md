# azure-rtos-threadx-demo-lpc802

This project is to demostrate porting Azure RTOS ThreadX on a tiny MCU LPC802, which has only 16KB Flash and 2KB RAM. Though running a RTOS on such a very resource constrained MCU is not very common, the primary goal here is to showcase how small a basic RTOS can be. 

> Generally a MCU with 64KB Flash and 8KB RAM will be a good fit for using a RTOS based application.  


The demo is toggling user LED at 1Hz. With release configuration in MCUXpresso IDE, it still has ~80% spare space for code and ~50% RAM available for variables. The Azure RTOS ThreadX kernel itself only uses **2188** bytes FLASH and **332** bytes RAM. 

Here is the memory map summary:

```
Memory region         Used Size  Region Size  %age Used
PROGRAM_FLASH:        3572 B     16256 B      21.97%
BOOT_FLASH:           0 GB       128 B        0.00%
SRAM:                 920 B      2016 B       45.63%
IAP_SRAM:             0 GB       32 B         0.00%
```

#NOTES

##Symbol Creation

###複製一個相近的元件來改為需用的元件

需要 PHILIPS P89C61X2BA。這一顆與 Microcontrollers (misc)/AT89C51\_PLCC.sym 很相近。故打開 /usr/share/gEDA/sym/micro/AT89C51_PLCC.sym 來修改。

###
1. Use the 'line', 'box', 'circle', and 'arc' tools in the Add menu to draw a symbol. The only allowed color is 'Graphic' (green). 
2. Select Add->Pin, or hit A P. Draw from the end of a pin to one of the edges of a symbol. A '0' and the word 'unknown' should pop up near your new pin. Note the direction to draw pins. Click on the selection tool, and select the pin to edit. Select Edit->Edit…, or hit E E (or right click, and hit Edit…). The Add Attribute section of this dialog does not reflect what has been selected, as it is only meant for addition, not for editing. 

pintype values are: in, out, io, oc, oe, pas, tp, tri, clk, pwr.
pinseq: This number dictates the order pins are looked at on this symbol in spice, gnetlist, and other tools. For our first pin, start this sequence number at '1', incrementing it on each new pin.
pinnumber: This is the number of the pin, on the package of the item you are drawing a symbol for. pinnumber values can be alphanumeric (i.e. like E or C).

Reference: 
1. gEDA/gaf Symbol Creation [link](http://wiki.geda-project.org/geda:gschem_symbol_creation)

##Configuring gschem

Add a configuration file "gafrc" in the working directory. The gafrc file writes as the following:

(component-library-search "/home/joel/workspace/notes/gEDA/sym")

Run gschem from that directory in a console.

Reference: 
1. [link](http://wiki.geda-project.org/geda:gschem_ug:config)

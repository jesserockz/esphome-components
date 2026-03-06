CSN-A2User manual 1/70

CSN-A2 Micro panel printer's
User Manual

Version4.0

---

CSN-A2User manual 2/70

# Content

CAUTIONS...........................................................................................................................3
1 General Specifications..........................................................................................................4
2 Features..............................................................................................................................4
3 Printer outline pictures and dimension...................................................................................5
3.1 Outline pictures.........................................................................................................5
3.2 Dimension.................................................................................................................5
4 Operation specifications and print test...................................................................................6
4.1 Operation specifications.............................................................................................6
4.2 Printing test...............................................................................................................7
5 Connector...........................................................................................................................7
5.1 TTLor RS232 connector............................................................................................7
5.2 Parallel connector......................................................................................................8
5.3 USB connector..........................................................................................................9
5.3.1 J3 Power supply connector...............................................................................9
5.3.2 CN4 TTL connector.........................................................................................9
5.3.3 CN3 USB /MINID connector............................................................................9
5.3.4 J2 Integrated Keyboard functions:...................................................................10
6 printer functions................................................................................................................10
7 Using attention..................................................................................................................11
8 ESC/POS Printing Command Set........................................................................................11
8.1 Command list..........................................................................................................11
8.2 Command Detail......................................................................................................13
8.2.1 Print Commands............................................................................................13
8.2.2 Line spacing setting commands.......................................................................16
8.2.3 Character Setting Commands..........................................................................18
8.2.4 Bit Image Command......................................................................................29
8.2.5 Init command................................................................................................40
8.2.6 Status Command............................................................................................40
8.2.7 Bar Code Command.......................................................................................42
8.2.8 Miscellaneous Function Command..................................................................47
8.2.9 New commands.............................................................................................49
Appendix 1 Code page..........................................................................................................54
Appendix 2 International characterset:..................................................................................69

---

CSN-A2User manual 3/70

CAUTIONS

1. This document shall apply only to the product(s) identified herein.

2. No part of this document may be reproduced, stored in a retrieval system, or
transmitted in any form or by any means, electronic, mechanical, photocopying, recording,
or otherwise, without the prior written permission of Kashino Technology Limited.

3. The contents of this document are subject to change without notice. Please contact us
for the latest information.

4. While every precaution has been taken in the preparation of this document, Kashino
Technology Limited assumes no responsibility for errors or omissions.

5. Neither is any liability assumed for damages resulting from the use of the information
contained herein.

6.Kashino Technology Limited shall be not liable to the purchaser of this product or third
parties for damages, losses, costs, or expenses incurred by the purchaser or third parties
as a result of: accident, misuse, or abuse of this product or unauthorized modifications,
repairs, or alterations to this product, or failure to strictly comply with Kashino Technology
Limited 's operating and maintenance instructions.

7. Kashino Technology Limited shall not be liable against any damages or problems
arising from the use of any options or any consumable products other than those
designated as Original Kashino Products or Kashino Approved Products by Kashino
Technology Limited.

---

CSN-A2User manual 4/70

1GeneralSpecifications

ITEM SPECIFICATION
Printmethod thermal direct line printing
Paper loading method easy paper loading
Paper width 58mm
Print width 48mm
Resolution ration 8dots/mm(384dots/line)
Life of printing head 50km
Printing speed 60mm/sec.;Max.:80MM/sec.(voltage 8.5V）
Character size ANK:9x17,12×24; GBK:24×24
Chinesecharacter fonts GB18030: 12x24or24x24dots
Outline dimension（WxHxD mm) 111x65x57
Installation(WxH mm): 103x57
Embedded depth 50 mm
Paper roll specification (width:58mm,Max. diameter:39mm)
Interface RS232C/TTL/parallel/USB
Input power DC5-9V or 12V
Operating temperature 5°C~50°C
Storage temperature -20°C~60°C
Operating humidity 10°C~80°C
Storage humidity 10°C~90°C

2Features

 Low-noise direct thermal printing method
 Printer control panel built-in ANK character or GB18030 Chinese character,
thoroughly remove the uncommon words of anguish
 Fast printing speed, low noise
 Can support Max.39mm(diameter) paper roll, which is biggest paper roll of the same
models.
 Optional serial interface (RS232C/TTL)/parallel/USB port
 Rich of graphics/ curves / characters print function
 Easy paper loading structure
 Support 5V-9V/12V wide power voltage

---

CSN-A2User manual 5/70

3Printer outline pictures and dimension

3.1Outline pictures

 Outline dimension:111W*65D*57Hmm
 Front panel Size:103 W*57Hmm
 Embedded depth: 50mm
 Max diameter of paper roll:39 mm

3.2Dimension

Outline is as follows:

---

CSN-A2User manual 6/70

The installation method:
Put the panel printerinto the front of the deviceas per Fig.1and Fig.2,and then install
fixedblock and screwing as per Fig.3
Note: have 1 to 6mm variation in thickness.

4Operation specifications and print test

4.1Operation specifications

A.the instruction of indicator light
Power on, the indicator light will flash2times, interval 1sec, it say the startness isOK, and

---

CSN-A2User manual 7/70

then theinstructions forthe indicator light as below:
 Blink once: Work well(Stay lit for some customized board)
 Blink twice: Printer mechanism is ununited or temperature is too low.
 Blink three times: No paper is detected
 Blinkfour times: Cutter is wrong (Just for board with cutter)
 Blinkfive times: Printer mechanism is overheat
 Blink six times: Roller didn't press well. (Just for board with roller detection.
 Blink ten times: Flash device is wrongfor the board

B.key instruction
The key on the panel printer is FEED key

C.how to change new paper roller
Before changing,turn up the switch,and put into the paper roller

4.2Printing test

Poweron, press the [feed]key, for a while, relax the key, it will print out one testing
sample.
Power on, press key per time, it will feed the paper.

5Connector

The user hasoption of RS232,TTL, USBand LPT interface.

5.1 TTL or RS232 connector

The define of the PIN of the interface for RS232,TTL as thefollowing:

Pin Signal name
number
1 GND(Ground)
2 NULL

---

CSN-A2User manual 8/70

3 VH(input voltage，
5V-9V)
4 GND(Ground)
5 RXD(receive data)
6 TXD(send data)

5.2Parallel connector

The define of the Pin of LPT interface asbelow:
1 GND， Ground
2 VH， input voltage，5V-9V
3 +5V， input voltage (generalcondition,only use +5Vm VH not input )
4 thedefinitionof the Pin of LPT interface as below:
1. STROBE
2-9. DATA0-DATA7
10. ACKNLG
11. BUSY
12. PE paper out
13. SLCT selection
14. AUTO FEED auto change line
15. ERROR
16. INIT
17. SLCT IN
18-26. GND

---

CSN-A2User manual 9/70

5.3USBconnector

m m
m m
0 0
0 0
. .
7 0
3 3

m
m
0
0
.
6

5.3.1J3Powersupply connector

Pin number Signal name
1 VH
2 GND

5.3.2CN4TTL connector

Pin number Signal name
1 +3.3V
2 Transmit data (TXD, printer output)
3 Receive data (RXD, printer input)
4 GND

5.3.3CN3USB /MINIDconnector

Pin number Signal name
1 VUSB
2 D-
3 D+
4 NC
5 GND

---

CSN-A2User manual 10/70

5.3.4J2Integrated Keyboard functions:

Pin number Signal name
1 LED
2 +3.3V
3 +3.3V
4 KEY_FEED

6 printer functions

CN1 FPC30/1.0

Pin number Signal name Function
1 PHK Cathode of photo interruptor
2 VSEN Photo-sensor power
3 PHE Emittor for photo interruptor
4 MT/B Step motor excitation signal
--
5 MT/B Step motor excitation signal
6 MT/A Step motor excitation signal
--
7 MT/A Step motor excitation signal
8 VH Head driver power
9 VH Head driver power
10 DI Data input
11 CLK Aynchronous clock for communication
12 GND Ground power supply for thermal head
13 GND Ground power supply for thermal head
14 STB6 Thermal head energizing control signal
15 STB5 Thermal head energizing control signal
16 STB4 Thermal head energizing control signal
17 VDD Logic power
18 TM Thermally sensitive resistor input terminal 1
19 TM Thermally sensitive resistor input terminal 2
20 STB3 Thermal head energizing control signal
21 STB2 Thermal head energizing control signal
22 STB1 Thermal head energizing control signal
23 GND Ground power supply for thermal head
24 GND Ground power supply for thermal head
25 \LAT Data Latch
26 DO Data output
27 VH Power supply for thermal head
28 VH Power supply for thermal head
29 N.C(101)SW1(103) Platen release switch
30 N.C(101)SW2(103) Platen release switch

---

CSN-A2User manual 11/70

7 Using attention

7.1Please notice, the ESD wrist ring and the humidity manufatures ETC, when using the
printer, to protect the inner elctrontic parts of the printer from the damage ofESD, because
the TPH of the Printer and photoelectric sensor are ESD Sensitive parts.

7.2For protecting plastic shaft, don’t smear any oil or others on the rubber parts.

7.3 Don’t touch the TPH, TPH having the palm oil, will induce the usage of the printer.If
any oil or others in the TPH, plsusing an alcohol cotton stick clean the area between
plastic shaft and printer head at once.PS,Don’t strike the TPH.

7.4 Due to the printer is easy-paper structure,you need pick up the rubber stick only push
the rubber stick.So,if the paper jam,push harder will cause the rubber stick gearwheel
damaged.so pls don’t push the paper harder, pls do open the cover and re-fill the paper

7.5 The temperature of the TPH protection must be below 65℃, if you print
continously,Because the exterior of the temperature of the IC protection & motor can’t not
over 90℃ to protect the motor thread ring.

7.6 Plsuse the good quality paper, becausethe sensetive of the paperwill infuenceprint
effect,meanwhile,rough paper will incease the excessive wear to the printer head, and
reduce the life of the printer.

8ESC/POS PrintingCommandSet

8.1 Commandlist

Type Command Name
LF Printand line feed
CR Print and carriage return
HT Horizontal tab
FF Print the data in buffer
Print Commands
ESC D Set horizontal tab positions
ESC J n Print and Feed n dots paper
ESC d n Print and Feed n lines
ESC = n Set peripheral device
ESC 2 Select default line spacing
ESC 3 n Set line spacing
Line spacingsetting
ESC a n Select justification
Commands
GS L nL nH Set left margin
ESC $ nL nH Set absolute print position

---

CSN-A2User manual 12/70

ESC B n SetLeft Space
ESC ! n Select print mode(s)
GS ! n Select character size
GS B n Turnwhite/black reverse printing mode
ESC V n Turn 90°clockwise rotation mode on/off
ESC G n Turn on/off double-strike mode
ESC E n Turn emphasized mode on/off
ESC SP n Set right-side character spacing
ESC SO n Select Double Width mode
ESC DC4 n Disable Double Width mode
Character Setting
ESC { n Turnson/off upside-down printing mode
Commands
ESC-n Set the underline dots(0,1,2)
ESC % n Select/Cancel user-defined characters
FS & Select Kanji character mode
FS . Cancel Kanji character mode
FS ! n Set print mode for Kanji characters
ESC & Define user-defined characters
ESC ? n Cancel user-defined characters
ESC R n Select and international character set
ESC t n Select character code table
ESC * Select bit-image mode
GS * Define downloaded bit image
GS / n Print downloaded bit image
GS v Print raster bit image
Bit Image
DC2 * Print the bitmap
Commands
DC2 V Print MSB bitmap
DC2 v Print LSB bitmap
FS p n m Print NV bitmap
FS q n Define NV bitmap
Init Commands ESC @ Initialize printer
GS r n Transmit status
GS a n Enable/Disable Automatic Status Back(ASB)
Status Commands
ESC v n Transmit paper sensor status
ESC un Transmit peripheral device status (For drawer)
GS Hn Select printing position for HRI characters
GS hn Set bar code height
Bar Code
GS wn Set bar code width
Commands
GS k Print bar code
GS xn Set barcode printing left space
ESC 7 n1 n2 n3 Setting Control Parameter Command
Miscellaneous ESC 8 n1 n2 Select sleeping parameter
function commands ESC 9 n Select Chinese code format
DC2 # n Set printing density

---

CSN-A2User manual 13/70

DC2 T Printing test page
FS t n Select Time out (for CB105B)
DC2E Feed Paper to Mark
DC2 m dlL lH Set Mark paper length
ESC C n Set BM Max (For BM)
Feed marked paper to print starting position
GS FF
(For BM)
ESC i Cut Paper (For cut)
ESC m Partial Cut Paper (For cut)
New commands GS V Select cut mode and cut paper (For cut)
ESC pm Generate pulse (For drawer)
ESC c 5 Enable/disable panel buttons (For button)
GS ( F Set adjustment values(s) (For 701BM)
FS C Start receive buffer count (For cb65c)
FS S Send receive buffer count(For cb65c)
FS s save print parameter (for XBLY)
FS d Load default leaving factory set (for XBLY)

8.2CommandDetail

8.2.1PrintCommands

LF

[Name] Print and line feed
[Format] ASCII: LF
Decimal: 10
Hexadecimal: 0A
[Description] Prints the data in the printbuffer and feeds one line, based on thecurrent
line spacing.
[Note] This command sets the print position to the beginning of the line.
[Reference] ESC 2,ESC 3

CR

[Name] Print and carriage return
[Format] ASCII: CR
Decimal: 13
Hexadecimal: 0D
[Description] When automatic line feed is enabled, this command functions thesame
asLF; when automatic line feed is disabled, this command isignored.
[Notes]  This command line feed is ignored with a serial interface model.
 Sets the print starting position to the beginning of the line.
[Reference] LF

---

CSN-A2User manual 14/70

HT

[Name] Horizontal tab
[Format] ASCII: HT
Decimal: 9
Hexadecimal: 09
[Description] Moves the print position to the next horizontal tab position.
[Notes]  This command is ignored unless the next horizontal tab position has
been set.
 If the next horizontal tab position exceeds the printing area, the
printersets the printing position to [printing area width+1].
 Horizontal tab positions are set withESC D.
 If this command is received when the printingposition is at [printing
area width+1], the printer executes print buffer-full printing of the
current line and horizontal tab processing from the beginning of the
next line.
[Reference] ESC D

FF

[Name] Print the data in buffer and locate to the nextblack mark
[Format] ASCII: FF
Decimal: 12
Hexadecimal: 0c
[Description]  Print the data in the buffer.
 Locate to the black mark.
[Note] Only board with black mark function support this command.

ESCDn1...nk NUL

[Name] Set horizontal tab positions
[Format] ASCII: ESC Dn1...nk NUL
Decimal: 27 68 n1…nk 00
Hexadecimal: 1B 44 n1…nk 00
[Range] 1≤n≤255
0≤k≤32
[Description] Set horizontal tab positions.
 n specifies the column number for setting a horizontal tab position
from thebeginning of the line.
 k indicates the total number of horizontal tab positions to be set.
[Note]  The horizontal tab position is stored as a value of [character width×n]
measured from the beginning of the line. The character width
includes the right-side character spacing, and double-width

---

CSN-A2User manual 15/70

characters are set with twice thewidth of normal characters.
 This command cancels the previous horizontal tab settings.
 When setting n = 8, the print position is moved to column 9 by
sendingHT.
 Up to 32 tab positions (k=32) can be set.Data exceeding 32 tab
positions isprocessed as normal data.
 Transmit [n]k in ascending order and place a NUL code 0 at the end.
 When [n]k is less than or equal to the preceding value [n]k-1, tab
setting is finished and the following data is processed as normal
data.
 ESC D NULcancels all horizontal tab positions.
 The previously specified horizontal tab positions do not change,
even if thecharacter width changes.
 The character width is memorized for each standard mode.
[Default] The default tab positionsare at intervals of 8 characters (columns 9, 17,
25...) forFont A (12×24).
[Reference] HT

ESC J n

[Name] Print and feed paper
[Format] ASCII: ESC J n
Decimal: 27 74 n
Hexadecimal: 1B 4A n
[Range] 0≤n≤255
[Description] Prints the data in the print buffer and feeds the paper [n×0.125 mm
(0.0049”)].
[Notes]  After printing is completed, this command sets the print starting
position to thebeginning of the line.
 The paper feed amount set by this command does not affect the
values set byESC2orESC 3.
 In standard mode, the printer uses the vertical motion unit (y).

ESC d n

[Name] Print and feed n lines
[Format] ASCII: ESC d n
Decimal: 27 100 n
Hexadecimal: 1B 64 n
[Range] 0≤n≤255
[Description] Print the data in the buffer and feed paper n lines.

---

CSN-A2User manual 16/70

[Notes]  This command sets the print starting position to the beginning of the
line.
 This command does not affect the line spacing set byESC 2orESC
3.
 The maximum paper feed amount is 1016 mm (40 inches). If the
paper feed amount (n×line spacing) of more than 1016 mm (40
inches) is specified, theprinter feeds the paper only 1016 mm (40
inches).
[Reference] ESC 2,ESC 3

ESC = n

[Name] Set peripheral device
ASCII: ESC = n
[Format] Decimal: 27 61 n
Hexadecimal: 1B 3d n
[Description] Set peripheral device:
Bit Off/On Hex Decimal Function
0 Off 00 0 Printer offline,not receive print data.
On 01 1 Printer online,receiveprint data.
1-7 - - - Undefined.

8.2.2 Linespacing setting commands

ESC 2

[Name] Select default line spacing
[Format] ASCII: ESC 2
Decimal: 27 50
Hexadecimal: 1B 32
[Description] Selects 3.75 mm (30×0.125 mm) line spacing.
[Note] The line spacing can be set independently in standard mode.
[Reference] ESC 3n

ESC 3 n

[Name] Set line spacing
[Format] ASCII: ESC 3 n
Decimal: 27 51 n
Hexadecimal: 1B 33 n
[Range] 0≤n≤255
[Description] Sets the line spacing to [n×0.125 mm].
[Note]  The line spacing can be set independently in standard mode.
 In standard mode, the vertical motion unit (y) is used.

---

CSN-A2User manual 17/70

[Default] n=30
[Reference] ESC 2

ESC a n

[Name] Select justification
[Format] ASCII: ESC a n
Decimal: 27 97 n
Hexadecimal: 1B 61 n
[Range] 0≤n≤2, 48≤n≤50
[Description] Aligns all the data in one line to the specified position.
n selects the justification as follows:
n Justification
0,48 Left justification
1,49 Centering
2, 50 Right justification
[Note]  The command is enabled only when processed at the beginning of
the line instandard mode.
 This command executes justification in the printing area.
 This command justifies the space area according toHT,ESC$.
[Default] n=0
[Example]
Left justification Centering Right justification
ABC ABC ABC
ABCD ABCD ABCD
ABCDE ABCDE ABCDE

GS L nL nH

[Name] Set leftmargin
[Format] ASCII: GS L nL nH
Decimal: 29 76 nL nH
Hexadecimal: 1D 4c nL nH
[Range] 0≤nL≤255
0≤nH≤255
[Description] Sets the left margin using nL and nH.
The left margin is set to [(nL+nH×256)×0.125 mm].

---

CSN-A2User manual 18/70

[Note]  This command is effective only when processed at the beginning of
the line instandard mode.
 If the setting exceeds the printable area, the maximum value of the
printablearea is used.
[Default] nL=0, nH=0

ESC B n

[Name] Set left blank char numbers
[Format] ASCII: ESC B n
Decimal: 27 66 n
Hexadecimal: 1B 42 n
[Range] Default is 0
0 ≤ m ≤ 47

ESC $nLnH

[Name] Setabsolute print positions
[Format] ASCII: ESC $nLnH
Decimal: 27 36nLnH
Hexadecimal: 1B 24 nLnH
[Range] 0≤nL≤255
0≤nH≤255
[Description] Set the distance from the beginning of the line to the position atwhich
subsequent are to be printed.
The distance from the beginning of the line to the print positionis[(nL+nH
×256)×0.125 mm]
[Note]  Settings outside the specified printable area are ignored.
 In standard mode, the horizontal motion unit (x) is used.
[Reference] ESC\,GS $,GS\

8.2.3 CharacterSetting Commands

ESC ! n

[Name] Select print mode
[Format] ASCII: ESC ! n
Decimal: 27 33 n
Hexadecimal: 1B 21 n
[Range] 0≤n≤255
[Description] Selects print mode(s) using n as follows:
Bit Off/On Hex Decimal Function
0 Off 00 0 Character Font A (12×24).

---

CSN-A2User manual 19/70

On 01 1 Character Font B (9×17).
1 Off 00 0 Turn white/black reverse printing mode not selected.
On 02 2 Turn white/black reverse printing mode selected.
2 Off 00 0 Turn on/off upside-down printing mode not selected.
On 04 4 Turn on/off upside-down printing mode selected.
3 Off 00 0 Emphasized mode not selected.
On 08 8 Emphasized mode selected.
4 Off 00 0 Double-height mode not selected.
On 10 16 Double-height mode selected.
5 Off 00 0 Double-width mode not selected.
On 20 32 Double-width mode selected.
6 Off 00 0 Turn Deleteline mode on/off not selected.
On 40 64 Turn Deleteline mode on/off selected.
7 - - - Undefined.

GS ! n

[Name] Select character size
[Format] ASCII: GS ! n
Decimal: 29 33 n
Hexadecimal: 1D 21 n
[Range] 0≤n≤255
(1≤vertical number of times≤8, 1≤horizontal number of times≤8)
[Description] Selects the character height using bits 0 to 2 and selects the character
width usingbits 4 to 7, as follows:
Bit Off/On Hex Decimal Function
0 Character height selection. See Table 2.
1
2
3
4 Character width selection. See Table 1.
5
6
7

Table 1 Table 2
Character Width Selection Character Height Selection
Hex Decimal Width Hex Decimal Width
00 0 1(normal) 00 0 1(normal)
10 16 2(double-width) 01 1 2(double-height)
20 32 3 02 2 3
30 48 4 03 3 4
40 64 5 04 4 5

---

CSN-A2User manual 20/70

50 80 6 05 5 6
60 96 7 06 6 7
70 112 8 07 7 8
[Note]  This command is effective for all characters (alphanumeric and
Kanji), exceptfor HRI characters.
 If n is outside the defined range, this command is ignored.
 In standard mode, the vertical direction is the paper feed direction,
and the horizontal direction is perpendicular to the paper feed
direction. However, when character orientation changes in 90°
clockwise-rotation mode, the relationship between vertical and
horizontal directions isreversed.
 When characters are enlarged with different sizes on one line, all the
characters on the line are aligned at the baseline.
 TheESC !command can also turn double-width and double-height
modes onor off. However, the setting of the last receivedcommand
is effective.
[Default] n=0
[Reference] ESC !

GS Bn

[Name] Turn white/black reverse printing mode
[Format] ASCII: GSBn
Decimal: 2966n
Hexadecimal: 1D42n
[Range] 0≤n≤255
[Description] Turns on or off white/black reverse printing mode.
 When the LSB of n is 0, white/black reverse mode is turned off.
 When the LSB of n is 1, white/black reverse mode is turned on.
[Note]  Only the lowest bit of n is valid.
 This commandis available for built-in characters and user-defined
characters.
 When white/black reverse printing mode is on, it also applies to
characterspacing set byESC SP.
 This command does not affect bit images, user-defined bit images,
bar codes,HRI characters,and spacing skipped byHT,ESC $.
 This command does not affect the space between lines.
 White/black reverse mode has a higher priority than underline mode.
Even ifunderline mode is on, it is disabled (but not canceled) when
white/black reversemode is selected.
[Default] n=0

---

CSN-A2User manual 21/70

ESC V n

[Name] Turn90°clockwise rotation mode on/off
[Format] ASCII: ESCVn
Decimal: 2786n
Hexadecimal: 1B56n
[Range] 0≤n≤1, 48≤n≤49
[Description] Turns 90°clockwise rotation mode on/off.
n is used as follows:
n Function
0,48 Turns off 90°clockwise rotation mode
1,49 Turns on 90°clockwise rotation mode
[Note]  This command affects printing in standard mode. However, the
setting isalways effective.
 When underline mode is turned on, the printer does not underline
90°clockwise-rotated characters.
 Double-width and double-height commands in 90° rotation mode
enlargecharacters in the opposite directions from double-height and
double-widthcommands in normal mode.
[Default] n=0
[Reference] ESC !,ESC

ESC G n

[Name] Turn on/off double-strike mode
[Format] ASCII: ESCGn
Decimal: 2771n
Hexadecimal: 1B47n
[Range] 0≤n≤255
[Description] Turns double-strike mode on or off.
 When the LSB of n is 0, double-strike mode is turned off.
 When the LSB of n is 1, double-strike mode is turned on.
[Note]  Only the lowest bit of n is enabled.
 Printer output is the same in double-strike mode and in emphasized
mode.
[Default] n=0
[Reference] ESC En

ESC E n

[Name] Turn emphasized mode on/off
[Format] ASCII: ESC E n
Decimal: 27 69 n

---

CSN-A2User manual 22/70

Hexadecimal: 1B 45 n
[Range] 0≤n≤255
[Description] Turns emphasized mode on or off
 When the LSB of n is 0, emphasized mode is turned off.
 When the LSB of n is 1, emphasized mode is turned on.
[Note]  Only the least significant bit of n is enabled.
 This command andESC !turn on and off emphasized mode in the
same way.Be careful when this command is used withESC!
[Default] n=0
[Reference] ESC !

ESC SP n

[Name] Set right-side character spacing
[Format] ASCII: ESC SP n
Decimal: 27 32 n
Hexadecimal: 1B 20 n
[Range] 0≤n≤255
[Description] Sets the character spacing for the right side of the character to [n×0.125
mm (n×0.0049”)].
[Note]  The right-side character spacing for double-width mode is twice the
normal value. When characters are enlarged, the right-side character
spacing is n times normal value.
 Thiscommand does not affect the setting of Kanji characters
 This command sets values independently in standard mode.
[Default] n=0

ESC SOn

[Name] Select Double Width mode
[Format] ASCII: ESC SOn
Decimal: 27 14n
Hexadecimal: 1B 0E n
[Description] Select Double Width mode
To turn double width off, useLForDC4command.

ESC DC4n

[Name] Disable Double Width mode
[Format] ASCII: ESC DC4n
Decimal: 27 20n
Hexadecimal: 1B14n
[Description] Disable Double Width mode

---

CSN-A2User manual 23/70

ESC {n

[Name] Turns on/off upside-down printing mode
[Format] ASCII: ESC { n
Decimal: 27 123 n
Hexadecimal: 1B 7B n
[Range] 0≤n≤255
[Description] Turns upside-down printing mode on or off.
 When the LSB of n is 0, upside-down printing mode is turned off.
 When theLSBof n is 1, upside-down printing mode is turned on.
[Note]  Only the lowest bit of n is valid.
 This command is enabled only when processed at the beginning of a
line instandard mode.
 In upside-down printing mode, the printer rotates the line to be
printed by 180°and then prints it.
[Default] n=0
[Example]

ESC-n

[Name] Turn underline mode on/off
[Format] ASCII: ESC-n
Decimal: 27 45 n
Hexadecimal: 1B 2D n
[Range] 0≤n≤2, 48≤n≤50
[Description] Turns underline mode on or off, based on the following values n：
n Function
0, 48 Turns off underline mode
1, 49 Turns on underline mode (1 dot thick)
2, 50 Turns on underline mode (2 dots thick)
[Note]  The printer can underline all characters (including right-side
character spacing),but cannot underline the space set byHT.

---

CSN-A2User manual 24/70

 The printer cannot underline90°clockwise rotated characters and
white/blackinverted characters.
 When underline mode is turned off by setting thevalue of n to 0 or
48, thefollowing data is not underlined, and the underline thickness
set before the mode is turned off does not change. The default
underline thickness is 1 dot.
 Changing the character size does not affect the current underline
thickness.
 Underline mode can also be turned on or off by usingESC !.Note,
however,that the last received command is effective.
[Default] n = 0
[Reference] ESC!

ESC % n

[Name] Enable/Disable User-defined Characters
[Format] ASCII: ESC % n
Decimal: 27 37 n
Hexadecimal: 1B 25 n
[Range] 0≤n≤255
[Description] Selects or cancels the user-defined character set.
 When the LSB of n is 0, the user-defined character set is canceled.
 When the LSB of n is 1, the user-defined character set is selected.
[Note]  When the user-defined character set is canceled, the built-in
character set is automatically selected.
 n is available only for the least significant bit.
[Default] n=0
[Reference] ESC &,ESC ?

FS &

[Name] Select Kanji character mode
[Format] ASCII: FS &
Decimal: 28 38
Hexadecimal: 1C 26
[Description] Selects Kanji character mode
[Note] ForKanji model:
 When the Kanji character mode is selected, the printer processes all
Kanjicodeas two bytes each.
 Kanji codes are processed in the order of the first byte and second
byte.
 Kanjicharacter mode is not selected when the power is turned on.
[Reference] FS .

---

CSN-A2User manual 25/70

FS.

[Name] Cancel Kanji character mode
[Format] ASCII: FS .
Decimal: 28 46
Hexadecimal: 1C 2E
[Description] Cancels Kanji character mode.
[Note] For Kanji model:
 When the Kanji character mode is not selected, all character codes
areprocessed one byte at a time as ASCII code.
 Kanji character mode is not selected when the power is turned on.
[Reference] FS &

FS !n

[Name] Set print mode(s) for Kanji characters
[Format] ASCII: FS ! n
Decimal: 28 33 n
Hexadecimal: 1C 21 n
[Range] 0≤n≤255
[Description] Sets the print mode for Kanji characters, using n as follows:
Bit Off/On Hex Decimal Function
0 － － － Undefined.
1 － － － Undefined.
2 Off 00 0 Double-width mode is OFF.
On 04 4 Double-width mode is ON.
3 Off 00 0 Double-height mode is OFF.
On 08 Double-height mode is ON.
4 － － － Undefined.
5 － － － Undefined.
6 － － － Undefined.
7 Off 00 0 Underline mode is OFF.
On 80 128 Underline modeis ON.
[Note]  When both double-width and double-height modes are set (including
right-andleft-side character spacing), quadruple-size characters are
printed.
 The printer can underline all characters (including right-and left-side
character spacing), but cannot underline the space set byHTand
90° clockwise-rotatedcharacters.
 When some of the characters in a line are double or more height, all
thecharacters on the line are aligned at the baseline.
 It is possible to emphasize the Kanji character usingGS !; the setting
of the last received command is effective.

---

CSN-A2User manual 26/70

[Default] n=0
[Reference] GS !

ESC & y c1 c2 [x1 d1...d(y×x1)]...[xk d1...d(y×xk)]

[Name] Define user-defined characters
[Format] ASCII: ESC&yc1c2[x1 d1...d(y×x1)]...[xk d1...d(y×xk)]
Decimal: 2738yc1c2 [x1 d1...d(y×x1)]...[xk d1...d(y×xk)]
Hexadecimal: 1B26yc1c2 [x1 d1...d(y×x1)]...[xk d1...d(y×xk)]
[Range] y=3
32≤c1≤c2≤126
0≤x≤12 (when Font A (12×24) is selected)
0≤d1…d(y×xk)≤255
[Description] Defines user-defined characters.
 y specifies the number of bytes in the vertical direction.
 c1 specifies the beginning character code for the definition, and c2
specifies the final code.
 x specifies the number of dots in the horizontal direction.
[Note]  The allowable character code range is from ASCII code <20>H to
<7E>H (95characters).
 It is possible to define multiple characters for consecutive character
codes.If only one character is desired, use c1=c2.
 d is the dot data for the characters. The dot pattern is in the horizontal
directionfrom the left side. Any remaining dots on the right side are
blank.
 The data to define user-defined characters is (y×x) bytes.
 Set acorresponding bit to 1 to print a dot or 0 not to print a dot.
 This command can define different user-defined character patterns for
eachfont. To select a font, use ESC !
 User-defined characters and a downloaded bit image cannot be
defined simultaneously. When this command is executed, the
downloaded bit image iscleared.
 The user-defined character definition is cleared when:
1）ESC @is executed.
2）GS*is executed.
3）ESC ?is executed.
4）The power is turned off.
[Default] The internal character set
[Reference] ESC %,ESC ?
[Example] When Font A (12×24) is selected.

---

CSN-A2User manual 27/70

d1=<0F>H d4=<30>H d7=<40>H . . . .
d2=<03>H d5=<80>H d8=<40>H . . . .
d3=<00>H d6=<00>H d9=<20>H . . . .

ESC? n

[Name] Cancel user-defined characters
[Format] ASCII: ESC ? n
Decimal: 27 37 n
Hexadecimal: 1B 3F n
[Range] 32≤n≤126
[Description] Cancels user-defined characters.

---

CSN-A2User manual 28/70

[Note]  Thiscommand cancels the patterns defined for the character codes
specifiedby n. After the user-defined characters are canceled, the
correspondingpatterns for the internal characters are printed.
 This command deletes the pattern defined for the specifiedcode in
the fontselected byESC !.
 If user-defined characters have not been defined, the printerignores
thiscommand.
[Reference] ESC &,ESC %

ESC R n

[Name] Select an internal character set
[Format] ASCII: ESC R n
Decimal: 27 82 n
Hexadecimal: 1B 52 n
[Range] 0≤n≤13
[Description] Select an internal character set n as follows:
n Character set n Character set
0 U.S.A 8 Japan
1 France 9 Norway
2 Germany 10 Denmark II
3 U.K 11 Spain II
4 Denmark I 12 Latin America
5 Sweden 13 Korea
6 Italy 14 Slovenia/Croatia
7 Spain I 15 China
[Default] n=0

ESC t n

[Name] Select character code table
[Format] ASCII: ESC t n
Decimal: 27 116 n
Hexadecimal: 1B 74 n
[Range] 0≤n≤5, 16≤n≤19,n=255
[Description] Select page n from the character code table as follows:
N Code Page N Code Page
0 CP437 [U.S.A., Standard Europe] 24 CP737 [Greek]
1 Katakana 25 WCP1257 [Baltic]
2 CP850 [Multilingual] 26 Thai
3 CP860 [Portuguese] 27 CP720[Arabic]
4 CP863 [Canadian-French] 28 CP855
5 CP865 [Nordic] 29 CP857[Turkish]

---

CSN-A2User manual 29/70

6 WCP1251 [Cyrillic] 30 WCP1250[Central Eurpoe]
7 CP866 Cyrilliec #2 31 CP775
8 MIK[Cyrillic /Bulgarian] 32 WCP1254[Turkish]
9 CP755 [East Europe，Latvian 2] 33 WCP1255[Hebrew]
10 Iran 34 WCP1256[Arabic]
11 reserve 35 WCP1258[Vietnam]
12 reserve 36 ISO-8859-2[Latin 2]
13 reserve 37 ISO-8859-3[Latin 3]
14 reserve 38 ISO-8859-4[Baltic]
15 CP862 [Hebrew] 39 ISO-8859-5[Cyrillic]
16 ＷCP1252 LatinI 40 ISO-8859-6[Arabic]
17 WCP1253 [Greek] 41 ISO-8859-7[Greek]
18 CP852 [Latina 2] 42 ISO-8859-8[Hebrew]
19 CP858 Multilingual Latin Ⅰ+Euro) 43 ISO-8859-9[Turkish]
20 Iran II 44 ISO-8859-15 [Latin 3]
21 Latvian 45 Thai2
22 CP864 [Arabic] 46 CP856
23 ISO-8859-1 [West Europe] 47 Cp874
[Default] n=0
[Reference] Character Code Tables

ESC 9 n

[Name] Select Chinese code format
[Format] ASCII: ESC 9 n
Decimal: 27 57 n
Hexadecimal: 1B 39 n
[Description] Select Chinese code format, n from the character code table as follows:
0: GBKcode.
1: UTF-8 code.
3:BIG5 code.
[Note] This version is not support English.
[Reference]

8.2.4Bit ImageCommand

ESC * m n1 n2 d1 d2…dk

[Name] Select bit-image mode
[Format] ASCII: ESC * m n1 n2 d1 d2 … dk
Decimal: 27 42 m n1 n2 d1 d2 … dk
Hexadecimal: 1B 2A m n1 n2 d1 d2 … dk
[Range] m =0,1,32,33
nL=0-255

---

CSN-A2User manual 30/70

nH=0-3
dx=0-255
[Description] Selects a bit-image mode using m for the number of dots specified by nL
and nH, as follows:
Vertical Direction Horizontal Direction
m Mode Number Dot Dot Number of Data
ofDots Density Density (K)
8-dot
0 8 67.7 dpi 101.6 dpi nL+nH×256
single-density
8-dot
1 8 67.7 dpi 203.2 dpi nL+nH×256
double-density
24-dot
32 24 203.2 dpi 101.6 dpi (nL+nH×256)×3
single-density
24-dot
33 24 203.2 dpi 203.2 dpi (nL+nH×256)×3
double-density
[Note]  If the value of m is out of the specified range, nL and nH the data
following are processed as normal data.
 The nL and nH indicate the number of dots in the bit image inthe
horizontal direction. The number of dots is calculated by nL+
nH×256.
 If the bit-image data input exceeds the number of dots to be printed
on a line, the excess data is ignored.
 d indicates the bit-image data. Set a corresponding bit to 1 to print a
dot or to 0 not to print a dot.
 After printing a bit image, the printer returns to normal data
processing mode.
 This command is not affected by print modes (emphasized,
double-strike, underline, character size, or white/black reverse
printing), except upside-down printing mode.
 The relationship between the image data and the dots to be printed
is described in Figure 3.11.3.
 When 8-dot bit image is selected:

---

CSN-A2User manual 31/70

Figure 3.11.3.
 When 24-dot bit image is selected:

Figure 3.11.3.

---

CSN-A2User manual 32/70

GS * x y d1...d(x×y×8)

[Name] Define downloaded bit image
[Format] ASCII: GS *x yd1 … d(x×y×8)
Decimal: 29 42x yd1 … d(x×y×8)
Hexadecimal: 1D 2Ax yd1 … d(x×y×8)
[Range] 1≤x≤255
1≤y≤48 (where x×y≤1536)
0≤d≤255
[Description] Defines a downloaded bit image using the number of dots specified by x
and y.
 x specifies the number of dots in the horizontal direction.
 y specifies the number of dots in the vertical direction.
[Note]  The number of dots in the horizontal direction is x×8; in the vertical
direction it is y×8.
 Ifx×y is out of the specified range, this command is disabled.
 The d indicates bit-image data. Data (d) specifies a bit printed as 1
and not printed as 0.
 The downloaded bit image definition is cleared when:
1) ESC @ is executed.
2) ESC & is executed.
3) Printer is reset or the power is turned off.
 The following figure shows the relationship between the downloaded
bit image and the printed data.

[Reference] GS /

---

CSN-A2User manual 33/70

GS / n

[Name] Print downloaded bit image
[Format] ASCII: GS / n
Decimal: 29 47 n
Hexadecimal: 1D2F n
[Range] 0≤n≤3, 48≤n≤51
[Description] Prints a downloaded bit image using the mode specified byn.
nselects a mode from the table below:
n Mode Vertical Dot Density Horizontal Dot Density
0, 48 Normal 203.2 dpi 203.2 dpi
1, 49 Double-width 203.2 dpi 101.6 dpi
2, 50 Double-height 101.6 dpi 203.2 dpi
3, 51 Quadruple 101.6 dpi 101.6 dpi
[Note]  This command is ignored if a downloaded bit image has not been
defined.
 In standard mode, this command is effective only when there is no
data in theprint buffer.
 This command has no effect in the print modes (emphasized,
double-strike, underline, character size, or white/black reverse
printing), except for upsidedownprinting mode.
 If the downloaded bit-image to be printed exceeds the printable area,
theexcess data isnot printed.
[Reference] GS*

GS v 0 m xL xH yL yH d1....dk

[Name] Print raster bit image
[Format] ASCII: GS v 0 m xL xH yL yH d1...dk
Decimal: 29118 48 m xL xH yL yH d1...dk
Hexadecimal: 1D 76 30m xL xH yL yH d1...dk
[Range] 0≤m≤3, 48≤m≤51
0≤xL≤255
0≤xH≤255,where 1≤(xL+xH×256)≤48
0≤yL≤255
0≤yH≤8,where 1≤(yL+yH×256)≤4095
0≤d≤255
k=(xL+xH×256)×(yL+yH×256) (k≠0)
[Description] Selects raster bit-image mode. The value of m selects the mode, as
follows:
Vertical Horizontal
m Mode
Dot Density Dot Density
0, 48 Normal 203.2 dpi 203.2 dpi

---

CSN-A2User manual 34/70

1, 49 Double-width 203.2 dpi 101.6 dpi
2, 50 Double-height 101.6 dpi 203.2 dpi
3, 51 Quadruple 101.6 dpi 101.6 dpi
 xL, xH, select the number of data bytes (xL+xH×256) in the
horizontal direction for thebit image.
 yL,yH, select the number of data bits (yL+yH×256) in the vertical
direction for the bitimage.
[Note]  In standard mode, this command is effective only when there is no
data in the print buffer.
 This command is not affected by print modes (character size,
emphasized, double-strike, upside-down, underline, white/black
reverse printing, etc.) for raster bit image.
 Data outside the printing area is read in and discarded on a
dot-by-dot basis.
 The position at which subsequent characters are to be printed for
raster bit image is specified byHT (Horizontal Tab), ESC $(Set
absolute print position), andGS L(Set left margin). If the position at
which subsequent characters are to be printed is a multiple of 8.
 TheESC a(Select justification) setting is also effective on raster bit
images.
 d indicates the bit-image data. Setting a bit to 1 print a dot and
setting it to 0 does not print a dot.
[Example] When xL+xH×256=64
← (xL+xH×256)×8dots=512dots →
1 2 3 **** * 62 63 64 ↑
65 66 67 **** * 126 127 128
**** * yL+yH×256dots
**** * K-2 K-1 K ↓

7 6 5 4 3 2 1 0
MSB LSB

DC2 * r n [d1…dn]

[Name] Print bitmap
[Format] ASCII: DC2 * r n [d1 … dn]
Decimal: 18 42 r n [d1 … dn]
Hexadecimal: 12 2A r n [d1 … dn]

---

CSN-A2User manual 35/70

[Description] Printing bitmap with width & height
r: Bitmap height
n: Bitmap width
Bitmap format:

DC2 V nL nH [d1…dn]

[Name] Print MSB Bitmap
[Format] ASCII: DC2 V nL nH [d1 … d48]
Decimal: 18 86 nL nH [d1 … d48]
Hexadecimal: 12 56 nL nH [d1 … d48]
[Description] This command use to print MSB format bitmap,
The width of bitmap must the same as the printer mechanism
Bitmap height: nL+nH*256
Bitmap format:

FS p n m

[Name] PrintNV bit image
[Format] ASCII: FS p n m
Decimal: 28 112 n m
Hexadecimal: 1C 70 n m
[Range] 1≤n≤255
0≤m≤3 , 48≤m≤51
[Description] Prints NV bit image n using the mode specified by m.
m Mode Vertical Dot Density Horizontal Dot Density
0，48 Normal 203.2 dpi 203.2 dpi

---

CSN-A2User manual 36/70

1，49 Double-width 203.2 dpi 101.6 dpi
2，50 Double-height 101.6 dpi 203.2 dpi
3，51 Quadruple 101.6 dpi 101.6 dpi
 n is the number of the NV bit image (defined using the FS q
command).
 m specifies the bit image mode.
[Details]  NV bit image is a bit image defined in non-volatile memory byFS q
and printed byFS p.
 This command is not effective when the specified NV bit image has
not beendefined.
 In standard mode, this command is effective only when there is no
data in theprint buffer.
 This command is not affected by print modes (emphasized,
underline, character size, white/black reverse printing, or90°rotated
characters,etc.), except upside-down printing mode.
 If the downloaded bit-image to be printed exceeds one line, the
excess data isnot printed.
 This command feeds dots (for the height n of the NV bit image) in
normal anddouble-width modes and (for the heightn×2 of the NV bit
image) in doubleheightand quadruple modes, regardless of the line
spacing specified byESC 2orESC 3.
 After printing the bit image, this command sets the print position to
the beginning of the line and processes the data that follows as
normal data.
[Reference] ESC*,FS q,GS /,GS v

FSqn[xL xH yL yH d1...dk]1...[xL xH yL yH d1...dk]n

[Name] Define NV bit image
[Format] ASCII: FSq n[xL xH yL yH d1...dk]1...[xL xH yL yHd1...dk]n
Decimal: 28 113n[xL xH yL yH d1...dk]1...[xL xH yL yHd1...dk]n
Hexadecimal: 1C 71n m[xL xH yL yH d1...dk]1...[xL xH yL yHd1...dk]n
[Range] 1≤n≤255
1≤xL≤255
1≤xH≤3 (when 1≤(xL+xH×256)≤1023
1≤yL≤255
1≤yH≤1(when 1≤(yL+yH×256)≤288
1≤d≤255
k=(xL+xH×256)×(yL+yH×256)×8
Total defined data area=192K bytes.
[Description] Define the NV bit image specified by n.
 n specifies the number of the defined NV bit image.
 xL,xHspecifies(xL+xH×256)×8dots in the horizontal direction for
the NV bitimage you are defining.

---

CSN-A2User manual 37/70

 yL,yHspecifies(yL+yH×256)×8dots in the vertical direction for the
NV bitimage you are defining.
[Note]  Frequent write command executions may damage the NV memory.
 Therefore, it is recommended to write the NV memory 10 times or
less a day.
 The printer performs a hardware reset after the procedure to place
the imageinto the NV memory. Therefore, user-defined characters,
downloaded bitimages should be defined only after completing this
command. The printer clears the receiver and print buffers and
resets the mode to themode that was in effect at power on.(this
version is not supporthardware reset).
 This command cancels all NV bit images that have already been
defined by thiscommand.
 From thebeginning of the processing of this command till the finish
of hardwarereset, mechanical operations (including initializing the
position of the print headwhen the cover is open, paper feeding
using the FEED button, etc.) cannot beperformed.
 During processing of this command, the printer is BUSY when writing
data tothe user NV memory and stops receiving data. Therefore it is
prohibited totransmit the data, including real-time commands, during
the execution of thiscommand.
 NV bit image is a bit image defined in non-volatile memory byFS q
and printedbyFS p.
 In standard mode, this command is effective only when processed at
thebeginning of the line.
 This command is effective when 7 bytes<FSyH> of the command
areprocessed normally.
 When the amount of data exceeds the capacity left in the range
defined by xL,xH, yL, yH, the printer processes xL, xH, yL, yH out of
the defined range.
 In the first group of NV bit images, when any of the parameters xL,
xH, yL, yH isout of the definition range, this command is disabled.
 In groups of NV bit images other than the first one, when the printer
encounters xL, xH, yL, yH out of the defined range, it stops
processing this command andstarts writing into the NV images. At
this time, NV bit images that haven’t been defined are disabled
(undefined), but any NV bit images before that areenabled.
 The dindicates the definition data. In data (d) a 1 bit specifies a dot
to beprinted and a 0 bit specifies a dot not to be printed.
 This command defines n as the number of aNV bit image. Numbers
rise inorder from NV bit image 01H. Therefore, the first data group
[xL xH yL yHd1...dk] is NV bit image 01H, and the last data group [xL
xH yL yH d1...dk] is NVbit image n. The total agrees with the number
of NV bit images specified by thecommandFS p.

---

CSN-A2User manual 38/70

 The definition data for an NV bit image consists of [xL xH yL yH
d1...dk].Therefore, when only one NV bit image is defined n=1, the
printer processes a data group [xL xH yL yH d1...dk] once. The
printer uses ([data: (xL+xH×256)×(yL+yH×256)×8]+[header: 4])
bytes of NV memory.
 The definition area in this printer is a maximum of 192K bytes. This
command can define several NV bit images, but cannot define bit
image data whose total capacity [bit image data+header] exceeds
192K bytes.
 The printer does not transmit ASB status or perform status detection
during processing of this command even when ASB is specified.
 Once an NV bit image is defined, it is not erased by performingESC
@, resetand power off.
 This command performs only definition of an NV bit image and does
not perform printing. Printing of the NV bit image is performed by the
FS pcommand.
[Reference] FS p
[Example] 当xL=64, xH=0, yL=96, yH=0

---

CSN-A2User manual 39/70

DC2 v nL nH [d1…dn]

[Name] Print LSB Bitmap
[Format] ASCII: DC2 v nL nH [d1 … d48]
Decimal: 18 118 nL nH [d1 … d48]
Hexadecimal: 12 76 nL nH [d1 … d48]
[Description] This command use to print LSB format bitmap,
The width of bitmap must the same as the printer mechanism
Bitmap height: nL+nH*256

---

CSN-A2User manual 40/70

Bitmap format:

8.2.5 Init command

ESC @

[Name] Initialize the printer
[Format] ASCII: ESC @
Decimal: 27 64
Hexadecimal: 1B 40
[Description] Initializes the printer.
 Theprint buffer is cleared.
 Reset the parametricto default value.
 return to standard mode
 Delete user-defined characters
[Note]  The DIP switch settings are not checked again.
 The data in the receive buffer is not cleared.

8.2.6Status Command

ESC v n

[Name] Transmit paper sensor status
[Format] ASCII: ESC v n
Decimal: 27 118 n
Hexadecimal: 1B 76 n
[Description] The return value is 1 bytes,It is a different on behalf of the status:
Bit Off/On Hex Decimal Function
Off 00 0 Offline.
0
On 01 1 Online.
1 - - - Undefined.
Off 00 0 Paper has.
2
On 04 4 Paper out.
Off 00 0 Voltage is normal.
3
On 08 8 Voltage＞9.5V.
4 - - - Undefined.

---

CSN-A2User manual 41/70

5 - - - Undefined.
Off 00 0 Temperatureis normal.
6
On 40 64 Temperature＞60°.
7 - - - Undefined.
For example：return “0x04” is means paper out.

GS a n

[Name] Enable/Disable Automatic Status Back(ASB)
[Format] ASCII: GS a n
Decimal: 29 97 n
Hexadecimal: 1D 61 n
[Range] 0≤n≤255
[Description] n definition as follows:
When ASB is enabled, the printer will send the changed status to PC
automatically.
Value
Bit Function
0 1
0 - - -
1 - - -
2 Disable/Enable ASB Disable Enable
3-4 - - -
5 Disable/Enable RTS as flow control Disable Enable
6-7 - - -

ESC u n(for Drawer)

[Name] Transmit peripheral devices status
[Format] ASCII: ESC u n
Decimal: 27 117 n
Hexadecimal: 1B 75 n
[Range] 0=0, 48
[Description] Transmitsthe status of the drawer kick-out connector pin 3 as 1byte of
data when n=0, 48.this allows the host to determine the status of a
peripheral device.
n is used as follows:
Bit On/off Hex Decimal Function
0 Off 00 0 Drawer kick out connector pin 3 is low
0 On 01 1 Drawer kick out connector pin 3 is high
1-3 - - - Undefined
4 Off 00 0 Not used.Fixed to off
5-6 - - - Undefined
7 Off 00 0 Not used.Fixed to off

---

CSN-A2User manual 42/70

GS r n

[Name] Transmit status
[Format] ASCII: GS r n
Decimal: 29 114 n
Hexadecimal: 1D 72 n
[Range] n=1, 49
[Description] Transmits the status specified by n as follows:
n Function
1, 49 Transmits paper sensor status
[Note]  When using a serial interface
1) When DTR/DSR control is selected, the printertransmits only 1 byte
after confirming the host is ready to receive data (DSR signal is
SPACE). If the host computer is not ready to receive data (DSR
signal is MARK), the printer waitsuntil the host is ready.
2) When XON/XOFF control is selected, the printer transmits only 1 byte
withoutconfirming the condition of the DSR signal.
 This command is executed when the data in the receive buffer is
developed.Therefore, there may be a time lag between receiving
this command andtransmitting the status, dependingon the receive
buffer status.
 When Auto Status Back (ASB) is enabled using GS a, the status
transmitted byGS r and the ASB status must be differentiated using.
 The status types to be transmitted are shown below:
Paper sensor status (n = 1, 49):
Bit Off/On Hex Decimal Status for ASB
0,1 - - - Undefined.
2,3 Off 00 0 Paper roll end sensor: paper adequate.
On (0C) (12) Paper roll end sensor: paper near end.
4 Off 00 0 Not used. Fixed to Off.
5,6 - - - Undefined.
7 Off 00 0 Not used. Fixed to Off.
Bits 2 and 3: When the paper end sensor detects a paper end, the printer goes offline
and does not execute this command. Therefore, bits 2 and 3 do not
transmit the status ofpaper end.
[Reference] GS a

8.2.7Bar Code Command

GS H n

[Name] Select printing position for HRI characters
[Format] ASCII: GS H n

---

CSN-A2User manual 43/70

Decimal: 29 72 n
Hexadecimal: 1D 48 n
[Range] 0≤n≤3,48≤n≤51
[Description] Selects the printing position of HRI characters when printing a bar code.n
selects the printing position as follows:
n Printing position
0, 48 Not printed
1, 49 Above the bar code
2, 50 Below the bar code
3, 51 Both above and below the bar code
HRI indicates Human Readable Interpretation.
[Note] HRI characters are printed using the font specified byGS f.
[Default] n=0
[Reference] GS f,GS k

GS h n

[Name] Set bar code height
[Format] ASCII: GS h n
Decimal: 29104 n
Hexadecimal: 1D68n
[Range] 0≤n≤255
[Description] Selects the height of the bar code.
n specifies the number of dots in the vertical direction.
[Default] n=162
[Reference] GS k

GS w n

[Name] Set bar code width
[Format] ASCII: GS w n
Decimal: 29 119 n
Hexadecimal: 1D 77 n
[Range] 2≤n≤6
[Description] Sets the horizontal size of the bar code.
n specifies the bar code width as follows:
Module Width (mm) Binary-level Bar Code
n forMulti-level Bar
Thin Element Width (mm) Thick Element Width(mm)
Code
2 0.250 0.250 0.625
3 0.375 0.375 1.000
4 0.560 0.500 1.250
5 0.625 0.625 1.625

---

CSN-A2User manual 44/70

6 0.750 0.750 2.000
 Multi-level bar codes are as follows:
UPC-A, UPC-E, JAN13 (EAN13), JAN8 (EAN8), CODE93, CODE128
 Binary-level bar codes are as follows:
CODE39, ITF, CODABAR
[Default] n=3
[Reference] GS k

GS k m d1 d2 … dk NUL

GS k m n d1 d2 … dn

[Name] Print bar code
[Format①] ASCII: GS k m d1 d2 … dk NUL
Decimal: 29 107 m d1 d2 … dk 0
Hexadecimal: 1D 6B m d1 d2 … dk 00
[Format②] ASCII: GS k m n d1 d2 … dn
Decimal: 29 107 m n d1 d2 … dn
Hexadecimal: 1D 6B m n d1 d2 … dn
[Range①] 0≤m≤6(k and d depend on the bar code system used)
[Range②] 65≤m≤73(n and d depend on the bar code system used)
[Description] Selects a bar code system and prints the bar code.
m selects a bar code system as follows:
m Bar Code System Number of Characters Remarks
① 0 UPC-A 11≤k≤12 48≤d≤57
1 UPC-E 11≤k≤12 48≤d≤57
2 JAN13 (EAN13) 12≤k≤13 48≤d≤57
3 JAN 8 (EAN8) 7≤k≤8 48≤d≤57
4 CODE39 1≤k′ 48≤d≤57, 65≤d≤90, 32, 36,
37, 43, 45, 46, 47
5 ITF 1≤k (even number) 48≤d≤57
6 CODABAR 1≤k′ 48≤d≤57, 65≤d≤68, 36, 43,
45, 46, 47, 58
② 65 UPC-A 11≤k≤12 48≤d≤57
66 UPC-E 11≤k≤12 48≤d≤57
67 JAN13 (EAN13) 12≤k≤13 48≤d≤57
68 JAN 8 (EAN8) 7≤k≤8 48≤d≤57
69 CODE39 1≤n≤255 48≤d≤57, 65≤d≤90, 32, 36,
37, 43, 45, 46, 47
70 ITF 1≤n≤255 (even 48≤d≤57
number)
71 CODABAR 1≤n≤255 48≤d≤57, 65≤d≤68 , 36, 43,
45, 46, 47, 58
72 CODE93 1≤n≤255 0≤d≤127

---

CSN-A2User manual 45/70

73 CODE128 2≤n≤255 0≤d≤127
[Notes for①]  This command ends with a NUL code.
 When the bar code system used is UPC-A or UPC-E, the printer
prints the barcode data after receiving 12 bytes of bar code data and
processes the followingdata as normal data.
 When the bar code system used is JAN13 (EAN13), the printer prints
the barcode after receiving 13 bytes of bar code data and processes
the following dataas normal data.
 When the bar code system used is JAN8 (EAN8), the printer prints
the bar codeafter receiving 8 bytes of bar code data and processes
the following data asnormal data.
 The number of data for the ITF bar code must be even numbers.
When an oddnumber of bytes of data is input, the printer ignores the
last received data.
[Notes for②]  n indicates the number of bar code data bytes, and the printer
processes nbytes from the next character data as bar code data.
 If n is outside the specified range, the printer stops command
processing andprocesses the following data as normal data.
[Notes in standard mode]
 If d is outside the specified range, the printer only feeds paper and
processesthe following data as normal data.
 If the horizontal size exceedsprinting area, the printer only feeds the
paper.
 This command feeds as much paper as is required to print the bar
code, regardless of the line spacing specified byESC 2orESC 3.
 This command is enabled only when no data exists in the print
buffer.Whendata exists in the print buffer, the printer processes the
datafollowing m asnormal data.
 After printing the bar code, this command sets the print position to
thebeginning of the line.
 This command is not affected by print modes (emphasized,
double-strike, underline, character size, white/black reverse printing,
or90°rotated character,etc.), except for upside-down printing mode.
Control character Control character
HRI character HRI character
ASCII Hex Decimal ASCII Hex Decimal
NUL 00 0 ■U DEL 10 16 ■P
SOH 01 1 ■A DC1 11 17 ■Q
STX 02 2 ■B DC2 12 18 ■R
ETX 03 3 ■C DC3 13 19 ■S
EOT 04 4 ■D DC4 14 20 ■T
ENQ 05 5 ■E NAK 15 21 ■U
ACK 06 6 ■F SYN 16 22 ■V
BEL 07 7 ■G ETB 17 23 ■W
BS 08 8 ■H CAN 18 24 ■X

---

CSN-A2User manual 46/70

HT 09 9 ■I EM 19 25 ■Y
LF 0A 10 ■J SUB 1A 26 ■Z
VT 0B 11 ■K ESC 1B 27 ■A
FF 0C 12 ■L FS 1C 28 ■B
CR 0D 13 ■M GS 1D 29 ■C
SO 0E 14 ■N RS 1E 30 ■D
SI 0F 15 ■O US 1F 31 ■E
DEL 7F 127 ■T
[Example] PrintingGS k72 7 67 111 100 101 13 57 51

When CODE128 (m= 73) is used:
When using CODE128 in this printer, take the following points into
account fordata transmission:
①The top of the bar code data string must be the code set selection
character(CODE A, CODE B, or CODE C), which selects the first code
set.
②Special charactersare defined by combining two characters "{" and
onecharacter. The ASCII character "{" is defined by transmitting "{" twice
consecutively.
Specific Transmit data
character ASCII Hex Decimal
SHIFT {S 7B, 53 123,83
CODE A {A 7B, 41 123,65
CODE B {B 7B,42 123,66
CODE C {C 7B,43 123,67
FNC1 {1 7B,31 123,49
FNC2 {2 7B,32 123,50
FNC3 {3 7B,33 123,51
FNC4 {4 7B,34 123,52
"{" {{ 7B,7B 123,123
[Example] Example data for printing "No. 123456"
In this example, the printer first prints "No." using CODE B, then prints
thefollowing numbers using CODE C.
GS k73 10 123 66 78 111 46 123 67 12 34 56

---

CSN-A2User manual 47/70

 If the top of the bar code data is not the code set selection character,
the printerstops command processing and processes the following
data as normal data.
 If the combination of "{" and the following character does not apply
any specialcharacter, the printer stops command processing and
processes the followingdata as normal data.
 If the printer receives characters that cannot be used in the special
code set,the printer stops command processing and processes the
following data asnormal data.
 The printer does not print HRI characters that correspond to the shift
charactersor code set selection characters.
 HRI character for the function character is space.
 HRI characters for the control character (<00>H to <1F>H and
<7F>H) arespace.
[Others] Be sure to keep spaces on both right and left sides of a bar code.
(Spaces are different depending on the types of the bar code.)
[Reference] GS H,GS h,GS w

GS xn

[Name] Set barcode printing left space
[Format] ASCII: GS x n
Decimal: 29 120 n
Hexadecimal: 1D 78 n
[Description] The print bar code staring positions is: 0→255

8.2.8MiscellaneousFunctionCommand

ESC 7 n1 n2 n3

[Name] Setting Control Parameter Command
[Format] ASCII: ESC 7 n1 n2 n3
Decimal: 27 55 n1 n2 n3
Hexadecimal: 1B 37 n1 n2 n3

---

CSN-A2User manual 48/70

[Description]  Set “max heating dots”,” heating time”, “heating interval”
n1=0-255 Max printing dots, Unit(8dots),Default:7(64 dots)
n2=3-255 Heating time, Unit(10us),Default:80(800us)
n3=0-255 Heating interval, Unit(10us),Default:2(20us)
 The more maxheatingdots, the more peak current will cost when
printing,the faster printing speed. The max heating dots is 8*(n1+1)
 The more heating time,the more density, but the slower printing
speed. If heating time is too short, blank page may occur.
 The more heating interval, the clearer, but the slower printingspeed.

ESC 8 n1 n2

[Name] Sleep parameter
[Format] ASCII: ESC 8 n1 n2
Decimal: 27 56 n1 n2
Hexadecimal: 1B 38 n1 n2
[Description] Setting the time for control board to enter sleep mode.
n1+n2*256 The time waiting for sleep after printing finished, Unit
(Second),Default: 0(don’t sleep).
When control board is in sleep mode, host must send onebyte (0xff) to
wake up control board. And waiting 50ms, then send printing command
and data.
[Note] The command is useful when the system is powered by battery.

DC2 # n

[Name] Set printing density
[Format] ASCII: DC2 # n
Decimal: 18 35 n
Hexadecimal: 12 23 n
[Description] D4..D0 of n is used to set the printing density
Density is 50% + 5% * n(D4-D0)
D7..D5 of n is used to set the printing break time
Break time is n(D7-D5)*250us

DC2 T

[Name] Printing test page
[Format] ASCII: DC2 T
Decimal: 18 84
Hexadecimal: 12 54
[Description] Printing the test page

---

CSN-A2User manual 49/70

FS t n(for CB105B)

[Name] SelectTimeout
[Format] ASCII: FS t n
Decimal: 28 116 n
Hexadecimal: 1C 74 n
[Description] Set Timeout for one byte, t=n×10ms;so if There are 100 bytes needed
for a command,the printer will wait 1000×n ms, when n=0,the printer will
wait until all chars needed have received.

8.2.9 New commands

DC2 E

[Name] Feed paper to mark
[Format] ASCII: DC2 E
Decimal: 18 69
Hexadecimal: 12 45
[Description] Feed paper to the Mark position

DC2 m d 1l 1h

[Name] Set mark paper length
[Format] ASCII: DC2 m d 1l 1h
Decimal: 18 109 d 1l 1h
Hexadecimal: 12 6d d 1l 1h
[Description] d = 0,1
1:stop at mark position
0:go on 3 steps after mark position detected
0 ≤ ll ≤ 255
0 ≤ lh ≤ 255
Paper length is (ll+lh*256) steps, means (ll+lh*256)/8 mm

ESCCn(for BM)

[Name] SetBMMax
[Format] ASCII: ESC C n
Decimal: 27 67 n
Hexadecimal: 1B 43 n
[Description] With the current row spacing of unit,the line number to define the scope
of testing black mark, the default value is 4 inches.

---

CSN-A2User manual 50/70

GS FF(for BM)

[Name] Feed marked paper to print starting position
[Format] ASCII: GS FF
Decimal: 29 12
Hexadecimal: 1D 0C
[Description] Feeds the marked paper to the print starting position.
Locate to the black mark.
[Note]  This command sets the next print position to the beginning of the
line.
 Even if this command is executed at the print starting position of the
markedpaper, the printer does not feedthe marked paper to the next
print startingposition.
[Reference] GS ( F

ESCi(for cut)

[Name] fullcutpaper
[Format] ASCII: ESC i
Decimal: 27 105
Hexadecimal: 1B 69
[Description] ESCiselect a paper cutting mode and then full cut thepaper.

ESC m(for cut)

[Name] partialcutpaper
[Format] ASCII: ESC i
Decimal: 27 105
Hexadecimal: 1B 69
[Description] ESCmselects a paper cutting mode and thenpartialcut the paper.

①GS Vm②GS V m n(for cut)

[Name] Select cut mode and cut paper
[Format] ①ASCII: GS V m
Decimal: 29 86 m
Hexadecimal: 1D 56 m
②ASCII: GS V m n
Decimal: 29 86 m n
Hexadecimal: 1D 56 m n
[Range] ① m=1, 49
② m=66, 0≤n≤255
[Description] Selects a mode for cutting paper and executes paper cutting. The value
of mselects the mode as follows:

---

CSN-A2User manual 51/70

m Print mode
1, 49 Partial cut (one point left uncut)
Feeds paper (cutting position + [n ×0.125 mm]), and cuts the paper
66
partially (onepoint left uncut).
[Notes for ① and ②]
 Cutting status is different, depending on the installed autocutter type.
 This command is effective only when processed at the beginning of a
line.
[Note for ① ] Only the partial cut is available; there is no full cut.
[Notes for ②]  When n=0, the printer feeds the paper to the cutting position and
cuts it.
 When n≠0, the printer feedsthe paper to (cutting position+[n×0.125
mm(0.0049”)]) and cuts it.

ESC Pm t1t2 (for Drawer)

[Name] Generate pulse
[Format] ASCII: ESC p m t1 t2
Decimal: 27 112 m t1 t2
Hexadecimal: 1B 70 m t1 t2
[Range] m=0,1,48,49
0≤t1≤255,0≤t2≤255
[Description] Outputs the pulse specified by t1 to connector pin m as follows:
m Function
0,48 Drawer kick-out connector pin2.
1,49 Drawer kick-out connector pin5.
[Note]  The pulse ON time is [t1×2ms] and the OFF time is [t2×2ms].
 If t2<t1, the OFF time is [t1×2ms].

ESC c 5 n(for buttons)

[Name] Enable/disable panel buttons
[Format] ASCII: ESC c 5 n
Decimal: 27 99 53 n
Hexadecimal: 1B 03 35 n
[Range] 0≤n≤255
[Description] Enable/disable panel buttons（support the panel buttons）
 When the LSB of n is 0, thepanel buttons are enabled.
 When the LSB of n is 1, the panel buttons are disabled.
[Default] n=0

---

CSN-A2User manual 52/70

GS (F pL pH a m nL nH (for 701BM)

[Name]
[Format] ASCII: GS ( F pL pH a m nL nH
Decimal: 29 40 70 pL pH a m nL nH
Hexadecimal: 1D 28 46 pL pH a m nL nH
[Range] (pL+(pH×256))=4 (where pL=4, pH=0)
1≤a≤2
m = 0, 48 or 1, 49
0≤( nL+nH×256)≤65535(where 0≤nL≤255, 0≤nH≤255)
[Description] This command is effective only when the BM sensor is enabled.
Sets adjustment values(s) for the printer operations specified by a.
 pL and pH specifies the number of the parameter such as a to
(pL+(pH×256))bytes.
 a specifies setting values for the positions to start printing and cutting
a Function
1 Setting value for the positions to start the printing.
2 Setting value for the positions to start the cutting.
 m specifies the direction of the adjustment.
m Function
0,48 Specifies a forwardpaper feeding direction
1,49 Specifies a backward paper feeding direction.
 nL and nH specifies the setting value to [(nL+nH×256)×0.125 mm].
 The adjustment value forthe print starting position (a=1) is affected
with the following commands:GS FF
 Theadjustment value for the paper cutting position (a=2) is affected
with thefollowing commands:GS V m n
[Default] All adjustment values are set to “0”.
(At the factory setting, the print starting position and the cutting position
are set to the head position and the cutter position respectively when the
BM sensor detects the BM.)
[Reference] GS FF,GS V

FSC(for CB65C)

[Name] Start receive buffer count
[Format] ASCII: FS C
Decimal: 28 67
Hexadecimal: 1C 43
[Description] Start receivingbuffer count.

FSS(for CB65C)

[Name] Startsendbuffer count

---

CSN-A2User manual 53/70

[Format] ASCII: FS S
Decimal: 28 83
Hexadecimal: 1C 53
[Description] Send count of receive buffer, include this command's 2 bytes.

FSs(for XBLY)

[Name] Save print parater
[Format] ASCII: FS s
Decimal: 28 115
Hexadecimal: 1C 73
[Description] Save print parater. (only forXBLY)

FSd(for XBLY)

[Name] Load default leaving factory set
[Format] ASCII: FS d
Decimal: 28 100
Hexadecimal: 1C 64
[Description] Load default leaving factory set .(only forXBLY)

---

CSN-A2User manual 54/70

Appendix 1Code page

Page0 PC437 Page3 CP860 [Portuguese]

Code page 437
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ Ç ü é â ä à å ç ê ë è ï î ì Ä Å
9_ É æ Æ ô ö ò û ù ÿ Ö Ü ¢ £ ¥ ₧ ƒ
A_á í ó ú ñ Ñ ª º ¿ ⌐ ¬ ½ ¼ ¡ « »
B_░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐
C_└ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀
E_α ß Γ π Σ σ μ τ Φ Θ Ω δ ∞ φ ε ∩
F_≡ ± ≥ ≤ ⌠ ⌡ ÷ ≈ ° ∙ · √ ⁿ ² ■

Page 1 Katakana

---

CSN-A2User manual 55/70

Page2 PC850[Multilingual]

Code page 850
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ Ç ü é â ä à å ç ê ë è ï î ì Ä Å
9_ É æ Æ ô ö ò û ù ÿ Ö Ü ø £ Ø × ƒ
A_á í ó ú ñ Ñ ª º ¿ ® ¬ ½ ¼ ¡ « »
B_░ ▒ ▓ │ ┤ Á Â À © ╣ ║ ╗ ╝ ¢ ¥ ┐
C_└ ┴ ┬ ├ ─ ┼ ã Ã ╚ ╔ ╩ ╦ ╠ ═ ╬ ¤
D_ð Ð Ê Ë È I Í Î Ï ┘ ┌ █ ▄ ¦ Ì ▀
E_Ó ß Ô Ò õ Õ μ þ Þ Ú Û Ù ý Ý ¯ ´
F_- ± ‗ ¾ ¶ § ÷ ¸ ° ¨ · ¹ ³ ² ■

Page3 PC860[Portuguese]

Code page 860
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ Ç ü é â ã à Á ç ê Ê è Í Ô ì Ã Â
9_ É À È ô õ ò Ú ù Ì Õ Ü ¢ £ Ù ₧ Ó
A_á í ó ú ñ Ñ ª º ¿ Ò ¬ ½ ¼ ¡ « »
B_░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐
C_└ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀
E_α ß Γ π Σ σ μ τ Φ Θ Ω δ ∞ φ ε ∩
F_≡ ± ≥ ≤ ⌠ ⌡ ÷ ≈ ° ∙ · √ ⁿ ² ■

Page4 PC863[Canadian-French]

Code page 863

_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F

8_ Ç ü é â Â à ¶ ç ê ë è ï î ‗ À §

9_ É È Ê ô Ë Ï û ù ¤ Ô Ü ¢ £ Ù Û ƒ

A_¦ ´ ó ú ¨ ¸ ³ ¯ Î ⌐ ¬ ½ ¼ ¾ « »

B_░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐

C_└ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧

D_╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀

E_α ß Γ π Σ σ μ τ Φ Θ Ω δ ∞ φ ε ∩

F_≡ ± ≥ ≤ ⌠ ⌡ ÷ ≈ ° ∙ · √ ⁿ ² ■

---

CSN-A2User manual 56/70

Page5 pc865[Nordic]

Code page 865
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_Ç ü é â ä à å ç ê ë è ï î ì Ä Å
9_É æ Æ ô ö ò û ù ÿ Ö Ü ø £ Ø ₧ ƒ
A_á í ó ú ñ Ñ ª º ¿ ⌐ ¬ ½ ¼ ¡ « ¤
B_░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐
C_└ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀
E_α ß Γ π Σ σ μ τ Φ Θ Ω δ ∞ φ ε ∩
F_≡ ± ≥ ≤ ⌠ ⌡ ÷ ≈ ° ∙ · √ ⁿ ² NBSP

Page6 pc1251 [Cyrillic]

Code page 1251

_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F

8_Ђ Ѓ ‚ ѓ „ … † ‡ € ‰ Љ ‹ Њ Ќ Ћ Џ

9_ђ ‘ ’ “ ” • – — ™ љ › њ ќ ћ џ

A_NBSPЎ ў Ј ¤ Ґ ¦ § Ё © Є « ¬ SHY® Ї

B_° ± І і ґ μ ¶ · ё № є » ј Ѕ ѕ ї

C_А Б В Г Д Е Ж З И Й К Л М Н О П

D_Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю Я

E_а б в г д е ж з и й к л м н о п

F_р с т у ф х ц ч ш щ ъ ы ь э ю я

Page7 pc866 Cyrilliec #2

Code page 866
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_А Б В Г Д Е Ж З И Й К Л М Н О П
9_Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю
A_а б в г д е ж з и й к л м н о п
B_░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐
C_└ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀
E_р с т у ф х ц ч ш щ ъ ы ь э ю я
F_Ё ё Є є Ї ї Ў ў ° ∙ · √ № ¤ ■ NBSP

---

CSN-A2User manual 57/70

Page8 MIK[Cyrillic /Bulgarian]

Code page MIK
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ А Б В Г Д Е Ж З И Й К Л М Н О П
9_ Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю Я
A_ а б в г д е ж з и й к л м н о п
B_ р с т у ф х ц ч ш щ ъ ы ь э ю я
C_ └ ┴ ┬ ├ ─ ┼ ╣ ║ ╚ ╔ ╩ ╦ ╠ ═ ╬ ┐
D_ ░ ▒ ▓ │ ┤ № § ╗ ╝ ┘ ┌ █ ▄ ▌ ▐ ▀
E_ α ß Γ π Σ σ μ τ Φ Θ Ω δ ∞ φ ε ∩
F_ ≡ ± ≥ ≤ ⌠ ⌡ ÷ ≈ ° ∙ · √ ⁿ ² ■ NBSP

Page9 CP755

Code page 755
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_А Б В Г Д Е Ж З И Й К Л М Н О П
9_Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю Я
A_а б в г д е ж з и й к л м н о п
B_░ ▒ ▓ │ ┤ Ā ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐
C_└ ┴ ┬ ├ ─ ┼ ā ║ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_Š ╦ Č č ╚ ╔ ģ Ī ī ┘ ┌ █ ▄ ū Ū ▀
E_р с т у ф х ц ч ш щ ъ ы ь э ю я
F_Ē ē Ģ К Κ ļ Ļ Ž Ž ∙ · √ Ν Š ■ NBSP

Page10 Iran

Code page Iran
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ ٠ ١ ٢ ٣ ۴ ۵ ۶ ٧ ٨ ٩ ، ـ ؟F ﺁ ﺋ ء
9_ ﺍ ﺎ ﺏ ﺑ پ پ ﺕ ﺗ ﺙ ﺛ ﺝ ﺟ* چC* چ ﺡ ﺣ
A_ﺥ ﺧ د ذ ر ز ژ ﺱ ﺳ ﺵ ﺷ ﺹ ﺻ ﺽ ﺿ ط
B_░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╜ ╛ ┐
C_└ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀
E_ظ ﻉ ﻊ ﻌ ﻋ ﻍ ﻎ ﻐ ﻏ ﻑ ﻓ ﻕ ﻗ ک ک گ
F_گ ﻝ ﻻ ﻟ ﻡ ﻣ ﻥ ﻧ و ﻩ ﻬ ﻫ ی ی ﯾ

---

CSN-A2User manual 58/70

Page15 CP862 [Hebrew]

Code page 862
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ א ב ג ד ה ו ז ח ט י ך כ ל ם מ ן
9_ נ ס ע ף פ ץ צ ק ר ש ת ¢ £ ¥ ₧ ƒ
A_ á í ó ú ñ Ñ ª º ¿ ⌐ ¬ ½ ¼ ¡ « »
B_ ░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐
C_ └ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_ ╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀
E_ α ß Γ π Σ σ μ τ Φ Θ Ω δ ∞ φ ε ∩
F_ ≡ ± ≥ ≤ ⌠ ⌡ ÷ ≈ ° ∙ · √ ⁿ ² ■ NBSP

Page 16 PC1252 Latin 1

Code page 1252
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ € ‚ ƒ „ … † ‡ ˆ ‰ Š ‹ Œ Ž
9_ ‘ ’ “ ” • – — ˜ ™ š › œ ž Ÿ
A_ NBSP¡ ¢ £ ¤ ¥ ¦ § ¨ © ª « ¬ SHY® ¯
B_ ° ± ² ³ ´ μ ¶ · ¸ ¹ º » ¼ ½ ¾ ¿
C_ À Á Â Ã Ä Å Æ Ç È É Ê Ë Ì Í Î Ï
D_ Ð Ñ Ò Ó Ô Õ Ö × Ø Ù Ú Û Ü Ý Þ ß
E_ à á â ã ä å æ ç è é ê ë ì í î ï
F_ ð ñ ò ó ô õ ö ÷ ø ù ú û ü ý þ ÿ

Page 17 WCP1253 [Greek]

Code page 1253
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ € ‚ ƒ „ … † ‡ ‰ ‹
9_ ‘ ’ “ ” • – — ™ ›
A_ NBSP΅ Ά £ ¤ ¥ ¦ § ¨ © « ¬ SHY® ―
B_ ° ± ² ³ ΄ μ ¶ · Έ Ή Ί » Ό ½ Ύ Ώ
C_ ΐ Α Β Γ Δ Ε Ζ Η Θ Ι Κ Λ Μ Ν Ξ Ο
D_ Π Ρ Σ Τ Υ Φ Χ Ψ Ω Ϊ Ϋ ά έ ή ί
E_ ΰ α β γ δ ε ζ η θ ι κ λ μ ν ξ ο
F_ π ρ ς σ τ υ φ χ ψ ω ϊ ϋ ό ύ ώ

---

CSN-A2User manual 59/70

Page18 PC852

Code page 852
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ Ç ü é â ä ů ć ç ł ë Ő ő î Ź Ä
9_ É Ĺ ĺ ô ö Ľ ľ Ś ś Ö Ü Ť ť Ł ×
A_ á í ó ú Ą ą Ž ž Ę ę ¬ ź Č ş « ―
B_ ░ ▒ ▓ │ ┤ Á Â Ě Ş ╣ ║ ╗ ╝ Ż ż Ώ
C_ └ ┴ ┬ ├ ─ ┼ Ă ă ╚ ╔ ╩ ╦ ╠ ═ ╬ Ο
D_ đ Đ Ď Ë ď Ň Í Î ě ┘ ┌ █ ▄ Ţ Ů ί
E_ Ó ß Ô Ń ń ň Š š Ŕ Ú ŕ Ű ý Ý ţ´ ο
F_ - ˝ ˛ ˇ ˘ § ÷ ¸ ° ¨ ˙ ű Ř ř ■

Page19 PC858 (Multilingual LatinI+Euro)

Code page 858
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ Ç ü é â ä à å ç ê ë è ï î ì Ä Å
9_ É æ Æ ô ö ò û ù ÿ Ö Ü ø £ Ø × ƒ
A_ á í ó ú ñ Ñ ª º ¿ ® ¬ ½ ¼ ¡ « »
B_ ░ ▒ ▓ │ ┤ Á Â À © ╣ ║ ╗ ╝ ¢ ¥ ┐
C_ └ ┴ ┬ ├ ─ ┼ ã Ã ╚ ╔ ╩ ╦ ╠ ═ ╬ ¤
D_ ð Ð Ê Ë È € Í Î Ï ┘ ┌ █ ▄ ¦ Ì ▀
E_ Ó ß Ô Ò õ Õ μ þ Þ Ú Û Ù ý Ý ¯ ´
F_ - ± ‗ ¾ ¶ § ÷ ¸ ° ¨ · ¹ ³ ² ■

Page20 Iran II

Code page Iran II
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ ٠ ١ ٢ ٣ ۴ ۵ ۶ ٧ ٨ ٩ ، ـ ؟F ﺁ ﺋ ء
9_ ﺍ ﺎ ﺏ ﺑ پ پ ﺕ ﺗ ﺙ ﺛ ﺝ ﺟ* چC* چ ﺡ ﺣ
A_ ﺥ ﺧ د ذ ر ز ژ ﺱ ﺳ ﺵ ﺷ ﺹ ﺻ ﺽ ﺿ ط
B_ ░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╜ ╛ ┐
C_ └ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_ ╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀
E_ ظ ﻉ ﻊ ﻌ ﻋ ﻍ ﻎ ﻐ ﻏ ﻑ ﻓ ﻕ ﻗ ک ک گ
F_ گ ﻝ ﻻ ﻟ ﻡ ﻣ ﻥ ﻧ و ﻩ ﻬ ﻫ ی ی ﯾ

---

CSN-A2User manual 60/70

Page21 Latvian

Code page Latvian

_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F

8_А Б В Г Д Е Ж З И Й К Л М Н О П

9_Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю Я

A_а б в г д е ж з и й к л м н о п

B_ А מ Ō

C_ ā

D_Š Č č Ī ╔ ģ Ī ī ū Ū

E_р с т у ф х ц ч ш щ ъ ы ь э ю я

F_Ē ē Ģ К Κ ⌠ ⌡ Ž Ž ō Ν Š NBSP

Page22 CP864 [Arabic]

Code page 864
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ ° · ∙ √ ▒ ─ │ ┼ ┤ ┬ ├ ┴ ┐ ┌ └ ┘
9_ β ∞ φ ± ½ ¼ ≈ « » ﻷ ﻸ ﻻ ﻼ
A_ NBSPSHYﺂ £ ¤ ﺄ € ﺎ ﺏ ﺕ ﺙ ، ﺝ ﺡ ﺥ
B_ ٠ ١ ٢ ٣ ٤ ٥ ٦ ٧ ٨ ٩ ﻑ ؛ ﺱ ﺵ ﺹ ؟
C_ ¢ ﺀ ﺁ ﺃ ﺅ ﻊ ﺋ ﺍ ﺑ ﺓ ﺗ ﺛ ﺟ ﺣ ﺧ د
D_ ذ ر ز ﺳ ﺷ ﺻ ﺿ ط ظ ﻋ ﻏ ¦ ¬ ÷ × ﻉ
E_ ـ ﻓ ﻗ ﻛ ﻟ ﻣ ﻧ ﻫ و ﻯ ﯾ ﺽ ﻌ ﻎ ﻍ ﻡ
F_ ّـ _ّ ﻥ ﻩ ﻬ ﻰ ﻲ ﻐ ﻕ ﻵ ﻶ ﻝ ﻙ ﻱ ■

Page23 ISO-8859-1 [West Europe]

Code page 8859-1
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSP¡ ¢ £ ¤ ¥ ¦6 § ¨ © ª « ¬ SHY® ¯
B_ ° ± ² ³ ´ μ ¶ · ¸ ¹ º » ¼ ½ ¾ ¿
C_ À Á Â Ã Ä Å Æ Ç È É Ê Ë Ì Í Î Ï
D_ Ð Ñ Ò Ó Ô Õ Ö × Ø Ù Ú Û Ü Ý Þ ß
E_ à á â ã ä å æ ç è é ê ë ì í î ï
F_ ð ñ ò ó ô õ ö ÷ ø ù ú û ü ý þ ÿ

---

CSN-A2User manual 61/70

Page24 CP737 [Greek]

Code page 737

_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F

8_ Α Β Γ Δ Ε Ζ Η Θ Ι Κ Λ Μ Ν Ξ Ο Π

9_ Ρ Σ Τ Υ Φ Χ Ψ Ω α β γ δ ε ζ η θ

A_ ι κ λ μ ν ξ ο π ρ σ ς τ υ φ χ ψ

B_ ░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐

C_ └ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧

D_ ╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀

E_ ω ά έ ή ϊ ί ό ύ ϋ ώ Ά Έ Ή Ί Ό Ύ

F_ Ώ ± ≥ ≤ Ϊ Ϋ ÷ ≈ ° ∙ · √ ⁿ ² ■ NBSP

Page25 WCP1257 [Baltic]

Code page 1257
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ € ‚ „ … † ‡ ‰ ‹ ¨ ˇ ¸
9_ ‘ ’ “ ” • – — ™ › ¯ ˛
A_ NBSP ¢ £ ¤ ¦ § Ø © Ŗ « ¬ SHY® Æ
B_ ° ± ² ³ ´ μ ¶ · ø ¹ ŗ » ¼ ½ ¾ æ
C_ Ą Į Ā Ć Ä Å Ę Ē Č É Ź Ė Ģ Ķ Ī Ļ
D_ Š Ń Ņ Ó Ō Õ Ö × Ų Ł Ś Ū Ü Ż Ž ß
E_ ą į ā ć ä å ę ē č é ź ė ģ ķ ī ļ
F_ š ń ņ ó ō õ ö ÷ ų ł ś ū ü ż ž ˙

---

CSN-A2User manual 62/70

Page26 Thai

Page27CP720 [Arabic]

Code page 720
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ é â à ç ê ë è ï î
9_ _ّ _ْ ô ¤ ـ û ù ء ﺁ ﺃ ﺅ £ إ ئ ﺍ
A_ ﺏ ﺓ ﺕ ﺙ ﺝ ﺡ ﺥ د ذ ر ز ﺱ ﺵ ﺹ « »
B_ ░ ▒ ▓ │ ┤ ╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ┐
C_ └ ┴ ┬ ├ ─ ┼ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧
D_ ╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ ┘ ┌ █ ▄ ▌ ▐ ▀
E_ ﺽ ط ظ ﻉ ﻍ ﻑ μ ﻕ ﻙ ﻝ ﻡ ﻥ ﻩ و ﻯ ﻱ
F_ ≡ _ً _ٌ _ٍ _َ _ُ _ِ ≈ ° ∙ · √ ⁿ ² ■ NBSP

Page28 CP855

Code page 855
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ ђ Ђ ѓ Ѓ ё Ё є Є ѕ Ѕ і І ї Ї ј Ј
9_ љ Љ њ Њ ћ Ћ ќ Ќ ў Ў џ Џ ю Ю ъ Ъ
A_ а А б Б ц Ц д Д е Е ф Ф г Г « »
B_ ░ ▒ ▓ │ ┤ х Х и И ╣ ║ ╗ ╝ й Й ┐
C_ └ ┴ ┬ ├ ─ ┼ к К ╚ ╔ ╩ ╦ ╠ ═ ╬ ¤
D_ л Л м М н Н о О п ┘ ┌ █ ▄ П я ▀

---

CSN-A2User manual 63/70

E_ Я р Р с С т Т у У ж Ж в В ь Ь №
F_ SHYы Ы з З ш Ш э Э щ Щ ч Ч § ■ NBSP

Page29PC857 [Turkish]

Code page 857
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ Ç ü é â ä à å ç ê ë è ï î I Ä Å
9_ É æ Æ ô ö ò û ù İ Ö Ü ø £ Ø Ş ş
A_ á í ó ú ñ Ñ Ğ ğ ¿ ® ¬ ½ ¼ ¡ « »
B_ ░ ▒ ▓ │ ┤ Á Â À © ╣ ║ ╗ ╝ ¢ ¥ ┐
C_ └ ┴ ┬ ├ ─ ┼ ã Ã ╚ ╔ ╩ ╦ ╠ ═ ╬ ¤
D_ º ª Ê Ë È Ç Í Î Ï ┘ ┌ █ ▄ ¦ Ì ▀
E_ Ó ß Ô Ò õ Õ μ Ç × Ú Û Ù ì ÿ ¯ ´
F_ - ± Ç ¾ ¶ § ÷ ¸ ° ¨ · ¹ ³ ² ■

Page30WCP1250 [Central Eurpoe]

Code page-1250
—0 —1 —2 —3 —4 —5 —6 —7 —8 —9 —A —B —C —D —E —F
8_ € ‚ „ … † ‡ ‰ Š ‹ Ś Ť Ž Ź
9_ ‘ ’ “ ” • – — ™ š › ś ť ž ź
A_ NBSPˇ ˘ Ł ¤ Ą ¦ § ¨ © Ş « ¬ SHY® Ż
B_ ° ± ˛ ł ´ μ ¶ · ¸ ą ş » Ľ ˝ ľ ż
C_ Ŕ Á Â Ă Ä Ĺ Ć Ç Č É Ę Ë Ě Í Î Ď
D_ Đ Ń Ň Ó Ô Ő Ö × Ř Ů Ú Ű Ü Ý Ţ ß
E_ ŕ á â ă ä ĺ ć ç č é ę ë ě í î ď
F_ đ ń ň ó ô ő ö ÷ ř ů ú ű ü ý ţ ˙

Page31 CP775

Code page 775
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ Ć ü é ā ä ģ å ć ł ē Ŗ ŗ ī Ź Ä Å
9_ É æ Æ ō ö Ģ ¢ Ś ś Ö Ü ø £ Ø × ¤
A_ Ā Ī ó Ż ż ź ” ¦ © ® ¬ ½ ¼ Ł « »
B_ ░ ▒ ▓ │ ┤ Ą Č Ę Ė ╣ ║ ╗ ╝ Į Š ┐
C_ └ ┴ ┬ ├ ─ ┼ Ų Ū ╚ ╔ ╩ ╦ ╠ ═ ╬ Ž
D_ ą č ę ė į š ų ū ž ┘ ┌ █ ▄ ▌ ▐ ▀
E_ Ó ß Ō Ń õ Õ μ ń Ķ ķ Ļ ļ ņ Ē Ņ ’

---

CSN-A2User manual 64/70

F_ SHY± “ ¾ ¶ § ÷ „ ° ∙ · ¹ ³ ² ■ NBSP

Page32WCP1254 [Turkish]

Code page-1254
_0 _1 _2 _3 _4 _5_6 _7 _8 _9 _A _B _C _D _E _F
8_ € ‚ ƒ „ … † ‡ ˆ ‰ Š ‹ Œ
9_ ‘ ’ “ ” • – — ˜ ™ š › œ Ÿ
A_NBSP¡ ¢ £ ¤ ¥ ¦ § ¨ © ª « ¬ SHY® ¯
B_° ± ² ³ ´ μ ¶ · ¸ ¹ º » ¼ ½ ¾ ¿
C_À Á Â Ã Ä Å Æ Ç È É Ê Ë Ì Í Î Ï
D_Ğ Ñ Ò Ó Ô Õ Ö × Ø Ù Ú Û Ü İ Ş ß
E_à á â ã ä å æ ç è é ê ë ì í î ï
F_ğ ñ ò ó ô õ ö ÷ ø ù ú û ü ı ş ÿ

Page33WCP1255 [Hebrew]

Code page-1255
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_€ ‚ ƒ „ … † ‡ ‰ ‹
9_ ‘ ’ “ ” • – — ˜ ™ ›
A_NBSP¡ ¢ £ ₪ ¥ ¦ § ¨ © × « ¬ SHY® ¯
B_° ± ² ³ ´ μ ¶ · ¸ ¹ ÷ » ¼ ½ ¾ ¿
C_◌ְ ◌ֱ ◌ֲ ◌ֳ ◌ִ ◌ֵ ◌ֶ ◌ַ ◌ָ ֹ ◌ֻ ◌ּ ◌ֽ ־ ◌ֿ
D_׀ ׁ◌ ׂ ◌ ׃1 װ ױ ײ ׳ ״6
E_א ב ג ד ה ו ז ח ט י ך כ ל ם מ ן
F_נ ס ע ף פ ץ צ ק ר ש ת LRMRLM

Page34WCP1256 [Arabic]

Code page-1256
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ € پ ‚ ƒ „ … † ‡ ˆ ‰ ٹ ‹ Œ چ ژ ڈ
9_ گ ‘ ’ “ ” • – — ک ™ ڑ › œ ZWNJZWJں
A_NBSP، ¢ £ ¤ ¥ ¦ § ¨ © ﻫ « ¬ SHY ® ¯
B_° ± ² ³ ´ μ ¶ · ¸ ¹ ؛ » ¼ ½ ¾ ؟
C_ﻩ ء ﺁ ﺃ ﺅ إ ئ ﺍ ﺏ ﺓ ﺕ ﺙ ﺝ ﺡ ﺥ د
D_ذ ر ز ﺱ ﺵ ﺹ ﺽ × ط ظ ﻉ ﻍ ـ ﻑ ﻕ ﻙ
E_à ﻝ â ﻡ ﻥ ﻩ و ç è é ê ë ﻯ ﻱ î ï
F_ ô ◌ُ ◌ِ ÷ ◌ّ ù ◌ْ û ü LRM RLMے

---

CSN-A2User manual 65/70

Page35WCP1258 [Vietnam]

Code page-1258
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_ € ‚ ƒ „ … † ‡ ˆ ‰ ‹ Œ
9_ ‘ ’ “ ” • – — ˜ ™ › œ Ÿ
A_ NBSP¡ ¢ £ ¤ ¥ ¦ § ¨ © ª « ¬ SHY® ¯
B_ ° ± ² ³ ´ μ ¶ · ¸ ¹ º » ¼ ½ ¾ ¿
C_ À Á Â Ă Ä Å Æ Ç È É Ê Ë  ̀ Í Î Ï
D_ Đ Ñ  ̉ Ó Ô Ơ Ö × Ø Ù Ú Û Ü Ư  ̃ ß
E_ à á â ă ä å æ ç è é ê ë  ́ í î ï
F_ đ ñ  ̣ ó ô ơ ö ÷ ø ù ú û ü ư ₫ ÿ

Page36 ISO-8859-2[Latin 2]

Code page-8859-2
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSPĄ ˘ Ł ¤ Ľ Ś § ¨ Š Ş Ť Ź SHYŽ Ż
B_ ° ą ˛ ł ´ ľ ś ˇ ¸ š ş ť ź ˝ ž ż
C_ Ŕ Á Â Ă Ä Ĺ Ć Ç Č É Ę Ë Ě Í Î Ď
D_ Đ Ń Ň Ó Ô Ő Ö × Ř Ů Ú Ű Ü Ý Ţ ß
E_ ŕ á â ă ä ĺ ć ç č é ę ë ě í î ď
F_ đ ń ň ó ô ő ö ÷ ř ů ú ű ü ý ţ ˙

Page37 ISO-8859-3[Latin 3]

Code page-8859-3
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSPĦ ˘ £ ¤ Ĥ § ¨ İ Ş Ğ Ĵ SHY Ż
B_ ° ħ ² ³ ´ μ ĥ · ¸ ı ş ğ ĵ ½ ż
C_ À Á Â Ä Ċ Ĉ Ç È É Ê Ë Ì Í Î Ï
D_ Ñ Ò Ó Ô Ġ Ö × Ĝ Ù Ú Û Ü Ŭ Ŝ ß
E_ à á â ä ċ ĉ ç è é ê ë ì í î ï
F_ ñ ò ó ô ġ ö ÷ ĝ ù ú û ü ŭ ŝ ˙

---

CSN-A2User manual 66/70

Page38 ISO-8859-4[Baltic]

Code page-8859-4
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSPĄ ĸ Ŗ ¤ Ĩ Ļ § ¨ Š Ē Ģ Ŧ SHYŽ ¯
B_ ° ą ˛ ŗ ´ ĩ ļ ˇ ¸ š ē ģ ŧ Ŋ ž ŋ
C_ Ā Á Â Ã Ä Å Æ Į Č É Ę Ë Ė Í Î Ī
D_ Đ Ņ Ō Ķ Ô Õ Ö × Ø Ų Ú Û Ü Ũ Ū ß
E_ ā á â ã ä å æ į č é ę ë ė í î ī
F_ đ ņ ō ķ ô õ ö ÷ ø ų ú û ü ũ ū ˙

Page39 ISO-8859-5[Cyrillic]

Code page-8859-5

_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F

8_

9_

A_ NBSPЁ Ђ Ѓ Є Ѕ І Ї Ј Љ Њ Ћ Ќ SHYЎ Џ

B_ А Б В Г Д Е Ж З И Й К Л М Н О П

C_ Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю Я

D_ а б в г д е ж з и й к л м н о п

E_ р с т у ф х ц ч ш щ ъ ы ь э ю я

F_ № ё ђ ѓ є ѕ і ї ј љ њ ћ ќ § ў џ

Page40 ISO-8859-6[Arabic]

Code page-8859-6
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSP ¤ ، SHY
B_ ؛ ؟
C_ ء ﺁ ﺃ ﺅ إ ئ ﺍ ﺏ ﺓ ﺕ ﺙ ﺝ ﺡ ﺥ د
D_ ذ ر ز ﺱ ﺵ ﺹ ﺽ ط ظ ﻉ ﻍ
E_ ـ ﻑ ﻕ ﻙ ﻝ ﻡ ﻥ ﻩ و ﻯ ﻱ ◌ً ◌ٌ ◌ٍ ◌َ ◌ُ

---

CSN-A2User manual 67/70

F_ ◌ِ ◌ّ ◌ْ

Page41 ISO-8859-7[Greek]

Code page-8859-7
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSP‘ ’ £ € ₯ ¦ § ¨ © ͺ « ¬ SHY ―
B_ ° ± ² ³ ΄ ΅ Ά · Έ Ή Ί » Ό ½ Ύ Ώ
C_ ΐ Α Β Γ Δ Ε Ζ Η Θ Ι Κ Λ Μ Ν Ξ Ο
D_ Π Ρ Σ Τ Υ Φ Χ Ψ Ω Ϊ Ϋ ά έ ή ί
E_ ΰ α β γ δ ε ζ η θ ι κ λ μ ν ξ ο
F_ π ρ ς σ τ υ φ χ ψ ω ϊ ϋ ό ύ ώ

Page42ISO-8859-8[Hebrew]

Code page-8859-8
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSP ¢ £ ¤ ¥ ¦ § ¨ © × « ¬ SHY® ¯
B_ ° ± ² ³ ´ μ ¶ · ¸ ¹ ÷ » ¼ ½ ¾
C_
D_ ‗
E_ א ב ג ד ה ו ז ח ט י ך כ ל ם מ ן
F_ נ ס ע ף פ ץ צ ק ר ש ת LRMRLM

Page43 ISO-8859-9[Turkish]

Code page-8859-9
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSP¡ ¢ £ ¤ ¥ ¦ § ¨ © ª « ¬ SHY® ¯
B_ ° ± ² ³ ´ μ ¶ · ¸ ¹ º » ¼ ½ ¾ ¿
C_ À Á Â Ã Ä Å Æ Ç È É Ê Ë Ì Í Î Ï
D_ Ğ Ñ Ò Ó Ô Õ Ö × Ø Ù Ú Û Ü İ Ş ß
E_ à á â ã ä å æ ç è é ê ë ì í î ï
F_ ğ ñ ò ó ô õ ö ÷ ø ù ú û ü ı ş ÿ

---

CSN-A2User manual 68/70

Page44 ISO-8859-15 [Latin 3]

Code page-8859-15
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_
9_
A_ NBSP¡ ¢ £ € ¥ Š § š © ª « ¬ SHY® ¯
B_ ° ± ² ³ Ž μ ¶ · ž ¹ º » Œ œ Ÿ ¿
C_ À Á Â Ã Ä Å Æ Ç È É Ê Ë Ì Í Î Ï
D_ Ð Ñ Ò Ó Ô Õ Ö × Ø Ù Ú Û Ü Ý Þ ß
E_ à á â ã ä å æ ç è é ê ë ì í î ï
F_ ð ñ ò ó ô õ ö ÷ ø ù ú û ü ý þ ÿ

Page45 Thai2

Page46CP856 ()

Code page 856
_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F
8_А Б В Г Д Е Ж З И Й К Л М Н О П
9_Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю Я
A_а б в г д е ж з и й к л м н о п
B_р с т у ф х ц ч ш щ ъ ы ь э ю я
C_└ ┴ ┬ ├ ─ ┼ ╣ ║ ╚ ╔ ╩ ╦ ╠ ═ ╬ ┐
D_░ ▒ ▓ │ ┤ № § ╗ ╝ ┘ ┌ █ ▄ ▌ ▐ ▀

---

CSN-A2User manual 69/70

E_α ß Γ π Σ σ μ τ Φ Θ Ω δ ∞ φ ε ∩
F_≡ ± ≥ ≤ ⌠ ⌡ ÷ ≈ ° ∙ · √ ⁿ ² ■ NBSP

Page47 Cp874

Code page 874

_0 _1 _2 _3 _4 _5 _6 _7 _8 _9 _A _B _C _D _E _F

8_€ …

9_ ‘ ’ “ ” • – —

A_ ก ข ฃ ค ฅ ฆ ง จ ฉ ช ซ ฌ ญ ฎ ฏ

B_ฐ ฑ ฒ ณ ด ต ถ ท ธ น บ ป ผ ฝ พ ฟ

C_ภ ม ย ร ฤ ล ฦ ว ศ ษ ส ห ฬ อ ฮ ฯ

D_ะ ّـ า ◌ํา ّـ ّـ ّـ ّـ ّـ ّـ ّـ ฿

E_เ แ โ ใ ไ ๅ ๆ ّـ ّـ ّـ ّـ ّـ ّـ 。 ّـ ๏

F_๐ ๑ ๒ ๓ ّـّـ๔ ๕ ๖ ๗ ๘ ๙ ๚ ๛ NBSP

Appendix 2 International character set:

ASCII Code(Hex)
County
23 24 40 5B 5C 5D 5E 60 7B 7C 7D 7E
U.S.A. # $ @ [ \ ] ^ ` { | } ~
France # $ à ◦ ç § ^ ` é ù è ¨
Germany # $ § Ä Ö Ü ^ ` ä ö ü ß
U.K. £ $ @ [ \ ] ^ ` { | } ~
DenmarkⅠ # $ @ Æ Ø Å ^ ` æ ø å ~
Sweden # ¤ É Ä Ö Å Ü é ä ö å ü
Italy # $ @ ° \ é ^ ù à ò è ì
SpainⅠ Pt $ @ ¡ Ñ ¿ ^ ` ¨ ñ } ~
Japan # $ @ [ ¥ ] ^ ` { | } ~
Norway # ¤ É Æ Ø Å Ü é æ ø å ü
DenmarkⅡ # $ É Æ Ø Å Ü é æ ø å ü
SpainⅡ # $ á ¡ Ñ ¿ é ` í ñ ó ú
Latin # $ á ¡ Ñ ¿ é ü í ñ ó ú
Korea # $ @ [ ₩ ] ^ ` { | } ~
Slovenia/Croatia # $ Ž Š Ď Ć Č ž š ď ć č
China # ¥ @ [ \ ] ^ ` { | } ~

---

CSN-A2User manual 70/70

---
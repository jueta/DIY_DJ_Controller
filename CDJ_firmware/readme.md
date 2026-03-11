For PCF8575 I2C I'm connecting to arduino ports 2 and 3. Then it has 16 buttons connected to it with an input pullup resistor connected to its hardware. When pressed, it shorts to the input pullup, otherwise it's grounded.

For the 74HC4067, the signal wire is connected to A0. The S0 is connected to arduino pin 15. The S1 is connected to 14. The S2 is connected to 16. The S3 is connected to pin 10. This IC is measuing 15 analog reads for the potentiomenters, both linear and rotary ones.

Arduino pins 4 and 5 are connected to the rotary enconder for music selection (the top middle one).

Also Arduino pins 8 and 9 are connected to a rotary encoder and pins 6 and 7 to another rotary encoder. Both are the encoders for the jog wheels.

Also Arduino pins A3, A2 and A1 are connected to buttons without an hardware pullup resistors. So they need to have the software internal input pullup configuration. Those are the 3 buttons for music selection on the top.


Button 1: deck 1 loop in
Button 0: deck 1 loop out
button 7: deck 1 play/pause
button 6: deck 1 cue
pot 14: deck 1 tempo fader
Pot 12: deck 1 master
button 4, 5, 2 and 3: deck 1 function buttons.
Jog wheel 2: it's actually the jog wheel 1.
Button A1: Load music to deck 1
Button A2: Load music to deck 2
Music encoder: is the music encoder selection
Button A3: the music encoder selection button, usually used for navigating directories.
Pot 0: Deck 1 gain
Pot 2: Deck 1 high 
Pot 4: Deck 1 mid
Pot 6: Deck 1 Low
Pot 8: Deck 1 Filter
Pot 13: Mixer fader
Pot 1: Deck 2 gain
Pot 3: Deck 2 high
Pot 5: Deck 2 mid
Pot 7: Deck 2 Low
Pot 9: Deck 2 filter
Pot 10: Deck 2 master
Button 14: Deck 2 loop in
Button 15: Deck 2 loop out
Button 13: Deck 2 play/pause
Button 12: Deck 2 Cue
Buttons 10, 11, 9, 8: Deck 2 function buttons.
Pot 11: deck 2 tempo fader.
Jog wheel 1: it's actually jog wheel 2.
##ZedBoard Asteroids
HDMI game console for ZedBoard that plays the game Asteroids. 
Created for EECE4534 - Microprocessor Based Design.

Notes:
- Currently updates game model and draws game objects 
- Everything is done in one loop (in main.c)
- To set up workspace, extract Zynq_HDMI_Workspace.zip and set SDK workspace to the HDMI directory. 
- Make sure to follow [this link](http://www.xilinx.com/support/answers/52971.html) if sin, cos, and abs functions are not defined

Todo:
- Set up controller function and struct
- Fix bugs

Bug List:
 - Change asteroids to use floats so that they can travel diagonally
 - Change model of ship so that it rotates
 - Score does not increase when ship collides with asteroids
 - Ship travels too fast
 - Ship travels in the wrong direction
 - When TV first turns on, it tries to use 1080i instead of 800x600
 - Ship acceleration needs work
 - Asteroid ship collisions are not working unless ship is completely surrounded by asteroid
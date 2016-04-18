##ZedBoard Asteroids
HDMI game console for ZedBoard that plays the game Asteroids. 
Created for EECE4534 - Microprocessor Based Design.

Notes:
- Currently updates game model and draws game objects 
- Everything is done in one loop (in main.c)
- To set up workspace, extract Zynq_HDMI_Workspace.zip and set SDK workspace to the HDMI directory. 
- Make sure to follow [this link](http://www.xilinx.com/support/answers/52971.html) if sin, cos, and abs functions are not defined

Todo:
- Draw game objects in models.h (Use large asteroids as example)
- Set up controller function and struct
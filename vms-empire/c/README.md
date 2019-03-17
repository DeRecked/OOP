# **VMS Empire**

## The program is comprised of the following files:
   - attack.c
   - compmove.c
   - data.c
   - display.c
   - edit.c
   - empire.c
   - empire.h
   - extern.h
   - game.c
   - main.c
   - map.c
   - math.c
   - object.c
   - term.c
   - usermove.c
   - util.c

## The source files can be broken down into the following basic functional categories:

**Definitions** <br />
extern.h	: Contains global variable definitions <br />
empire.h	: Defines all data structures (mostly structs and #define statements) <br />
data.c		: Defines all constants used for game function <br />

**Main** <br />
main.c		: Program entrypoint; parses program arugments and calls empire() <br />
empire.c	: Contains empire() function to run game. This is the main game loop <br />

**Screen** <br />
display.c	: Updates the screen <br />
term.c		: Updates informational area of screen <br />

**Map** <br />
game.c		: Sets up and managers the game board <br />
edit.c		: Allows user to edit game in edit mode <br />

**Actions** <br />
object.c	: Manipulating objects in game <br />
attack.c	: Handles attacking <br />
usermove.c	: Handles user moves <br />
compmove.c	: Handles computer moves <br />
map.c		: finds path to move peices <br />

**Misc** <br />
math.c		: Math functions <br />
util.c		: Misc functions and I/O <br />

## The above section can be used to create a high-level abstraction of the cpp version of the program:

**Definitions** <br />
**Creating/Running game obj** <br />
**(Game) Object classes** <br />
**Manipulation of game objects** <br />
**I/O (screen, user input, etc.)** <br />

## Questions to answer:

Should each in-game object (such as an army) be a unique object of a class? <br />
Should constants (data.c) be defined in their own .hpp/.cpp file, or rolled into their respective classes? <br />


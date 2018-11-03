# piw_piw

## Authors:
* marsakov
* oevtushe

## Intructions:

The goal of this project is to implement a simplistic shoot-em-up
style game in your terminal.

### Requirements:

You will use a screen made up of a grid of 'squares'.
These can be equated to the characters on your terminal.
Entities of your game are each represented by a character on the screen.

*Controls:*

* Arrows movement.
* Spacebar to fire lasers

*Features*
* Single-player mode
* Display using the ncurses library
* Horizontal or vertical scrolling
* The player can shoot at enemies
* Basic collision handling (if an enemy touches you, you die!)
* Game entities occupy one 'square' of the map only.
* Frame-based timing
* Display score, time, number of lives on the screen
* Clock-based timing using whatever system facilty or library you like
* Entities that can occupy multiple squares
* Enemies can also shoot

### Run:

	git clone https://github.com/marsakov/piw_piw.git
	cd piw_piw
	make
	./piw_piw

#### Our future depends on you!

![Image alt](https://github.com/marsakov/piw_piw/raw/master/img/start.png)
![Image alt](https://github.com/marsakov/piw_piw/raw/master/img/end.png)
![Image alt](https://github.com/marsakov/piw_piw/raw/master/img/game.png)
![Image alt](https://github.com/marsakov/piw_piw/raw/master/img/win.png)

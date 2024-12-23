Alex Ostapyuk

Hello, this is my Fruit Fall project. In this game, the goal is to catch as many fruit as possible

What have I implemented?

1) I added DrawOpposite() functions in rendering so I can use with the key handler, so when the right arrow key is 
pressed and the image should flip, it will flip and move with the proper key. The way I did this was have a bool 
variable to keep track of the direction it is facing, the original is assuming its facing the left side. When a key 
like right arrow is pressed, the image will flip horizontally so it is moving smoothly

2) FruitFall files contain the creation of fruits, fruits' visibility disappearing, fruit constant falling and fruit
colliding with character

-In creation of fruits, or addFruit() function is when a new fruit will be added to the game at a random x location
in the game and at a high y level in the game window

-In fruits' visibility disappearing, or deleteFruit() when this function is called, the fruit will dissapear if it 
collides with the character or falls at a zone where the character cannot reach

-In fruit falling function or fallingFruit(), the fruit will constantly fall till a deleteFruit condition comes up

-In fruit colliding with character, or collideFruit() it checks if the character and fruit collides, if it does then
we will change the visibility of the apple to dissapear

I also added ctime in order to have the fruit spawn every 2 seconds

3) I did not want the character to move out of the window frame, so I made restrictions to the key handler to only
allow the character to move within the window
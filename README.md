# ShootingBirdGame
Shoot Birds Game, made with QT and C++.

This is a type of game I have seen designed many different ways over the years and I wanted to do my own version. Particularly interesting was using the math library to engage with the Trig functions in order to ascertain the rotation angle for the Bow so that it can always follow the mouse. The way it works is that each mouse movement triggers an event which is captured by the Bow. Then an invisible line is drawn from the centre of the bow to the current position of the mouse and the angle this makes with the horizontal is easily obtained using the definition of Sine.

Using this I could then swivel the Bow image using a rotational transform and this gives the appearance of the bow always being in sync with the position of the mouse. This provides the game mechanism for targeting the birds as they fly by.

The birds spawn randomly, and the effect of flapping is achieved by swapping out the image of each bird with alternate wing positions. Each bird is an object as are the arrows and when they collide the bird is replaced with a puff cloud to indicate it's been hit and the score is incremented by one. Arrows
can be fired one at a time, or the mouse key can be held down for a continuous auto fire.

If any birds make it past the screen, they are automatically deleted and their memory is cleaned up to prevent leaks. Similarly each arrow is destroyed and removed from the Graphics Scene when it leaves the visible area of the screen also, again to prevent memory leaks.

https://user-images.githubusercontent.com/111576658/201339107-bd5561b3-5f50-4518-96b3-fc1ef07997ec.mp4


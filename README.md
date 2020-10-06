# Image-Modification-2
Use recursion to perform image segmentation and linked lists to store some results

Your image class should include (at least) the following capabilities. Use my image library as much as possible to make these simple. For example, store an image variable in your private data. Use ReadGIF to implement the first constructor, etc.

Constructor using a filename (read from a file)
Constructor using just the number of rows and columns (create a blank, black image)
Copy constructor, destructor, operator= (these are important, since ImageLib uses dynamic memory!)
Accessors for the number of rows and columns in the image
Accessor and mutator functions for individual image pixels
Output to a file
Overload the == and != operator for comparison of images (every pixel must be the same)
Overload the > and < operators. We will say that an image is “greater than” another image if it contains more pixels and “less than” another image if it contains less pixels.
Overload the << operator to output the number of rows and columns in the image (ignore the pixels)
Create a method that returns a  mirror-image of the original image. (The return value should be an object of your new class returned by value. Do not modify the input image.)
Now, using your image class (and without writing any more methods), write a driver (main method) that performs the following operations. These are similar to Program 1, except that you should use the interface provided by your class and not use ImageLib directly.

Read the image “test2.gif”.
Output the number of rows and columns using operator<<.
Create a mirror image using your member function (use this image as the input to step 4).
For every pixel, subtract row mod 7 from the blue component and add col mod 9 to the red component. Continue to check for (and correct) overflow and underflow.
Write the image as “output.gif” and read that file back into a new variable.
Compare the image that you wrote to the image read in the previous step using your == operator for images.
If the images are different, count the number of different pixels.
Output the number of differences.

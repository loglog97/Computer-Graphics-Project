# Computer-Graphics-Project
By: Logan Cole

**Description**
* When compiled and ran, the code will display a 2D image of a wartortle made to look 3D
  * It is turned a few degrees to see the edges of the image
  * The faces shown to make it appear to be 3D is just using darker color values to give the illusion
  * Besides coloring the vertices, no light is being used

**Purpose**
* Created for Intro to Computer Graphics to teach the basics of OpenGL
  * Using Glew and FreeGlut

**Compiling**
* Once the nessecary libraries are installed, make sure the Mesa version is set to 4.5 for color
* In terminal:
  * Once in directory, using "make all" will compile the project, and is then able to be ran with "./pixel"

**Zipping the project**
* For distributing, using "make zip" will zip all source files including the make file

**Cleaning Object files**
* Using "make clean" in the terminal directory will remove all object files that were created
  * If a zip file has been made, it will also remove it.

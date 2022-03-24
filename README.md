# OpenFL
This is a very simple header only library that replaces "fstream" in cases where ease-of-use by the programmer is more important than optimization.  

The whole thing is just one file `openfl.hpp`. No need for editing linker settings or anything like that.

Just include it and you're good to go!

# Why you would want to use this
+ You don't know how to use fstream, or at least find it too cumbersome
+ You need a fast to deploy method, that only requires two lines of code to open a file and read/store any data
+ You want to more easily save and load data for games, or other more complex applications (not fully supported yet)

# How to use it
+ Download `openfl.hpp` and include it in your project
+ Create a variable of type OpenFL, and chose wether you want to write or read from the file at the given path
  + `OpenFL f { RWType::READ, "path/to/file.xyz" };`
+ Use "storeString()" to store a string when you are in write mode
  + `f.storeString("string-to-store", false);` this will store the string in the file, overwriting already existing contents
  + `f.storeString("string-to-store", true);` this will append the string to the file, without instering a new line
+ Use "fileContents" to read the file contents as a char array
  + `string s = f.fileContents;` variable `s` now holds the contents of the file
+ Use "len" to get the length of the loaded file
  + `int x = f.len;` varible `x` now holds the length or size of the file contents

# Future plans
- [ ] CSV support, with option for custom sepparator
- [ ] JSON support
- [ ] Custom file format OFL support, made for storing stuff like game data
- [ ] Create a DLL version, for faster compile times
- [ ] BMP loading for OpenGL

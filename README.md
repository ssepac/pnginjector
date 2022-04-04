# pnginjector
Inserts a tEXt chunk into a given png image. 

## How to use
The following args should be passed to the executable:
1) The input directory of the png image.
2) The output directory of the png image.
3) The keyword for the tEXt chunk. (See [4.2.3.1. tEXt Textual data here](http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html))
4) The text to include, relative to the keyword. 

## Notes
- Assumes that the tEXTt chunk should be added at n-12 bytes of the png file.

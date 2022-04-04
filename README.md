# pnginjector
Inserts a tEXTt chunk with a keyword "IPFS" and the hash of the resource on the IPFS. 

## How to use
Change the input and output .png file path to where you'd like it.

## Notes
- If the IPFS hash is longer than 80 characters, this should be refactored to use compressed text.
- Assumes that the tEXTt chunk should be added at n-12 bytes of the png file.

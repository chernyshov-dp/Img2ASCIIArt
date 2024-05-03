# Image to ASCII art
This simple image converter allows you to create ASCII art from PNG images. It converts a color image to a black and white image, then replaces each pixel with an ASCII character based on its brightness, creating ASCII art.

## Build
```console
mkdir build && cd build
cmake ..
make
```

## Usage
```console
./Img2ASCIIArt <image_path> [output_width output_height]
```

## Dependencies
[libpng++](http://www.libpng.org/pub/png/libpng.html)

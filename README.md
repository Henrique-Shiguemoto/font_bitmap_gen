# font_bitmap_gen

This is a simple tool I use to generate bitmaps based on a font image (just like the <code>6x7_custom_font.png</code> file).

It uses [stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h) for image loading and stdio.h to create a .c file with a, unsigned int array of pixels color values.

#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char const *argv[]) {
	int w, h, c_count;
	unsigned char* data = stbi_load("6x7_custom_font.png", &w, &h, &c_count, 0);
	if(!data){
		printf("Error! Couldn't load file.\n");
		return 1;
	}

	FILE* output_file = fopen("custom_font.c", "w");
	fprintf(output_file, "const unsigned int custom_font_bmp[%i * %i] = {\n", w, h);

	unsigned int* pixel = (unsigned int*)data;
	unsigned int current_pixel = *pixel;

	while(current_pixel != 0xFF0000FF){
		fprintf(output_file, "\t0x%04x,\n", current_pixel);
		pixel++;
		current_pixel = *pixel;
	}

	fprintf(output_file, "\t0x%04x,\n", 0xFFFFFFFF);
	fprintf(output_file, "\n};\n");

	stbi_image_free(data);
	fclose(output_file);
	return 0;
}

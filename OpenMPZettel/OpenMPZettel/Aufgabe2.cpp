#include "stdafx.h"
#include "bitmap_image.hpp"

using namespace std;
// <>
int main()
{
	int width = 200;
	int height = 200;
	bitmap_image image(width, height);
	// set background to random Values
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image.set_pixel(i, j, rand() % 255, rand() % 255, rand() % 255);
		}
	}
	// set the background to grayscale
	image.convert_to_grayscale();
	//checkered_pattern(30, 30, 230, bitmap_image::red_plane, image);
	//checkered_pattern(30, 30, 0, bitmap_image::green_plane, image);
	//checkered_pattern(30, 30, 100, bitmap_image::blue_plane, image);

	image_drawer draw(image);

	draw.pen_width(3);
	draw.pen_color(255, 0, 0);
	draw.circle(image.width() / 2, image.height() / 2, 50);

	draw.pen_width(1);
	draw.pen_color(0, 0, 255);
	draw.rectangle(50, 50, 150, 150);
	
	image.save_image("output.bmp");

	return 0;
}

float Vektor1a(float y, float Y)
{
	return (-(y - (2 / 8) * Y));
}

float Vektor1b(float x, float X)
{
	return (x - (1 / 5)*X);
}
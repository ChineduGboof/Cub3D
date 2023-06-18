# Image Manipulation

This code includes functions related to image manipulation. Let's summarize the functionality and need for these functions:

## Color Conversion

- The `int_to_color` function converts an integer-based color representation to a `t_color` structure. It extracts the transparency, red, green, and blue components from the source color and assigns them to the respective fields of the `t_color` structure.
- The `unsigned_int_to_color` function performs the same operation as `int_to_color` but with an unsigned integer as the source.

## Image Creation and Import

- The `create_image` function creates a new image structure and initializes its fields. It allocates memory for the `t_image` structure, creates an image, retrieves image information, and assigns the width and height. The resulting image structure is returned.
- The `import_image` function imports an image from a file using a specific format (e.g., XPM). It creates a new image structure, loads the image from the file, retrieves image information, and returns the resulting image structure.

## Painting and Pixel Manipulation

- The `paint_image` function paints a specified range of rows in the image with the specified color. It iterates over the rows and pixels within the specified range and updates the color of each pixel in the image.
- The `get_pixel_index` function calculates the index of a pixel in the image's pixel data array. It takes into account the bits per pixel and line length to calculate the correct index.
- The `put_pixel_into_image` function updates a pixel in the image with the specified color. It calculates the destination address of the pixel using `get_pixel_index` and assigns the color components to the respective bytes in the destination address.

These functions are essential for working with images within a graphical application. They provide the capability to convert color representations, create or import images, paint specific areas of an image, and manipulate individual pixels. They enable the display of visual content and the ability to modify images as needed in various graphics-related applications.

## Break Down of Each Function 

The code includes functions related to image manipulation. Let's go through each function:

1. `t_color int_to_color(int source_color)`: This function converts an integer-based color representation to a `t_color` structure. It extracts the transparency, red, green, and blue components from the source color using bit shifting and bitwise AND operations and assigns them to the respective fields of the `t_color` structure.

2. `t_color unsigned_int_to_color(unsigned int source_color)`: This function converts an unsigned integer-based color representation to a `t_color` structure. It performs the same operations as the `int_to_color` function but with an unsigned integer as the source.

3. `t_image *create_image(void *mlx, int width, int height)`: This function creates a new image structure and initializes its fields. It allocates memory for the `t_image` structure, creates an image using `mlx_new_image`, retrieves information about the image (bits per pixel, line length, endian) using `mlx_get_data_addr`, and assigns the width and height. The resulting image structure is returned.

4. `t_image *import_image(void *mlx_ptr, char *relative_path)`: This function imports an image from a file using the XPM format. It creates a new image structure, allocates memory for it, loads the image using `mlx_xpm_file_to_image`, retrieves the image information, and returns the resulting image structure.

5. `void paint_image(t_image *image, t_color color, int y_start, int y_end)`: This function paints a specified range of rows in the image with the specified color. It iterates over the rows specified by `y_start` and `y_end` and iterates over each pixel in the row. It creates a `t_pixel` structure with the pixel coordinates and color and calls `put_pixel_into_image` to update the pixel in the image with the specified color.

6. `int get_pixel_index(t_image *image, t_pixel pixel)`: This function calculates the index of a pixel in the image's pixel data array. It takes into account the bits per pixel and line length to calculate the correct index.

7. `void put_pixel_into_image(t_image *image, t_pixel pixel)`: This function updates a pixel in the image with the specified color. It calculates the destination address of the pixel using `get_pixel_index` and assigns the color components (blue, green, red, transparency) to the respective bytes in the destination address.

These functions are likely used in conjunction with the MLX library or a similar graphics library to create, manipulate, and display images within a graphical application.
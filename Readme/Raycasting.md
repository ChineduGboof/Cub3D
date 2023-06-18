Raycasting is a technique used in computer graphics to create a 3D perspective in 2D environments, often used in games like Wolfenstein 3D.

# Raycasting Engine Functions

This project implements a raycasting engine to create a 3D-like representation of a 2D environment. The engine uses a combination of mathematical calculations and data processing to cast rays from the player's position and render the scene. Let's summarize the functions and their role in the raycasting process:

## Core Raycasting Functions

### determine_drawing_range
This function calculates the start and end points of the vertical range on the screen where a vertical line will be drawn.

### determine_texture_point_x
This function calculates the texture point along the x-axis for a specific ray hit.

### initialize_y_related_values
This function initializes the values related to the y-coordinate of the drawing process.

### draw_vertical_line
This function draws a vertical line on the screen using the provided drawing and ray information.

### determine_grid_spacings
This function determines the grid spacings for the x and y directions based on the ray direction.

### determine_step
This function determines the step values for the x and y directions based on the ray direction.

### determine_nearest_boundary_distances
This function calculates the distances to the nearest boundaries in the x and y directions based on the ray position and grid spacings.

### raycasting_cockpit
This is the main raycasting function. It performs the raycasting process for each x-coordinate on the screen. It calculates the ray direction, determines the grid spacings, steps, nearest boundary distances, wall hit direction, distance to wall, drawing range, wall hit location, and selects the appropriate texture.

### fill_image
This function fills the image with the raycasted scene. It iterates over each x-coordinate and calls `raycasting_cockpit` to perform the raycasting process.

## Supporting Functions

### calculate_ray_direction
This function calculates the ray direction based on the player's direction and the offset from the center of the screen.

### choose_texture
This function selects the appropriate texture based on the wall hit direction.

### rotate_vector
This function rotates a vector by a given angle.

### determine_distance_to_wall
This function determines the distance to the wall based on the wall hit direction and the nearest boundary distances.

### determine_wall_hit_location
This function determines the wall hit location based on the ray info, player position, and distance to the wall.

### take_horizontal_step
This function updates the ray info and wall hit direction when taking a horizontal step.

### take_vertical_step
This function updates the ray info and wall hit direction when taking a vertical step.

### send_ray
This function sends a ray through the map to determine the wall hit direction. It iteratively steps horizontally or vertically until a wall is hit.

These functions work together to perform the raycasting process, calculating ray directions, determining wall hit locations, and drawing the scene onto an image. The raycasting engine provides the foundation for creating a 3D-like representation of the game environment.

## Break Down of Each Function 

Let's go through the functions one by one and provide a brief explanation of each:

1. `void determine_drawing_range(t_drawing_range *drawing_range, int line_height)`: This function calculates the start and end points of the vertical range on the screen where a vertical line will be drawn. It takes the `line_height` and updates the `drawing_range` structure accordingly.

2. `void determine_texture_point_x(int *texture_point_x, t_ray_info ray_info, int current_texture_width)`: This function calculates the texture point along the x-axis for a specific ray hit. It takes the `ray_info` and the `current_texture_width` and updates the `texture_point_x` accordingly.

3. `void initialize_y_related_values(double *y_addend, double *y_double, t_drawing_info drawing_info)`: This function initializes the values related to the y-coordinate of the drawing process. It takes the `drawing_info` and updates the `y_addend` and `y_double` variables accordingly.

4. `void draw_vertical_line(t_drawing_info drawing_info, t_ray_info ray_info, t_image *image, int x_index)`: This function draws a vertical line on the screen using the provided drawing and ray information. It iterates over the y-coordinates within the drawing range and determines the texture point and color for each pixel.

5. `void determine_grid_spacings(t_grid_spacings *grid_spacings, t_vector ray_direction)`: This function determines the grid spacings for the x and y directions based on the ray direction.

6. `void determine_step(t_step *step, t_vector ray_direction)`: This function determines the step values for the x and y directions based on the ray direction.

7. `void determine_nearest_boundary_distances(t_nearest_boundary_distances *nearest_boundary_distances, t_ray ray, t_grid_spacings grid_spacings)`: This function calculates the distances to the nearest boundaries in the x and y directions based on the ray position and grid spacings.

8. `void raycasting_cockpit(t_ray_info *ray_info, t_drawing_info *drawing_info, t_image *image, t_game *game)`: This is the main raycasting function. It performs the raycasting process for each x-coordinate on the screen. It calculates the ray direction, determines the grid spacings, steps, nearest boundary distances, wall hit direction, distance to wall, drawing range, wall hit location, and selects the appropriate texture. Finally, it calls `draw_vertical_line` to draw the vertical line on the screen.

9. `void fill_image(t_image *image, t_game game)`: This function fills the image with the raycasted scene. It iterates over each x-coordinate and calls `raycasting_cockpit` to perform the raycasting process.

10. `t_vector calculate_ray_direction(t_player player, double offset_from_center)`: This function calculates the ray direction based on the player's direction and the offset from the center of the screen.

11. `t_image *choose_texture(t_game game, int wall_hit_direction)`: This function selects the appropriate texture based on the wall hit direction.

12. `void rotate_vector(t_vector *vector, double angle)`: This function rotates a vector by a given angle.

13. `void determine_distance_to_wall(double *distance_to_wall, int wall_hit_direction, t_nearest_boundary_distances nearest_boundary_distances, t_grid_spacings grid_spacings)`:

 This function determines the distance to the wall based on the wall hit direction and the nearest boundary distances.

14. `void determine_wall_hit_location(t_ray_info *ray_info, t_vector player_position, double distance_to_wall)`: This function determines the wall hit location based on the ray info, player position, and distance to the wall.

15. `void take_horizontal_step(t_ray_info *ray_info, int *wall_hit_direction)`: This function updates the ray info and wall hit direction when taking a horizontal step.

16. `void take_vertical_step(t_ray_info *ray_info, int *wall_hit_direction)`: This function updates the ray info and wall hit direction when taking a vertical step.

17. `int send_ray(t_ray_info *ray_info, int **map)`: This function sends a ray through the map to determine the wall hit direction. It iteratively steps horizontally or vertically until a wall is hit.

Overall, these functions work together to perform raycasting and generate a 3D-like representation of a 2D environment.
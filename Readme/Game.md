# Raycasting Game

This project implements a raycasting game that creates a 3D-like representation of a 2D environment. The game involves moving a player within a map and exploring the surroundings. Let's summarize the different components and their functionalities:

## Display and Input Handling

- The `refresh_display` function updates the game's display by painting the ceiling and floor colors onto the image, filling the image with game elements, and putting the image on the window.
- The `on_keydown` function handles key press events. It allows the player to control the movement and rotation of the player character. The game terminates if the Escape key is pressed.
- The `on_destroy` function is called when the game window is closed, ensuring a proper termination of the game.

## Player Movement and Rotation

- The `calculate_new_position` function determines the new position of the player based on the current position, movement direction, and player's direction vector.
- The `is_valid_position` function checks if a given position is within the game's map boundaries and corresponds to an empty space.
- The `move_player` function updates the player's position if it's a valid position and refreshes the display.
- The `rotate_player` function adjusts the player's direction and plane vectors based on the rotation direction (LEFT or RIGHT) and refreshes the display.

## Game Initialization and Termination

- The `fill_game_struct` function populates the game structure with the map and player information based on the provided specifications.
- The `run_game` function is the entry point of the game. It initializes the game and MLX resources, fills the game structure, loads textures, and starts the game loop.
- The `load_textures` function loads the textures for the game walls using the provided image paths. It returns true if all the textures are successfully loaded, otherwise false.
- The `free_textures` function frees the memory allocated for the texture image paths.
- The `release_mlx_resources` function releases the MLX resources, including the image and window objects.
- The `safely_terminate` function ensures a safe termination of the game by releasing resources, freeing memory, and exiting the program.
- The `terminate_with_message` function prints an error message, safely terminates the game, and exits with the provided error code.

These functions collectively handle the game logic, including user input, player movement, rendering, and resource management. The game provides an immersive experience by simulating a 3D environment using raycasting techniques.

## Break Down of Each Function 

Here's a breakdown of the code and its functionality:

1. The `refresh_display` function updates the display by painting the ceiling and floor colors onto the image, filling the image with game elements, and then putting the image on the window using `mlx_put_image_to_window`.

2. The `on_keydown` function handles key press events. If the keycode corresponds to the Escape key, it terminates the game. Otherwise, it checks for specific keycodes (W, S, D, A, Left, Right) and calls the corresponding functions (`move_player` and `rotate_player`) to update the player's position or rotation.

3. The `on_destroy` function is called when the game window is closed. It also terminates the game.

4. The `calculate_new_position` function calculates the new position of the player based on the current position, movement direction, and player's direction vector.

5. The `is_valid_position` function checks if a given position (x, y) is valid within the game's map boundaries and if it corresponds to an empty space (0) on the map.

6. The `move_player` function moves the player to a new position if it's a valid position and then refreshes the display.

7. The `rotate_player` function updates the player's direction and plane vectors based on the rotation direction (LEFT or RIGHT) and then refreshes the display.

8. The `fill_game_struct` function populates the game structure with the map and player information based on the provided specifications.

9. The `run_game` function is the entry point of the game. It initializes the game and MLX resources, fills the game structure, loads textures, and starts the game loop using `mlx_loop`.

10. The `load_textures` function loads the textures for the game walls using the provided image paths. It returns true if all the textures are successfully loaded, otherwise false.

11. The `free_textures` function frees the memory allocated for the texture image paths in the specifications.

12. The `release_mlx_resources` function releases the MLX resources, including the image and window objects.

13. The `safely_terminate` function is responsible for safely terminating the game. It releases all the allocated resources, frees memory, and exits the program with the provided error code.

14. The `terminate_with_message` function prints an error message, safely terminates the game, and exits with the provided error code.

Overall, the code handles key input, updates the game state based on the input, renders the game using MLX, and manages the resources and memory.
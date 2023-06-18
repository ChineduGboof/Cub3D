# Map Conversion and Player Information Extraction

This code includes functions that handle map conversion and extract player information from the map. Let's summarize the functionality and need for these functions:

## Map Conversion

- The `get_map_height` function calculates the height of the map by counting the number of rows in the `map` array.
- The `get_map_row_width` function calculates the width of a map row by counting the number of characters in the `row` string.
- The `convert_map` function converts the map from a string-based representation to an integer-based representation. It assigns integer values to each character in the map, representing different map elements. This conversion allows for efficient processing and manipulation of the map during the raycasting process.

## Player Information Extraction

- The `get_int_map_height` function calculates the height of the integer-based map by counting the number of rows in the `map` array.
- The `get_player_position` function searches for the player position in the map and returns it as a `t_vector` structure. It identifies the coordinates where the player character ('N', 'S', 'E', or 'W') is present.
- The `get_player_direction` function determines the player's direction based on the character found in the map and returns it as a `t_vector` structure. It identifies the character representing the player's direction ('N', 'S', 'E', or 'W').
- The `determine_plane` function determines the player's camera plane direction based on the character found in the map and returns it as a `t_vector` structure. It identifies the character representing the player's direction and assigns a corresponding value for the perpendicular direction to the camera plane.

These functions are crucial for setting up the raycasting engine and providing the necessary information about the map and player. They ensure that the raycasting process operates on the correct map and properly initializes the player's position, direction, and camera plane for accurate rendering and interaction within the game.

## Break Down of Each Function 

The code includes several functions related to map conversion and extracting player information from the map. Let's go through each function:

1. `size_t get_map_height(char **map)`: This function calculates the height of the map by counting the number of rows in the `map` array.

2. `size_t get_map_row_width(char *row)`: This function calculates the width of a map row by counting the number of characters in the `row` string.

3. `int **convert_map(char **map)`: This function converts the map from a string-based representation to an integer-based representation. It allocates memory for the resulting 2D integer array and maps each character of the original map to its corresponding integer value. Player positions ('N', 'S', 'E', 'W') are mapped to 0, whitespace characters are mapped to '1', and numeric characters are converted to their integer representation.

4. `size_t get_int_map_height(int **map)`: This function calculates the height of the integer-based map by counting the number of rows in the `map` array.

5. `t_vector get_player_position(char **map)`: This function searches for the player position in the map and returns it as a `t_vector` structure. It iterates over the map and finds the coordinates where 'N', 'S', 'E', or 'W' is present, indicating the player's position.

6. `t_vector get_player_direction(char **map)`: This function determines the player's direction based on the character found in the map ('N', 'S', 'E', or 'W') and returns it as a `t_vector` structure. It iterates over the map and identifies the character representing the player's direction.

7. `t_vector determine_plane(char **map)`: This function determines the player's camera plane direction based on the character found in the map ('N', 'S', 'E', or 'W') and returns it as a `t_vector` structure. It iterates over the map and identifies the character representing the player's direction, and assigns a corresponding value for the perpendicular direction to the camera plane.

These functions are likely used in conjunction with the raycasting engine code you provided earlier to extract necessary information about the player and map before performing the raycasting process.
## Map Validation and Error Checking

The provided code includes various functions dedicated to checking the map for errors and ensuring its validity. These functions play a crucial role in detecting and handling potential issues in the map file. Here is an overview of the map validation and error checking process:

### 1. Parsing and Basic Checks
The initial functions focus on parsing and performing basic checks on the map file. These include:
- Validating the file path and ensuring it can be opened.
- Checking for missing specifications and verifying the presence of essential elements in the file.
- Verifying if the map file has a valid extension.
- Detecting if the file is empty or if there are wrong placements within the map.

### 2. Map Parsing and Structure
The code further proceeds to parse the map by reading each line and expanding the map structure accordingly. It performs the following tasks:
- Parsing the floor and ceiling colors from the file and assigning them to the corresponding variables.
- Checking for duplicate or invalid color identifiers.
- Expanding the map array and adding parsed lines to construct the map structure.

### 3. Map Error Checking
Once the map has been parsed and structured, the code executes various error checking functions to validate the map's integrity. These functions include:
- Determining the directions (north, south, east, west) in the map based on the player's initial position and direction.
- Checking if there are walls in a particular direction from a given position in the map.
- Verifying if a position is walled, meaning it has walls on all adjacent sides.
- Checking if a fence is valid, ensuring it has an opening and doesn't enclose the map completely.
- Determining the first, last, and next rows in the map for reference.
- Checking if a row is fenced, meaning it has walls on both ends.
- Performing a comprehensive map error check by examining each row for issues.

These functions collectively analyze the map structure, its elements, and the relationships between them to identify potential errors or inconsistencies. They ensure that the map follows the expected rules and can be properly rendered and navigated in the game.

## Conclusion
The provided code demonstrates a thorough approach to map validation and error checking. By employing a combination of parsing, basic checks, map structure creation, and comprehensive error checks, it ensures the map's correctness and integrity. These checks are essential to avoid rendering and gameplay issues, guaranteeing a smooth and enjoyable gaming experience.

## Break Down of Each Function 

Here is a summary of the parsing done in the provided code to make cub3D work effectively:

1. The `is_map_line` function checks if a given line represents a valid map line. It verifies that the line contains only valid characters ('0', '1', 'E', 'N', 'S', 'W', ' ', '\t') and at least one valid map character. Returns true if the line is a valid map line.

2. The `wrong_placement` function checks if there is any wrong placement in the map. It iterates through the file, checking each line using the `is_map_line` function. If a line is found that is not a valid map line after the map has started, it returns true indicating a wrong placement.

3. The `open_file` function opens a file and returns the file descriptor. If the file cannot be opened, it displays an error message and returns true.

4. The `init_specs` function initializes an array of specifications.

5. The `check_for_one` function checks if there is at least one line starting with '1' in the file. It reads each line and if a line starts with '1', it returns true.

6. The `check_for_missing_specification` function checks if there are any missing specifications in the file. It iterates through the array of specifications and for each specification, it checks if the file contains a line starting with that specification. If any specification is missing, it returns true.

7. The `has_missing_specification` function checks if the file has any missing specification or if there is no line starting with '1'. It calls the `open_file`, `check_for_missing_specification`, and `check_for_one` functions to perform the checks and returns true if any specification is missing or there is no line starting with '1'.

8. The `validate_map_file` function validates if the given file is a valid map file. It checks if the file is a directory and displays an error message if it is. Then it checks if the file can be opened and displays an error message if it can't.

9. The `check_map_file_ext` function checks if the map file has a valid file extension. It verifies that the file extension is ".cub" and displays an error message if it's not.

10. The `validate_argument` function validates the map file path. It calls the `validate_map_file` and `check_map_file_ext` functions to perform the validations.

11. The `is_empty_file` function checks if the file is empty. It opens the file, reads the first line, and if there is no line, it returns true indicating an empty file.

12. The `init_specifications` function initializes the `t_specifications` structure with default values.

13. The `parsing` function performs the overall parsing of the map file. It initializes the specifications, parses colors, textures, and the map itself.

14. The `parse_floor_color` function parses the floor color from a line and assigns it to the `specifications->floor_color` field. It checks for duplicates and invalid color identifiers.

15. The `parse_ceiling_color` function parses the ceiling color from a line and assigns it to the `specifications->ceiling_color` field. It checks for duplicates and invalid color identifiers.

16. The `parse_colors` function parses the color specifications from the map file. It reads each line and checks if it contains floor or ceiling color specifications. It calls the `parse_floor_color` and `parse_ceiling_color` functions accordingly.

17. The `too_many_commas` function checks if there are too many commas in a string. It counts the number of commas and returns true if the count exceeds 

 with the warning. (Use `!warnings` to see all warnings.)

18. The `open_map` function takes a file path as an argument and attempts to open the file for reading. If the file cannot be opened, it calls the `ft_exit_msg` function with an error message.

19. The `find_identifier` function checks if a given line contains specific identifiers related to the map specifications.

20. The `init_map` function initializes the map size and index variables, opens the map file using the `open_map` function, and allocates memory for the map using `ft_calloc`. If memory allocation fails, it calls the `free_map` function.

21. The `parse_line` function parses a single line from the map file. It skips leading whitespace, checks if the line contains any identifiers using the `find_identifier` function, trims the line using `ft_strtrim`, and then expands the map by adding the parsed line to the map array using the `expand_map` function.

22. The `parse_map` function is the main function for parsing the map file. It opens the map file, reads each line using the `get_next_line` function, trims the line, and calls `parse_line` to handle the parsed line. It closes the file after parsing and calls `check_map_errors` to validate the parsed map.

23. The `free_map` function frees the memory allocated for the map and sets the map pointer to NULL. It is called when there is an error or when the program exits.

24. The `free_map_assured` function is similar to `free_map` but additionally prints an error message before exiting.

25. The `expand_map` function expands the map array if needed and adds a new line to it. It first replaces tabs with spaces in the line, reallocates memory if necessary, and assigns the new line to the map at the specified index.

26. The `is_valid_identifier` function checks if a given string represents a valid identifier and file path pair.

27. The `print_specifications` function checks if all required texture specifications are present and exits with an error message if any are missing.

28. The `open_filepath` function is similar to `open_map` but with a different error message.

29. The `parse_textures` function opens the map file, reads each line, checks if the line contains a valid identifier using `is_valid_identifier`, and calls `parse_identifier_line` to handle the parsed line. It closes the file after parsing and calls `print_specifications` to validate the parsed texture specifications.

30. The `extract_identifier_and_path` function splits a string into an identifier and a path using whitespace as the delimiter.

31. The `set_texture_path` function assigns a texture path to a specified texture variable, checking for duplicates.

32. The `parse_identifier_line` function parses a line containing an identifier and a path. It determines the type of identifier and assigns the corresponding path to the appropriate texture variable. If the identifier is invalid, it exits with an error message.

33. The code includes some additional functions related to checking the map for errors, such as `determine_directions`, `has_wall_in_direction`, `is_walled`, `is_valid_fence`, `get_first_row`, `get_last_row`, `get_next_row`, `is_fenced`, `check_row`, and `check_map_errors`. These functions are responsible for checking various aspects of the map to ensure its validity and identify any errors.

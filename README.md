## **Introduction:**

In this project, we have developed a 2D game that involves the player moving around, collecting coins and avoiding enemies. Our aim was to become proficient in utilizing the mlx library and UI in general.

## **Game Rules:**

Our game follows a set of specific rules. The executable 'game_name' will receive a map with a .ber filetype as its only argument. The map must meet the following requirements:

    The map must contain characters P (player), 1 (wall), 0 (empty space), C (coin), and E (exit). (Enemies can be added as a bonus.)
    The map must be rectangular, i.e., all rows must have the same length.
    There must be at least one exit, one player, and one coin on the map.
    The map must be enclosed, i.e., surrounded by walls.

If any of these rules are violated, the game will end with an 'Error\n' message followed by a custom error message.

The goal of the game is for the player to collect all the coins on the map before reaching the exit in the fewest possible steps.

## **How it Works:**

We utilized the minilibx library for the graphics part of our game. It's a basic yet fun-to-use library.

## **Part 1: Reading the Map:**

We first checked that the given map was properly opened and that it had a .ber filetype. We then read the file one line at a time using get_next_line. During this process, we filled a struct with some basic map attributes such as the number of players, exits, coins, the number of rows and columns, etc. We also created a string containing the entire map, which was later useful when creating a matrix using ft_split, with '\n' as the separator.

## **Part 2: Starting the Game:**

We took the struct from Part 1 and our map matrix to build the main game struct. This struct includes more detailed information about the game state, such as a list of players and enemies, the number of loop repetitions (frames), and other relevant information. From here, we initialized a window using the mlx function and started drawing the static elements of the map (walls, spaces, and coins) on the window. The mlx library has an infinite loop where the game events happen. From here, we check the state of the game to re-print certain elements of the map or to manage special events, such as when the player is caught by an enemy. The mlx library has hooks, which link certain events on the computer (keypresses, mouse clicks, etc.) with functions we implement. We hooked the end of the game function to pressing the 'x' button to close the window. We also used a key hook to link keypresses with the player's movements.

## **Part 3: Game Mechanics:**

The game ends when the 'ESC' or 'Q' key is pressed. If the arrow keys or 'W', 'A', 'S', 'D' keys are pressed, the player changes direction and tries to move in that direction. Also, every so often, all players will move forward in the direction they're headed. Enemies behave similarly, but instead of responding to the keypress, they use a basic algorithm to find the player and try to catch them. Whenever a player is caught by an enemy, the game ends, and the player dies with a short animation. To make the game more interesting, the enemies will enter panic mode when there are fewer enemies than players. This mode causes them to move in random directions for a brief period.

Lastly, if a player reaches the exit and there are no coins left, the player will be deleted from the list of players. If all players reach the exit, the game ends, and the final score is displayed

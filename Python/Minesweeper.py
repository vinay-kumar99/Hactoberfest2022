"""A command line version of Minesweeper"""
import random
import re
import time
from string import ascii_lowercase


class MineSweeper:
    """Utility class for MineSweeper Game"""

    def __init__(self, grid_size, number_of_mines):
        """Initialize Game"""
        self.grid_size = grid_size
        self.number_of_mines = number_of_mines

    @staticmethod
    def show_grid(grid):
        """Method to print the grid"""
        grid_size = len(grid)

        horizontal = '   ' + (4 * grid_size * '-') + '-'

        # Print top column letters
        top_label = '     '

        for i in ascii_lowercase[:grid_size]:
            top_label = top_label + i + '   '

        print(top_label + '\n' + horizontal)

        # Print left row numbers
        for idx, i in enumerate(grid):
            row = '{0:2} |'.format(idx + 1)

            for j in i:
                row = row + ' ' + j + ' |'

            print(row + '\n' + horizontal)

        print('')

    def parse_input(self, input_string, help_message):
        """Method to parse the user input"""
        cell = ()
        message = "Invalid cell. " + help_message

        pattern = r'([a-{}])([0-9]+)(f?)'.format(ascii_lowercase[self.grid_size - 1])
        valid_input = re.match(pattern, input_string)

        if input_string == 'help':
            message = help_message

        elif valid_input:
            row_no = int(valid_input.group(2)) - 1
            col_no = ascii_lowercase.index(valid_input.group(1))

            if -1 < row_no < self.grid_size:
                cell = (row_no, col_no)
                message = ''

        return {'cell': cell, 'message': message}

    def set_up_grid(self, start):
        """Method to setup the grid"""
        empty_grid = [['0' for i in range(self.grid_size)] for i in range(self.grid_size)]

        mines = self.get_mines(empty_grid, start)

        for i, j in mines:
            empty_grid[i][j] = 'M'

        grid = MineSweeper.get_numbers(empty_grid)

        return grid, mines

    def get_mines(self, grid, start):
        """Method to generate random mines in the grid"""
        mines = []
        neighbors = MineSweeper.get_neighbors(grid, *start)

        for i in range(self.number_of_mines):
            cell = MineSweeper.get_random_cell(grid)
            while cell == start or cell in mines or cell in neighbors:
                cell = MineSweeper.get_random_cell(grid)
            mines.append(cell)

        return mines

    @staticmethod
    def get_numbers(grid):
        """Method to calculate number of mines surrounding for each cell"""
        for row_no, row in enumerate(grid):
            for col_no, cell in enumerate(row):
                if cell != 'M':
                    # Gets the values of the neighbors
                    values = [grid[r][c] for r, c in MineSweeper.get_neighbors(grid, row_no, col_no)]

                    # Counts how many are mines
                    grid[row_no][col_no] = str(values.count('M'))

        return grid

    @staticmethod
    def get_neighbors(grid, row_no, col_no):
        """Method to get neighbors of a given cell"""
        grid_size = len(grid)
        neighbors = []

        for i in range(-1, 2):
            for j in range(-1, 2):
                if i == 0 and j == 0:
                    continue
                elif -1 < (row_no + i) < grid_size and -1 < (col_no + j) < grid_size:
                    neighbors.append((row_no + i, col_no + j))

        return neighbors

    @staticmethod
    def get_random_cell(grid):
        """Method to get random cell from grid"""
        grid_size = len(grid)

        a = random.randint(0, grid_size - 1)
        b = random.randint(0, grid_size - 1)

        return a, b

    @staticmethod
    def play_again():
        """Method to check if user want to play again"""
        choice = input('Play again? (y/n): ')

        return choice.lower() == 'y'

    @staticmethod
    def show_cell(grid, curr_grid, row_no, col_no):
        """Method to show reveal the cell"""
        # Exit function if the cell was already shown
        if curr_grid[row_no][col_no] != '*':
            return

        # Show current cell
        curr_grid[row_no][col_no] = grid[row_no][col_no]

    def is_won(self, curr_grid, grid):
        """Method to check if the user has won"""
        mines = 0
        un_revealed = 0
        for row_no, row in enumerate(curr_grid):
            for col_no, cell in enumerate(row):
                if curr_grid[row_no][col_no] == '*':
                    un_revealed += 1
                    if grid[row_no][col_no] == 'M':
                        mines += 1
                    if un_revealed > self.number_of_mines:
                        return False
        if un_revealed == self.number_of_mines and mines == self.number_of_mines:
            return True
        return False

    def play_game(self):
        """Method to start Game"""

        curr_grid = [['*' for i in range(self.grid_size)] for i in range(self.grid_size)]

        grid = []
        start_time = 0

        help_message = "Type the column followed by the row (eg. a5). "

        MineSweeper.show_grid(curr_grid)
        print(help_message + " Type 'help' to show this message again.\n")

        while True:
            prompt = input('Enter the cell: ')
            result = self.parse_input(prompt, help_message + '\n')

            message = result['message']
            cell = result['cell']

            if cell:
                print('\n\n')
                row_no, col_no = cell
                curr_cell = curr_grid[row_no][col_no]

                if not grid:
                    grid, mines = self.set_up_grid(cell)
                if not start_time:
                    start_time = time.time()

                if grid[row_no][col_no] == 'M':
                    print('Game Over\n')
                    MineSweeper.show_grid(grid)
                    if MineSweeper.play_again():
                        self.play_game()
                    return

                elif curr_cell == '*':
                    MineSweeper.show_cell(grid, curr_grid, row_no, col_no)

                else:
                    message = "That cell is already shown"

                if self.is_won(curr_grid, grid):
                    minutes, seconds = divmod(int(time.time() - start_time), 60)
                    print(
                        'You Win. '
                        'It took you {} minutes and {} seconds.\n'.format(minutes,
                                                                          seconds))
                    MineSweeper.show_grid(grid)
                    if MineSweeper.play_again():
                        self.play_game()
                    return

            MineSweeper.show_grid(curr_grid)
            print(message)


def main():
    """Entry point to start game"""
    game = MineSweeper(grid_size=8, number_of_mines=8)
    game.play_game()


if __name__ == "__main__":
    main()

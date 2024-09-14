# In square_evaluation.py

class SquareEvaluator:
    def __init__(self, game_board):
        self.game_board = game_board

    def evaluate_squares(self):
        squares = 0
        # Iterate through each potential square
        for row in range(self.game_board.rows - 1):
            for col in range(self.game_board.cols - 1):
                # Get the labels and IDs of the lines forming the potential square
                label1 = self.game_board.game_state[f"{row}{col}"]["label"]
                label2 = self.game_board.game_state[f"{row}{col + 1}"]["label"]
                label3 = self.game_board.game_state[f"{row + 1}{col}"]["label"]
                label4 = self.game_board.game_state[f"{row + 1}{col + 1}"]["label"]
                id1 = f"{row}{col}"
                id2 = f"{row}{col + 1}"
                id3 = f"{row + 1}{col}"
                id4 = f"{row + 1}{col + 1}"
                print(f"IDs: {id1}, {id2}, {id3}, {id4}")
                # Check if all four sides of the square are bold
                if (self.game_board.game_state[f"{row}{col}"]["bold"] and
                    self.game_board.game_state[f"{row}{col + 1}"]["bold"] and
                    self.game_board.game_state[f"{row + 1}{col}"]["bold"] and
                    self.game_board.game_state[f"{row + 1}{col + 1}"]["bold"]):
                    squares += 1
        return squares

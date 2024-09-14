from game_board import GameBoard
import copy

def minimax(game_board, game_state, player, depth, AI_PLAYER, HUMAN_PLAYER, game_over):
    if depth == 0 or game_over(game_state):
        return None, evaluate(game_board, game_state, AI_PLAYER)

    if player == AI_PLAYER:
        best_score = float('-inf')
        best_move = None
        for move in generate_moves(game_state, AI_PLAYER):
            new_game_state = copy.deepcopy(game_state)
            new_game_state = make_move(new_game_state, move, AI_PLAYER)
            score = evaluate(game_board, new_game_state, AI_PLAYER)
            if score == 2:
                return move, score
            if score == 1:
                return move, score
            _, score = minimax(game_board, new_game_state, HUMAN_PLAYER, depth - 1, AI_PLAYER, HUMAN_PLAYER, game_over)
            if score > best_score:
                best_score = score
                best_move = move
        return best_move, best_score

    else:
        best_score = float('inf')
        best_move = None
        for move in generate_moves(game_state, HUMAN_PLAYER):
            new_game_state = copy.deepcopy(game_state)
            new_game_state = make_move(new_game_state, move, HUMAN_PLAYER)
            score = evaluate(game_board, new_game_state, AI_PLAYER)
            if score == 2:
                game_state = make_move(game_state, move, HUMAN_PLAYER)
                return move, score
            if score == 1:
                game_state = make_move(game_state, move, HUMAN_PLAYER)
                return move, score
            _, score = minimax(game_board, new_game_state, AI_PLAYER, depth - 1, AI_PLAYER, HUMAN_PLAYER, game_over)
            if score < best_score:
                best_score = score
                best_move = move
        return best_move, best_score


def evaluate(game_board, game_state, player):
    squares_completed = 0
    for line_id, line_info in game_state.items():
            squares_completed = game_board.evaluate_squares(line_id,game_state) 
            if squares_completed>=2:
                return squares_completed
            if squares_completed>=1:
                return squares_completed
           
    return squares_completed  # Total squares completed by the player


def generate_moves(game_state, player):
    possible_moves = set()  # Use a set to store distinct moves
    for line_id, line_info in game_state.items():
        if not line_info.get("bold", False):  # Check if the line is not bold
            possible_moves.add(line_id)  # Add the line ID to the set
    return list(possible_moves)  # Convert the set back to a list before returning

def make_move(game_state, move, player):
    if move in game_state:
        game_state[move]["bold"] = True
    else:
        print(f"Invalid move: {move} does not exist in game_state")
    return game_state

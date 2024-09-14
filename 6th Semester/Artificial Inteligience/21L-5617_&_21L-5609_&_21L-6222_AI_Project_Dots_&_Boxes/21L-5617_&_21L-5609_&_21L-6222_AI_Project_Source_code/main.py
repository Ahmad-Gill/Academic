import tkinter as tk
import pygame
from MinMax import minimax
from game_board import GameBoard



# Initialize pygame
pygame.init()

# Load sounds
game = pygame.mixer.Sound("game_over.wav")
move_sound = pygame.mixer.Sound("mixkit-video-game-win-2016.wav")
make_move = pygame.mixer.Sound("make_move.wav")
bonus= pygame.mixer.Sound("bonus.wav")



AI_PLAYER = 0
HUMAN_PLAYER = 1
AI_score = 0
H_score =0
start=0
def draw_welcome_screen(canvas, game_board):
    if canvas:
        canvas.delete("all") 
                # Load the image

        # Display the image on the canvas

        
        # Draw the outer boundary
        canvas.create_rectangle(game_board.padding, game_board.padding, game_board.cols * game_board.cell_size + game_board.padding, game_board.rows * game_board.cell_size + game_board.padding, outline="blue", width=3)  

        # Draw an inner boundary with a different color
        inner_padding = 10
        canvas.create_rectangle(game_board.padding + inner_padding, game_board.padding + inner_padding, game_board.cols * game_board.cell_size + game_board.padding - inner_padding, game_board.rows * game_board.cell_size + game_board.padding - inner_padding, outline="green", width=2)
        inner_padding = 20
        canvas.create_rectangle(game_board.padding + inner_padding, game_board.padding + inner_padding, game_board.cols * game_board.cell_size + game_board.padding - inner_padding, game_board.rows * game_board.cell_size + game_board.padding - inner_padding, outline="purple", width=2)

        # Draw the title
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding, 90, text="Dots & Boxes", font=("Arial", 40), fill="maroon")

        # Draw the message
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding, game_board.rows * game_board.cell_size / 2 + game_board.padding, text="Press any key to start", font=("Arial", 16), fill="red")

        # Add contributors' information
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding, game_board.rows * game_board.cell_size / 2 + game_board.padding + 50, text="Contributors:", font=("Arial", 12), fill="black")
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding, game_board.rows * game_board.cell_size / 2 + game_board.padding + 70, text="     Muhammad Ahmad               21L-5617", font=("Arial", 12), fill="black")
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding, game_board.rows * game_board.cell_size / 2 + game_board.padding + 90, text="         Nimra Amer                         21L-5609", font=("Arial", 12), fill="black")
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding, game_board.rows * game_board.cell_size / 2 + game_board.padding + 110, text="Raviha Zubair                     21lL-6222", font=("Arial", 12), fill="black")

        key_pressed = False

        def bind_key(event):
            nonlocal key_pressed
            key_pressed = True
            root.quit()  # Exit the mainloop when a key is pressed

        root.bind("<Key>", bind_key)  # Bind the key event

        root.mainloop()  # Wait for events, such as key presses

        if key_pressed:
            return

    else:
        print("Canvas is not properly instantiated.")


def draw_game_over(canvas, game_board):
    global AI_score,H_score
    if canvas:
        canvas.delete("all") 
                # Load the image

        # Display the image on the canvas

        
        # Draw the outer boundary
        canvas.create_rectangle(game_board.padding, game_board.padding, game_board.cols * game_board.cell_size + game_board.padding, game_board.rows * game_board.cell_size + game_board.padding, outline="blue", width=3)  

        # Draw an inner boundary with a different color
        inner_padding = 10
        canvas.create_rectangle(game_board.padding + inner_padding, game_board.padding + inner_padding, game_board.cols * game_board.cell_size + game_board.padding - inner_padding, game_board.rows * game_board.cell_size + game_board.padding - inner_padding, outline="green", width=2)
        inner_padding = 20
        canvas.create_rectangle(game_board.padding + inner_padding, game_board.padding + inner_padding, game_board.cols * game_board.cell_size + game_board.padding - inner_padding, game_board.rows * game_board.cell_size + game_board.padding - inner_padding, outline="purple", width=2)

        # Draw the title
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding, 90, text="Game Over", font=("Arial", 40), fill="maroon")

        # Draw the message
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding,
                        game_board.rows * game_board.cell_size / 2 + game_board.padding,
                        text="AI score = " + str(AI_score),  # Concatenate AI_score with the text
                        font=("Arial", 16),
                        fill="red")
        canvas.create_text(game_board.cols * game_board.cell_size / 2 + game_board.padding,
                        game_board.rows * game_board.cell_size / 2 + game_board.padding + inner_padding,  # Adjust the y-coordinate
                        text="Your Score = " + str(H_score),  # Concatenate H_score with the text
                        font=("Arial", 16),
                        fill="red")
        key_pressed = False

        def bind_key(event):
            nonlocal key_pressed
            key_pressed = True
            root.quit()  # Exit the mainloop when a key is pressed

        root.bind("<Key>", bind_key)  # Bind the key event

        root.mainloop()  # Wait for events, such as key presses

        if key_pressed:
            draw_game_over(canvas, game_board)

    else:
        print("Canvas is not properly instantiated.")





def draw_grid(canvas, game_board):
    

    if canvas:
        canvas.delete("all") 
                # Draw an inner boundary with a different color
        inner_padding = -10
        canvas.create_rectangle(game_board.padding + inner_padding, game_board.padding + inner_padding, game_board.cols * game_board.cell_size + game_board.padding - inner_padding, game_board.rows * game_board.cell_size + game_board.padding - inner_padding, outline="green", width=2)
        inner_padding = -5
        canvas.create_rectangle(game_board.padding + inner_padding, game_board.padding + inner_padding, game_board.cols * game_board.cell_size + game_board.padding - inner_padding, game_board.rows * game_board.cell_size + game_board.padding - inner_padding, outline="purple", width=2)

        canvas.create_rectangle(game_board.padding, game_board.padding, game_board.cols * game_board.cell_size + game_board.padding, game_board.rows * game_board.cell_size + game_board.padding, outline="black")  # Draw the box outline
        for line_id, line_info in game_board.game_state.items():
            bold = line_info.get("bold", False)
            width = 4 if bold else 1
            canvas.create_line(*line_info["coords"], width=width, tags=f"line-{line_id}")
            x1, y1, x2, y2 = line_info["coords"]
            label_x = (x1 + x2) / 2
            label_y = (y1 + y2) / 2
            canvas.create_text(label_x, label_y, text=line_info["label"], font=("Arial", 10))
    else:
        print("Canvas is not properly instantiated.")

def toggle_line_bold(event):
    global H_score, HUMAN_PLAYER,AI_PLAYER

    if not game_over(game_board.game_state):

        if HUMAN_PLAYER == 1:
            line_id = event.char

            if event.state & 0x2:
                line_id = line_id.upper()
                # Special characters that may change when Shift is pressed
                special_characters = {'=': '+', ';': ':', ',': '<', '.': '>', '/': '?', '-': '_',
                                    '[': '{', ']': '}', '\\': '|', "'": '"', '`': '~', '1': '!',
                                    '2': '@', '3': '#', '4': '$', '5': '%', '6': '^', '7': '&',
                                    '8': '*', '9': '(', '0': ')'}
                line_id = special_characters.get(line_id, line_id)
            else:
                line_id = line_id.lower()

            line_info = game_board.game_state.get(line_id)
            if line_info and not line_info["bold"]:
                line_info["bold"] = True
                make_move.play()
                draw_grid(event.widget, game_board)
                game_state=game_board.game_state
                squares_completed = game_board.evaluate_squares(line_id,game_state)
                if squares_completed > 0:
                    H_score += 1 
                    bonus.play()
                    return
                HUMAN_PLAYER=0
                AI_PLAYER=1 
                AI_turn()  # Let AI make its move
                draw_grid(event.widget, game_board)
        elif AI_PLAYER:
            AI_turn()  # Let AI make its move
            draw_grid(event.widget, game_board)

def game_over(game_state):
    global root

    # Check if any line is not bold
    for line_info in game_state.values():
        if not line_info["bold"]:
            return False

    # Play the game over sound
    game.play()

    # Update the title
    root.title("---------------------------------Game Over------------------------------------")
    draw_game_over(canvas, game_board)

    return True


def AI_turn():
    global HUMAN_PLAYER,AI_score # Declare HUMAN_PLAYER as global
    HUMAN_PLAYER = 1
    AI_PLAYER=0
    ai_move,score = minimax(game_board, game_board.game_state, AI_PLAYER, depth=1, AI_PLAYER=AI_PLAYER, HUMAN_PLAYER=HUMAN_PLAYER, game_over=game_over)
    game_board.game_state[ai_move]["bold"] = True
    squares_completed = game_board.evaluate_squares(ai_move,game_board.game_state)
    if squares_completed > 0:
                    AI_score += 1 
                    bonus.play()
                    draw_grid(canvas, game_board)
                    HUMAN_PLAYER = 0
                    AI_PLAYER=1
    draw_grid(canvas, game_board)

def main():
    global game_board, root, canvas ,start # Initialize the score variable
    if start==0:
        start=1
        move_sound.play()

    rows = 5
    cols = 5
    cell_size = 100
    padding = 30

    game_board = GameBoard(rows, cols, cell_size, padding)

    root = tk.Tk()
    root.title("---------------------------------Happy Coding------------------------------------")

    canvas = tk.Canvas(root, width=cols * cell_size + 2 * padding, height=rows * cell_size + 2 * padding)
    canvas.pack()
    draw_welcome_screen(canvas, game_board) 
    draw_grid(canvas, game_board)

     #Start with the human player's turn
    if HUMAN_PLAYER:
        root.bind("<Key>", toggle_line_bold)
    else:
        toggle_line_bold(event=None)
    canvas.focus_set()


    root.mainloop()  # Start event loop
    print('After AI tunr')
if __name__ == "__main__":
    main()

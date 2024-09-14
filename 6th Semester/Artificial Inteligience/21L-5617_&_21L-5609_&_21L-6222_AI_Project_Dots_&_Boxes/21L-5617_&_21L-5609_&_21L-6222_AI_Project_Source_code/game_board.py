from sys import int_info


class GameBoard:
    def __init__(self, rows, cols, cell_size, padding):
        self.rows = rows
        self.cols = cols
        self.cell_size = cell_size
        self.padding = padding
        self.game_state = self.generate_line_coordinates()

    def generate_line_coordinates(self):
        game_state = {}
        line_id = 'a'
        for i in range(self.rows + 1):
            for j in range(self.cols):
                y = i * self.cell_size + self.padding
                x1 = j * self.cell_size + self.padding
                x2 = (j + 1) * self.cell_size + self.padding
                game_state[line_id] = {"coords": (x1, y, x2, y), "label": line_id, "bold": False,"id_1":0,"id_2":0,"checked":False}
                line_id = chr(ord(line_id) + 1)
                if line_id == '{':
                    line_id = '0'

        for i in range(self.rows):
            for j in range(self.cols + 1):
                x = j * self.cell_size + self.padding
                y1 = i * self.cell_size + self.padding
                y2 = (i + 1) * self.cell_size + self.padding
                game_state[line_id] = {"coords": (x, y1, x, y2), "label": line_id, "bold": False,"id_1":0,"id_2":0,"checked":False}
                line_id = chr(ord(line_id) + 1)
                if line_id == '{':
                    line_id = '0'
        return game_state




    def evaluate_squares(self, line_id, game_state):

        corresponding_lines = {
    'a': {'part_1': ['a', '4', '5', 'f'], 'part_2': []},
    'b': {'part_1': ['5', '6', 'g', 'b'], 'part_2': []},
    'c': {'part_1': ['6', '7', 'h'], 'part_2': []},
    'd': {'part_1': ['7', '8', 'i', 'd'], 'part_2': []},
    'e': {'part_1': ['8', '9', 'e', 'j'], 'part_2': []},
    'f': {'part_1':['a', '4', '5','f' ], 'part_2':[':', ';', 'k', 'f']},
    'g': {'part_1': ['b', '6', '5','g' ], 'part_2': ['g','<',':', 'l']},
    'h': {'part_1': ['h', '6', '7', 'c'], 'part_2': ['h','<', '=', 'm',]},
    'i': {'part_1': [ 'i','7', '8', 'd'], 'part_2': ['i','>', '=', 'n',]},
    'j': {'part_1': ['8', '9', 'e','j'], 'part_2': ['j','>', '?', 'o', ]},
    'k': {'part_1': [';', ':', 'f','k' ], 'part_2': ['k','@', 'A', 'p']},
    'l': {'part_1': ['g', ';', '<','l'], 'part_2': ['l', 'A', 'B', 'q']},
    'm': {'part_1': ['<', 'h', '=','m'], 'part_2': ['m', 'B', 'C', 'r']},
    'n': {'part_1': ['=', '>', 'i','n' ], 'part_2': ['n','C', 'D', 's']},
    'o': {'part_1': ['>', 'j', '?','o' ], 'part_2': ['o','D', 'E', 't']},
    'p': {'part_1': ['@', 'k', 'A','p' ], 'part_2': ['p','F', 'G', 'u']},
    'q': {'part_1': ['A', 'B', 'l','q' ], 'part_2': ['q','G', 'H', 'v']},
    'r': {'part_1': ['B', 'm', 'C','r' ], 'part_2': ['r','H', 'I', 'w']},
    's': {'part_1': ['C', 'D', 'n', 's'], 'part_2': ['s','I', 'J', 'X']},
    't': {'part_1': ['D', 'E', 'o','t' ], 'part_2': ['t','J', 'K', 'y']},
    'u': {'part_1': ['F', 'G', 'p','u'], 'part_2': ['u', 'L', 'M', 'z']},
    'v': {'part_1': ['G', 'q', 'H', 'v'], 'part_2': ['v','M', 'N', '0']},
    'w': {'part_1': ['H', 'I', 'r','w' ], 'part_2': ['w','N', 'O', '1']},
    'x': {'part_1': ['s', 'I', 'J','x' ], 'part_2': ['x','O', 'P', '2']},
    'y': {'part_1': ['J', 'K', 't','y' ], 'part_2': ['y','P', 'Q', '3']},
    'z': {'part_1': ['z', 'L', 'M', 'u'], 'part_2': []},
    '0': {'part_1': ['0', 'M', 'v', 'N'], 'part_2': []},
    '1': {'part_1': ['1', 'N', 'O', 'w'], 'part_2': []},
    '2': {'part_1': ['2', 'O', 'X', 'P'], 'part_2': []},
    '3': {'part_1': ['3', 'P', 'Q', 'y'], 'part_2': []},
    '4': {'part_1': ['4', 'a', '5', 'f'], 'part_2': []},
    '5': {'part_1': ['a', '4', 'f','5'], 'part_2': ['5', 'b', '6', 'g']},
    '6': {'part_1': ['5', 'b', 'g','6' ], 'part_2': ['6','c', 'h', '7']},
    '7': {'part_1': ['6', 'c', 'h', '7'], 'part_2': ['7','i', 'd', '8']},
    '8': {'part_1': ['7', 'd', 'i','8'], 'part_2': ['8', 'e', 'j', '9']},
    '9': {'part_1': ['9', '8', 'e', 'j'], 'part_2': []},
    ':': {'part_1': [':', 'f', 'k', ';'], 'part_2': []},
    ';': {'part_1': ['f', 'k', ':',';'], 'part_2': [';', 'g', 'l','<']},
    '<': {'part_1': [';', 'g', 'l', '<'], 'part_2': ['<','h', '=','m']},
    '=': {'part_1': ['<', 'h', 'm','=' ], 'part_2': ['=','i', 'n','>']},
    '>': {'part_1': ['=', 'i', 'n','>'], 'part_2': ['>', 'j', '?','e']},
    '?': {'part_1': ['?', 'j', '>', 'o'], 'part_2': []},
    '@': {'part_1': ['@', 'k', 'A', 'p'], 'part_2': []},
    'A': {'part_1': ['@', 'k', 'p', 'A'], 'part_2': ['B', 'A','l', 'q']},
    'B': {'part_1': ['A', 'l', 'q','B'], 'part_2': ['r', 'B', 'm', 'c']},
    'C': {'part_1': ['B', 'm', 'r', 'D'], 'part_2': ['D', 'C','n', 's']},
    'D': {'part_1': ['C', 'n', 's','D'], 'part_2': ['t', 'D', 'o', 'E']},
    'E': {'part_1': ['E', 'o', 'D', 't'], 'part_2': []},
    'F': {'part_1': ['F', 'u', 'G', 'P'], 'part_2': []},
    'G': {'part_1': ['F', 'P', 'u', 'G'], 'part_2': ['H', 'G','q', 'v']},
    'H': {'part_1': ['G', 'q', 'v','H'], 'part_2': ['I', 'H', 'r', 'w']},
    'I': {'part_1': ['H', 'r', 'w', "I"], 'part_2': ['J', 'I','s', 'x']},
    'J': {'part_1': ['I', 's', 'x','J'], 'part_2': ['K', 'y', 'J', 't']},
    'K': {'part_1': ['K', 'J', 't', 'y'], 'part_2': []},
    'L': {'part_1': ['L', 'u', 'M', 'z'], 'part_2': []},
    'M': {'part_1': ['u', 'L', 'z','M'], 'part_2': ['N', '0', 'M', 'v']},
    'N': {'part_1': ['M', 'v', '0', 'N'], 'part_2': ['O', '1', 'N','w']},
    'O': {'part_1': ['N', 'w', '1', 'O'], 'part_2': ['P', '2', 'O','x']},
    'P': {'part_1': ['O', 'x', '2','P'], 'part_2': ['Q', '3', 'P', 'y']},
    'Q': {'part_1': ['Q', 'P', 'y', '3'], 'part_2': []}
        }
        squares = 0
        # Check if line_id exists in corresponding_lines
        if line_id in corresponding_lines:
            corresponding_labels = corresponding_lines[line_id]
            line_info = game_state.get(line_id)
            id_1_status = game_state[line_id]["id_1"]  
            id_2_status = game_state[line_id]["id_2"] # Get id_1 status for the current line_id
           

            if line_info and id_1_status != 1 :
                corresponding_labels = corresponding_lines.get(line_id)
                if corresponding_labels:
                    part_1 = corresponding_labels.get("part_1")
                    if part_1:
                        part_1_bold = all(game_state.get(label, {"bold": False})["bold"] for label in part_1)
                        if part_1_bold:
                            game_state[line_id]["id_1"] = 1
                            squares = 1
                            for label in part_1:
                                if label in game_state:
                                    game_state[label]["id_1"] = 1

                # Check if all part_2 corresponding lines are bold
                part_2_bold = False  # Initialize part_2_bold
                if line_info and id_2_status != 1:
                    if "part_2" in corresponding_labels:
                        part_2_labels = corresponding_labels["part_2"]
                        if part_2_labels:  # Check if part_2 is not empty
                            part_2_bold = all(game_state.get(label, {"bold": False})["bold"] for label in part_2_labels)
                            if part_2_bold is not None and part_2_bold:
                                game_state[line_id]["id_2"] = 1
                                squares = 1
                                
                if part_1_bold and part_2_bold:
                    squares = 2
        return squares




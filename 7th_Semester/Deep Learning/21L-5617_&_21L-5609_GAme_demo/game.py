import pygame
import numpy as np

pygame.init()

GRID_SIZE = 5
WINDOW_SIZE = 500
CELL_SIZE = WINDOW_SIZE // GRID_SIZE

WHITE = (245, 245, 245)
BLACK = (50, 50, 50)
RED = (200, 0, 0)
GREEN = (0, 180, 0)
BLUE = (0, 100, 200)
LIGHT_BLUE = (135, 206, 250)
DARK_GRAY = (100, 100, 100)
YELLOW = (255, 255, 0)

start_pos = (0, 0)
goal_pos = (GRID_SIZE - 1, GRID_SIZE - 1)
holes = [(1, 1), (3, 3), (3, 0), (0, 3), (0, 4), (1, 0), (4, 0), (3, 2), (3, 4), (2, 3)]
visited_holes = set()

q_table = np.zeros((GRID_SIZE, GRID_SIZE, 4))

actions = {
    0: (-1, 0),
    1: (1, 0),
    2: (0, -1),
    3: (0, 1),
}

screen = pygame.display.set_mode((WINDOW_SIZE, WINDOW_SIZE))
pygame.display.set_caption("Q-learning Grid Game")
background_image = pygame.image.load("1.jpg")
background_image = pygame.transform.scale(background_image, (WINDOW_SIZE, WINDOW_SIZE))

agent_image = pygame.image.load("3.png")
agent_image = pygame.transform.scale(agent_image, (CELL_SIZE, CELL_SIZE))

hole_image = pygame.image.load("water.jpg")
hole_image = pygame.transform.scale(hole_image, (CELL_SIZE, CELL_SIZE))

agent_pos = start_pos

learning_rate = 0.1
discount_factor = 0.9
epsilon = 0.1

visited_states = set()

def manhattan_distance(pos1, pos2):
    return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1])

def draw_grid():
    screen.blit(background_image, (0, 0))
    pygame.draw.rect(screen, GREEN, (goal_pos[1] * CELL_SIZE, goal_pos[0] * CELL_SIZE, CELL_SIZE, CELL_SIZE))
    for hole in visited_holes:
        screen.blit(hole_image, (hole[1] * CELL_SIZE, hole[0] * CELL_SIZE))
    screen.blit(agent_image, (agent_pos[1] * CELL_SIZE, agent_pos[0] * CELL_SIZE))
    font = pygame.font.SysFont('Comic Sans MS', 20, bold=True)
    score_text = font.render(f"Score: {len(visited_holes)}", True, BLACK)
    screen.blit(score_text, (10, WINDOW_SIZE - 30))
    q_text = font.render(f"Q-values: {q_table[agent_pos[0], agent_pos[1]]}", True, WHITE)
    screen.blit(q_text, (10, 10))

def update_q_table(state, action, reward, next_state):
    current_q_value = q_table[state[0], state[1], action]
    max_future_q_value = np.max(q_table[next_state[0], next_state[1]])
    q_table[state[0], state[1], action] = current_q_value + learning_rate * (
        reward + discount_factor * max_future_q_value - current_q_value
    )

running = True
clock = pygame.time.Clock()

while running:
    screen.fill(WHITE)
    draw_grid()
    state = agent_pos
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            action = None
            if event.key == pygame.K_UP:
                action = 0
            elif event.key == pygame.K_DOWN:
                action = 1
            elif event.key == pygame.K_LEFT:
                action = 2
            elif event.key == pygame.K_RIGHT:
                action = 3
            if action is not None:
                next_pos = (agent_pos[0] + actions[action][0], agent_pos[1] + actions[action][1])
                if 0 <= next_pos[0] < GRID_SIZE and 0 <= next_pos[1] < GRID_SIZE:
                    if next_pos == goal_pos:
                        reward = 10
                        agent_pos = next_pos
                    elif next_pos in holes:
                        reward = -5
                        visited_holes.add(next_pos)
                        agent_pos = start_pos
                    else:
                        current_distance = manhattan_distance(agent_pos, goal_pos)
                        new_distance = manhattan_distance(next_pos, goal_pos)
                        reward = 1 if new_distance < current_distance else -1
                        agent_pos = next_pos
                    if (state, action) not in visited_states:
                        visited_states.add((state, action))
                        update_q_table(state, action, reward, agent_pos)
                    
    pygame.display.flip()
    clock.tick(10)

pygame.quit()

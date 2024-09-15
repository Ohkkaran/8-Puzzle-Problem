# 8-Puzzle-Problem
The 8-puzzle problem is a classic example of a sliding puzzle that consists of a 3x3 grid containing 8 numbered tiles (from 1 to 8) and one blank space. The objective is to arrange the tiles in a specific goal configuration by sliding the tiles into the blank space, one move at a time.
The puzzle consists of 9 spaces: 8 spaces are filled with numbered tiles (1 to 8), and 1 space is left blank (often represented by 0 or a blank space).
The puzzle begins with an initial state where the tiles are arranged randomly.
We will be using Hill climbing algorithm to solve the above problem. Let's have a look at what is this algorithm and how does it work.
The Hill Climbing algorithm is a heuristic search algorithm used in optimization problems. It belongs to the family of local search algorithms, which aim to find solutions by making incremental changes to a single solution (state) and evaluating its quality based on some heuristic function. The main idea of Hill Climbing is to start with an arbitrary solution and iteratively make moves towards better neighboring solutions until a local optimum is reached.
Eg: 
Intial State [[1 2 3],[0 4 6],[7 5 8]]
Final State  [[1 2 3],[4 5 6],[7 8 0]]
                      
we will be calculating heuristic value for each state and move to the next step if new heuristic value is smaller than the existing one.
Like here heuristic value for current state is 3.It will explore all the possiblities and move to the better path. So it will move to next state having heuristic value <3 like 2 for this next move  
[[1 2 3],[4 0 6],[7 5 8]]



                                    

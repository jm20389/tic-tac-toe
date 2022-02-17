
std::vector<char> mark_select();

void paint_board(std::vector<char> board, char player, char cpu);

void place_mark(std::vector<char>& board, char player);

void cpu_place_mark(std::vector<char>& board, char cpu);

bool is_win(std::vector<char> board);

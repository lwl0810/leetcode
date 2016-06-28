//Design Snake Game
//Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.
//The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
//You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.
//Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.
//When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
//
//Example:
//Given width = 3, height = 2, and food = [[1,2],[0,1]].
//
//Snake snake = new Snake(width, height, food);
//
//Initially the snake appears at position (0,0) and the food at (1,2).
//
//|S| | |
//| | |F|
//
//snake.move("R"); -> Returns 0
//
//| |S| |
//| | |F|
//
//snake.move("D"); -> Returns 0
//
//| | | |
//| |S|F|
//
//snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )
//
//| |F| |
//| |S|S|
//
//snake.move("U"); -> Returns 1
//
//| |F|S|
//| | |S|
//
//snake.move("L"); -> Returns 2 (Snake eats the second food)
//
//| |S|S|
//| | |S|
//
//snake.move("U"); -> Returns -1 (Game over because snake collides with border)
class SnakeGame{
public:
	SnakeGame(int width, int height, vector<pair<int, int>> food);
	~SnakeGame(void);

	int move(string direction);

private:
	int width, height, score;
	deque<int> food;
	deque<int> snake;
	unordered_set<int> biteSelf;
};

SnakeGame::SnakeGame(int width, int height, vector<pair<int, int>> food){
	this->width = width;
	this->height = height;
	this->score = 0;
	for(int i = 0; i < food.size(); ++i)
		this->food.push_back(width * food[i].first + food[i].second);
	this->snake.push_back(0);
	this->biteSelf.insert(0);
}


SnakeGame::~SnakeGame(void){
}


int SnakeGame::move(string direction){
	pair<int, int> head(snake.front()/width, snake.front()%width);
	if(direction == "U") head.first--;
	else if(direction == "D") head.first++;
	else if(direction == "L") head.second--;
	else if(direction == "R") head.second++;
	int headElem = width*head.first+head.second;
	if (head.first < 0 || head.first >= height || 
		head.second < 0 || head.second >= width ||
		biteSelf.find(headElem) != biteSelf.end() ){
		return -1;
	}
	snake.push_front(headElem);
	biteSelf.insert(headElem);
	if(!food.empty() && headElem == food.front()){
		food.pop_front();
		score += 1;
	}else{
		biteSelf.erase(snake.back());
		snake.pop_back();
	}
	return score;
}

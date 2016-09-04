/*
Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
*/
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        food_index=0;
        snake.emplace_back(0,0);
        f=food;
        w=width;
        h=height;
        score=0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int,int> temp;
        temp=snake.front();
        int direc=direction[0]-'A';
        switch(direc){
            case (20):{temp.first--;break;}
            case (11):{temp.second--;break;}
            case (17):{temp.second++;break;}
            case 3:{temp.first++;break;}
        }
        if(temp.first<0 or temp.first>=h or temp.second<0 or temp.second>=w) return -1;
        if(food_index<f.size() and temp==f[food_index]){
            food_index++;
            snake.push_front(temp);
            return ++score;
        }
        else{
            snake.pop_back();
            if(find(snake.begin(),snake.end(),temp)!=snake.end()) return -1;
            else{
                snake.push_front(temp);
                return score;
            }
        }
        return -1;
    }
private:
    int food_index;
    list<pair<int,int>> snake;
    vector<pair<int,int>> f;
    int score;
    int w,h;
};

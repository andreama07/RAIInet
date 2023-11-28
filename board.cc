module board;
using namespace std;

GameBoard::GameBoard() {}

bool isWithinBounds(int x, int y) {
    // need a size filed
  if (x <= 8 && y <= 8) {
    return true;
  } else {
    return false;
  }
}


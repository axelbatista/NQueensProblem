

#include <iostream>
#include <vector>
#include <algorithm>

int width = 8;                      //width and height are the dimensions for the board.
int height = 8;
std::vector<int> board(width* height);
std::vector<bool> column(width);
std::vector<std::pair<bool, int>> diagonal(width* height);
int number = 8;                                         //number is the number of queens that we want to have on the board.
long long count = 0;

void determineDiagonals(int x, int y) {
    int j = y - 1;
    for (int i = x - 1, u = x + 1; i >= 0 || u < width; i--, u++) {
        for (; j >= 0;) {
            if (i >= 0) {
                diagonal[j * width + i].first = true;
                diagonal[j * width + i].second++;
            }
            if (u < width) {
                diagonal[j * width + u].first = true;
                diagonal[j * width + u].second++;
            }
            j--;
            break;
        }
    }
    j = y + 1;
    for (int i = x - 1, u = x + 1; i >= 0 || u < width; i--, u++) {
        for (; j < height;) {
            if (i >= 0) {
                diagonal[j * width + i].first = true;
                diagonal[j * width + i].second++;
            }
            if (u < width) {
                diagonal[j * width + u].first = true;
                diagonal[j * width + u].second++;
            }
            j++;
            break;
        }
    }
}

void deterDiagonals(int x, int y) {
    int j = y - 1;
    for (int i = x - 1, u = x + 1; i >= 0 || u < width; i--, u++) {
        for (; j >= 0;) {
            if (i >= 0) {
                diagonal[j * width + i].second--;
                if (diagonal[j * width + i].second == 0) diagonal[j * width + i].first = false;
            }
            if (u < width) {
                diagonal[j * width + u].second--;
                if (diagonal[j * width + u].second == 0) diagonal[j * width + u].first = false;
            }
            j--;
            break;
        }
    }
    j = y + 1;
    for (int i = x - 1, u = x + 1; i >= 0 || u < width; i--, u++) {
        for (; j < height;) {
            if (i >= 0) {
                diagonal[j * width + i].second--;
                if (diagonal[j * width + i].second == 0) diagonal[j * width + i].first = false;
            }
            if (u < width) {
                diagonal[j * width + u].second--;
                if (diagonal[j * width + u].second == 0) diagonal[j * width + u].first = false;
            }
            j++;
            break;
        }
    }
}

void stateProgresser(int n, int many) {
    if (many == number) {
        count++;
        for (int j = 0; j < height; j++) {                      //many is how many queens are done so far, from which we compare against number.
            for (int i = 0; i < width; i++) {
                if (i == width - 1) {
                    std::cout << board[j * width + i] << '\n';
                }                                                           //this part right here <- is for printing.
                else {
                    std::cout << board[j * width + i] << ' ';
                }
            }
        }
        std::cout << '\t' << "the count is: " << count;
        std::cout << "\n\n";
        return;
    }
    for (int i = n; i < width * height; i++) {
        if (!diagonal[i].first && !column[i % width]) {
            board[i] = column[i % width] = 1;
            determineDiagonals(i % width, i / width);           //this is the algorithm, where we check if a spot is good or not and save every current
            stateProgresser(i + (width - (i % width)), many + 1); //state because we want to see how many configurations we can have for placing a third queen when we have 
            board[i] = column[i % width] = 0;                       //two queens, and we can do this for as many queens as we specify.
            deterDiagonals(i % width, i / width);
        }
    }
}           //determineDiagonals just marks all the [row,col]'s that are used from a new queen being placed, and does that 
//progressively for any new queen placed such that it marks all the spots on a board that are uninhabitable because any one or more queens can reach that spot.
//Likewise, deterDiagonals undoes those marked spots done by the placement of the latest queen because that queen is no longer on the board
//due to being replaced or the algorithm being done.

int main()
{
    stateProgresser(0, 0);
}


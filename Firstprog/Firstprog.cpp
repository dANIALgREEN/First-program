#include <iostream>
#include <ctime>

void Introdaction(int Difficulty) {
    std::cout << "\n\nHello. You are try to hack bomb level " << Difficulty;
    std::cout << " You need to pick right code before It will explode.\n";
}

bool PlayGame(int Difficulty) {

    Introdaction(Difficulty);

    int NumA = rand() % Difficulty + Difficulty;
    int NumB = rand() % Difficulty + Difficulty;
    int NumC = rand() % Difficulty + Difficulty;

    int CodeSum = NumA + NumB + NumC;
    int CodeProduct = NumA * NumB * NumC;

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ Sum of this numbers is ---->" << CodeSum;
    std::cout << "\n+ Product of this numbers is ---->" << CodeProduct;
    std::cout << "\n+ First number is ---->" << NumA << std::endl;
    std::cout << "Enter the correct code\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessA == NumA && GuessB == NumB && GuessC == NumC) 
    {
        std::cout << "\nThe bomb finaly hacked!! Going to the next lvl.";
        return true;
    }
    else 
    {
        std::cout << "\nYOU DIED. Try again.";
        return false;
    }

}


int main() 
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxLvl = 5;
    while (LevelDifficulty <= MaxLvl) 
    {
        bool bLevelCompleate = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelCompleate) 
        {
            // increase the level difficulty
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\nYou defused all bombs in that area. You are the best.\n";

    return 0;
}
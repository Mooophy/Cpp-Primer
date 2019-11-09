#include <iostream>
#include <vector>
#include <string>
using std::vector; using std::string; using std::cout; using std::endl; using std::cin;

int main()
{
    vector<string> scores={"F","D","C","B","A","A++"};
    int score;
    while (cin >> score)
    {
        string lettergrade = score > 100 ? "score should be less than 100!" : score > 60 ? scores[(score-50)/10] :
         score >= 0 ? scores[0] : "score should higher than 0!" ;
        lettergrade += (score >=100 || score <0 || score < 60)? "" : score % 10 > 7? "+" : score % 10 < 3? "-": "" ;
        cout<<letterband<<endl;
    }
}

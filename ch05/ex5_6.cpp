#include <iostream>
#include <vector>
#include <string>
using std::vector; using std::string; using std::cout; using std::endl; using std::cin;

int main()
{
    vector<string> scores={"F","D","C","B","A","A++"};
    
    int grade=0;
    while (cin >> grade)
    {
        string lettergrade = grade > 100 ? "score should be less than 100!" : grade > 60 ? scores[(score-50)/10] :
         score >= 0 ? scores[0] : "score should higher than 0!" ;
        lettergrade += (grade >=100 || grade <0 || grade < 60)? "" : grade % 10 > 7? "+" : grade % 10 < 3? "-": "" ;
        cout<<letterband<<endl;
    }
    return 0;
}

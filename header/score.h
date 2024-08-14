#ifndef SCORE_H
#define SCORE_H
#include <string>

using namespace std;

class Score {
    public:
        Score();
        Score(double, double, double);
        double getChineseScore();
        double getMathScore();
        double getEnglishScore();
        void setChineseScore(double);
        void setMathScore(double);
        void setEnglishScore(double);
        string printAllScore();
    private:
        double Chinese;
        double Math;
        double English;
};

#endif // SCORE_H
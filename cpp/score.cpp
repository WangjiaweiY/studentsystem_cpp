#include "../header/score.h"
#include <iostream>

using namespace std;

Score::Score() {
    setChineseScore(0);
    setMathScore(0);
    setEnglishScore(0);
};


Score::Score(double Chinese, double Math, double English) {
    setChineseScore(Chinese);
    setMathScore(Math);
    setEnglishScore(English);
};

void Score::setChineseScore(double Chinese) {
    this->Chinese = Chinese;
};

double Score::getChineseScore() {
    return this->Chinese;
};

void Score::setMathScore(double Math) {
    this->Math = Math;
};

double Score::getMathScore() {
    return this->Math;
};

void Score::setEnglishScore(double English) {
    this->English = English;
};

double Score::getEnglishScore() {
    return this->English;
};

string Score::printAllScore() {
    return "Chinese: " + to_string(getChineseScore()) + " Math: " + to_string(getMathScore()) + " English: " + to_string(getEnglishScore());
};
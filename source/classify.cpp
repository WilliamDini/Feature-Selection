#include "../header/classify.h"

void Classifier::setClass(float x) { this->classNum = x; }

void Classifier::insertFeatures(float x) { this->features.push_back(x); }

float Classifier::getClassNum() { return this->classNum; }

float Classifier::getfeatNum(int x) { return this->features.at(x); }

int Classifier::featSize() { return this->features.size(); }
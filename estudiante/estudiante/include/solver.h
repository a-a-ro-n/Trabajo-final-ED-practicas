#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <string>
#include <utility>
#include <vector>

#include "letters_set.h"
#include "dictionary.h"

using namespace std;

class Solver{
private:
  Dictionary dictionary;
  LettersSet letters_set;

  //A completar
private bool poderConstruir(string palabra, vector<char> available_letters);

public vector<string> getSolutions(const vector<char>& available_letters, bool score_game);
};

#endif // __SOLVER_H__

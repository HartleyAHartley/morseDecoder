#include <iostream>
#include <string>
#include <vector>

struct node{
    node():name('*'){};
    node(char name):name(name){}
    char name;
    node* nDot=nullptr;
    node* nDash=nullptr;
};

node* initMorseCode(){
   node* start = new node();
   node *E,*T;
   start->nDot  = E = new node('E');
   start->nDash = T = new node('T');
   node *I,*A;
   E->nDot  = I     = new node('I');
   E->nDash = A     = new node('A');
   node *N,*M;
   T->nDot  = N     = new node('N');
   T->nDash = M     = new node('M');
   node *S,*U;
   I->nDot  = S     = new node('S');
   I->nDash = U     = new node('U');
   node *R,*W;
   A->nDot  = R     = new node('R');
   A->nDash = W     = new node('W');
   node *D,*K;
   N->nDot  = D     = new node('D');
   N->nDash = K     = new node('K');
   node *G,*O;
   M->nDot  = G     = new node('G');
   M->nDash = O     = new node('O');
   node *H,*V;
   S->nDot  = H     = new node('H');
   S->nDash = V     = new node('V');
   node *F,*uDash;
   U->nDot  = F     = new node('F');
   U->nDash = uDash = new node();
   node *L;
   R->nDot  = L     = new node('L');
   node *P,*J;
   W->nDot  = P     = new node('P');
   W->nDash = J     = new node('J');
   node *B,*X;
   D->nDot  = B     = new node('B');
   D->nDash = X     = new node('X');
   node *C,*Y;
   K->nDot  = C     = new node('C');
   K->nDash = Y     = new node('Y');
   node *Z,*Q;
   G->nDot  = Z     = new node('Z');
   G->nDash = Q     = new node('Q');
   node *oDot,*oDash;
   O->nDot  = oDot  = new node();
   O->nDash = oDash = new node();
   H->nDot          = new node('5');
   H->nDash         = new node('4');
   V->nDash         = new node('3');
   uDash->nDash     = new node('2');
   J->nDash         = new node('1');
   B->nDot          = new node('6');
   Z->nDot          = new node('7');
   oDot->nDot       = new node('8');
   oDash->nDot      = new node('9');
   oDash->nDash     = new node('0');
   return start;
}

std::vector<std::string> split(std::string split, char delimiter=' '){
    std::vector<std::string> splitVector;
    std::string word = "";
    for(char i : split){
       if(i == delimiter){
          splitVector.push_back(word);
          word = "";
          continue;
       }
       word += i;
    }
    splitVector.push_back(word);
    return splitVector;
}
node* morseTree;
char parseLetter(std::string letter){
  node* travel = morseTree;
  for(char i : letter){
    if(i == '.')
      if(travel->nDot)
        travel = travel->nDot;
      else
          return '*';
    else if(i == '-')
      if(travel->nDash)
        travel = travel->nDash;
      else
          return '*';
  }
  return travel->name;
}

std::string parseMorseCode(std::string morseCode){
   std::string decoded = "";
   auto wordList = split(morseCode,'/');
   for(auto word : wordList){
     auto letterList = split(word);
     std::string decodedWord = "";
     for(auto letter : letterList){
        if(letter == "")
            continue;
        decodedWord += parseLetter(letter);
     }
     decoded += decodedWord + ' ';
   }
   return decoded;
}

int main(int argc, char *argv[]){
   if(argc == 1){
      std::cout<<"Usage: MorseDecoder MORSECODE_STR"<<std::endl;
      return 0;
   }
   std::string morseCode = "";
   for(int i = 1; i < argc; i++){
      morseCode += argv[i];
      morseCode += " ";
   }
   morseTree = initMorseCode();
   std::cout <<parseMorseCode(morseCode)<<std::endl;
   return 0;
}

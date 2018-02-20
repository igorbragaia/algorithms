#include<iostream>
#include<vector>
using namespace std;


struct student{
  int idade;
  string nome;
};
typedef struct student student;


bool criteria(student & a, student & b){
    if(a.idade < b.idade){
      return true;
    } else{
      return a.nome < b.nome;
    }
}


int main(){
    vector<student> vetor;

    student * igor = new student;
    igor->idade = 21;
    igor->nome = "Igor";

    student * katia = new student;
    katia->idade = 29;
    katia->nome = "Kátia";

    student * chicken = new student;
    chicken->idade = 21;
    chicken->nome = "Chicken";

    vetor.push_back(*igor);
    vetor.push_back(*katia);
    vetor.push_back(*chicken);

    sort(vetor.begin(), vetor.end(), criteria);

    for(int i = 0; i < vetor.size(); i++){
      cout << vetor[i].nome << ", " << vetor[i].idade << " anos" << endl;
    }

  return 0;
}

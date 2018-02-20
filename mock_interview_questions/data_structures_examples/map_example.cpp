#include<iostream>
#include<map>
using namespace std;


struct student{
  int idade;
  string nome;
  bool operator<(const student & x) const {
    if(idade < x.idade){
      return true;
    } else{
      return nome < x.nome;
    }
  }
};
typedef struct student student;


int main(){
    map<student, string> mapa;

    student * igor = new student;
    igor->idade = 21;
    igor->nome = "Igor";

    student * katia = new student;
    katia->idade = 29;
    katia->nome = "Kátia";

    student * chicken = new student;
    chicken->idade = 21;
    chicken->nome = "Chicken";

    mapa[*igor] = "vai coroi!";
    mapa[*katia] = "será?";
    mapa[*chicken] = "money for nothing";

    for(map<student,string>::iterator it = mapa.begin(); it != mapa.end(); it++){
      cout << it->first.nome << ", " << it->first.idade << " anos" << ", frase: " << it->second << endl;
    }

  return 0;
}

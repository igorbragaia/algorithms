#include<iostream>
#include<queue>
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
    // orders in reversed sorting order
    priority_queue<student> pq;
    student top;

    student * igor = new student;
    igor->idade = 21;
    igor->nome = "Igor";

    student * katia = new student;
    katia->idade = 29;
    katia->nome = "Kátia";

    student * chicken = new student;
    chicken->idade = 21;
    chicken->nome = "Chicken";

    pq.push(*igor);
    pq.push(*katia);
    pq.push(*chicken);


    while(!pq.empty()){
      top = pq.top();
      cout << top.nome << ", " << top.idade << " anos" << endl;
      pq.pop();
    }

  return 0;
}

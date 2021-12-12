#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
//cout << RED "hola" RESET<<GREEN "adios" RESET << endl;
string s;
bool bendecido = false;


struct Player{
    int health;
    string name;

};
void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

bool compare_s(vector<string> a, vector<string> b){
  if(a.size() != b.size()) return false;
  else{
    for(int i = 0; i < a.size(); i++){
      if(a[i] != b[i]) return false;
    }
    return true;
  }
}

void lectura_entrada(vector<string>& e1){
  e1 = {};
  string e;
  cin >> e;
  while(e != "."){
    e1.push_back(e);
    cin >> e;
  }
}

void bendicion(Player& p) {
cout<<BOLDCYAN"                                                /|"<<endl;
cout<<"                                                ||"<<endl;
cout<<"                                                ||"<<endl;
cout<<"                                                ||"<<endl;
cout<<"                                                ||"<<endl;
cout<<"                 .--._                          ||"<<endl;
cout<<"            _.-'' (   /                         ||                        .-."<<endl;
cout<<"           (_.-(   `. |                         ||                        )  `-._"<<endl;
cout<<"          (  (   __.   |                        ||                   __.-' ` .)._)"<<endl;
cout<<"          (  (  _.-'  `.`-._                    ||               _.-     )  )     )"<<endl;
cout<<"           (  (   (         `.                  ||            .-'   .'  `.   )` - .)"<<endl;
cout<<"           ((  .-'   .-'  `.  `-.               ||          .'   .'     )  ) - . )  )"<<endl;
cout<<"            (  ( .-'       `-.   |            __/|__       / .'     `-.   `. )     )"<<endl;
cout<<"             `. ( _.-'         `. `.          _(  |       :     `-.       )   `-.  )"<<endl;
cout<<"              (   (   .'.-'         `.       /  ) /     .'  .'`.     `-.     ) _.-'"<<endl;
cout<<"              (.-' (      .-'    `.   `.    | ,'| |   .' .'                )  )"<<endl;
cout<<"               (     (     .'        `. `.,' /  |  |.'  : `-._`-.  `-.  `.)`.)"<<endl;
cout<<"                `-._  (       .'  .     ,'  /    |  | .'               )`.  )"<<endl;
cout<<"                    (      (       .'  /   ,-""-./|  | `.  `-.  )   )`-._.-'"<<endl;
cout<<"                     `-.      .'       |  / __.. `|  /               .-'"<<endl;
cout<<"                        |   .'     .'  | | /_  _|/  / `-. `.    ) .-'"<<endl;
cout<<"                         `-._.'        | | )    (|  |            /"<<endl;
cout<<"                             `-._   ,; |.' |    /   |   ` .  _.-'"<<endl;
cout<<"                                   -._ /   )`--'|   |  `._.-'"<<endl;
cout<<"                                      /   /`-..-'  /_..-'"<<endl;
cout<<"                                     ;  _/        |"<<endl;
cout<<"                                      ,'          `."<<endl;
cout<<"                                      |            |"<<endl;
cout<<"                                      `.__.-' '.__.'"<<endl;
cout<<"                                         `.       |"<<endl;
cout<<"                                           |       `."<<endl;
cout<<"                                           |         ."<<endl;
cout<<"                                           |          |"<<endl;
cout<<"                                           |           ."<<endl;
cout<<"                                          .'            |"<<endl;
cout<<"                                           ,'           |"<<endl;
cout<<"                                         ,'             |"<<endl;
cout<<"                                         .'             /"<<endl;
cout<<"                                         |              /"<<endl;
cout<<"                                         |             |"<<endl;
cout<<"                                         |             /"<<endl;
cout<<"                                        |             |"<<endl;
cout<<"                                        |             |"<<endl;
cout<<"                                      /               |"<<endl;
cout<<"                                     /    /            |"<<endl;
cout<<"                                    /           .:     |"<<endl;
cout<<"                                   /    .      .:      |"<<endl;
cout<<"                                  /    .:      .:     ,'"<<endl;
cout<<"                                ,'    .:      .::__.-|"<<endl;
cout<<"                               -..__   : __,,..-' |  |"<<endl;
cout<<"                                 /  |''''         |  ("<<endl;
cout<<"                               .'  ,'             |_  `."<<endl;
cout<<"                               `..'                 `.__;" RESET <<endl;
cout<<endl;
cout<<BOLDWHITE "BENDICIÓ: Sempre hi haurà algú disposat a ajudar-te! Recuperes la teva salut!" RESET<<endl;
p.health=100;
bendecido = true;
cout<<"VIDA: "<<p.health<<endl;
sleep(3);
Clear();
}


void delay_ms(double x){
    usleep(x*1000);
}

struct Question{
    string quest;
    string opt1;
    string opt2;
    string opt3;
    string opt4;
    int answ;
    string hint;
};

void boss1_ascii(){
    cout << BOLDWHITE "           _.------.                        .----.__      "   << endl;
    cout << "         /         \\_.       ._           /---.__  \\      "        << endl;
    cout << "         |  O    O   |\\\\___  //|          /       `\\ |     "    << endl;
    cout << "         |  .vvvvv.  | )   `(/ |         | o     o  \\|" << endl;
    cout << "         /  |     |  |/      \\ |  /|   ./| .vvvvv.  |\\ " << endl;
    cout << "        /   `^^^^^'  / _   _  `|_ ||  / /| |     |  | \\ "<< endl;
    cout << "      ./  /|         | O)  O   ) \\|| //' | `^vvvv'  |/\\\\ "<< endl;
    cout << "     /   / |         \\        /  | | ~   \\          |  \\\\ "<< endl;
    cout << "     \\  /  |        / \\ Y   /'   | \\     |          |   ~ "<< endl;
    cout << "      `'   |  _     |  `._/' |   |  \\     7        / "<< endl;
    cout << "       _.-'-' `-'-'|  |`-._/   /    \\ _ /    .    | "<< endl;
    cout << "   __.-'            \\  \\   .   / \\_.  \\ -|_/\\/ `--.|_ "<< endl;
    cout << "--'                  \\  \\ |   /    |  |              `- "<< endl;
    cout << "                      \\uU \\UU/     |  /" RESET << endl;
}





void boss1(Player &me){

// PREGUNTES
Question q1, q2, q3, q4, q5, q6,q7, q8, q9, q10;
q1.quest = "Teclas tengo sin ser piano y mi tamaño es pequeño: conmigo puede mi dueño ahorrar fatiga a su mano.";
q1.opt1 = "Teclado";
q1.opt2 = "Mouse";
q1.opt3 = "Máquina de escribir";
q1.opt4 = "Celular";
q1.answ = 1;
q1.hint = "PISTA: Tienes uno muy cerca ahora mismo";

q2.quest = "Son 28 caballeros de espaldas negras y lisas; delante, todo agujeros, por dominar se dan prisa.";
q2.opt1 = "Cartas";
q2.opt2 = "Dientes o braquets";
q2.opt3 = "Ajedrez";
q2.opt4 = "Domino";
q2.answ = 4;
q2.hint = "PISTA: Qué juego tiene fichas con agujeros y 'espaldas' negras?";

q3.quest = "Soy de madera, tengo un arco y no flecha.";
q3.opt1 = "Marco";
q3.opt2 = "Pintura";
q3.opt3 = "Mesa";
q3.opt4 = "Violín";
q3.answ = 4;
q3.hint = "PISTA: Qué objeto es de madera y se usa con un arco?";

q4.quest = "Vueltas y vueltas doy sin cansarme, mas si no bebo, paro al instante.";
q4.opt1 = "Volante de un coche";
q4.opt2 = "Borracho";
q4.opt3 = "Molino de agua";
q4.opt4 = "Globo de agua";
q4.answ = 3;
q4.hint = "PISTA: Qué objeto da vueltas siempre y cuando 'beba'?";

q5.quest = "Blanca como la paloma, negra como la pez, habla y no tiene lengua, anda y no tiene pies.";
q5.opt1 = "Lengua";
q5.opt2 = "Carta";
q5.opt3 = "Mano";
q5.opt4 = "Cucaracha";
q5.answ = 2;
q5.hint = "PISTA: Qué es blanco siempre y puede 'hablar' y 'moverse'?";

q6.quest = "Quin és el país més gran d'Àfrica per àrea?";
q6.opt1 = "Algèria";
q6.opt2 = "Republica Democràtica del Congo";
q6.opt3 = "Sudan";
q6.opt4 = "Etiòpia";
q6.answ = 1;
q6.hint = "PISTA: No és ni el Congo ni Etiòpia";

q7.quest = "Sobre quin menjar es va basar el personatge de Pac Man?";
q7.opt1 = "Meló";
q7.opt2 = "Taronja";
q7.opt3 = "Formatge";
q7.opt4 = "Pizza";
q7.answ = 4;
q7.hint = "PISTA: No és ni el Formatge ni el Meló";

vector<Question> vector_preguntas = {q1, q2, q3, q4, q5, q6, q7};

srand(getpid());
boss1_ascii();
cout << endl;
cout << endl;
sleep(1);
cout << "EH TU! Què fas aquí?" << endl;
cout << BLUE "\nPresiona qualsevol tecla + Enter per a continuar ..." RESET << endl;
cin >> s;
Clear();
boss1_ascii();
cout << "\nNo pasaràs si no contestes correctament a totes les preguntes que faré!" << endl;
cout << "Si contestes malament..." << endl;
sleep(1);
cout << RED "Perdràs 10 punts de vida!" RESET << endl;
sleep(1);
cout << "Una vegada les contestis totes, et deixaré passar..." << endl;
delay_ms(100);
cout << endl;
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
cout << endl;
cin >> s;
Clear();
boss1_ascii();
delay_ms(600);

// COMENÇA EL JOC!

// 1
int times = 0;
int x = rand() % 7;
Question q = vector_preguntas[x];

while (true){
    Clear();
    cout << YELLOW "███████████████████████████████████████████████████████████████████▀████████████████████████████" << endl;
    cout << "█▄─▄▄─█▄─▄▄▀█▄─▄█▄─▀█▀─▄█▄─▄▄─█▄─▄▄▀██▀▄─████▄─▄▄─█▄─▄▄▀█▄─▄▄─█─▄▄▄▄█▄─██─▄█▄─▀█▄─▄█─▄─▄─██▀▄─██" << endl;
    cout << "██─▄▄▄██─▄─▄██─███─█▄█─███─▄█▀██─▄─▄██─▀─█████─▄▄▄██─▄─▄██─▄█▀█─██▄─██─██─███─█▄▀─████─████─▀─██" << endl;
    cout << "▀▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▀▄▄▄▀▄▄▄▀▄▄▄▄▄▀▄▄▀▄▄▀▄▄▀▄▄▀▀▀▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▀▀▄▄▀▀▄▄▄▀▀▄▄▀▄▄▀" RESET<< endl;
    cout << endl;
    cout << q.quest << endl;
    cout << endl;
    cout << "1. " << q.opt1 << endl;
    cout << "2. " << q.opt2 << endl;
    cout << "3. " << q.opt3 << endl;
    cout << "4. " << q.opt4 << endl;
    cout << endl;
    if (times == 2){
        cout << q.hint << endl;
    }
    int ans;
    cout <<GREEN "---->" RESET;
    cin >> ans;

    if (ans == q.answ){
        break;
    } else {
        ++times;
        me.health -= 10;
        cout << RED "\nINCORRECTE [-10 HP]" RESET << endl;
        sleep(1);
        if (me.health <= 0){
            bendicion(me);
            sleep(3);
        }
    }
}

vector_preguntas.erase(vector_preguntas.begin() + x);
times = 0;
x = rand() % 6;
q = vector_preguntas[x];

// 2
while(true){
    Clear();

    cout << BLUE "█████████████████▀████████████████████████████████████████████▀████████████████████████████" << endl;
    cout << "█─▄▄▄▄█▄─▄▄─█─▄▄▄▄█─▄▄─█▄─▀█▄─▄██▀▄─████▄─▄▄─█▄─▄▄▀█▄─▄▄─█─▄▄▄▄█▄─██─▄█▄─▀█▄─▄█─▄─▄─██▀▄─██" <<endl;
    cout << "█▄▄▄▄─██─▄█▀█─██▄─█─██─██─█▄▀─███─▀─█████─▄▄▄██─▄─▄██─▄█▀█─██▄─██─██─███─█▄▀─████─████─▀─██" << endl;
    cout <<"▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▀▀▄▄▀▄▄▀▄▄▀▀▀▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▀▀▄▄▀▀▄▄▄▀▀▄▄▀▄▄▀" RESET<< endl;
    cout << endl;
    cout << q.quest << endl;
    cout << endl;
    cout << "1. " << q.opt1 << endl;
    cout << "2. " << q.opt2 << endl;
    cout << "3. " << q.opt3 << endl;
    cout << "4. " << q.opt4 << endl;
    cout << endl;
    if (times == 2){
        cout << q.hint << endl;
    }
    int ans;
    cout << GREEN "---->" RESET;
    cin >> ans;

    if (ans == q.answ){
        break;
    } else {
        ++times;
        me.health -= 10;
        cout << RED "\nINCORRECTE [-10 HP]" RESET << endl;
        sleep(1);
        if (me.health <= 0){
            bendicion(me);
            sleep(3);
        }
    }
}
vector_preguntas.erase(vector_preguntas.begin() + x);

times = 0;
x = rand() % 5;
q = vector_preguntas[x];
// 3
while(true){
    Clear();
    cout << GREEN "▀▀█▀▀ ▒█▀▀▀ ▒█▀▀█ ▒█▀▀█ ▒█▀▀▀ ▒█▀▀█ ░█▀▀█ 　 ▒█▀▀█ ▒█▀▀█ ▒█▀▀▀ ▒█▀▀█ ▒█░▒█ ▒█▄░▒█ ▀▀█▀▀ ░█▀▀█" << endl;
    cout << "░▒█░░ ▒█▀▀▀ ▒█▄▄▀ ▒█░░░ ▒█▀▀▀ ▒█▄▄▀ ▒█▄▄█ 　 ▒█▄▄█ ▒█▄▄▀ ▒█▀▀▀ ▒█░▄▄ ▒█░▒█ ▒█▒█▒█ ░▒█░░ ▒█▄▄█" << endl;
    cout << "░▒█░░ ▒█▄▄▄ ▒█░▒█ ▒█▄▄█ ▒█▄▄▄ ▒█░▒█ ▒█░▒█ 　 ▒█░░░ ▒█░▒█ ▒█▄▄▄ ▒█▄▄█ ░▀▄▄▀ ▒█░░▀█ ░▒█░░ ▒█░▒█" RESET << endl;
    cout << endl;
    cout << q.quest << endl;
    cout << endl;
    cout << "1. " << q.opt1 << endl;
    cout << "2. " << q.opt2 << endl;
    cout << "3. " << q.opt3 << endl;
    cout << "4. " << q.opt4 << endl;
    cout << endl;
    if (times == 2){
        cout << q.hint << endl;
    }
    int ans;
    cout <<GREEN "---->" RESET;

    cin >> ans;

    if (ans == q.answ){
        break;
    } else {
        ++times;
        me.health -= 10;
        cout << RED "\nINCORRECTE [-10 HP]" RESET << endl;
        sleep(1);
        if (me.health <= 0){
            bendicion(me);
            sleep(3);
        }
    }
}
vector_preguntas.erase(vector_preguntas.begin() + x);

times = 0;
x = rand() % 4;
q = vector_preguntas[x];
// 4
while(true){
    Clear();

cout << RED "██╗░░░██╗██╗░░░░░████████╗██╗███╗░░░███╗░█████╗░" << endl;
cout << "██║░░░██║██║░░░░░╚══██╔══╝██║████╗░████║██╔══██╗" << endl;
cout << "██║░░░██║██║░░░░░░░░██║░░░██║██╔████╔██║███████║" << endl;
cout << "██║░░░██║██║░░░░░░░░██║░░░██║██║╚██╔╝██║██╔══██║" << endl;
cout << "╚██████╔╝███████╗░░░██║░░░██║██║░╚═╝░██║██║░░██║" << endl;
cout << "░╚═════╝░╚══════╝░░░╚═╝░░░╚═╝╚═╝░░░░░╚═╝╚═╝░░╚═╝" << endl;

cout << "██████╗░██████╗░███████╗░██████╗░██╗░░░██╗███╗░░██╗████████╗░█████╗░" << endl;
cout << "██╔══██╗██╔══██╗██╔════╝██╔════╝░██║░░░██║████╗░██║╚══██╔══╝██╔══██╗" << endl;
cout << "██████╔╝██████╔╝█████╗░░██║░░██╗░██║░░░██║██╔██╗██║░░░██║░░░███████║" << endl;
cout << "██╔═══╝░██╔══██╗██╔══╝░░██║░░╚██╗██║░░░██║██║╚████║░░░██║░░░██╔══██║" << endl;
cout << "██║░░░░░██║░░██║███████╗╚██████╔╝╚██████╔╝██║░╚███║░░░██║░░░██║░░██║" << endl;
cout << "╚═╝░░░░░╚═╝░░╚═╝╚══════╝░╚═════╝░░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝" RESET << endl;
    cout << endl;
    cout << q.quest << endl;
    cout << endl;
    cout << "1. " << q.opt1 << endl;
    cout << "2. " << q.opt2 << endl;
    cout << "3. " << q.opt3 << endl;
    cout << "4. " << q.opt4 << endl;
    cout << endl;
    if (times == 2){
        cout << q.hint << endl;
    }
    int ans;
    cout <<GREEN "---->" RESET;
    cin >> ans;

    if (ans == q.answ){
        break;
    } else {
        ++times;
        me.health -= 10;
        cout << RED "\nINCORRECTE [-10 HP]" RESET << endl;
        sleep(1);
        if (me.health <= 0){
            bendicion(me);
            sleep(3);
        }
    }
}
// El jugador ha guanyat al boss
Clear();
boss1_ascii();
cout << MAGENTA " \nFELICITATS! Has superat la prova!" RESET<< endl;
sleep(3);

return;
}

void boss2(Player& me){ //piedra papel tijera

Clear();
 cout << "Avans de començar" << endl;
 cout << "PER AQUESTA PART:" << endl << endl;
 delay_ms(500);
 cout << "Si veus en qualsevol moment " <<GREEN "---->" RESET << " hauràs d'escriure una resposta, D'UNA PARAULA, amb el teclat i polsar la tecla " << RED "enter" RESET << endl;
 sleep(1);
 cout << endl << "Prova-ho" << endl;
 cout <<GREEN "---->" RESET;
 cin >> s;
 sleep(1);
 cout << endl;
 cout << "Molt bé!" << endl << endl;
 delay_ms(1500);
 cout << "També apareixerà, en certes ocasions, el missatge: " <<GREEN "Prem qualsevol tecla per a continuar ..." RESET<< endl;
 cout << "En aquest cas hauràs de polsar " <<RED  "qualsevol tecla" RESET << " i " << RED "enter" RESET<< endl;
 sleep(1);
 cout << endl << "Prova-ho" << endl;
 cout <<GREEN "Prem qualsevol tecla per a continuar ..." RESET<< endl;
 cin >> s;
 sleep(1);
 cout << endl << "GENIAL! Ja podem començar" << endl;
 sleep(1);
 cout << endl;
 cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
cin >> s;
Clear();


cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░▄█▀▀▀████████████▀▀▀█░░" << endl;
cout << "█░░░░░░██████████░░░░░▀▄" << endl;
cout << "█▄░░░█▀░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░▀█░░░█░░░░░░░░░░█░░░█▀░" RESET<< endl;
cout << endl;
cout << endl;
cout << "EH, TU!" << endl;
sleep(1);
cout << "QUÈ FAS AQUÍ!?" << endl;
cout << GREEN "---->" RESET;
//string s;
cin >> s;
sleep(1);
cout << "Així que " <<YELLOW << s <<RESET<< " eh" << endl;
cout << endl;
sleep(1);
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
cin >> s;
Clear();
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░▄█▀▀▀████████████▀▀▀█░░" << endl;
cout << "█░░░░░░██████████░░░░░▀▄" << endl;
cout << "█▄░░░█▀░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░▀█░░░█░░░░░░░░░░█░░░█▀░" RESET<< endl;
cout << endl;
cout << endl;
sleep(1);
cout << "He sentit que et dius " << me.name << endl;
sleep(1);
cout << "Jo em dic " << GREEN "Panya" RESET<< endl;
sleep(1);
cout <<GREEN "Panya" RESET << ", l' aranya" << endl;
cout << endl;
sleep(1);
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
cin >> s;
Clear();
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░▄█▀▀▀████████████▀▀▀█░░" << endl;
cout << "█░░░░░░██████████░░░░░▀▄" << endl;
cout << "█▄░░░█▀░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░▀█░░░█░░░░░░░░░░█░░░█▀░" RESET<< endl;
cout << endl;
cout << endl;
sleep(1);
cout << "Si vols continuar el teu ";
cout << MAGENTA "màgic" RESET << " viatge..."  << endl;
sleep(2);
cout << "Hauràs de jugar amb mi!" << endl;
sleep(1);
cout << "Últimament estic molt avorrit en aquesta cova" << endl;
sleep(1);
cout << endl;
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
//std::cin.get();
cin >> s;
Clear();
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░▄█▀▀▀████████████▀▀▀█░░" << endl;
cout << "█░░░░░░██████████░░░░░▀▄" << endl;
cout << "█▄░░░█▀░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░▀█░░░█░░░░░░░░░░█░░░█▀░" RESET<< endl;
cout << endl;
cout << endl;
sleep(1);
cout << "Jugarem, jugarem..." << endl;
sleep(1);
cout << "A què juguem?" << endl;
cout <<GREEN "---->" RESET;
cin >> s;
sleep(1);
cout << "Vols jugar a " <<YELLOW<< s <<RESET<< '?' << endl;
sleep(1);
cout << "Saps què? Com que tinc 8 mans, per què no juguem a pedra, paper o tisores?" << endl;
cout << endl;
sleep(1);
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
//std::cin.get();
cin >> s;
Clear();
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░▄█▀▀▀████████████▀▀▀█░░" << endl;
cout << "█░░░░░░██████████░░░░░▀▄" << endl;
cout << "█▄░░░█▀░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░▀█░░░█░░░░░░░░░░█░░░█▀░" RESET<< endl;
cout << endl;
cout << endl;
sleep(1);
cout << "T'explicarè com jugarem" << endl;
delay_ms(1000);
cout << "Jo tindré tantes vides com mans em quedin, començaré amb 8!" << endl;
delay_ms(1000);
cout << "Si em guanyes perdré una vida (i un braç, auch)" << endl;
delay_ms(800);
cout << "Però compte! Si jo et guanyo perdràs tants punts de vida com mans em quedin" << endl;
cout << endl;
delay_ms(2000);

cout << "Avans, però, et recordaré com es juga al meu joc favorit" << endl << endl;
delay_ms(800);
cout << "A cada torn hauràs de escollir entre ";
cout <<  BOLDYELLOW "PEDRA  PAPER  TISORES"  RESET<< endl;
cout << "Jo escollirè també una de les opcions però no et diré quina, és clar" << endl;
delay_ms(500);
cout << "La " << GREEN "PEDRA" RESET << " guanya a les " << RED "TISORES" RESET << endl;
delay_ms(500);
cout << "Les " << GREEN "TISORES" RESET << " a el " << RED "PAPER" RESET << endl;
delay_ms(500);
cout << "I el "  << GREEN "PAPER" RESET << " a la " << RED "PEDRA" RESET<< endl;
cout << endl;
sleep(2);
cout << "ESTÀS LLEST?" << endl << endl;

sleep(1);
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
//std::cin.get();
cin >> s;
Clear();

int vides = 8, anterior = -1;
bool inici = true;
while (vides > 0) {

  cout << "██████╗░██╗░░░░░░█████╗░██╗░░░██╗███████╗██████╗░  ██╗░░░██╗░██████╗░░░  ██████╗░░█████╗░███╗░░██╗██╗░░░██╗░█████╗░" << endl;
  cout << "██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝██╔════╝██╔══██╗  ██║░░░██║██╔════╝░░░  ██╔══██╗██╔══██╗████╗░██║╚██╗░██╔╝██╔══██╗" << endl;
  cout << "██████╔╝██║░░░░░███████║░╚████╔╝░█████╗░░██████╔╝  ╚██╗░██╔╝╚█████╗░░░░  ██████╔╝███████║██╔██╗██║░╚████╔╝░███████║" << endl;
  cout << "██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░██╔══╝░░██╔══██╗  ░╚████╔╝░░╚═══██╗░░░  ██╔═══╝░██╔══██║██║╚████║░░╚██╔╝░░██╔══██║" << endl;
  cout << "██║░░░░░███████╗██║░░██║░░░██║░░░███████╗██║░░██║  ░░╚██╔╝░░██████╔╝██╗  ██║░░░░░██║░░██║██║░╚███║░░░██║░░░██║░░██║" << endl;
  cout << "╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝  ░░░╚═╝░░░╚═════╝░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝" << endl;

  cout << endl << endl << endl;
    if (inici) delay_ms(500);
  switch(vides)
  {
      case 8:
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░▄█▀▀▀████████████▀▀▀█░░" << endl;
cout << "█░░░░░░██████████░░░░░▀▄" << endl;
cout << "█▄░░░█▀░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░▀█░░░█░░░░░░░░░░█░░░█▀░" RESET<< endl;
      break;
      case 7:
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░▄█▀▀▀████████████▀▀▀█░░" << endl;
cout << "█░░░░░░██████████░░░░░▀▄" << endl;
cout << "█▄░░░░░░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░▀█░░░░░░░░░░░░░░█░░░█▀░" RESET<< endl;
      break;
      case 6:
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░░░░░░████████████▀▀▀█░░" << endl;
cout << "░░░░░░░██████████░░░░░▀▄" << endl;
cout << "░░░░░░░░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░░░░░░░░░░░░░░░░░█░░░█▀░" RESET<< endl;
      break;
      case 5:
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░░░░░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "░░░░░░░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░░░░░░████████████▀▀▀█░░" << endl;
cout << "░░░░░░░██████████░░░░░▀▄" << endl;
cout << "░░░░░░░░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░░░░░░░░░░░░░░░░░█░░░█▀░" RESET<< endl;
      break;
      case 4:
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░░░░░░║░░░░▄▀░░░░░░" << endl;
cout << "░░░░░░░░░▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "░░░░░░░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░░░░░░████████████▀▀▀█░░" << endl;
cout << "░░░░░░░██████████░░░░░▀▄" << endl;
cout << "░░░░░░░░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░░░░░░░░░░░░░░░░░█░░░█▀░" RESET<< endl;
      break;
      case 3:
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░▄▄▄▄▄▄░░░░░▄▄▄░" << endl;
cout << "░░░░░░░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░░░░░░████████████▀▀▀█░░" << endl;
cout << "░░░░░░░██████████░░░░░▀▄" << endl;
cout << "░░░░░░░░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░░░░░░░░░░░░░░░░░█░░░█▀░" RESET<< endl;
      break;
      case 2:
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░▄▄▄▄▄▄░░░░░░░░░" << endl;
cout << "░░░░░░░█▀░░▐▌░░▀█░░░░░░░" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░░░░░░████████████▀▀▀█░░" << endl;
cout << "░░░░░░░██████████░░░░░▀▄" << endl;
cout << "░░░░░░░░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░░░░░░░░░░░░░░░░░█░░░█▀░" RESET<< endl;
      break;
      case 1:
cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░▄▄▄▄▄▄░░░░░░░░░" << endl;
cout << "░░░░░░░█▀░░▐▌░░▀█░░░░░░░" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░░░░░░████████████░░░░░░" << endl;
cout << "░░░░░░░██████████░░░░░░░" << endl;
cout << "░░░░░░░░░▀▀▀▀▀▀░░▀█░░░░░" << endl;
cout << "░░░░░░░░░░░░░░░░░█░░░░░░" RESET<< endl;
      break;
  }
      cout << endl << endl;



if(inici) delay_ms(500);
  cout << GREEN "▄█─ ─ 　 " RESET <<BOLDCYAN "░█▀▀█ ░█▀▀▀ ░█▀▀▄ ░█▀▀█ ─█▀▀█" RESET << endl;
  cout << GREEN "─█─   　 " RESET <<BOLDCYAN "░█▄▄█ ░█▀▀▀ ░█─░█ ░█▄▄▀ ░█▄▄█" RESET << endl;
  cout << GREEN "▄█▄ ▄ 　 " RESET <<BOLDCYAN "░█─── ░█▄▄▄ ░█▄▄▀ ░█─░█ ░█─░█" RESET << endl;
  cout << endl << endl;
if(inici) delay_ms(500);
  cout << GREEN "█▀█ ─ 　 " RESET <<BOLDCYAN "░█▀▀█ ─█▀▀█ ░█▀▀█ ░█▀▀▀ ░█▀▀█" RESET << endl;
  cout << GREEN "─▄▀ ▄ 　 " RESET <<BOLDCYAN "░█▄▄█ ░█▄▄█ ░█▄▄█ ░█▀▀▀ ░█▄▄▀" RESET << endl;
  cout << GREEN "█▄▄ █ 　 " RESET <<BOLDCYAN "░█─── ░█─░█ ░█─── ░█▄▄▄ ░█─░█" RESET << endl;
  cout << endl << endl;
if(inici) delay_ms(500);
  cout << GREEN "█▀▀█ ─ 　 " RESET <<BOLDCYAN "▀▀█▀▀ ▀█▀ ░█▀▀▀█ ░█▀▀▀█ ░█▀▀█ ░█▀▀▀ ░█▀▀▀█" RESET << endl;
  cout << GREEN "──▀▄ ▄ 　 " RESET <<BOLDCYAN "─░█── ░█─ ─▀▀▀▄▄ ░█──░█ ░█▄▄▀ ░█▀▀▀ ─▀▀▀▄▄" RESET << endl;
  cout << GREEN "█▄▄█ █ 　 " RESET <<BOLDCYAN "─░█── ▄█▄ ░█▄▄▄█ ░█▄▄▄█ ░█─░█ ░█▄▄▄ ░█▄▄▄█" RESET << endl;
  cout << endl << endl;

if(inici) delay_ms(500);
cout << BOLDYELLOW "Escull una de les tres opcions escrivint el seu número corresponent" RESET << endl << endl;
cout <<GREEN "---->" RESET;
//cin >> s;
int res;
cin >> res;
delay_ms(500);
cout << endl << "Has volgut jugar ";
if (res == 1) cout << RED "pedra" RESET<< endl;
else if (res == 2) cout << RED "paper" RESET << endl;
else cout << RED "tisores" RESET << endl;
delay_ms(1000);
cout << "L'aranya " << GREEN "Panya" RESET << " ha jugat..." << endl;
int ar;
if (inici) {
inici = false;
ar = rand() % 3;
}
else ar = anterior;
sleep(1);
if (ar == 1) cout << CYAN "pedra" RESET<< endl;
else if (ar == 2) cout << CYAN "paper" RESET<< endl;
else cout << CYAN "tisores" RESET<< endl;
delay_ms(1000);
cout << endl << "......" << endl;
sleep(2);
cout << endl;
anterior = res;

if ((res == 1 and ar == 3) or (res == 2 and ar == 1) or (res == 3 and ar == 2)) {
--vides;
cout << GREEN "Has guanyat la ronda!" RESET << endl;
}

else if (res == ar) {
cout << BLUE "Heu empatat! Ningú perd vida, continua el joc" RESET << endl;
}
else {
cout << RED "L'aranya guanya!" RESET << " Però això no s'ha acabat ancara!" << endl << "Jejejeje..." << endl << endl;
///////////// --vida
me.health -= vides;
cout << GREEN "Vida de " << me.name << ": " << me.health << RESET << endl;
if (me.health < 10) {
  sleep(1);
  cout << endl << "COMPTE, tens poca vida..." << endl;
  delay_ms(1000);
  cout << YELLOW "EH? S'ACOSTA UN AJUDANT!" RESET << endl;
  sleep(1);
  cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
  //std::cin.get();
  cin >> s;
    bendicion(me);
}
}

delay_ms(1000);
cout << endl;
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
//std::cin.get();
cin >> s;
Clear();




  }

  cout << "██████╗░██╗░░░░░░█████╗░██╗░░░██╗███████╗██████╗░  ██╗░░░██╗░██████╗░░░  ██████╗░░█████╗░███╗░░██╗██╗░░░██╗░█████╗░" << endl;
  cout << "██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝██╔════╝██╔══██╗  ██║░░░██║██╔════╝░░░  ██╔══██╗██╔══██╗████╗░██║╚██╗░██╔╝██╔══██╗" << endl;
  cout << "██████╔╝██║░░░░░███████║░╚████╔╝░█████╗░░██████╔╝  ╚██╗░██╔╝╚█████╗░░░░  ██████╔╝███████║██╔██╗██║░╚████╔╝░███████║" << endl;
  cout << "██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░██╔══╝░░██╔══██╗  ░╚████╔╝░░╚═══██╗░░░  ██╔═══╝░██╔══██║██║╚████║░░╚██╔╝░░██╔══██║" << endl;
  cout << "██║░░░░░███████╗██║░░██║░░░██║░░░███████╗██║░░██║  ░░╚██╔╝░░██████╔╝██╗  ██║░░░░░██║░░██║██║░╚███║░░░██║░░░██║░░██║" << endl;
  cout << "╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝  ░░░╚═╝░░░╚═════╝░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝" << endl;

  cout << endl << endl << endl;

  cout <<BOLDRED "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░▄▄▄▄▄▄░░░░░░░░░" << endl;
cout << "░░░░░░░█▀░░▐▌░░▀█░░░░░░░" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░░░░░░████████████░░░░░░" << endl;
cout << "░░░░░░░██████████░░░░░░░" << endl;
cout << "░░░░░░░░░▀▀▀▀▀▀░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░░░░░░░░░░░░░░" RESET<< endl;
cout << endl << endl;

sleep(1);
cout << endl;
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
//std::cin.get();
cin >> s;
Clear();




cout << "██╗░░░██╗██╗░█████╗░████████╗░█████╗░██████╗░██╗░█████╗░" << endl;
cout << "██║░░░██║██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗██║██╔══██╗" << endl;
cout << "╚██╗░██╔╝██║██║░░╚═╝░░░██║░░░██║░░██║██████╔╝██║███████║" << endl;
cout << "░╚████╔╝░██║██║░░██╗░░░██║░░░██║░░██║██╔══██╗██║██╔══██║" << endl;
cout << "░░╚██╔╝░░██║╚█████╔╝░░░██║░░░╚█████╔╝██║░░██║██║██║░░██║" << endl;
cout << "░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝" << endl;
cout << endl << endl;

cout <<BOLDYELLOW "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░░░░░░░░▄▄▄▄▄▄░░░░░░░░░" << endl;
cout << "░░░░░░░█▀░░▐▌░░▀█░░░░░░░" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░░░░░░████████████░░░░░░" << endl;
cout << "░░░░░░░██████████░░░░░░░" << endl;
cout << "░░░░░░░░░▀▀▀▀▀▀░░░░░░░░░" << endl;
cout << "░░░░░░░░░░░░░░░░░░░░░░░░" RESET<< endl;
cout << endl << endl;
cout << "M'has guanyat!!" << endl;
delay_ms(800);
cout << "Ets molt bo" << endl;
cout << YELLOW "Saps què, menys a la primera ronda, t'he copiat els moviments?" << endl << "Pesava així et guanyaria, però ets millor del que esperava" RESET<< endl;
sleep(1);
cout << endl;
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
//std::cin.get();
cin >> s;
Clear();

cout << "██╗░░░██╗██╗░█████╗░████████╗░█████╗░██████╗░██╗░█████╗░" << endl;
cout << "██║░░░██║██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗██║██╔══██╗" << endl;
cout << "╚██╗░██╔╝██║██║░░╚═╝░░░██║░░░██║░░██║██████╔╝██║███████║" << endl;
cout << "░╚████╔╝░██║██║░░██╗░░░██║░░░██║░░██║██╔══██╗██║██╔══██║" << endl;
cout << "░░╚██╔╝░░██║╚█████╔╝░░░██║░░░╚█████╔╝██║░░██║██║██║░░██║" << endl;
cout << "░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝" << endl;
cout << endl << endl;
cout <<BOLDYELLOW "░░░░░░░░░░░║░░░░░░░░░░░░" << endl;
cout << "░░▄█▀▄░░░░░║░░░░░░▄▀▄▄░░" << endl;
cout << "░░░░░░▀▄░░░║░░░░▄▀░░░░░░" << endl;
cout << "░▄▄▄░░░░█▄▄▄▄▄▄█░░░░▄▄▄░" << endl;
cout << "▀░░░▀█░█▀░░▐▌░░▀█░█▀░░░▀" << endl;
cout << "░░░░░░██░░▀▐▌▀░░██░░░░░░" << endl;
cout << "░▄█▀▀▀████████████▀▀▀█░░" << endl;
cout << "█░░░░░░██████████░░░░░▀▄" << endl;
cout << "█▄░░░█▀░░▀▀▀▀▀▀░░▀█░░░▄█" << endl;
cout << "░▀█░░░█░░░░░░░░░░█░░░█▀░" RESET<< endl;
cout << endl << endl;
sleep(1);
cout << "Ja puc estirar les cames un altre cop" << endl;
cout << endl;
sleep(1);
cout << "T'ho has passat tant bé com jo? Espero que sí!" << endl;
delay_ms(1500);
cout << "Estic ansiós per veure quan podem jugar més" << endl << endl;
sleep(3);
cout << GREEN "Crec que ha arribat el moment del nostre comiat" RESET << endl << endl;
sleep(3);
cout << "Com m'has vençut, compliré la meva paraula i et " << CYAN << "deixaré passar" RESET << endl;
cout << endl;
sleep(3);
cout << YELLOW "ENS VEIEM!" RESET << endl;
sleep(1);
cout << endl;
cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
//std::cin.get();
cin >> s;
Clear();

}

void imprir_murcie1(){
cout<<"                      _..-'(                       )`-.._ "<< endl;
cout<<"                    ./'. '||\\\\.       (\\_/)       .//||` .`\\. "<< endl;
cout<<"                 ./'.|'.'||||\\\\|..    )O O(    ..|//||||`.`|.`\\. "<< endl;
cout<<"              ./'..|'.|| |||||\\`````` '`\"'` ''''''/||||| ||.`|..`\\. "<< endl;
cout<<"            ./\'.||\'.|||| ||||||||||||.     .|||||||||||| |||||.`||.`\\. "<< endl;
cout<<"           /\'|||\'.|||||| ||||||||||||{     }|||||||||||| ||||||.`|||`\\ "<< endl;
cout<<"          \'.|||\'.||||||| ||||||||||||{     }|||||||||||| |||||||.`|||.` "<< endl;
cout<<"         \'.||| ||||||||| |/\'   ``\\||``     \'\'||/\'\'   `\\| ||||||||| |||.` "<< endl;
cout<<"         |/\' \\./\'     `\\./         \\!|\\   /|!/         \\./\'     `\\./ `\\| "<< endl;
cout<<"         V    V         V          }\' `\\ /\' `{          V         V    V "<< endl;
cout<<"         `    `         `               V               '         '    '"<< endl;
}
void imprir_murcie2(){
cout<<"                            -.                       .- "<< endl;
cout<<"                        _..-'(                       )`-.._ "<< endl;
cout<<"                    ./'. '||\\\\.      _ _ /|" << YELLOW "ACK!" RESET<<"  .//||` .`\\. "<< endl;
cout<<"                 ./'.|'.'||||\\\\|..   \\'o.O\' /  ..|//||||`.`|.`\\. "<< endl;
cout<<"              ./\'..|\'.|| |||||\\``````=(___)=''''''/||||| ||.`|..`\\. "<< endl;
cout<<"            ./'.||'.|||| ||||||||||||.  U  .|||||||||||| ||||.`||.`\\. "<< endl;
cout<<"           /'|||'.|||||| |||||||||||||     ||||||||||||| ||||||.`|||`\\ "<< endl;
cout<<"          '.|||'.||||||| |||||||||||||     ||||||||||||| |||||||.`|||.` "<< endl;
cout<<"         '.||| ||||||||| |/'   ``\\||``     ''||/''   `\\| ||||||||| |||.` "<< endl;
cout<<"         |/' \\./'     `\\./         \\!|\\   /|!/         \\./'     `\\./ `\\| "<< endl;
cout<<"         V    V         V          }' `\\ /' `{          V         V    V "<< endl;
cout<<"         `    `         `               V               '         '    ' "<< endl;
}
void boss3(Player& me){
    imprir_murcie1();
    int hp=100;
    cout << YELLOW "emmmm..." RESET<< endl;
    sleep(2);
    cout << BLUE "What's" <<GREEN " up" RESET<< MAGENTA" boy~~~~~" RESET << endl;
    sleep(2);
    cout << GREEN "No em preguntis qui sóc, tampoc et pregunto qui ets. Sóc un ànim lliure."<< endl;
    sleep(2);
    cout << "Només et deixo pasar si...." RESET<< endl;
    sleep(2);
    cout << RED"EM DONAS EL TEU COR, " RESET<< BLUE "perquè així mai estaràs TRIST." RESET << endl;
    sleep(2);
    cout << GREEN "RELAX~~ (～￣▽￣)～" RESET << endl;
    sleep(3);
    cout << GREEN "És una broma. HAHAHA" << endl;
    sleep(2);
    cout << "Jo m'alimento del mal, si vols passar m'has d'atacar amb el teu mal." RESET << endl;
    sleep(2);
    cout << RED"Però si el teu mal és insuficient em quedo amb la teva bona memòria." RESET<< endl;
    sleep(1);
    cout << WHITE "ACCEPTES?" RESET << RED " S" RESET << "/" << BLUE "N" RESET << endl;
    char rep;
    while(cin >> rep ){
        if(rep == 'S' or rep =='s'){
        Clear();
        imprir_murcie1();
        cout << BOLDCYAN "██████╗░███████╗██████╗░  ░██████╗░██╗░░░██╗███████╗  ███████╗░██████╗████████╗░█████╗░░██████╗"<< endl;
        cout <<"██╔══██╗██╔════╝██╔══██╗  ██╔═══██╗██║░░░██║██╔════╝  ██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔════╝"<< endl;
        cout <<"██████╔╝█████╗░░██████╔╝  ██║██╗██║██║░░░██║█████╗░░  █████╗░░╚█████╗░░░░██║░░░███████║╚█████╗░"<< endl;
        cout <<"██╔═══╝░██╔══╝░░██╔══██╗  ╚██████╔╝██║░░░██║██╔══╝░░  ██╔══╝░░░╚═══██╗░░░██║░░░██╔══██║░╚═══██╗"<< endl;
        cout <<"██║░░░░░███████╗██║░░██║  ░╚═██╔═╝░╚██████╔╝███████╗  ███████╗██████╔╝░░░██║░░░██║░░██║██████╔╝"<< endl;
        cout <<"╚═╝░░░░░╚══════╝╚═╝░░╚═╝  ░░░╚═╝░░░░╚═════╝░╚══════╝  ╚══════╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═════╝░"<< endl;

        cout <<"████████╗██████╗░██╗░██████╗████████╗░█████╗░"<< endl;
        cout <<"╚══██╔══╝██╔══██╗██║██╔════╝╚══██╔══╝██╔══██╗"<< endl;
        cout <<"░░░██║░░░██████╔╝██║╚█████╗░░░░██║░░░╚═╝███╔╝"<< endl;
        cout <<"░░░██║░░░██╔══██╗██║░╚═══██╗░░░██║░░░░░░╚══╝░"<< endl;
        cout <<"░░░██║░░░██║░░██║██║██████╔╝░░░██║░░░░░░██╗░░"<< endl;
        cout <<"░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═════╝░░░░╚═╝░░░░░░╚═╝░░" RESET<< endl;
        cout << BOLDCYAN"RESPOSTES:has de posar" << RED <<'.' << RESET<< BOLDCYAN "al final de la frase." RESET<< endl;
        int cont=0;
        char c;
        while(cin >> c and c != '.') ++cont;
        if(cont >= 20){
            Clear();
            imprir_murcie2();
            hp -= cont/2;
            cout << "HP: " << hp << endl;
            cout << RED"ψ(｀∇´)ψ  AIXÍ ÉS, DONA'M MÉS" RESET<< endl;
        }
        else {
            cout << RED"(*￣︿￣)  INSUFICIENT, VULL MÉS, MOLT MÉS" RESET<< endl;
            me.health-= cont;
            if(me.health >0) cout<< GREEN "Ànim: " RESET<< RED  <<me.health <<RESET<< endl;
            else {
                cout<< GREEN "Ànim: " RESET<< RED  <<0 <<RESET<< endl;
                    sleep(3);
                    cout << BLUE"██████╗░███████╗██████╗░██████╗░░█████╗░████████╗░█████╗░" << endl;
                    cout <<"██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗" << endl;
                    cout <<"██║░░██║█████╗░░██████╔╝██████╔╝██║░░██║░░░██║░░░███████║" << endl;
                    cout <<"██║░░██║██╔══╝░░██╔══██╗██╔══██╗██║░░██║░░░██║░░░██╔══██║"<< endl;
                    cout <<"██████╔╝███████╗██║░░██║██║░░██║╚█████╔╝░░░██║░░░██║░░██║"<< endl;
                    cout <<"╚═════╝░╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝" RESET<< endl;
                    sleep(1);
            }
        }
        sleep(3);
        Clear();
        if(me.health <0) bendicion(me);
        if(me.health >0 and hp > 0){
            imprir_murcie1();
            sleep(2);
            cout <<BOLDCYAN "░██████╗░██╗░░░██╗██╗███╗░░██╗░█████╗░  ░█████╗░░█████╗░░██████╗░█████╗░  ███████╗████████╗"<< endl;
            cout <<"██╔═══██╗██║░░░██║██║████╗░██║██╔══██╗  ██╔══██╗██╔══██╗██╔════╝██╔══██╗  ██╔════╝╚══██╔══╝"<< endl;
            cout <<"██║██╗██║██║░░░██║██║██╔██╗██║███████║  ██║░░╚═╝██║░░██║╚█████╗░███████║  █████╗░░░░░██║░░░"<< endl;
            cout <<"╚██████╔╝██║░░░██║██║██║╚████║██╔══██║  ██║░░██╗██║░░██║░╚═══██╗██╔══██║  ██╔══╝░░░░░██║░░░"<< endl;
            cout <<"░╚═██╔═╝░╚██████╔╝██║██║░╚███║██║░░██║  ╚█████╔╝╚█████╔╝██████╔╝██║░░██║  ███████╗░░░██║░░░"<< endl;
            cout <<"░░░╚═╝░░░░╚═════╝░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝  ░╚════╝░░╚════╝░╚═════╝░╚═╝░░╚═╝  ╚══════╝░░░╚═╝░░░"<< endl;

            cout <<"███████╗░█████╗░  ███╗░░░███╗███████╗░██████╗  ██████╗░░█████╗░██████╗░░█████╗░"<< endl;
            cout <<"██╔════╝██╔══██╗  ████╗░████║██╔════╝██╔════╝  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗"<< endl;
            cout <<"█████╗░░███████║  ██╔████╔██║█████╗░░╚█████╗░  ██████╔╝██║░░██║██████╔╝╚═╝███╔╝"<< endl;
            cout <<"██╔══╝░░██╔══██║  ██║╚██╔╝██║██╔══╝░░░╚═══██╗  ██╔═══╝░██║░░██║██╔══██╗░░░╚══╝░"<< endl;
            cout <<"██║░░░░░██║░░██║  ██║░╚═╝░██║███████╗██████╔╝  ██║░░░░░╚█████╔╝██║░░██║░░░██╗░░"<< endl;
            cout <<"╚═╝░░░░░╚═╝░░╚═╝  ╚═╝░░░░░╚═╝╚══════╝╚═════╝░  ╚═╝░░░░░░╚════╝░╚═╝░░╚═╝░░░╚═╝░░"<< endl;
            cout << BOLDCYAN"RESPOSTES:has de posar" << RED <<'.' << RESET<< BOLDCYAN "al final de la frase." RESET<< endl;
            cont=0;
            while(cin >> c and c != '.') ++cont;
            if(cont >= 10){
                Clear();
                imprir_murcie2();
                hp -= cont/2;
                cout << "HP: " << hp << endl;
                cout << RED"ψ(｀∇´)ψ  AIXÍ ÉS!! DONA'M MÉS!!" RESET<< endl;

            }
            else {
                cout << RED"（｀へ´）  INSUFICIENT, VULL MÉS MOLT MÉS" RESET<< endl;
                me.health-= cont;
                if(me.health >0) cout<< GREEN "Ànim: " RESET<< RED  <<me.health <<RESET<< endl;
                else {
                    cout<< GREEN "Ànim: " RESET<< RED  <<0 <<RESET<< endl;
                    sleep(3);
                    cout << BLUE"██████╗░███████╗██████╗░██████╗░░█████╗░████████╗░█████╗░" << endl;
                    cout <<"██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗" << endl;
                    cout <<"██║░░██║█████╗░░██████╔╝██████╔╝██║░░██║░░░██║░░░███████║" << endl;
                    cout <<"██║░░██║██╔══╝░░██╔══██╗██╔══██╗██║░░██║░░░██║░░░██╔══██║"<< endl;
                    cout <<"██████╔╝███████╗██║░░██║██║░░██║╚█████╔╝░░░██║░░░██║░░██║"<< endl;
                    cout <<"╚═════╝░╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░╚═╝░░╚═╝" RESET<< endl;
                    sleep(1);
                    }
            }
        }
        if(me.health <=0 ) bendicion(me);

        if(me.health >0 and hp > 0){
            sleep(3);
            Clear();
            imprir_murcie1();
            cout << BOLDCYAN "██████╗░███████╗██████╗░  ░██████╗░██╗░░░██╗███████╗  ██████╗░███████╗███╗░░██╗░██████╗███████╗░██████╗" << endl;
            cout << "██╔══██╗██╔════╝██╔══██╗  ██╔═══██╗██║░░░██║██╔════╝  ██╔══██╗██╔════╝████╗░██║██╔════╝██╔════╝██╔════╝" << endl;
            cout << "██████╔╝█████╗░░██████╔╝  ██║██╗██║██║░░░██║█████╗░░  ██████╔╝█████╗░░██╔██╗██║╚█████╗░█████╗░░╚█████╗░" << endl;
            cout << "██╔═══╝░██╔══╝░░██╔══██╗  ╚██████╔╝██║░░░██║██╔══╝░░  ██╔═══╝░██╔══╝░░██║╚████║░╚═══██╗██╔══╝░░░╚═══██╗" << endl;
            cout << "██║░░░░░███████╗██║░░██║  ░╚═██╔═╝░╚██████╔╝███████╗  ██║░░░░░███████╗██║░╚███║██████╔╝███████╗██████╔╝" << endl;
            cout << "╚═╝░░░░░╚══════╝╚═╝░░╚═╝  ░░░╚═╝░░░░╚═════╝░╚══════╝  ╚═╝░░░░░╚══════╝╚═╝░░╚══╝╚═════╝░╚══════╝╚═════╝░" << endl;

            cout << "░██████╗░██╗░░░██╗███████╗  ███╗░░██╗██╗███╗░░██╗░██████╗░██╗░░░██╗" << endl;
            cout << "██╔═══██╗██║░░░██║██╔════╝  ████╗░██║██║████╗░██║██╔════╝░██║░░░██║" << endl;
            cout << "██║██╗██║██║░░░██║█████╗░░  ██╔██╗██║██║██╔██╗██║██║░░██╗░██║░░░██║" << endl;
            cout << "╚██████╔╝██║░░░██║██╔══╝░░  ██║╚████║██║██║╚████║██║░░╚██╗██║░░░██║" << endl;
            cout << "░╚═██╔═╝░╚██████╔╝███████╗  ██║░╚███║██║██║░╚███║╚██████╔╝╚██████╔╝" << endl;
            cout << "░░░╚═╝░░░░╚═════╝░╚══════╝  ╚═╝░░╚══╝╚═╝╚═╝░░╚══╝░╚═════╝░░╚═════╝░" << endl;

            cout << "████████╗██╗███████╗███╗░░██╗████████╗███████╗███╗░░██╗░█████╗░" << endl;
            cout << "╚══██╔══╝╚█║██╔════╝████╗░██║╚══██╔══╝██╔════╝████╗░██║██╔══██╗" << endl;
            cout << "░░░██║░░░░╚╝█████╗░░██╔██╗██║░░░██║░░░█████╗░░██╔██╗██║╚═╝███╔╝" << endl;
            cout << "░░░██║░░░░░░██╔══╝░░██║╚████║░░░██║░░░██╔══╝░░██║╚████║░░░╚══╝░" << endl;
            cout << "░░░██║░░░░░░███████╗██║░╚███║░░░██║░░░███████╗██║░╚███║░░░██╗░░" << endl;
            cout << "░░░╚═╝░░░░░░╚══════╝╚═╝░░╚══╝░░░╚═╝░░░╚══════╝╚═╝░░╚══╝░░░╚═╝░░" << endl;
            cout << BOLDCYAN"RESPOSTES:has de posar" << RED <<'.' << RESET<< BOLDCYAN "al final de la frase." RESET<< endl;
            cont=0;
            while(cin >> c and c != '.') ++cont;
            if(cont >= 20){
                cout << RED"ψ(｀∇´)ψ  AIXÍ ÉS!! DONA'M MÉS!!" RESET<< endl;
                hp -= cont*2;
                cout<< GREEN "Ànim: " RESET<< RED <<me.health <<RESET<< endl;
            }
        }
        }
        else if (rep == 'N' or rep == 'n') cout << WHITE "ACCEPTES?" RESET << RED " S" RESET << "/" << BLUE "N" RESET << endl;
        if (rep == 'S' or rep == 's') break;
    }
    Clear();
    cout << YELLOW "█░█ █ █▀▀ ▀█▀ █▀█ █▀█ █ ▄▀█" << endl;
    cout << YELLOW "▀▄▀ █ █▄▄ ░█░ █▄█ █▀▄ █ █▀█" RESET<< endl;
    sleep(3);
    Clear();
    imprir_murcie1();
    cout << YELLOW "El sentiment negatiu és un sobrepès, si portes una dia no passa res, però si portes un mes..." RESET << endl;
    sleep(4);
    cout << YELLOW "Dona'm la teva motxilla. " RESET<< endl;
    cout << RED "          ─────▄█▀█▄──▄███▄────❤" << endl;
    cout <<"          ───▐█░██████████▌────"<< endl;
    cout <<"          ─────██▒█████████─────"<< endl;
    cout <<"          ──────▀████████▀──────"<< endl;
    cout <<"          ─────────▀██▀" << endl;
    sleep(2);
    cout <<RED"(っ◕‿◕)っ" RESET <<  RED" una abraçada " RESET<< endl;
    sleep(1);
    cout << GREEN"Ara et sents millor? Jo també." << endl;

}


void boss4(Player& p) {
  int iterador = 0;
  Clear();

  cout<<"                 ..."<<endl;
  cout<<"                ;::::;"<<endl;
  cout<<"              ;::::; :;"<<endl;
  cout<<"            ;:::::'   :;"<<endl;
  cout<<"           ;:::::;     ;."<<endl;
  cout<<"          ,:::::'       ;           OOO"<<endl;
  cout<<"          ::::::;       ;          OOOOO"<<endl;
  cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
  cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
  cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
  cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
  cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
  cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
  cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
  cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
  cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
  cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
  cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
  cout<<"      :::::::::::::::::;':;::#                O"<<endl;
  cout<<"       :::::::::::::;' /  / :#"<<endl;
  cout<<"       :::::::::::;'  /  /   #"<<endl;
  cout << endl << endl;
  cout << "Oh, quina grata sorpresa trobarte aquí..." << endl;
  delay_ms(1000);
  cout << "Anem a";
  cout << BLUE " jugar" RESET;
  cout <<" a alguna cosa" << endl;
  delay_ms(1000);
  cout << "Algo simple...." << endl;
  delay_ms(1000);
  cout << "L'únic que has de fer és";
  cout <<RED " repetir el que et diga" RESET << endl;
  delay_ms(1000);
  cout << BOLDGREEN "MOLT IMPORTANT" RESET << endl;
  delay_ms(1000);
  cout << "Tinc que demanarte que escriguis un";
  cout << RED " . " RESET;
  cout << "quan terminis l'oració per fer-me saber que ja has acabat" << endl;
  delay_ms(1000);
  cout << "Simple veritat?" << endl;
  string c; cin >> c;
  cout << "Comencem-hi doncs" << endl;
  delay_ms(2000);


  Clear();

  cout<<"                 ..."<<endl;
  cout<<"                ;::::;"<<endl;
  cout<<"              ;::::; :;"<<endl;
  cout<<"            ;:::::'   :;"<<endl;
  cout<<"           ;:::::;     ;."<<endl;
  cout<<"          ,:::::'       ;           OOO"<<endl;
  cout<<"          ::::::;       ;          OOOOO"<<endl;
  cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
  cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
  cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
  cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
  cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
  cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
  cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
  cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
  cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
  cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
  cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
  cout<<"      :::::::::::::::::;':;::#                O"<<endl;
  cout<<"       :::::::::::::;' /  / :#"<<endl;
  cout<<"       :::::::::::;'  /  /   #"<<endl;

cout << endl << endl;






cout << "░██████╗░█████╗░░█████╗░  ░█████╗░░█████╗░██████╗░░█████╗░░█████╗░  ██████╗░███████╗" << endl;
cout << "██╔════╝██╔══██╗██╔══██╗  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔══██╗██╔════╝" << endl;
cout << "╚█████╗░██║░░██║██║░░╚═╝  ██║░░╚═╝███████║██████╔╝███████║██║░░╚═╝  ██║░░██║█████╗░░" << endl;
cout << "░╚═══██╗██║░░██║██║░░██╗  ██║░░██╗██╔══██║██╔═══╝░██╔══██║██║░░██╗  ██║░░██║██╔══╝░░" << endl;
cout << "██████╔╝╚█████╔╝╚█████╔╝  ╚█████╔╝██║░░██║██║░░░░░██║░░██║╚█████╔╝  ██████╔╝███████╗" << endl;
cout << "╚═════╝░░╚════╝░░╚════╝░  ░╚════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝░╚════██  ╚═════╝░╚══════╝" << endl;
cout << "████████╗░█████╗░████████╗  ░█████╗░██╗░░░░░██╗░░░░░░█████╗░  ░██████╗░██╗░░░██╗███████╗" << endl;
cout << "╚══██╔══╝██╔══██╗╚══██╔══╝  ██╔══██╗██║░░░░░██║░░░░░██╔══██╗  ██╔═══██╗██║░░░██║██╔════╝" << endl;
cout << "░░░██║░░░██║░░██║░░░██║░░░  ███████║██║░░░░░██║░░░░░██║░░██║  ██║██╗██║██║░░░██║█████╗░░" << endl;
cout << "░░░██║░░░██║░░██║░░░██║░░░  ██╔══██║██║░░░░░██║░░░░░██║░░██║  ╚██████╔╝██║░░░██║██╔══╝░░" << endl;
cout << "░░░██║░░░╚█████╔╝░░░██║░░░  ██║░░██║███████╗███████╗╚█████╔╝  ░╚═██╔═╝░╚██████╔╝███████╗" << endl;
cout << "░░░╚═╝░░░░╚════╝░░░░╚═╝░░░  ╚═╝░░╚═╝╚══════╝╚══════╝░╚════╝░  ░░░╚═╝░░░░╚═════╝░╚══════╝" << endl;
cout << "███████╗███╗░░░███╗  ██████╗░██████╗░░█████╗░██████╗░░█████╗░░██████╗██╗    ░░░" << endl;
cout << "██╔════╝████╗░████║  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝██║    ░░░" << endl;
cout << "█████╗░░██╔████╔██║  ██████╔╝██████╔╝██║░░██║██████╔╝██║░░██║╚█████╗░██║    ░░░" << endl;
cout << "██╔══╝░░██║╚██╔╝██║  ██╔═══╝░██╔══██╗██║░░██║██╔═══╝░██║░░██║░╚═══██╗██║    ░░░" << endl;
cout << "███████╗██║░╚═╝░██║  ██║░░░░░██║░░██║╚█████╔╝██║░░░░░╚█████╔╝██████╔╝██║    ██╗" << endl;
cout << "╚══════╝╚═╝░░░░░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝░╚════╝░╚═╝░░░░░░╚════╝░╚═════╝░╚═╝    ╚═╝" << endl;

 cout << endl << endl;
  vector<string> f1 = {"SOC", "CAPAÇ", "DE", "TOT", "ALLO", "QUE", "EM", "PROPOSI"};

  vector<string> e1;

  lectura_entrada(e1);

  if(compare_s(f1, e1) == true){
    cout << CYAN"(￣▽￣)" RESET;
    cout << " Bé, bé, sembla que ho has entés" << endl;
    delay_ms(2000);
    cout << "Pasem-hi al següent" << endl;
    delay_ms(2000);
  }
  else{
    cout << "Torna a intentar-lo" << endl;
    while(compare_s(f1, e1) == false){
      lectura_entrada(e1);
    }
    cout << CYAN"(￣▽￣)" RESET;
    cout << " Bé, bé, sembla que ho has entés" << endl;
    delay_ms(2000);
    cout << "Pasem-hi al següent" << endl;
  }
  Clear();

  cout<<"                 ..."<<endl;
  cout<<"                ;::::;"<<endl;
  cout<<"              ;::::; :;"<<endl;
  cout<<"            ;:::::'   :;"<<endl;
  cout<<"           ;:::::;     ;."<<endl;
  cout<<"          ,:::::'       ;           OOO"<<endl;
  cout<<"          ::::::;       ;          OOOOO"<<endl;
  cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
  cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
  cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
  cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
  cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
  cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
  cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
  cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
  cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
  cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
  cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
  cout<<"      :::::::::::::::::;':;::#                O"<<endl;
  cout<<"       :::::::::::::;' /  / :#"<<endl;
  cout<<"       :::::::::::;'  /  /   #"<<endl;

  vector<string> f2 = {"NO", "EM", "CAL", "NINGU"};

  cout << endl << endl;
  cout << "███╗░░██╗░█████╗░  ███████╗███╗░░░███╗  ░█████╗░░█████╗░██╗░░░░░" << endl;
  cout << "████╗░██║██╔══██╗  ██╔════╝████╗░████║  ██╔══██╗██╔══██╗██║░░░░░" << endl;
  cout << "██╔██╗██║██║░░██║  █████╗░░██╔████╔██║  ██║░░╚═╝███████║██║░░░░░" << endl;
  cout << "██║╚████║██║░░██║  ██╔══╝░░██║╚██╔╝██║  ██║░░██╗██╔══██║██║░░░░░" << endl;
  cout << "██║░╚███║╚█████╔╝  ███████╗██║░╚═╝░██║  ╚█████╔╝██║░░██║███████╗" << endl;
  cout << "╚═╝░░╚══╝░╚════╝░  ╚══════╝╚═╝░░░░░╚═╝  ░╚════╝░╚═╝░░╚═╝╚══════╝" << endl;
  cout << "███╗░░██╗██╗███╗░░██╗░██████╗░██╗░░░██╗  ░░░" << endl;
  cout << "████╗░██║██║████╗░██║██╔════╝░██║░░░██║  ░░░" << endl;
  cout << "██╔██╗██║██║██╔██╗██║██║░░██╗░██║░░░██║  ░░░" << endl;
  cout << "██║╚████║██║██║╚████║██║░░╚██╗██║░░░██║  ░░░" << endl;
  cout << "██║░╚███║██║██║░╚███║╚██████╔╝╚██████╔╝  ██╗" << endl;
  cout << "╚═╝░░╚══╝╚═╝╚═╝░░╚══╝░╚═════╝░░╚═════╝░  ╚═╝" << endl;
  vector<string> e2;
  cout << endl << endl;
  lectura_entrada(e2);
  if(compare_s(f2, e2)){
    cout << MAGENTA"(ˋ ▽ ˊ) " RESET;
    delay_ms(500);
    cout << RED " HAHAHA " RESET;
    delay_ms(500);
    cout << " continua" << endl;
    delay_ms(2000);
    p.health -= 5;
    if(p.health <= 0){
      Clear();
      bendicion(p);
      delay_ms(3000);
      Clear();
      cout<<"                 ..."<<endl;
      cout<<"                ;::::;"<<endl;
      cout<<"              ;::::; :;"<<endl;
      cout<<"            ;:::::'   :;"<<endl;
      cout<<"           ;:::::;     ;."<<endl;
      cout<<"          ,:::::'       ;           OOO"<<endl;
      cout<<"          ::::::;       ;          OOOOO"<<endl;
      cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
      cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
      cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
      cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
      cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
      cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
      cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
      cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
      cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
      cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
      cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
      cout<<"      :::::::::::::::::;':;::#                O"<<endl;
      cout<<"       :::::::::::::;' /  / :#"<<endl;
      cout<<"       :::::::::::;'  /  /   #"<<endl;
      cout << endl << endl;
    }
  }
  else{
    cout << "Dona-li altre intent" << endl;
    while(!compare_s(f2, e2) and iterador < 3)
    {
      lectura_entrada(e2);
      if(compare_s(f2, e2)){
        cout << MAGENTA"(ˋ ▽ ˊ)" RESET;
        delay_ms(500);
        cout << RED " HAHAHA" RESET;
        delay_ms(500);
        cout << "continua" << endl;
        delay_ms(2000);
        p.health -= 5;
        if(p.health <= 0){
          Clear();
          bendicion(p);
          delay_ms(4000);
          Clear();
          cout<<"                 ..."<<endl;
          cout<<"                ;::::;"<<endl;
          cout<<"              ;::::; :;"<<endl;
          cout<<"            ;:::::'   :;"<<endl;
          cout<<"           ;:::::;     ;."<<endl;
          cout<<"          ,:::::'       ;           OOO"<<endl;
          cout<<"          ::::::;       ;          OOOOO"<<endl;
          cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
          cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
          cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
          cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
          cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
          cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
          cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
          cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
          cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
          cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
          cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
          cout<<"      :::::::::::::::::;':;::#                O"<<endl;
          cout<<"       :::::::::::::;' /  / :#"<<endl;
          cout<<"       :::::::::::;'  /  /   #"<<endl;
          cout << endl << endl;
        }
      }
      else {
        if(iterador == 0){
          cout << "Llegeix bé " << p.name << endl;
        }
        else if(iterador == 1){
          cout << BLUE "Estàs segur de que coneixes les regles?" RESET;
          cout << " Dona-li altre intent" << endl;
        }
        else if(iterador == 2){
          cout << RED "A veure si amb la següent entres en raó..." RESET << endl;
          delay_ms(2000);
        }
      }
      iterador ++;
    }
  }
  Clear();

  cout<<"                 ..."<<endl;
  cout<<"                ;::::;"<<endl;
  cout<<"              ;::::; :;"<<endl;
  cout<<"            ;:::::'   :;"<<endl;
  cout<<"           ;:::::;     ;."<<endl;
  cout<<"          ,:::::'       ;           OOO"<<endl;
  cout<<"          ::::::;       ;          OOOOO"<<endl;
  cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
  cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
  cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
  cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
  cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
  cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
  cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
  cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
  cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
  cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
  cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
  cout<<"      :::::::::::::::::;':;::#                O"<<endl;
  cout<<"       :::::::::::::;' /  / :#"<<endl;
  cout<<"       :::::::::::;'  /  /   #"<<endl;

  cout << endl << endl;
cout << "░██████╗░█████╗░░█████╗░  ███████╗██╗░░░░░  ░██████╗░██╗░░░██╗███████╗  ███████╗██╗░░░░░░██████╗" << endl;
cout << "██╔════╝██╔══██╗██╔══██╗  ██╔════╝██║░░░░░  ██╔═══██╗██║░░░██║██╔════╝  ██╔════╝██║░░░░░██╔════╝" << endl;
cout << "╚█████╗░██║░░██║██║░░╚═╝  █████╗░░██║░░░░░  ██║██╗██║██║░░░██║█████╗░░  █████╗░░██║░░░░░╚█████╗░" << endl;
cout << "░╚═══██╗██║░░██║██║░░██╗  ██╔══╝░░██║░░░░░  ╚██████╔╝██║░░░██║██╔══╝░░  ██╔══╝░░██║░░░░░░╚═══██╗" << endl;
cout << "██████╔╝╚█████╔╝╚█████╔╝  ███████╗███████╗  ░╚═██╔═╝░╚██████╔╝███████╗  ███████╗███████╗██████╔╝" << endl;
cout << "╚═════╝░░╚════╝░░╚════╝░  ╚══════╝╚══════╝  ░░░╚═╝░░░░╚═════╝░╚══════╝  ╚══════╝╚══════╝╚═════╝░" << endl;
cout << "░█████╗░██╗░░░░░████████╗██████╗░███████╗░██████╗  ██████╗░███████╗███╗░░██╗░██████╗███████╗███╗░░██╗" << endl;
cout << "██╔══██╗██║░░░░░╚══██╔══╝██╔══██╗██╔════╝██╔════╝  ██╔══██╗██╔════╝████╗░██║██╔════╝██╔════╝████╗░██║" << endl;
cout << "███████║██║░░░░░░░░██║░░░██████╔╝█████╗░░╚█████╗░  ██████╔╝█████╗░░██╔██╗██║╚█████╗░█████╗░░██╔██╗██║" << endl;
cout << "██╔══██║██║░░░░░░░░██║░░░██╔══██╗██╔══╝░░░╚═══██╗  ██╔═══╝░██╔══╝░░██║╚████║░╚═══██╗██╔══╝░░██║╚████║" << endl;
cout << "██║░░██║███████╗░░░██║░░░██║░░██║███████╗██████╔╝  ██║░░░░░███████╗██║░╚███║██████╔╝███████╗██║░╚███║" << endl;
cout << "╚═╝░░╚═╝╚══════╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═════╝░  ╚═╝░░░░░╚══════╝╚═╝░░╚══╝╚═════╝░╚══════╝╚═╝░░╚══╝" << endl;
cout << "██████╗░███████╗  ███╗░░░███╗██╗   ░░░" << endl;
cout << "██╔══██╗██╔════╝  ████╗░████║██║   ░░░" << endl;
cout << "██║░░██║█████╗░░  ██╔████╔██║██║   ░░░" << endl;
cout << "██║░░██║██╔══╝░░  ██║╚██╔╝██║██║   ░░░" << endl;
cout << "██████╔╝███████╗  ██║░╚═╝░██║██║   ██╗" << endl;
cout << "╚═════╝░╚══════╝  ╚═╝░░░░░╚═╝╚═╝   ╚═╝" << endl;


vector<string> f3 = {"SOC", "EL", "QUE", "ELS", "ALTRES", "PENSEN", "DE", "MI"};
vector<string> e3;
cout << endl;
lectura_entrada(e3);

  if(compare_s(f3, e3)){
    cout << MAGENTA"ψ(‵ ▽ ′)ψ " RESET;
    delay_ms(500);
    cout << RED " MUAHAHAHAHA " RESET;
    delay_ms(500);
    cout << "M'encanta aquesta sensació, continua " << endl;
    delay_ms(1000);
    cout << RED " MUAHAHAHAHA" RESET;
    delay_ms(2000);
    p.health -= 10;
    if(p.health <= 0){
      Clear();
      bendicion(p);
      delay_ms(4000);
      Clear();
      cout<<"                 ..."<<endl;
      cout<<"                ;::::;"<<endl;
      cout<<"              ;::::; :;"<<endl;
      cout<<"            ;:::::'   :;"<<endl;
      cout<<"           ;:::::;     ;."<<endl;
      cout<<"          ,:::::'       ;           OOO"<<endl;
      cout<<"          ::::::;       ;          OOOOO"<<endl;
      cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
      cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
      cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
      cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
      cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
      cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
      cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
      cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
      cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
      cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
      cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
      cout<<"      :::::::::::::::::;':;::#                O"<<endl;
      cout<<"       :::::::::::::;' /  / :#"<<endl;
      cout<<"       :::::::::::;'  /  /   #"<<endl;
      cout << endl << endl;
    }
  }
  else{
    cout << "Dona-li altre intent" << endl;
    while(!compare_s(f3, e3) and iterador < 6)
    {
      lectura_entrada(e3);
      if(compare_s(f3, e3)){
        cout << MAGENTA"ψ(‵ ▽ ′)ψ " RESET;
        delay_ms(500);
        cout << RED " MUAHAHAHAHA " RESET;
        delay_ms(500);
        cout << "M'encanta aquesta sensació, continua" << endl;
        delay_ms(1000);
        cout << RED " MUAHAHAHAHA" RESET;
        delay_ms(2000);
        p.health -= 10;
        cout<<"                 ..."<<endl;
        cout<<"                ;::::;"<<endl;
        cout<<"              ;::::; :;"<<endl;
        cout<<"            ;:::::'   :;"<<endl;
        cout<<"           ;:::::;     ;."<<endl;
        cout<<"          ,:::::'       ;           OOO"<<endl;
        cout<<"          ::::::;       ;          OOOOO"<<endl;
        cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
        cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
        cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
        cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
        cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
        cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
        cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
        cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
        cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
        cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
        cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
        cout<<"      :::::::::::::::::;':;::#                O"<<endl;
        cout<<"       :::::::::::::;' /  / :#"<<endl;
        cout<<"       :::::::::::;'  /  /   #"<<endl;
        cout << endl << endl;
      }
      else {
        if(iterador < 3){
          if(iterador == 0){
            cout << "Llegeix bé " << p.name << endl;
          }
          else if(iterador == 1){
            cout << BLUE "Estàs segur de que coneixes les regles?" RESET;
            cout << " Dona-li altre intent" << endl;
          }
          else if(iterador == 2){
            cout << RED "No m'agrada la teva actitud" RESET << endl;
          }
        }
        else {
          if(iterador == 3){
            cout << "Mai sortiràs d'aquí si continues per aquest camí" << endl;
          }
          else if(iterador == 4){
            cout << GREEN "No et facis el graciós" RESET << endl;
          }
          else if(iterador == 5){
            cout << RED "(#‵ ′)凸   Ja m'estàs enfadant!" RESET << endl;
            delay_ms(2000);
          }
        }
      }
      iterador ++;
    }
  }

Clear();

cout<<"                 ..."<<endl;
cout<<"                ;::::;"<<endl;
cout<<"              ;::::; :;"<<endl;
cout<<"            ;:::::'   :;"<<endl;
cout<<"           ;:::::;     ;."<<endl;
cout<<"          ,:::::'       ;           OOO"<<endl;
cout<<"          ::::::;       ;          OOOOO"<<endl;
cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
cout<<"      :::::::::::::::::;':;::#                O"<<endl;
cout<<"       :::::::::::::;' /  / :#"<<endl;
cout<<"       :::::::::::;'  /  /   #"<<endl;

cout << endl << endl;

cout << BOLDYELLOW "█░█ █ █▄░█ █▀▀ ▄▀█ ░ " RESET << endl;
cout << BOLDYELLOW "▀▄▀ █ █░▀█ █▄█ █▀█ █ " RESET << endl;
cout << endl;

cout << BOLDYELLOW "█▀▄ █ █▀▀ █░█ █▀▀ █▀ ▄▄ █▀▄▀█ █▀▀   █▀▀ █░░   █▀█ █░█ █▀▀   █░█ █░█ █░░ █░░   █▀ █▀▀ █▄░█ ▀█▀ █ █▀█" RESET << endl;
cout << BOLDYELLOW "█▄▀ █ █▄█ █▄█ ██▄ ▄█ ░░ █░▀░█ ██▄   ██▄ █▄▄   ▀▀█ █▄█ ██▄   ▀▄▀ █▄█ █▄▄ █▄▄   ▄█ ██▄ █░▀█ ░█░ █ █▀▄" RESET << endl;

cout << endl;
cout << "░██████╗░█████╗░░█████╗░  ██╗░░░██╗███╗░░██╗  ██╗███╗░░██╗██╗░░░██╗████████╗██╗██╗░░░░░   ░░░" << endl;
cout << "██╔════╝██╔══██╗██╔══██╗  ██║░░░██║████╗░██║  ██║████╗░██║██║░░░██║╚══██╔══╝██║██║░░░░░   ░░░" << endl;
cout << "╚█████╗░██║░░██║██║░░╚═╝  ██║░░░██║██╔██╗██║  ██║██╔██╗██║██║░░░██║░░░██║░░░██║██║░░░░░   ░░░" << endl;
cout << "░╚═══██╗██║░░██║██║░░██╗  ██║░░░██║██║╚████║  ██║██║╚████║██║░░░██║░░░██║░░░██║██║░░░░░   ░░░" << endl;
cout << "██████╔╝╚█████╔╝╚█████╔╝  ╚██████╔╝██║░╚███║  ██║██║░╚███║╚██████╔╝░░░██║░░░██║███████╗   ██╗" << endl;
cout << "╚═════╝░░╚════╝░░╚════╝░  ░╚═════╝░╚═╝░░╚══╝  ╚═╝╚═╝░░╚══╝░╚═════╝░░░░╚═╝░░░╚═╝╚══════╝   ╚═╝" << endl;

vector<string> f4 = {"SOC", "UN", "INUTIL"};
vector<string> e4;
cout << endl;
lectura_entrada(e4);

  if(compare_s(f4, e4)){
    cout << RED "ψ(‵ ▽ ′)ψ " RESET;
    delay_ms(500);
    cout << RED " MUAHAHAHAHA " RESET;
    delay_ms(1000);
    cout << endl;
    cout << endl;
    cout << RED "█░░ ▄▀█   ▀█▀ █▀▀ █░█ ▄▀█   ▄▀█ █░░ █▀▄▀█ ▄▀█   █▀▀ █▀▄▀█   █▀█ █▀▀ █▀█ ▀█▀ ▄▀█ █▄░█ █▄█" RESET << endl;
    cout << RED "█▄▄ █▀█   ░█░ ██▄ ▀▄▀ █▀█   █▀█ █▄▄ █░▀░█ █▀█   ██▄ █░▀░█   █▀▀ ██▄ █▀▄ ░█░ █▀█ █░▀█ ░█ " RESET<< endl;

    delay_ms(2000);
    p.health -= 100;
    if(p.health <= 0){
      Clear();
      bendicion(p);
      delay_ms(3000);
      Clear();
    }
  }
  else{
    cout << "Vinga, fes-me cas" << endl;
    while(!compare_s(f4, e4) and iterador < 7)
    {
      lectura_entrada(e4);
      if(compare_s(f4, e4)){
        cout << RED "ψ(‵ ▽ ′)ψ " RESET;
        delay_ms(500);
        cout << RED " MUAHAHAHAHA " RESET;
        delay_ms(1000);
        cout << endl;
        cout << endl;
        cout << RED "█░░ ▄▀█   ▀█▀ █▀▀ █░█ ▄▀█   ▄▀█ █░░ █▀▄▀█ ▄▀█   █▀▀ █▀▄▀█   █▀█ █▀▀ █▀█ ▀█▀ ▄▀█ █▄░█ █▄█" RESET << endl;
        cout << RED "█▄▄ █▀█   ░█░ ██▄ ▀▄▀ █▀█   █▀█ █▄▄ █░▀░█ █▀█   ██▄ █░▀░█   █▀▀ ██▄ █▀▄ ░█░ █▀█ █░▀█ ░█ " RESET<< endl;
        delay_ms(2000);
        p.health -= 100;
        if(p.health <= 0){
          Clear();
          bendicion(p);
          delay_ms(3000);
          Clear();
        }
      }
      else {
          if(iterador == 0){
            cout << "Llegeix bé " << p.name << endl;
          }
          else if(iterador == 1){
            cout << BLUE "Estàs segur de que coneixes les regles?" RESET;
            cout << " Dona-li altre intent" << endl;
          }
          else if(iterador == 2){
            cout << RED "A veure si amb la següent entres en raó..." RESET << endl;
          }
          if(iterador == 3){
            cout << "Mai sortiràs d'aquí si continues per aquest camí" << endl;
          }
          else if(iterador == 4){
            cout << GREEN "No et facis el graciós" RESET << endl;
          }
          else if(iterador == 5){
            cout << BOLDRED "(#‵ ′)凸   Ja m'estàs enfadant!" RESET << endl;
            delay_ms(2000);
          }
          else if(iterador == 6){
            Clear();

            cout<<"                 ..."<<endl;
            cout<<"                ;::::;"<<endl;
            cout<<"              ;::::; :;"<<endl;
            cout<<"            ;:::::'   :;"<<endl;
            cout<<"           ;:::::;     ;."<<endl;
            cout<<"          ,:::::'       ;           OOO"<<endl;
            cout<<"          ::::::;       ;          OOOOO"<<endl;
            cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
            cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
            cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
            cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
            cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
            cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
            cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
            cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
            cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
            cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
            cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
            cout<<"      :::::::::::::::::;':;::#                O"<<endl;
            cout<<"       :::::::::::::;' /  / :#"<<endl;
            cout<<"       :::::::::::;'  /  /   #"<<endl;

            cout << endl << endl;

            cout << "█▄░█ █▀█ █▄░█ █▀█ █▄░█ █▀█ █▄░█ █▀█" << endl;
            cout << "█░▀█ █▄█ █░▀█ █▄█ █░▀█ █▄█ █░▀█ █▄█" << endl;

            delay_ms(2000);

            Clear();

            cout<<"                 ..."<<endl;
            cout<<"                ;::::;"<<endl;
            cout<<"              ;::::; :;"<<endl;
            cout<<"            ;:::::'   :;"<<endl;
            cout<<"           ;:::::;     ;."<<endl;
            cout<<"          ,:::::'       ;           OOO"<<endl;
            cout<<"          ::::::;       ;          OOOOO"<<endl;
            cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
            cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
            cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
            cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
            cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
            cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
            cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
            cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
            cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
            cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
            cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
            cout<<"      :::::::::::::::::;':;::#                O"<<endl;
            cout<<"       :::::::::::::;' /  / :#"<<endl;
            cout<<"       :::::::::::;'  /  /   #"<<endl;

            cout << endl << endl;

            cout << "█▀▀ ▀█▀ █▀   ▀█▀ █░█   █▀█ █░█ █   ▄▀█ █░█ █░█ █▀█ █ ▄▀█   █▀▄ █▀▀   █▀█ █▀▀ █▀█ █▀▄ █▀█ █▀▀ ░   █▄░█ █▀█   ░░█ █▀█" << endl;
            cout << "██▄ ░█░ ▄█   ░█░ █▄█   ▀▀█ █▄█ █   █▀█ █▀█ █▄█ █▀▄ █ █▀█   █▄▀ ██▄   █▀▀ ██▄ █▀▄ █▄▀ █▀▄ ██▄ █   █░▀█ █▄█   █▄█ █▄█" << endl;

            delay_ms(2000);

            Clear();

            cout<<"                 ..."<<endl;
            cout<<"                ;::::;"<<endl;
            cout<<"              ;::::; :;"<<endl;
            cout<<"            ;:::::'   :;"<<endl;
            cout<<"           ;:::::;     ;."<<endl;
            cout<<"          ,:::::'       ;           OOO"<<endl;
            cout<<"          ::::::;       ;          OOOOO"<<endl;
            cout<<"          ;:::::;       ;         OOOOOOOO"<<endl;
            cout<<"         ,;::::::;     ;'         / OOOOOOO"<<endl;
            cout<<"        ;:::::::::. ,,,;.        /  / DOOOOOO"<<endl;
            cout<<"     .';:::::::::::::::::;,     /  /     DOOOO"<<endl;
            cout<<"    ,::::::;::::::;;;;::::;,   /  /        DOOO"<<endl;
            cout<<"     ;::::::'::::::;;;::::: ,#/  /          DOOO"<<endl;
            cout<<"     ::::::::;::::::;;::: ;::#  /            DOOO"<<endl;
            cout<<"     :::::::::;:::::::: ;::::# /              DOO"<<endl;
            cout<<"      ::::::::;:::::: ;::::::#/               DOO"<<endl;
            cout<<"     ::::::::::;; ;:::::::::##                OO"<<endl;
            cout<<"     :::::::::::;::::::::;:::#                OO"<<endl;
            cout<<"      :::::::::::::::::;':;::#                O"<<endl;
            cout<<"       :::::::::::::;' /  / :#"<<endl;
            cout<<"       :::::::::::;'  /  /   #"<<endl;

            cout << endl << endl;

            cout << "▄▀█ ▄▀█ ▄▀█ ▄▀█ ▄▀█ ▄▀█ ▄▀█ ▄▀█ ▄▀█ █░█ █░█ █░█ █ █ █" << endl;
            cout << "█▀█ █▀█ █▀█ █▀█ █▀█ █▀█ █▀█ █▀█ █▀█ █▀█ █▀█ █▀█ ▄ ▄ ▄" << endl;

            e4 = f4;
          }
      }
      iterador ++;
    }
  }
}


int main(){
    Player me;
    me.health = 100;
    Clear();
    cout << "Ostres!" << endl;
    sleep(1);
    cout << "Hola!" << endl;
    sleep(1);
    cout << "Un viatger nou per aquestes terres! Feia anys que no veia un dels de la teva espècie! Quin es el teu nom?" << endl;
    cin >> me.name;
    cout << "Així que "<< me.name <<" ehh... Espero que estiguis preparat per l'aventura que t’espera! El bosc al qual et dirigeixes està regnat per 4 monstres que et posaran a prova, però no et desanimis! Recorda que no estàs sol!" << endl;
    sleep(6);
    Clear();
    sleep(2);
    cout << "(...) Deixes enrere a l’home savi i et dirigeixes cap a l’entrada del bosc..." << endl;
    sleep(2);
    cout<< "(...) Camines uns pocs metres fins que el trobes, és molt exhuberant" << endl;
    sleep(2);
    cout<< "(...) I de cop i volta!" << endl << endl;
    cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
    cout << endl;
    cin >> s;
    Clear();
    //BOSS 1
    boss1(me);

    Clear();
    cout << "(...) Tot i que t’han volgut confondre has tingut les idees clares i continues el teu camí, moltes vegades la resposta està en escoltar-se a un mateix" << endl;
    sleep(4);
    cout<< "(...) Continuant per el bosc, entre la naturalesa divises una cova i al apropar-te veus que està plena de teranyines" << endl;
    sleep(4);
     cout<< "Sembla que per aquí continua el camí!" << endl;
    sleep(3);
    cout<< "(...) T’endinses en la cova" << endl;
    sleep(3);
    cout<< "(...) En la foscor, et xoques amb unes teranyines amb la cara" << endl;
    sleep(3);
    cout<< "(...) Rapidament intentes treurete-les de sobre..." << endl;
    sleep(3);
    cout<< "(...)" << endl << endl;
    cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
    cout << endl;
    cin >> s;
    Clear();
    //BOSS 2
    boss2(me);
    Clear();
    cout << "Quina mala estona he passat... " << endl;
    sleep(2);
    cout<< "Però pensant-ho bé, ha sigut divertit al final!" << endl;
    sleep(3);
    cout<< "(...) Realment qualsevol situació té una part bona, només has d’aprendre a veure-la" << endl;
    sleep(3);
    cout<< "(...) Esta molt fosc en la cova, pero segueixes endavant" << endl;
    sleep(3);
    cout<< "(...) De sobte, sents una veu tenebre a la teva esquena..." << endl;
    sleep(3);
    cout<< "(...) " << endl << endl;
    cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
    cout << endl;
    cin >> s;
    Clear();
    //BOSS 4
    boss4(me); //pablo
    Clear();
    cout<< "NO EM GUANYARIES MAI AMB UNA ESTRATEGIA TAN TRISTAAAA!!" << endl;
    sleep(3);
    cout<< "(...) En mig de la foscor sempre hi haurà algu disposat a posar-te les coses difícils, però no has de fer cas" << endl;
    sleep(3);
    cout<< "(...) Ets molt més del que cualsevol desconegut et pugui dir, espero que ho descobreixis en el teu camí si encara no ho saps" << endl;
    sleep(3);
    cout<< "Es hora de prosseguir amb l'aventura i sortir d’aquesta cova! " << endl;
    sleep(3);
    cout<< "Allà! Ja veig la llum!" << endl;
    sleep(1);
    cout<< "(...) Però un altre monstre custodia la sortida" << endl;
    cout <<BLUE "Prem qualsevol tecla per a continuar ... " RESET<< endl;
    cout << endl;
    cin >> s;
    Clear();
    //BOSS 3
    boss3(me);
    sleep(6);
    Clear();




cout << YELLOW "                    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" RESET<< endl;
cout << CYAN"                    ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░" RESET<< endl;
cout << RED "                    ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░" RESET<< endl;
cout <<MAGENTA"                    ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░" RESET<< endl;
cout <<GREEN"                    ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░" RESET<< endl;
cout <<BOLDYELLOW"                    ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░" RESET<< endl;
cout <<BOLDRED"                    ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░" RESET<< endl;
cout <<BOLDGREEN"                    ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░" RESET<< endl;
cout <<BLUE"                    ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░" RESET<< endl;
cout <<MAGENTA"                    ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░" RESET<< endl;
cout <<BOLDCYAN "                    ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░" RESET<< endl;
cout <<BOLDGREEN"                    ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░" RESET<< endl;
cout <<BOLDMAGENTA"                    ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░" RESET<< endl;
cout <<RED"                    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" RESET<< endl;

cout << endl;
cout << YELLOW "                    █▀▀ █▀█ ▄▀█ █▀▀ █ ▄▀█ █▀   █▀█ █▀▀ █▀█   ░░█ █░█ █▀▀ ▄▀█ █▀█" << endl;
cout << "                    █▄█ █▀▄ █▀█ █▄▄ █ █▀█ ▄█   █▀▀ ██▄ █▀▄   █▄█ █▄█ █▄█ █▀█ █▀▄" RESET<< endl;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Find out what kind of spell the wizard used. 
    // Note to myself: I can reveal the name of the spell with the revealScrollName function only if he casted a generic spell.
    Fireball* fireb = dynamic_cast<Fireball*>(spell);
    Frostbite* frostb = dynamic_cast<Frostbite*>(spell);
    Thunderstorm* thunders = dynamic_cast<Thunderstorm*>(spell);
    Waterbolt* waterb = dynamic_cast<Waterbolt*>(spell);
    if(fireb != nullptr){
        fireb->revealFirepower();
    }else if(frostb != nullptr){
        frostb->revealFrostpower();
    }else if(thunders != nullptr){
        thunders->revealThunderpower();
    }else if(waterb != nullptr){
        waterb->revealWaterpower();
    }else{  // If I arrive here, the wizard casted a generic spell.
        // The task is to find the size of the longest common subsequence
        string sn = spell->revealScrollName();  // Scroll name
        string js = SpellJournal::journal;  // Journal string
        int n = sn.length();
        int m = js.length();
        int c[n+1][m+1];
        int i, j;  // i: iterator for scroll name, j: iterator for journal string
        for(i = 0; i <= n; i++){
            c[i][0] = 0;
        }
        for(j = 0; j <= m; j++){
            c[0][j] = 0;
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                if(sn[i-1] == js[j-1]){
                    c[i][j] = c[i-1][j-1] + 1;
                }else{
                    if(c[i-1][j] >= c[i][j-1]){
                        c[i][j] = c[i-1][j];
                    }else{
                        c[i][j] = c[i][j-1];
                    }
                }
            }
        }
        cout << c[n][m] << endl;

        /* Display table
        for(i = 0; i <= n; i++){
            for(j = 0; j <=m; j++){
                cout << c[i][j] << ' ';
            }
            cout << endl;
        }*/
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;   // This statement does not append the new spell to the journal string, the old spell is overwritten with the new spell.
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
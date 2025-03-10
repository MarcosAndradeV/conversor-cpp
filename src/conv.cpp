#include <cassert>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

#define shift(xs_len, xs) (assert(xs_len > 0), xs_len--, *xs++)

using namespace std;

int main(int argc, char **argv) {
    string program_name = shift(argc, argv);

    if (argc < 1) {
        cerr << "ERROR: Arquivo não provido.\n";
        cout << "INFO: Para usar o programa utilize:\n";
        cout << "    `" << program_name << " <arquivo.txt>" << "`\n";
        return -1;
    }

    string arquivo = shift(argc, argv);
    ifstream Arquivo(arquivo);
    if (!Arquivo.is_open()) {
        cerr << "ERROR: Falha ao abrir o arquivo \"" << arquivo << "\".\n";
        return -1;
    }

    string bits;

    char bit;
    while(Arquivo.get(bit)) {
        if (bit == '0' || bit == '1') {
            bits.push_back(bit);
        }
    }
    Arquivo.close();

    if(bits.size() % 8 != 0) {
        cout << "ERROR: O tamanho do arquivo precisa ser divisivel por 8." << "\n";
        return -1;
    }

    string msg = "";
    for(size_t i = 0; i < bits.size(); i+=8) {
        stack<char> buffer;
        for(size_t j = 0; j < 8; j++) {
            buffer.push(bits[i + j]);
        }
        char letter = 0;
        for(char n = 1; !buffer.empty(); n++) {
            if(buffer.top() == '1')
                letter = (letter | (1 << (n - 1)));
            buffer.pop();
        }
        msg.push_back(letter);
    }

    cout << "mensagem: " << msg << endl;
    return 0;
    }

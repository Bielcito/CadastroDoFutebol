#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using std::cout;
using std::endl;
using std::string;
using std::ofstream;

bool doesFileExist(const char *filename) {
    return GetFileAttributes(filename) != INVALID_FILE_ATTRIBUTES;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Portuguese");
    string path;

    //Verifica o diretório primeiro, caso não exista, ele cria o diretório "postgresql" na pasta Roaming de APPDATA:
    path = getenv("APPDATA");
    path = path + "\\postgresql";

    if(!doesFileExist(path.c_str()))
    {
        if(!CreateDirectory(path.c_str(), NULL))
        {
            cout << "Não conseguiu criar a pasta!" << endl;
            return 0;
        }
    }

    //Verifica se o arquivo existe:
    path = path + "\\pgpass.conf";

    if(!doesFileExist(path.c_str()))
    {
        ofstream file(path.c_str());

        if(!doesFileExist(path.c_str()))
        {
            cout << "Não foi possível criar o arquivo. Favor executar novamente este programa em modo de administrador." << endl;
            cout << "Para executar este programa em modo administrador, clique com o botão direito em cima dele, e selecione a opção: \"Executar em modo de Administrador\".\n" << endl;
        }
        else
        {
            cout << "OK!" << endl;
        }
    }
    else
    {
        cout << "OK!" << endl;
    }

    system("pause");

    return 0;
}

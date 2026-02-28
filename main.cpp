// COMSC-210 | Lab 15 | Johnathan Perez Baltazar

#include <iostream>
using namespace std;

class Movie {
    private:
        string writer;
        int yearReleased;
        string title;
    public:
        void movie(string writer, int yearReleased, string title) {
            this->writer = writer;
            this->yearReleased = yearReleased;
            this->title = title;
        }

        void printData() {
            cout << "Movie: " << title << endl;
            cout << "   Year Released: " << yearReleased << endl;
            cout << "   ScreenWriter: " << writer << endl;
        }
};

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    return 0;
}

// COMSC-210 | Lab 15 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void insertMovieData(Movie i);

const string MOVIE_FILE = "movies.txt";

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
    vector<Movie> movies;

    return 0;
}

void insertMovieData(Movie i, string fileName){
    string writer;
    int yearReleased;
    string title;

    ifstream inputFile;
    string text;

    inputFile.open(fileName);
    if (inputFile.is_open()) {
        while (getline(inputFile, text)) {
            cout << text << endl;
        }
        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
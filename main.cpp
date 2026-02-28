// COMSC-210 | Lab 15 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void insertMovieData(string filePath);

const string MOVIE_FILE = "C:\\Users\\lordj\\COMSC-210\\projects\\210-lab-15\\movies.txt";

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

    insertMovieData(MOVIE_FILE);

    return 0;
}

void insertMovieData(string filePath){
    string writer;
    int yearReleased;
    string title;

    ifstream inputFile;
    string text;

    inputFile.open(filePath);
    if (inputFile.is_open()) {
        int i = 0;
        while (getline(inputFile, text)) {
            if (i % 3 == 0){
                
            }
            cout << text << endl;
        }
        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
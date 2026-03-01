// COMSC-210 | Lab 15 | Johnathan Perez Baltazar

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string MOVIE_FILE = "movies.txt";

class Movie {
    private:
    string writer;
    int yearReleased;
    string title;
    public:
    void setWriter(string w) {
        this->writer = w;
    }
    void setYearReleased(int y) {
        this->yearReleased = y;
    }
    void setTitle(string t) {
        this->title = t;
    }
    
    void printData() {
        cout << "Movie: " << title << endl;
        cout << "   Year Released: " << yearReleased << endl;
        cout << "   ScreenWriter: " << writer << endl;
    }
};

void insertMovieData(string, vector<Movie>&);

/**
 * @brief - Description of main
 * @return 
*/
int main() {
    vector<Movie> movies;

    insertMovieData(MOVIE_FILE, movies);

    cout << "Movie Data: " << endl;
    for (Movie m : movies) {
        m.printData();
    }

    return 0;
}

void insertMovieData(string filePath, vector<Movie>& moviesV) {
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
                Movie* newMOV = new Movie;
                newMOV->setTitle(text);
            }
            if (i % 3 == 1){
                Movie* newMOV = new Movie;
                // stoi() converts a string to an integer
                newMOV->setYearReleased(stoi(text));
            }
            if (i % 3 == 2){
                Movie* newMOV = new Movie;
                newMOV->setWriter(text);
                // push_back() adds a new element to the end of the vector
                moviesV.push_back(*newMOV);
            }

            cout << text << endl;
        }
        inputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}
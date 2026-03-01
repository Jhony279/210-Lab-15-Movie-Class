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
    // Setter and getter functions for the Movie class attributes
    void setWriter(string w) {
        this->writer = w;
    }
    void setYearReleased(int y) {
        this->yearReleased = y;
    }
    void setTitle(string t) {
        this->title = t;
    }
    
    // Function to print the movie data to the console in a formatted manner
    void printData() {
        cout << "Movie: " << title << endl;
        cout << "   Year Released: " << yearReleased << endl;
        cout << "   ScreenWriter: " << writer << endl << endl;
    }
};

void insertMovieData(string, vector<Movie>&);

/**
 * @brief Main function. reads movie data from a file, stores it in a vector of Movie
 *        objects, and prints the data to the console
*/
int main() {
    // Create a vector to hold Movie objects
    vector<Movie> movies;

    // Function to read from file and store into vector 
    insertMovieData(MOVIE_FILE, movies);

    // Print the movie data to the console
    for (Movie m : movies) {
        m.printData();
    }

    return 0;
}

/**
 * @brief Reads movie data from a file and populates a vector of Movie objects
 * @param filePath The path to the file containing movie data
 * @param moviesV A reference to a vector of Movie objects to be populated with the data
*/
void insertMovieData(string filePath, vector<Movie>& moviesV) {
    // Variables to hold the data read from the file for each movie
    string writer;
    int yearReleased;
    string title;

    // Create an input file stream object to read from the specified file
    ifstream inputFile;
    string text;

    inputFile.open(filePath);
    // Check if the file was successfully opened before attempting to read from it
    if (inputFile.is_open()) {
        int i = 0;
        while (getline(inputFile, text)) {
            if (i % 3 == 0) {
                writer = text;
            } else if (i % 3 == 1) {
                yearReleased = stoi(text);
            } else if (i % 3 == 2) {
                title = text;
                Movie m;
                m.setTitle(title);
                m.setYearReleased(yearReleased);
                m.setWriter(writer);
                // Add the newly created Movie object to the vector of movies
                moviesV.push_back(m);
            }
            // Increment the line counter to keep track of which line we are on
            i++;
        }
        inputFile.close();

    // If the file could not be opened, print an error message to the console
    } else {
        cout << "Unable to open file." << endl;
    }
}
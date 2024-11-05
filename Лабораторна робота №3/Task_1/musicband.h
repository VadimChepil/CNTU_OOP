#ifndef MUSICBAND_H
#define MUSICBAND_H

#include <string>
#include <vector>
#include "musician.h"
#include "vocalist.h"

using namespace std;

class MusicBand
{
public:
    MusicBand(string name, string style, Musician leader);

    void setBandName(string name);
    string getBandName();

    void setStyleMusic(string style);
    string getStyleMusic();

    void setBandLeader(Musician leader);
    string getBandLeader();

    void addMusicianBand(Musician musician);
    void addVocalistBand(Vocalist vocalist);
    void deleteBandMember(Musician musician);

    void printMusicBand();

private:
    string bandName;
    string styleMusic;
    vector<Musician> listMusicians;  // агрегація
    vector<Vocalist> listVocalists;  // агрегація
    Musician bandLeader;             // композиція
};

#endif // MUSICBAND_H

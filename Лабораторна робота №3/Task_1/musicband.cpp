#include "musicBand.h"
#include <iostream>

MusicBand::MusicBand(string name, string style, Musician leader)
    : bandName(name), styleMusic(style), bandLeader(leader) {
    listMusicians.push_back(leader);
}

void MusicBand::setBandName(string name)
{
    bandName = name;
}

string MusicBand::getBandName()
{
    return bandName;
}

void MusicBand::setStyleMusic(string style)
{
    styleMusic = style;
}

string MusicBand::getStyleMusic()
{
    return styleMusic;
}

void MusicBand::setBandLeader(Musician leader)
{
    bandLeader = leader;
}

string MusicBand::getBandLeader()
{
    return bandLeader.getMusicianName();
}

void MusicBand::addMusicianBand(Musician musician)
{
    listMusicians.push_back(musician);
}

void MusicBand::addVocalistBand(Vocalist vocalist)
{
    listVocalists.push_back(vocalist);
}

void MusicBand::deleteBandMember(Musician musician)
{
    int index = -1;

    for (int i = 0; i < static_cast<int>(listMusicians.size()); ++i)
    {
        if (listMusicians[i].getMusicianName() == musician.getMusicianName())
        {
            index = i;
            if (listMusicians[i].getMusicianName() == getBandLeader())
            {
                musician.setMusicianName("Not leader");
                setBandLeader(musician);
            }
            break;
        }
    }

    if (index != -1)
    {
        listMusicians.erase(listMusicians.begin() + index);
        return;
    }

    index = -1;
    for (int i = 0; i < static_cast<int>(listVocalists.size()); ++i)
    {
        if (listVocalists[i].getMusicianName() == musician.getMusicianName())
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        listVocalists.erase(listVocalists.begin() + index);
    }
}

void MusicBand::printMusicBand()
{
    cout << "Band name: " << bandName << endl;
    cout << "Style music: " << styleMusic << endl;
    cout << "Band leader: " << MusicBand::getBandLeader() << endl;

    for (Musician musician : listMusicians)
    {
        cout << "Musician: " << musician.getMusicianName()
             << ", Tool: " << musician.getTool().getToolName()
             << " (" << musician.getTool().getYearManufacture() << ")" << endl;
    }

    for (Vocalist vocalist : listVocalists)
    {
        cout << "Vocalist: " << vocalist.getMusicianName()
             << ", Tool: " << vocalist.getTool().getToolName()
             << " (" << vocalist.getTool().getYearManufacture() << "), "
             << "Type: " << vocalist.getVocalistType() << endl;
    }

    cout << endl;
}

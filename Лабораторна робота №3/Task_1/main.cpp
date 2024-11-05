#include <iostream>
#include "musicband.h"

using namespace std;

int main()
{
    // Створення інструментів
    Tool guitar("Guitar", 2020);
    Tool dudka("Dudka", 2018);
    Tool baraban("Baraban", 2010);
    Tool microphone("Microphone", 2021);

    // Створення музикантів
    Musician musician1("Sanya", guitar);
    Musician musician2("Taras", dudka);
    Musician musician3("Vadim", baraban);

    // Створення вокалістів
    Vocalist vocalist1("Sofia", microphone,"Solo");
    Vocalist vocalist2("Ivan", microphone,"Backing vocalist");
    Vocalist vocalist3("Oleg", microphone, "Choir singer");

    // Створення музичного гурту
    MusicBand band("Rock Band", "Rock", musician1);
    band.addMusicianBand(musician2);
    band.addMusicianBand(musician3);
    band.addVocalistBand(vocalist1);
    band.addVocalistBand(vocalist2);
    band.addVocalistBand(vocalist3);

    // Видалення учасника гурту
    //band.deleteBandMember(musician1);

    // Встановлення лідера
    //band.setBandLeader(vocalist1);

    //виведення інформоції про гурт
    band.printMusicBand();
    return 0;
}

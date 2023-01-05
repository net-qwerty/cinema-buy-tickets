#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include "class.h"
#include "function.h"
using namespace std;

int main ()
{
setlocale(LC_ALL, "Russian");

vector<cinema> cinemaP; //вектор объектов кинотеатров
cinemaP.push_back(cinema("Kinomax"));
cinemaP.push_back(cinema("5Stars"));
cinemaP.push_back(cinema("Miraj"));
cinemaP.push_back(cinema("KARO"));
cinemaP.push_back(cinema("Kinopolice"));

vector<film> filmP; //вектор объектов фильмов
filmP.push_back(film("Mstitely",400));
filmP.push_back(film("Winner", 300));
filmP.push_back(film("OldBoy",200));
filmP.push_back(film("JIGA",250));
filmP.push_back(film("GunBoron",320));
filmP.push_back(film("Split",270));
filmP.push_back(film("KingArthurSword",380));

vector<place> placeP; //вектор объектов сеансов
placeP.push_back(place("8:00"));
placeP.push_back(place("11:00"));
placeP.push_back(place("12:30"));
placeP.push_back(place("14:30"));
placeP.push_back(place("16:30"));
placeP.push_back(place("18:00"));
placeP.push_back(place("19:30"));
placeP.push_back(place("23:00"));
SetFilm_inCinema(cinemaP,filmP);//заполняем массив объекта кинотетра фильмами

//Открываем массивы с бронированными сеансами из файлов
for (int w = 0; w < placeP.size(); w++){
string s = to_string(w);
openMstitely(placeP,w, s,"Mstitely");
openWinner(placeP,w, s,"Winner");
openOldBoy(placeP,w, s,"OldBoy");
openJIGA(placeP,w, s,"JIGA");
openGunBoron(placeP,w, s,"GunBoron");
openSplit(placeP,w, s,"Split");
openKingArthurSword(placeP,w, s,"KingArthurSword");
}


cout << "Здравствуйте !" << endl;

AllCinema(cinemaP); //Выбираем кинотеатр
int cinema;
cin >> cinema; 
string nameCin=cinemaP[cinema].GetCinema(); //выбранный кинотеатр

AllDate(); //Выбираем день сеанса
int date;
cin >> date;

AllPrice(filmP, cinema); //выбираем фильм
int film;
cin >> film;
string nameFil=filmP[film].GetFilm(); //выбранный фильм
int priceF=filmP[film].GetPrice(); // цена выбранного фильма
string  ValDate=filmP[film].GetDate(date);

AllTimePlace(placeP); //Выберите время сеанса
int time; 
cin >> time;
string ValTime=placeP[time].GetTime();
int row;
int mesto;
vector<int> rows;
vector<int> mesta;
do {
placeP[time].Place(nameFil); //Вывести свободные места на данный сеанс
cout << "Ряд: ";
cin >> row;
if (row == 99 ){
    cout << "Exit"<< endl;
    break;
}
cout << "Место: ";
cin >> mesto;
rows.push_back(row);
mesta.push_back(mesto);
SelectPlace(placeP, filmP, film, time, row, mesto);
} while (row != 99);
PrintCheck(nameCin,nameFil,ValDate,ValTime,priceF, rows,mesta);


//Сохраняем массивы с забронированными местами в файлы
for (int w = 0; w < placeP.size(); w++){
string s = to_string(w);
saveMstitely(placeP,w,s,"Mstitely");
saveWinner(placeP,w,s,"Winner");
saveOldBoy(placeP,w,s,"OldBoy");
saveJIGA(placeP,w,s,"JIGA");
saveGunBoron(placeP,w,s,"GunBoron");
saveSplit(placeP,w,s,"Split");
saveKingArthurSword(placeP,w,s,"KingArthurSword");
}

return 0;
}
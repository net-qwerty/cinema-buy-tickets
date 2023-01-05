#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
using namespace std;
class film;
class cinema
{
    private:
    string nameCinema; // Название кинотеатра
    
    public:
    cinema(){};
    cinema(string ValCinema)
    {
        nameCinema=ValCinema;
    };
    vector<string> filmN; // Вектор с фильма в кинотеатре
    
    void pushFilm(string ValFilm)  // Добавить фильм в кинотеатр 
    {
    this->filmN.push_back(ValFilm);
    }
   
    void GetFilms(){       // Вывести все фильмы в кинотеатре
        cout << endl << "Выберите фильм" << endl;
        for(int i = 0; i < filmN.size(); i++)
        cout << filmN[i] << " - " << i << ";";
        cout << endl;
    }
    void SetCinema (string ValCinema)   // Сетер кинотеатра
    {
        nameCinema = ValCinema;
    }
    string GetCinema(){
        return nameCinema;
    }
};   
    


class film //: public cinema //класс фильмы
{
    private:
    string nameFilm;
    int Price;
    vector<string> date = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскрсенье"};
    
    public:
    film(){};
    film(string VlFilm, int ValPrice)   // конструктор задаёт название фильма, цену, добавляет вильм в вектор с кинотеатром
    { 
        nameFilm=VlFilm;
        Price=ValPrice;
    };
    

    string GetDate(int d)
    {
        return date[d];
    }

    void SetFilm (string ValFilm)
    {
        nameFilm = ValFilm;
    }

    string GetFilm()
    {
        return nameFilm;
    }

    void SetPrice (int ValPrice)
    {
        Price = ValPrice;
    }

    int GetPrice()
    {
        return Price;
    }
    friend void AllPrice(vector<film>&filmP);
    friend void SelectPlace(vector<cinema>&cinemaP,vector<film>&filmP,int k, int r, int m);
};

class place//: public cinema
{
private:
string time; 
int placeMstitely[10][10]{}; //[ряд] [место]
int placeWinner[10][10]{}; //[ряд] [место]
int placeOldBoy[10][10]{}; //[ряд] [место]
int placeJIGA[10][10]{}; //[ряд] [место]
int placeGunBoron[10][10]{}; //[ряд] [место]
int placeSplit[10][10]{}; //[ряд] [место]
int placeKingArthurSword[10][10]{}; //[ряд] [место]

public:
place(){};
place(string VlPlace)   // конструктор задаёт название фильма, цену, добавляет вильм в вектор с кинотеатром
{ 
time=VlPlace;

//       pushFilm(VlFilm);
};

string GetTime(){
    return time;
}
void Place(string PLfilm){   
    int n=10; //ряд
    int m=10; // место
    cout << endl << "Выберите ряд и место в зале: ";
    cout << endl<< "      ";
    for (int i = 1; i < m; ++i)
    {
        cout << "м   ";
    }
    cout << endl;
    for (int i = 1; i < n; ++i)
    {
    cout << "ряд" << i << " ";
    for (int j = 1; j < m; ++j)
    {
    if (PLfilm == "Mstitely")
	cout << "(" << placeMstitely[i][j] << ") ";
    if (PLfilm == "Winner")
	cout << "(" << placeWinner[i][j] << ") ";
    if (PLfilm == "OldBoy")
	cout << "(" << placeOldBoy[i][j] << ") ";
    if (PLfilm == "JIGA")
	cout << "(" << placeJIGA[i][j] << ") ";
    if (PLfilm == "GunBoron")
	cout << "(" << placeGunBoron[i][j] << ") ";
    if (PLfilm == "Split")
	cout << "(" << placeSplit[i][j] << ") ";
    if (PLfilm == "KingArthurSword")
	cout << "(" << placeKingArthurSword[i][j] << ") ";
    }
    cout << endl;   
    }
    cout << "      ";
    for (int i = 1; i < m; ++i)
    {
        cout << i << "   ";
    }
    cout << endl << "0-свободно; " << "1-занято;" << "99-закончить выбор и распечатать билеты"<< endl;
    }

    friend void SelectPlace(vector<place>&placeP,vector<film>&filmP,int k,int f, int r, int m);
    
    friend void openMstitely(vector<place>&placeP,int n,string m, string name);
    friend void openWinner(vector<place>&placeP,int n,string m, string name);
    friend void openOldBoy(vector<place>&placeP,int n,string m, string name);
    friend void openJIGA(vector<place>&placeP,int n,string m, string name);
    friend void openGunBoron(vector<place>&placeP,int n,string m, string name);
    friend void openSplit(vector<place>&placeP,int n,string m, string name);
    friend void openKingArthurSword(vector<place>&placeP,int n,string m, string name);
    
    friend void saveMstitely(vector<place>&placeP,int n,string m, string name);
    friend void saveWinner(vector<place>&placeP,int n,string m, string name);
    friend void saveOldBoy(vector<place>&placeP,int n,string m, string name);
    friend void saveJIGA(vector<place>&placeP,int n,string m, string name);
    friend void saveGunBoron(vector<place>&placeP,int n,string m, string name);
    friend void saveSplit(vector<place>&placeP,int n,string m, string name);
    friend void saveKingArthurSword(vector<place>&placeP,int n,string m, string name);
};

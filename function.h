
//Выводит список фильмов и цен
void AllPrice(vector<film>&filmP, int k){
        cout << "Выберите Фильм: ";
        for(int i = 0; i < filmP.size(); i++)
        cout << filmP[i].GetFilm()<< "(" <<filmP[i].GetPrice() << "руб.)"<< " - " << i << "; "; 
        cout << endl;
    }

//Вывод списка кинотеатров
void AllCinema(vector<cinema>&cinemaP){
    cout << endl << "Выберите кинотеатр" << endl;
    for (int i=0; i < cinemaP.size(); i++)
    cout << cinemaP[i].GetCinema() << " - " << i << ";";
    cout << endl;
}

//Бронирование билетов
void SelectPlace(vector<place>&placeP,vector<film>&filmP,int film,int time, int r, int m){
    if ( filmP[film].GetFilm() == "Mstitely" ){
    if (placeP[time].placeMstitely[r][m] != 1){
    placeP[time].placeMstitely[r][m]= 1;
    cout << "Ваше место забронировано, можете выбрать слудующее.";}
    else
    {cout << "Место занято, выберите другое";}} 

    if ( filmP[film].GetFilm() == "Winner" ){
    if (placeP[time].placeWinner[r][m] != 1){
    placeP[time].placeWinner[r][m]= 1;
    cout << "Ваше место забронировано, можете выбрать слудующее.";}
    else
    {cout << "Место занято, выберите другое";}} 

    if ( filmP[film].GetFilm() == "OldBoy" ){
    if (placeP[time].placeOldBoy[r][m] != 1){
    placeP[time].placeOldBoy[r][m]= 1;
    cout << "Ваше место забронировано, можете выбрать слудующее.";}
    else
    {cout << "Место занято, выберите другое";}}

    if ( filmP[film].GetFilm() == "JIGA" ){
    if (placeP[time].placeJIGA[r][m] != 1){
    placeP[time].placeJIGA[r][m]= 1;
    cout << "Ваше место забронировано, можете выбрать слудующее.";}
    else
    {cout << "Место занято, выберите другое";}}

    if ( filmP[film].GetFilm() == "GunBoron" ){
    if (placeP[time].placeGunBoron[r][m] != 1){
    placeP[time].placeGunBoron[r][m]= 1;
    cout << "Ваше место забронировано, можете выбрать слудующее.";}
    else
    {cout << "Место занято, выберите другое";}}

    if ( filmP[film].GetFilm() == "Split" ){
    if (placeP[time].placeSplit[r][m] != 1){
    placeP[time].placeSplit[r][m]= 1;
    cout << "Ваше место забронировано, можете выбрать слудующее.";}
    else
    {cout << "Место занято, выберите другое";}}

    if ( filmP[film].GetFilm() == "KingArthurSword" ){
    if (placeP[time].placeKingArthurSword[r][m] != 1){
    placeP[time].placeKingArthurSword[r][m]= 1;
    cout << "Ваше место забронировано, можете выбрать слудующее.";}
    else
    {cout << "Место занято, выберите другое";}}
}

//Вывод времени сеанса
void AllTimePlace(vector<place>&placeP){
    cout << "Выберите время сеанса" << endl; 
    for (int i=0; i < placeP.size(); i++)
    cout << placeP[i].GetTime() << " - " << i << ";";  
}


void PrintCheck(string cinema, string film,string date, string place, int price, vector<int>&rows, vector<int>&mesta){
    //Вывод чека на экран
    
    cout << "      Ваш Билет" << endl;
    cout << "Кинотеатр: "<< cinema << endl;
    cout << "Фильм: "<< film << endl;
    cout << "День: " << date << endl;
    cout << "Время сеанса: "<< place << endl;
    for (int i=0; i<rows.size(); i++ )
    {
    cout << "Ряд: " << rows[i];   
    cout << " Место: " << mesta[i] << endl;
    }
    cout << "Цена: " << price * mesta.size() << endl;

    //выводит чек в файл 
    ofstream ticket;           //создание потока ввода
    ticket.open("ticket.txt");
    ticket << "      Ваш Билет" << endl;
    ticket << "Кинотеатр: "<< cinema << endl;
    ticket << "Фильм: "<< film << endl;
    ticket << "День: " << date << endl;
    ticket << "Время сеанса: "<< place << endl;
    for (int i=0; i<rows.size(); i++ )
    {
    ticket << "Ряд: " << rows[i];   
    ticket << " Место: " << mesta[i] << endl;
    }
    ticket << "Цена: " << price * mesta.size() << endl;
    ticket.close();
}


void AllDate(){
vector<string> date = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскрсенье"};
cout << endl << "Выберите день недели" << endl;
for(int i = 0; i < date.size(); i++)
cout << date[i] << " - " << i << ";";
cout << endl;
}
// void SetFilm_inFilm(vector<film>&filmP){
// for (int i=0; i<filmP.size(); i++ )
// {
// for (int j=0; j< filmP.size(); j++){
// string x;
// x = filmP[j].GetFilm();
// filmP[i].pushFilm(x);
// }}}

void SetFilm_inCinema(vector<cinema>&cinemaP,vector<film>&filmP){
for (int i=0; i<cinemaP.size(); i++ )
{
for (int j=0; j< filmP.size(); j++){
string x;
x = filmP[j].GetFilm();
cinemaP[i].pushFilm(x);
}}}


//ОТКРЫВЕМ РАСПИСАНИЕ ИЗ ФАЙЛА

void openMstitely(vector<place>&placeP,int n,string m, string name){ 
    ifstream fi;
    string nameF = m + name;
    fi.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            fi >> placeP[n].placeMstitely[i][j];
        }
    }
    fi.close();
}

void openWinner(vector<place>&placeP,int n,string m, string name){ 
    ifstream fi;
    string nameF = m + name;
    fi.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            fi >> placeP[n].placeWinner[i][j];
        }
    }
    fi.close();
}

void openOldBoy(vector<place>&placeP,int n,string m, string name){   
    ifstream fi;
    string nameF = m + name;
    fi.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            fi >> placeP[n].placeOldBoy[i][j];
        }
    }
    fi.close();
}

void openJIGA(vector<place>&placeP,int n,string m, string name){   
    ifstream fi;
    string nameF = m + name;
    fi.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            fi >> placeP[n].placeJIGA[i][j];
        }
    }
    fi.close();
}

void openGunBoron(vector<place>&placeP,int n,string m, string name){  
    ifstream fi;
    string nameF = m + name;
    fi.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            fi >> placeP[n].placeGunBoron[i][j];
        }
    }
    fi.close();
}

void openSplit(vector<place>&placeP,int n,string m, string name){   
    ifstream fi;
    string nameF = m + name;
    fi.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            fi >> placeP[n].placeSplit[i][j];
        }
    }
    fi.close();
}

void openKingArthurSword(vector<place>&placeP,int n,string m, string name){   
    ifstream fi;
    string nameF = m + name;
    fi.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            fi >> placeP[n].placeKingArthurSword[i][j];
        }
    }
    fi.close();
}


//СОХРАНЯЕМ РАСПИСАНИЕ В ФАЙЛ

void saveMstitely(vector<place>&placeP,int n,string m, string name){
    ofstream f;
    string nameF = m + name;
    f.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            f << placeP[n].placeMstitely[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}

void saveWinner(vector<place>&placeP,int n,string m, string name){
    ofstream f;
    string nameF = m + name;
    f.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            f << placeP[n].placeWinner[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}

void saveOldBoy(vector<place>&placeP,int n,string m, string name){
    ofstream f;
    string nameF = m + name;
    f.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            f << placeP[n].placeOldBoy[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}

void saveJIGA(vector<place>&placeP,int n,string m, string name){
    ofstream f;
    string nameF = m + name;
    f.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            f << placeP[n].placeJIGA[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}

void saveGunBoron(vector<place>&placeP,int n,string m, string name){
    ofstream f;
    string nameF = m + name;
    f.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            f << placeP[n].placeGunBoron[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}

void saveSplit(vector<place>&placeP,int n,string m, string name){
    ofstream f;
    string nameF = m + name;
    f.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            f << placeP[n].placeSplit[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}

void saveKingArthurSword(vector<place>&placeP,int n,string m, string name){
    ofstream f;
    string nameF = m + name;
    f.open(nameF);
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            f << placeP[n].placeKingArthurSword[i][j] << " ";
        }
        f << endl;
    }
    f.close();
}




#include<bits/stdc++.h>
using namespace std;

//Functions prototype
int timestamp();
void menu();
void add_new_event();
void show_events();
void book_seat();
void display_seats(int idx);
void init_seats(int idx);
bool canBookTogether(vector<vector<int>> &seats, int r, int c, int n);
void bookTogether(vector<vector<int>> &seats, int r, int c, int n);
bool firstFit(vector<vector<int>> &seats, int n);

//Structures
struct event{
    string event_name;
    int dd=0;
    int mm=0;
    int yyyy=0;
    int hall=0;
};

struct Seat {
    int row;
    int col;
    bool isBooked;
    string personName;
};

struct day{
    int t_day=0;
    int t_month=0;
    int t_year=0;
};

//Global Variable
int Harry_Convention_Center[25][20]={0};         //(500)
int Ron_Convention_Center[25][16]={0};           //(400)
int Hermione_Convention_Center[25][40]={0};      //(1000)

vector <event> event_list;

day today;

map<int, vector<vector<int>>> event_seats;







int main(){
    cout<<"Hogwarts Banquet Hall & Convention Center"<<endl;
    timestamp();

    menu();
    return 0;
}

void menu(){
    int choice;

    while(true){
        cout<<"\n========= MENU =========\n";
        cout<<"1. Book Seats\n";
        cout<<"2. Add New Event\n";
        cout<<"3. Show Events\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1) book_seat();
        else if(choice==2) add_new_event();
        else if(choice==3) show_events();
        else if(choice==4) break;
        else cout<<"Invalid choice\n";
    }
}



void add_new_event(){
    event temp;

    cout<<"Event name: ";
    cin>>temp.event_name;

    cout<<"Year: "; cin>>temp.yyyy;
    cout<<"Month: "; cin>>temp.mm;
    cout<<"Day: "; cin>>temp.dd;

    while(temp.hall<1 || temp.hall>3){
    cout<<"Please Select a hall you want to book: "<<endl;
    cout<<"1. Harry Convention Center    - 500 Seats"<<endl;
    cout<<"2. Ron Convention Center      - 400 Seats"<<endl;
    cout<<"3. Hermione Convention Center - 1000 Seats"<<endl;
        cin>>temp.hall;
    }

    event_list.push_back(temp);
    int idx = event_list.size()-1;

    init_seats(idx);

    cout<<"Event Added Successfully!\n";
}

void init_seats(int idx){
    int rows = 25, cols;

    if(event_list[idx].hall==1) cols=20;
    else if(event_list[idx].hall==2) cols=16;
    else cols=40;

    vector<vector<int>> seats(rows, vector<int>(cols,0));
    event_seats[idx] = seats;
}

void show_events(){
    if(event_list.empty()){
        cout<<"No events available\n";
        return;
    }

    for(int i=0;i<event_list.size();i++){
        cout<<i<<". "<<event_list[i].event_name<<" ("
            <<event_list[i].dd<<"-"
            <<event_list[i].mm<<"-"
            <<event_list[i].yyyy<<")\n";
    }
}

void display_seats(int idx){
    auto &seats = event_seats[idx];

    for(int i=0;i<seats.size();i++){
        for(int j=0;j<seats[i].size();j++){
            cout<<(seats[i][j] ? "X " : "O ");
            if((j+1)%10==0) cout<<"   ";
        }
        cout<<endl;
    }
}

void book_seat(){
    show_events();

    int idx;
    cout<<"Select event index: ";
    cin>>idx;

    if(idx<0 || idx>=event_list.size()){
        cout<<"Invalid event\n";
        return;
    }

    auto &seats = event_seats[idx];

    display_seats(idx);

    int r,c,n;
    cout<<"Row: "; cin>>r;
    cout<<"Column: "; cin>>c;
    cout<<"Number of seats: "; cin>>n;

    // adjust for 0 indexing
    r--; c--;

    if(canBookTogether(seats, r, c, n)){
        bookTogether(seats, r, c, n);
        cout<<"Seats booked together successfully!\n";
    }
    else{
        cout<<"Cannot book seats together.\n";
        cout<<"Do you want separate seats? (1=Yes / 0=No): ";

        int choice;
        cin>>choice;

        if(choice==1){
            if(firstFit(seats, n)){
                cout<<"Seats booked using First Fit (separate).\n";
            } else {
                cout<<"Not enough seats available.\n";
            }
        }
        else{
            cout<<"Try different row/column.\n";
        }
    }
}

bool canBookTogether(vector<vector<int>> &seats, int r, int c, int n){
    for(int i=0;i<n;i++){
        if(c+i >= seats[0].size() || seats[r][c+i] == 1){
            return false;
        }
    }
    return true;
}

void bookTogether(vector<vector<int>> &seats, int r, int c, int n){
    for(int i=0;i<n;i++){
        seats[r][c+i] = 1;
    }
}

bool firstFit(vector<vector<int>> &seats, int n){
    int rows = seats.size();
    int cols = seats[0].size();

    int count = 0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(seats[i][j] == 0){
                seats[i][j] = 1;
                count++;
                if(count == n) return true;
            }
        }
    }
    return false;
}




int timestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    int hour = ltm->tm_hour;
    int min = ltm->tm_min;
    int sec = ltm->tm_sec;

    cout << setfill('0');
    cout << year << " "
         << setw(2) << month << " "
         << setw(2) << day << " - "
         << setw(2) << hour << ":"
         << setw(2) << min << ":"
         << setw(2) << sec << endl;
    
    today.t_day=day;
    today.t_month=month;
    today.t_year=year;
         return 0;
}

#include "Date.h"

Date::Date(){
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(string date){
	vector<string> DateComponents;
	string segment;
	stringstream test(date);
	while (getline(test, segment, '/'))
	{
		DateComponents.push_back(segment);
	}
	this->year = stoi(DateComponents[2]);
	this->month= stoi(DateComponents[1]);
	this->day= stoi(DateComponents[0]);
}

/*********************************
 * GET Methods
 ********************************/
unsigned short Date::getDay() const{
	return day;
}

unsigned short Date::getMonth() const{
	return month;
}
    
unsigned Date::getYear() const{
	return year;
}


// disply a Date in a nice format
ostream& operator<<(ostream& out, const Date & date){
	out << date.getDay() << '/' << date.getMonth() << '/' << date.getYear() ;
	return out;
}

int DateValidation(string date){

    regex rx("(0?[1-9]|[12][0-9]|3[01])[/](0?[1-9]|1[0-2])[/](19[5-9][0-9]|20[0-4][0-9]|2050)");
    if (!regex_match(date.begin(), date.end(), rx)) {
        return 1;
    }
    Date new_date = Date(date);
    if ((new_date.getMonth() == 1 || new_date.getMonth() == 3 || new_date.getMonth() == 5 || new_date.getMonth() == 7 ||
            new_date.getMonth() == 8 || new_date.getMonth() == 10 || new_date.getMonth() == 12) && ( new_date.getDay()>31 || new_date.getDay()<1) )
    {
        return 1;
    }
    else if ((new_date.getMonth() == 4 ||new_date.getMonth() == 6 || new_date.getMonth() == 9 || new_date.getMonth() == 11) && (new_date.getDay()>30 || new_date.getDay()<1) )
    {
        return 1;
    }
    else if ((new_date.getMonth() == 2) && (new_date.getYear() % 4 == 0) && (new_date.getDay()>29 || new_date.getDay()<1))
    {
        return 1;
    }
    else if ((new_date.getMonth() == 2) && (new_date.getYear() % 4 != 0) && (new_date.getDay()>28 || new_date.getDay()<1) )
    {
        return 1;
    }
    else if ((new_date.getYear() < 999) || (new_date.getYear() > 10000))
    {
        return 1;
    }
    if ((new_date.getMonth() < 1) || (new_date.getMonth() > 12))
    {
        return 1;
    }
    return 0;
}

Date getCurrentDate(){
    auto timenow =chrono::system_clock::to_time_t(chrono::system_clock::now());
    stringstream ss;
    ss << ctime(&timenow);
    string dia,mes,ano,tmp;
    getline(ss,tmp,' ');
    getline(ss,mes,' ');
    getline(ss,dia,' ');
    getline(ss,tmp,' ');
    getline(ss,ano);
    if (mes=="Dec") mes = "12";
    else if (mes=="Jan") mes = "1";
    else if (mes== "Feb") mes = "2";
    else if (mes=="Mar") mes = "3";
    else if (mes=="Apr") mes = "4";
    else if (mes=="May") mes = "5";
    else if (mes=="Jun") mes ="6";
    else if (mes== "Jul") mes="7";
    else if (mes== "Aug") mes="8";
    else if (mes=="Sep") mes="9";
    else if (mes=="Oct") mes="10";
    else if (mes=="Nov") mes ="11";
    return Date(dia+"/"+mes+"/"+ano);
}
bool DateInRange( int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear){
    int data_atual = (getCurrentDate().getYear() * 10000) + (getCurrentDate().getMonth() * 100) + getCurrentDate().getDay();
    int data_inicio_convocatoria = (startYear * 10000) + (startMonth * 100) + startDay;
    int data_fim_convocatoria = (endYear * 10000) + (endMonth * 100) + endDay;

    if (data_atual >= data_inicio_convocatoria && data_atual <= data_fim_convocatoria){
        return true;
    }
    else{
        return false;
    }
}

#include "ofxDateTime.h"
#include "ofxExtras.h"

ofxDateTime::ofxDateTime() {
    setFromCurrentTime();
}

ofxDateTime::ofxDateTime(const ofxDateTime &dt) {
    set(dt.timeValue);
}

ofxDateTime::ofxDateTime(long seconds) { //was float
    timeValue = (long)seconds;
}

void ofxDateTime::set(long seconds) { //was float
    timeValue = (long)seconds;
}

void ofxDateTime::setFromCurrentTime() {
    time_t rawtime;
    time(&rawtime);
    timeValue = (long)rawtime;
}

string ofxDateTime::getDate(string fmt) {
	return format(fmt);
}

string ofxDateTime::getTime(string fmt) {
    return format(fmt);
}

string ofxDateTime::getMinutesAndSeconds() {
    return format("%M:%S");
}
//
//string ofxDateTime::getSeconds() {
//    return format("%S");
//}

/*int ofxDateTime::getSeconds() {
    return timeValue; //ofxToInteger(format("%S")); //waarom niet gewoon return timeValue? sowieso overbodig en verwarrend
}*/

string ofxDateTime::getDateTime(string fmt) {
    return format(fmt);
}

string ofxDateTime::format(string fmt) {
	char buffer[80];
	time_t rawtime = (time_t)timeValue;
	struct tm *timeinfo = localtime(&rawtime);
	strftime(buffer,80,fmt.c_str(),timeinfo);
	return buffer;
}

//ofxDateTime ofxDateTime::operator-(ofxDateTime &t) {
//    return ofxDateTime(this->timeValue - t.timeValue);
//}

ofxDateTime ofxDateTime::operator-(const ofxDateTime t) {
	//cout << timeValue << " - " << t.timeValue << "=" << (timeValue - t.timeValue) << endl;
    return (timeValue - t.timeValue);
}

ofxDateTime ofxDateTime::operator-=(const ofxDateTime t) {
    timeValue -= t.timeValue;
    return *this;
}

ofxDateTime ofxDateTime::operator+(const ofxDateTime t) {
    return timeValue + t.timeValue;
}

ofxDateTime ofxDateTime::operator+=(const ofxDateTime t) {
    timeValue += t.timeValue;
    return *this;
}

ofxDateTime ofxDateTime::now() {
    return ofxDateTime();
}

int ofxDateTime::secondsElapsedSince() {
    return (now().timeValue - timeValue);
}

ofxDateTime ofxDateTime::timeElapsedSince() {
    return ofxDateTime(secondsElapsedSince());
}

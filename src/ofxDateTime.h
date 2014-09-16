    #ifndef OFX_DATE_TIME
#define OFX_DATE_TIME

#include "ofMain.h"

class ofxDateTime {
public:

//    time_t rawtime;

	long timeValue; //in ms

    ofxDateTime();
    ofxDateTime(long seconds); //was float
    ofxDateTime(const ofxDateTime &dt);

    void setFromCurrentTime();
    void set(long value); //was float

    string getMinutesAndSeconds();
//    string getSeconds();
    int getSeconds();

    string getTime(string fmt="%X");
    string getDate(string fmt="%d-%m-%Y");
    string getDateTime(string fmt="%d-%m-%Y %X");
    string format(string fmt);

    ofxDateTime operator+(ofxDateTime t);
    ofxDateTime operator-(ofxDateTime t);
    ofxDateTime operator+=(ofxDateTime t);
    ofxDateTime operator-=(ofxDateTime t);

    int secondsElapsedSince();
    ofxDateTime timeElapsedSince();

    static ofxDateTime now();

};

#endif

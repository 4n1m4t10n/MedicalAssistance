
#include "hospital.h"
hospital::hospital::hospital(string& name, string& oldName) {
    this->name = name;
    this->number = 0;
    this->oldName = oldName;
    this->city = "";
    this->state = "";
    this->facilityType = "";
    //placeholder until rating is set
    this->ratingOverall = 0;
//vectors are automatically empty so no need to do anything for them
}
hospital::hospital::hospital() {
    this->name = "";
    this->number = 0;
    this->oldName = "";
    this->city = "";
    this->state = "";
    this->facilityType = "";
    this->ratingOverall = 0;
//vectors are automatically empty so no need to do anything for them
}

void hospital::hospital::setString(string stringData, const string& category) {
    if (category=="name") {
        this->name = stringData;
    } else if (category=="city") {
        this->city = stringData;
    } else if (category=="facility") {
        this->facilityType = stringData;
    } else if (category=="overallrating") {
        if (stringData != "-1") {
            this->ratingOverall = stoi(stringData);
        } else {
            //no data
            this->ratingOverall = -1;
        }
    } else if (category=="state") {
        this->state = stringData;
    } else if (category=="heartattack") {
        if (stringData != "0") {
            this->heartAttackCost = stoi(stringData);
        } else {
            this->heartAttackCost = 0;
        }
    } else if (category=="heartfailure") {
        if (stringData != "0") {
            this->heartFailureCost = stoi(stringData);
        } else {
            this->heartFailureCost = 0;
        }
    } else if (category=="pneumonia") {
        if (stringData != "0") {
            this->pneumoniaCost = stoi(stringData);
        } else {
            this->pneumoniaCost = 0;
        }
    } else if (category=="hipknee") {
        if (stringData != "0") {
            this->hipkneeCost = stoi(stringData);
        } else {
            this->hipkneeCost = 0;
        }
    } else if (category=="timeliness") {
        if (stringData=="Above") {
            this->timelinessRating = 3;
        } else if (stringData=="Below") {
            this->timelinessRating = 1;
        } else if (stringData=="Same") {
            this->timelinessRating = 2;
        } else if (stringData=="None") {
            this->timelinessRating = 0;
        }
    } else if (category=="safety") {
        if (stringData=="Above") {
            this->safetyRating = 3;
        } else if (stringData=="Below") {
            this->safetyRating = 1;
        } else if (stringData=="Same") {
            this->safetyRating = 2;
        } else if (stringData=="None") {
            this->safetyRating = 0;
        }
    } else if (category=="average") {
        this->averageCost = ((double)(this->heartAttackCost+this->heartFailureCost+this->pneumoniaCost+this->hipkneeCost))/(double)4.00;
    } else if (category=="number") {
        this->number = stoi(stringData);
    }
}

string hospital::hospital::returnString(const string& category) {
    if (category=="name") {
        return this->name;
    } else if (category=="city") {
        return this->city;
    } else if (category=="facility") {
        return this->facilityType;
    } else if (category=="overallrating") {
        return to_string(this->ratingOverall);
    } else if (category=="state") {
        return this->state;
    } else if (category=="heartattack") {
        return to_string(this->heartAttackCost);
    } else if (category=="heartfailure") {
        return to_string(this->heartFailureCost);
    } else if (category=="pneumonia") {
        return to_string(this->pneumoniaCost);
    } else if (category=="hipknee") {
        return to_string(this->hipkneeCost);
    } else if (category=="timeliness") {
        return to_string(this->timelinessRating);
    } else if (category=="safety") {
        return to_string(this->safetyRating);
    } else if (category=="average") {
        return to_string(this->averageCost);
    } else if (category=="number") {
        return to_string(this->number);
    }
    return "";
}
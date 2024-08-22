#include "../../include/Utils/Position.h"

Position::Position(double latitude, double longitude): latitude(latitude), longitude(longitude) {}

double Position::getLatitude() {
    return this->latitude;
}

void Position::setLatitude(double latitude) {
    this->latitude = latitude;
}

double Position::getLongitude() {
    return this->longitude;
}

void Position::setLongitude(double longitude) {
    this->longitude = longitude;
}

double Position::getEuclidianDistance(const Position & point) {
    return sqrt(pow(point.latitude - this->latitude, 2) + pow(point.longitude - this->longitude, 2));
}


double Position::getHaversineDistance(const Position & point){
    // Earth's radius is 6371000m on average.
    // Planes fly at an average altitude of 35000 ft, or about 10700m.
    const double R = 6371000 + 10700;
    double phi1 = this->latitude * M_PI/180;
    double phi2 = point.latitude * M_PI/180;
    double deltaPhi = (point.latitude - this->latitude) * M_PI/180;
    double deltaLambda = (point.longitude - this->longitude) * M_PI/180;

    double a =
            sin(deltaPhi/2.0) * sin(deltaPhi/2.0) +
            cos(phi1) * cos(phi2) *
            sin(deltaLambda/2.0) * sin(deltaLambda/2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1-a));

    double d = R * c;

    return d;
}

double Position::getTimeDistance(const Position & point) {
    return 0.3 + getHaversineDistance(point)/8e5;
}


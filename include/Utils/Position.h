#ifndef INCLUDE_POSITION_H
#define INCLUDE_POSITION_H

#include <algorithm>
#include <cmath>

using namespace std;
/**Represents a Position instance and all it's relevant information**/
class Position {
private:
    double latitude;
    double longitude;
public:
    /**Position Constructor
     *
     * @param latitude latitude of a point
     * @param longitude longitude of a point
     */
    Position(double latitude, double longitude);

    /**Gets the position's latitude
     *
     * @return latitude
     */
    double getLatitude();
    /**Sets the position's latitude
     *
     * @param latitude
     */
    void setLatitude(double latitude);

    /**Gets the position's longitude
     *
     * @return
     */
    double getLongitude();
    /**Sets the position's longitude
     *
     * @param longitude
     */
    void setLongitude(double longitude);

    /**Gets the euclidian distance between two points
     *
     * @param point point to calculate the distance to
     * @return distance calculated
     */
    double getEuclidianDistance(const Position & point);

    /**Gets the time distance between two points
     *
     * @param point point to calculate the distance to
     * @return distance calculated
     */
    double getTimeDistance(const Position & point);

    /**Gets the haversine distance between two points
     *
     * @param point point to calculate the distance to
     * @return distance calculated
     */
    double getHaversineDistance(const Position & point);
};


#endif //INCLUDE_POSITION_H

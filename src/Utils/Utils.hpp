#ifndef Utils_H
#define Utils_H

/**
 * @brief Takes in the new deltatime value and checks whether it is anomalous.
 *
 * Sometimes there is an extended period of time between gameloop iterations, causing an abnormally
 * large deltatime. This causes sprites to clip through others. Therefore this func records a small history
 * of the deltatime and checks if a new one is abnormal.
 *
 * Abnormal is calculated if the new value is greater than 30x the median.
 *
 * @param new_deltatime
 * @return Whether the deltatime is anomalous
 */
bool does_deltatime_seem_wrong(float new_deltatime);

#endif

#include "Utils/Utils.hpp"
#include <array>

// The last 5 deltatime values
std::array<float, 5> deltatime_history = {};

// Where the new deltatime value should be saved in the history array
int deltatime_history_index = 0;

bool does_deltatime_seem_wrong(float new_deltatime)
{
	// Copy the history array so that it can be sorted
	std::array<float, 5> history_copy = deltatime_history;

	// Save the new deltatime value
	deltatime_history[deltatime_history_index] = new_deltatime;

	// Update the index
	deltatime_history_index = (deltatime_history_index + 1) % 5;

	// If 5 values have not been recorded yet, assume deltatime is valid
	if (deltatime_history[4] == 0.f)
		return false;

	// Sort array to find median
	std::sort(history_copy.begin(), history_copy.end());
	const float median = history_copy[2];

	// Return whether new value is anomalous
	return median * 3 < new_deltatime;
}

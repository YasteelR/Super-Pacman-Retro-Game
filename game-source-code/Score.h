#ifndef A98570DD_3CC0_4B62_9562_11D1DEE22ADD
#define A98570DD_3CC0_4B62_9562_11D1DEE22ADD

#include <string>
#include <fstream>
#include <memory>
#include <vector>

using namespace std;

/**
 * @class Score
 * @brief Manages the player's score and high scores in the game.
 * 
 * The Score class provides functionality to add points, handle high scores,
 * and store/retrieve high scores from storage.
 */
class Score {
    public:
        /**
         * @brief Constructor for the Score class.
         * 
         * Initializes the score and high score-related variables.
         */
        Score();

        /**
         * @brief Adds a set number of points to the current score.
         * 
         * This method increments the player's current score.
         */
        void addPoints();

        /**
         * @brief Adds star points based on matching conditions.
         * 
         * Adds bonus points if certain conditions are met based on star matches.
         * 
         * @param matched1 Whether the first condition is matched.
         * @param matched2 Whether the second condition is matched.
         */
        void addStarPoints(bool matched1, bool matched2);

        /**
         * @brief Retrieves the current score.
         * 
         * @return int The current score of the player.
         */
        int getScore();

        /**
         * @brief Retrieves the current score as a string.
         * 
         * Converts the current score to a string format.
         * 
         * @return string The current score in string format.
         */
        string getStringScore();

        /**
         * @brief Stores the current score as a high score if it's eligible.
         * 
         * This method stores the score in the high score list if it qualifies.
         */
        void storeHighScore();

        /**
         * @brief Checks if the current score is a new high score.
         * 
         * Determines whether the current score qualifies as a new high score.
         * 
         * @return bool True if the score is a new high score, false otherwise.
         */
        bool newHighScore();

        /**
         * @brief Retrieves the list of high scores.
         * 
         * @return shared_ptr<vector<int>> A shared pointer to a vector of high scores.
         */
        shared_ptr<vector<int>> getHighScores();

    private:
        int points; ///< The player's current score.
        string ScoreString; ///< The player's score as a string.
        vector<int> HighScores; ///< A list of high scores.
        bool hScore; ///< Flag to indicate whether the score is a new high score.

        /**
         * @brief Sorts the list of high scores.
         * 
         * This method sorts the high scores in descending order.
         */
        void sortScores();

        /**
         * @brief Stores the high scores to a file.
         * 
         * This method saves the high score list to an external file for persistence.
         */
        void store();
};

#endif /* A98570DD_3CC0_4B62_9562_11D1DEE22ADD */

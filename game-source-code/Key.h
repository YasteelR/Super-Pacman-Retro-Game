#ifndef C52769D9_9D04_4104_8174_7698B3973915
#define C52769D9_9D04_4104_8174_7698B3973915

#include "Sprite.h"
#include "Door.h"

using namespace std;

/**
 * @brief Represents a Key object in the game.
 * 
 * The Key class provides functionality for key objects,
 * including door interaction.
 */
class Key : public Sprite {
public:
    Key();
    
    /**
     * @brief Destroys doors associated with this key.
     * 
     * @param doors The vector of door objects to destroy.
     */
    void destroyDoors(vector<shared_ptr<Door>>& doors);

private:
    vector<shared_ptr<int>> doors; ///< Vector to hold door references.
    static int NumberOfKeys; ///< Total number of keys created.
    int ThisKeysNumber; ///< The number of this specific key.
};

#endif /* C52769D9_9D04_4104_8174_7698B3973915 */

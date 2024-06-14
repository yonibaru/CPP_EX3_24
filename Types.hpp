#ifndef TYPES_HPP
#define TYPES_HPP

enum class PlayerType{
    PLAYER,
    WORLD
};

enum class Resource{
    WOOD,
    STONE,
    WOOL,
    WHEAT,
    BRICK,
    NONE, //For desert tiles.
};

enum class Building{
    SETTLEMENT,
    CITY,
    NONE,
};

enum class Port{
    GENEREAL_PORT, //3:1 PORT
    WOOD_PORT,     //2:1 WHEAT PORT
    STONE_PORT,    //2:1 STONE PORT
    WOOL_PORT,     //2:1 WOOL PORT
    WHEAT_PORT,    //2:1 WHEAT PORT
    BRICK_PORT,    //2:1 BRICK PORT
    NONE,
};

enum class DevCardType{
    KNIGHT,
    VICTORY_POINT,
    YEAR_OF_PLENTY,
    MONOPOLY,
    ROAD_BUILDING,
    NONE,
};

#endif